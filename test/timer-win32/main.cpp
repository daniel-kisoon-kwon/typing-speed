#include <stdio.h>
#include "timer-win32.h"
#include <Windows.h>
void main()
{
	Timer timer;
	timer.start();

	Sleep(2000);
	printf("Current time : %f\n", timer.getCurrentTimeMicroSec() / 1000000);
	Sleep(2000);
	timer.end();

	printf("Elapsed time : %f\n", timer.getElapsedTimeMicroSec() / 1000000);
}