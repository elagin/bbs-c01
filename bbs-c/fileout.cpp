#include "stdafx.h"
#include "fileout.h"


CFileOut::~CFileOut()
{
	if( hFile != INVALID_HANDLE_VALUE )
	{
		CloseHandle( hFile );
	}
}

bool CFileOut::write( CStringA & out )
{
	DWORD cb = 0;
	bool res = false;
	if( hFile != INVALID_HANDLE_VALUE )
	{
		res = WriteFile( hFile, out, out.GetLength(), &cb, NULL );
		if( !res )
		{
			cout << "Error: " << GetLastError();
		}
	}
	else
	{
		cout << "File not exist";
	}

	return res;
}

bool CFileOut::create( CString fileName )
{
	hFile = CreateFile( fileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if( hFile == INVALID_HANDLE_VALUE )
	{
		cout << "Error: " << GetLastError();

	}
	
	return hFile != INVALID_HANDLE_VALUE;
}
