#include <windows.h>
#include <iostream>

using namespace std;

int main(void)
{
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
	LARGE_INTEGER frequency;

	QueryPerformanceFrequency(&frequency);
	startCount.QuadPart = 0;
	endCount.QuadPart = 0;
	
	double start = QueryPerformanceCounter(&startCount);
	Sleep(3000);
	double end = QueryPerformanceCounter(&endCount);
	cout << endCount.QuadPart * (1000000.0 / frequency.QuadPart) - startCount.QuadPart * (1000000.0 / frequency.QuadPart) << " ms.\n";
	return 0;
}
/*
#include <windows.h>
#include <iostream>

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

int main()
{
	StartCounter();
	Sleep(10000);
	cout << GetCounter() << "\n";
	return 0;
}
*/