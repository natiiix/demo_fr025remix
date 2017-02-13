#include "gl_Scene.hpp"

gl::Scene::Scene(const double & startTime)
{
	m_startTime = startTime;
}

double gl::Scene::getStartTime(void) const
{
	return m_startTime;
}
