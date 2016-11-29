#include "CScan.h"

CScan* pCScan;

inline BYTE HexCharToByte(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return (c - 'a') + 10;
	else if (c >= 'A' && c <= 'Z')
		return (c- 'A') + 10;

	return -1;
}

int FindPattern(BYTE* needle, int nLen, BYTE* hayStack, int sLen, bool* skipIndex)
{
	for (int i = 0; i < sLen - nLen; i++)
	{
		bool found = true;

		for (int j = 0; j < nLen; j++)
		{
			found = (hayStack[i+j] == needle[j]);

			if (skipIndex)
				found = found || skipIndex[j];

			if (!found)
				break;
		}

		if (found)
			return i;
	}

	return -1;
}

LPBYTE CScan::FindMemoryPattern(std::string strProcess, DWORD ProcessId, char* szPattern, int iOffset, int iSize)
{
	int length = strlen(szPattern);
	assert(length % 2 == 0);

	int tlen = length/2;
	BYTE* translation = new BYTE[tlen];
	bool* skipOver = new bool[tlen];

	for (int i = 0; i < length; i += 2)
	{
		int idx = i/2;
		translation[idx] = (HexCharToByte(szPattern[i]) << 4) | (HexCharToByte(szPattern[i+1]));
		skipOver[idx] = (szPattern[i] == '*' && szPattern[i+1] == '*') || (szPattern[i] == '?' && szPattern[i+1] == '?');
	}

	LPBYTE location = NULL;
    MODULEENTRY32 mod;
	mod.dwSize = sizeof(mod);
	HANDLE proc = OpenProcess(PROCESS_VM_READ, FALSE, ProcessId);

	HANDLE tool = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessId);

    if (Module32First(tool, &mod))
    {
	    do
	    {
			std::string s(CW2A(mod.szModule));

			if (s == strProcess)
			{
				BYTE* buffer = new BYTE[mod.modBaseSize];
				ReadProcessMemory(proc, mod.modBaseAddr, buffer, mod.modBaseSize, NULL);
				int pattern = FindPattern(translation, tlen, buffer, mod.modBaseSize, skipOver);

				if (pattern != -1)
					location = mod.modBaseAddr + pattern;

				delete[] buffer;
				mod.dwSize = sizeof(mod);
			}
	    }
	    while (Module32Next(tool, &mod) && (location == NULL));

		if (iOffset)
		{
			if (iSize)
			{
				LPBYTE sized = NULL;
				ReadProcessMemory(proc, location+iOffset, &sized, iSize, NULL);
				location = sized;
			}
			else
			{
				ReadProcessMemory(proc, location+iOffset, &location, sizeof(location), NULL);
			}
		}
    }

	CloseHandle(tool);
	CloseHandle(proc);

	return location;
}