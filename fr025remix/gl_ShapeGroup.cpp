#include "gl_ShapeGroup.hpp"

namespace gl
{
	ShapeGroup::ShapeGroup(std::string name)
	{
		m_name = name;
	}

	std::string ShapeGroup::getName(void) const
	{
		return m_name;
	}

	ShapeGroup * ShapeGroup::FindByName(std::vector<ShapeGroup *> const & shapeGroups)
	{
		return nullptr;
	}
}
