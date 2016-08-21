#include "timer-win32.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&frequency);
	startCount.QuadPart = 0.0;
	endCount.QuadPart = 0.0;
}

Timer::~Timer()
{
}

void Timer::start()
{
	QueryPerformanceCounter(&startCount);
}

void Timer::end()
{
	QueryPerformanceCounter(&endCount);
}

double Timer::getCurrentTimeMicroSec()
{
	double currentTime = 0.0;
	LARGE_INTEGER currentCount;
	currentCount.QuadPart = 0.0;

	QueryPerformanceCounter(&currentCount);

	startTimeMicroSec = startCount.QuadPart;

	if (startTimeMicroSec > 0.0)
		currentTime = (currentCount.QuadPart - startTimeMicroSec) * (1000000.0 / frequency.QuadPart);

	return currentTime;
}

double Timer::getElapsedTimeMicroSec()
{
	double elapsedTime = 0.0;
	startTimeMicroSec = startCount.QuadPart;
	endTimeMicroSec = endCount.QuadPart;
	elapsedTime = (endTimeMicroSec - startTimeMicroSec) * (1000000.0 / frequency.QuadPart);

	return elapsedTime;
}