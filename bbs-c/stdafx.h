// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
//#include <tchar.h>
#include <iostream>

#define _WTL_NO_CSTRING
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include "atlbase.h"
#include "atlapp.h"
#include "atlmisc.h"
#include "atlstr.h"
#include "comutil.h"


using namespace std; 

struct PARAMS
{
	CString firstStart;
	CString firstEnd;
	CString secondStart;
	CString secondEnd;
	CString fileName;
};
// TODO: reference additional headers your program requires here
