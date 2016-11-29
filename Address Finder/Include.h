#pragma once

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <Windows.h>
#include <TlHelp32.h>
#include <dbghelp.h>
#include <psapi.h>
#include <atlbase.h>

#pragma  comment(lib, "dbghelp")
#pragma  comment(lib, "psapi")

#include <boost\thread.hpp>

#include <QtGui>

#include "AddressFinder.h"
#include "ProcessList.h"

#include "CScan.h"

#endif