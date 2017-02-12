#pragma once

#ifndef CHRONOCLOCK_HPP
#define CHRONOCLOCK_HPP

#include <chrono>

class ChronoClock
{
public:
	double getDeltaTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> prevLoop;
};

#endif // !CHRONOCLOCK_HPP
