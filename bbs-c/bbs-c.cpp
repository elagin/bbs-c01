// bbs-c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "fileout.h"



//bool parceCommandLine( int argc, _TCHAR* argv[], CString & fileName, CString & firstStart, CString & firstEnd, CString & secondStart, CString & secondEnd );
bool parceCommandLine( int argc, _TCHAR* argv[], PARAMS & params  );



int _tmain(int argc, _TCHAR* argv[])
{

	CString firstStart;
	CString firstEnd;
	CString secondStart;
	CString secondEnd;
	CString fileName;

	PARAMS params;

	if( parceCommandLine( argc, argv, params ) )
	{
		CFileOut fileOut;
		CStringA firstLine ("\"1\",\"2\",\"3\",\"4\"\r\n");
		if( fileOut.create( params.fileName ) )
		{
			CString twoRow;			// Второй столбец
			CString resCrcStr;		// Контрольная сумма

			fileOut.write( firstLine );

			CMath math;
//			math.getCRC( firstStart, twoRow, resCrcStr );
			math.getCRC( params );

			CString outStr;
			outStr.Format( _T("\"%s%s\",\"%s\"\r\n"), firstStart, resCrcStr, twoRow );
			CStringA outStra(outStr);
			fileOut.write( outStra );
		}
		//	cout << firstStart << " " << twoRow << " " << resCrcStr<< "\n";
	}
	return 0;
}


bool parceCommandLine( int argc, _TCHAR* argv[], PARAMS & params )
{
	if( argc == 6 )
	{
		for( int count = 1; count < argc; count++ )
		{
			TCHAR* param = argv[count];
			switch( count )
			{
				case 1:
				params.fileName = argv[count];
				break;

				case 2:
				params.firstStart = argv[count];
				break;

				case 3:
				params.firstEnd = argv[count];
				break;

				case 4:
				params.secondStart = argv[count];
				break;

				case 5:
				params.secondEnd = argv[count];
				break;

			}
			int a = 0;
		}
		return true;
	}
	else
	{
		cout << "Invalid params\n";
		cout << "c:\\out.txt 10793360000 10793360200 10793420100 10793420300\n";
		return false;
	}
}
