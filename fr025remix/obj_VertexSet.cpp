#include "obj_VertexSet.hpp"

namespace obj
{
	VertexSet::VertexSet(const std::string & strVertexSet)
	{
		std::vector<std::string> elements;
		str::split(strVertexSet, elements, '/');

		// Indexes in .obj files are counted from 1, however the C++ ones start at 0
		m_vertex = str::toInt(elements[0]) - 1;
		m_texture = str::toInt(elements[1]) - 1;
		m_normal = str::toInt(elements[2]) - 1;
	}

	int VertexSet::getVertex() const
	{
		return m_vertex;
	}

	int VertexSet::getTexture() const
	{
		return m_texture;
	}

	int VertexSet::getNormal() const
	{
		return m_normal;
	}
}
