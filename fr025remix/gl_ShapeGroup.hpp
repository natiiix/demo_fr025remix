#pragma once

#include "gl_Shape.hpp"

#include <string>
#include <vector>

namespace gl
{
	class ShapeGroup
	{
	public:
		ShapeGroup(std::string groupName = NULL);
		std::string getName(void) const;
		static ShapeGroup * FindByName(std::vector<ShapeGroup *> const & shapeGroups);
	private:
		std::string m_name;
		std::vector<Shape *> m_shapes;
	};
}
