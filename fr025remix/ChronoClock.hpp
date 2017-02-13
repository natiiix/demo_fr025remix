#pragma once

#include <chrono>

class ChronoClock
{
public:
	double getDeltaTime(void);
	double getTotalTime(void) const;
private:
	double totalTime;
	std::chrono::time_point<std::chrono::steady_clock> firstLoop;
	std::chrono::time_point<std::chrono::steady_clock> prevLoop;
};
