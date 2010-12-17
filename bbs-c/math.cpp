#include "stdafx.h"
#include "math.h"

//bool CMath::getCRC( const CString numStr, CString & twoRow, CString & resCrcStr )
bool CMath::getCRC( PARAMS & params )
{
	const int maxLen = 9;
// 	CString firstStartCut = params.firstStart;
// 	CString firstEndCut = params.firstEnd;
	__int64 firstStartI = _ttoi64( params.firstStart );
	__int64 firstEndI = _ttoi64( params.firstEnd );
	__int64 secondStartI = _ttoi64( params.secondStart );
	__int64 secondEndI = _ttoi64( params.secondEnd );
//	float aa = _ttoi64( params.firstStart );

// 	if( params.firstStart.GetLength() > maxLen )	// Если надо, берем правую часть
// 	{
// 		firstStartCut = params.firstStart.Right(maxLen);
// 	}
// 
// 	if( params.firstEnd.GetLength() > maxLen )		// Если надо, берем правую часть
// 	{
// 		firstEndCut = params.firstEnd.Right(maxLen);
// 	}

// 	const int firstStartI = _ttoi(firstStartCut);
// 	const int firstEndI = _ttoi(firstEndCut);
//	__int64 firstCount = firstEndI - firstStartI;
/*
	CString secondStartCut = params.secondStart.Right(9);
	const int secondStartI = _ttoi(secondStartCut);

	CString secondEndCut = params.secondEnd.Right(9);
	const int secondEndI = _ttoi(secondEndCut);
	int secondCount = secondEndI - secondStartI;
*/
//	float a2a = 10793360000;

	for( __int64 start = firstStartI; start < firstEndI; start++ )
	{
/*
		CString numStr;
		TCHAR buffer[100];
		_i64tot_s( start, buffer, 100, 10 );
		numStr = buffer;
*/
		CString twoRow;
		CString resCrcStr;
		CString startStr;
		convert( start, startStr );
		calcRow( startStr, twoRow, resCrcStr);
		::Sleep(0);
	}
	return true;
}

void convert( __int64 & in, CString & out )
{
	CString numStr;
	const int size = 100;
	TCHAR buffer[size];
	_i64tot_s( in, buffer, size, 10 );
	out = buffer;
}

bool CMath::calcRow( const CString numStr, CString & twoRow, CString & resCrcStr )
{
	twoRow = numStr.Right(6);

	const int len = numStr.GetLength();
	int multiplicationSum = 0;

	TCHAR item = 0;
	int preRes = 0;							// Результат умножения для каждой позиции
	for ( int i = 0; i < len; i++ )
	{
		item = numStr.GetAt( i );			// Извлекаем посимвольно 
		const int numInt = _ttoi(&item);	// Переводим в int
		if( i % 2 == 0 )					// В зависимости от позиции умножаем
		{
			preRes = numInt * 3;
			int a = 0;
		}
		else
		{
			preRes = numInt;
			int a = 0;
		}
		multiplicationSum += preRes;		// Накапливаем результат
	}
	int minMul = multiplicationSum / 10;		// Находим минимальный целый множитель
	minMul++;									// Максимальный - следующий.

	int maxMul = minMul * 10;
	int crc = maxMul - multiplicationSum;		// Контрольная сумма в int

	TCHAR buffer[100];
	_itot(crc, buffer, 10);	

	resCrcStr = buffer;					// Контрольная сумма в CString

	return true;
}