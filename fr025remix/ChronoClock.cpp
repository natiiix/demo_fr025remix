#include "ChronoClock.hpp"

double ChronoClock::getDeltaTime(void)
{
	double deltaTime = 0;
	// Get current time
	std::chrono::time_point<std::chrono::steady_clock> nowTime = std::chrono::steady_clock::now();

	if (m_prevLoop.time_since_epoch().count() > 0)
	{
		// Get the time delta since the last iteration
		deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(nowTime - m_prevLoop).count();
		// Get the total time since the first iteration
		m_totalTime = std::chrono::duration_cast<std::chrono::duration<double>>(nowTime - m_firstLoop).count();
	}
	else
	{
		// First iteration setup
		m_firstLoop = nowTime;
		m_totalTime = 0.0;
	}

	// Update the most recent iteration (the current one) time
	m_prevLoop = nowTime;

	return deltaTime;
}

double ChronoClock::getTotalTime(void) const
{
	return m_totalTime;
}
