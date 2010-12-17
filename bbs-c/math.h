#pragma once

class CMath
{
public:
//	bool CMath::getCRC( const CString numStr, CString & twoRow, CString & crc );
	bool CMath::getCRC( PARAMS & params );
	bool calcRow( const CString numStr, CString & twoRow, CString & resCrcStr );
	void convert( __int64 & in, CString & out );
};