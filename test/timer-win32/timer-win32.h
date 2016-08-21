#ifndef TIMER_H_DEF
#define TIMER_H_DEF

#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();
	void start();
	void end();
	double getCurrentTimeMicroSec();
	double getElapsedTimeMicroSec();

private:
	double startTimeMicroSec;
	double endTimeMicroSec;

	LARGE_INTEGER frequency;
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
};

#endif