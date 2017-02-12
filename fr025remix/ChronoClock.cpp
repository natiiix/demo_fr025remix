#include "ChronoClock.hpp"

double ChronoClock::getDeltaTime()
{
	double deltaTime = 0;
	std::chrono::time_point<std::chrono::steady_clock> nowTime = std::chrono::steady_clock::now();

	if (prevLoop.time_since_epoch().count() > 0)
		deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(nowTime - prevLoop).count();

	prevLoop = nowTime;

	return deltaTime;
}
