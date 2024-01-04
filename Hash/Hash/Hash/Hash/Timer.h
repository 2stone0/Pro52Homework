#pragma once
#include <windows.h>

class Timer
{
public:
	Timer();


	void Start();
	void End();

	double GetElaspedTime();

private:
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;
};

