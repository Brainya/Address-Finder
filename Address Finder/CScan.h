#pragma once

#ifndef _CSCAN_H_
#define _CSCAN_H_

#include "Include.h"

class CScan
{
public:
	LPBYTE FindMemoryPattern(std::string strProcess, DWORD ProcessId, char* szPattern, int iOffset, int iSize);
};

extern CScan* pCScan;

#endif