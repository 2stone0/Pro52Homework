#include "Timer.h"

#include <iostream>

Timer::Timer()
{
	QueryPerformanceFrequency(&Frequency);
}

void Timer::Start()
{
	QueryPerformanceCounter(&BeginTime);
}

void Timer::End()
{
	QueryPerformanceCounter(&Endtime);
}

double Timer::GetElaspedTime()
{
	__int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	double duringtimeSec = (double)elapsed / (double)Frequency.QuadPart;

	std::cout << std::endl << "수행시간 : " << duringtimeSec * 1000 << "ms" << std::endl;

	return duringtimeSec;
}
