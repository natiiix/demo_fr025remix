#include "ChronoClock.hpp"

double ChronoClock::getDeltaTime(void)
{
	double deltaTime = 0;
	// Get current time
	std::chrono::time_point<std::chrono::steady_clock> nowTime = std::chrono::steady_clock::now();

	if (prevLoop.time_since_epoch().count() > 0)
	{
		// Get the time delta since the last iteration
		deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(nowTime - prevLoop).count();
		// Get the total time since the first iteration
		totalTime = std::chrono::duration_cast<std::chrono::duration<double>>(nowTime - firstLoop).count();
	}
	else
	{
		// First iteration setup
		firstLoop = nowTime;
		totalTime = 0.0;
	}

	// Update the most recent iteration (the current one) time
	prevLoop = nowTime;

	return deltaTime;
}

double ChronoClock::getTotalTime(void) const
{
	return totalTime;
}
