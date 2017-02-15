#pragma once

#include "str.hpp"

#include <string>
#include <vector>

namespace obj
{
	// Used to store sets vertex indexes (vertex, texture coordinates, normal)
	class VertexSet
	{
	public:
		// Parses the vertex set from a string
		VertexSet(const std::string & strVertexSet);

		/*// Only vertex index is defined
		VertexSet(const int & vertex) :
		m_vertex(vertex), m_texture(0), m_normal(0) { }
		// Texture index is undefined
		VertexSet(const int & vertex, const int & normal) :
		m_vertex(vertex), m_texture(0), m_normal(normal) { }
		// All indexes are defined
		VertexSet(const int & vertex, const int & texture, const int & normal) :
		m_vertex(vertex), m_texture(texture), m_normal(normal) { }*/

		int getVertex() const;
		int getTexture() const;
		int getNormal() const;

	private:
		int m_vertex;
		int m_texture;
		int m_normal;
	};
}
