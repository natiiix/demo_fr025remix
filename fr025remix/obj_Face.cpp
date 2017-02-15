#include "obj_Face.hpp"

namespace obj
{
	void obj::Face::addVertexSet(const VertexSet & vertSet)
	{
		m_vertexSets.push_back(vertSet);
	}

	std::vector<VertexSet>& Face::getVertexSets(void)
	{
		return m_vertexSets;
	}

	void Face::EvaluateShape(void)
	{
		switch (m_vertexSets.size())
		{
		case 3:
			m_shape = Triangle;
			break;

		case 4:
			m_shape = Quad;
			break;

		default:
			m_shape = Polygon;
			break;
		}
	}
}
