#pragma once

class CFileOut
{
public:
	~CFileOut();
	
	bool create( CString fileName );
	bool write( CStringA & out );

private:
	HANDLE hFile;
};
