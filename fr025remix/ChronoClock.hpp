#pragma once

#include <chrono>

// Used to measure elapsed time, both total and the time difference between consecutive iterations
class ChronoClock
{
public:
	// Returns the time elapsed since the previous iteration, 0 if this is the first iteration
	double getDeltaTime(void);

	// Returns the time elapsed since the first iteration
	double getTotalTime(void) const;

private:
	double m_totalTime;
	std::chrono::time_point<std::chrono::steady_clock> m_firstLoop;
	std::chrono::time_point<std::chrono::steady_clock> m_prevLoop;
};
