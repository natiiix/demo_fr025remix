#pragma once

#include "obj_VertexSet.hpp"

#include <vector>

namespace obj
{
	enum FaceShape : int
	{
		Triangle,
		Quad,
		Polygon
	};

	// Used to store face definitions of 3D objects
	class Face
	{
	public:
		// Appends a vertex set to this face
		void addVertexSet(const VertexSet & vertSet);

		// Returns all vertex sets associated with this face
		std::vector<VertexSet> & getVertexSets(void);

		// Should be called after all vertex sets were appended
		// Figures out the shape of the face by counting the amount of vertex sets
		void EvaluateShape(void);

	private:
		std::vector<VertexSet> m_vertexSets;
		FaceShape m_shape;
	};
}
