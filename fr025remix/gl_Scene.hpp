#pragma once

#include "gl_ShapeGroup.hpp"

#include <vector>

namespace gl
{
	class Scene
	{
	public:
		Scene(const double & startTime);
		double getStartTime(void) const;
	private:
		double m_startTime;
		std::vector<gl::ShapeGroup *> m_shapeGroups;
	};
}
