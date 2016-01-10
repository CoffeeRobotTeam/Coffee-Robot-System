#ifndef DELAY_H
#define DELAY_H

#include "stdafx.h"

void delay(double delaytime)
{
	DWORD dwStart = GetTickCount();
	DWORD dwEnd = dwStart;
	do
	{
		MSG   msg;
		GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		dwEnd = GetTickCount() - dwStart;
	} while (dwEnd < delaytime);
}
#endif