#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace obj
{
	class Object;
	class Face;
	class VertexSet;
	class Property3f;

	// Used to parse 3D objects from Wavefront .obj files
	void objParse(const std::string & objPath, std::vector<Object> & objects,
		std::vector<Property3f> & vertices, std::vector<Property3f> & textures, std::vector<Property3f> & normals);
	// Checks whether the string str begins with the string beginning
	bool strBeginsWith(const std::string & str, const std::string & beginning);
	// Used to split strings by a certain character
	void strSplit(const std::string & strInput, std::vector<std::string> & strWords, const char & separator = ' ', const bool & removeEmpty = false);
	// Extracts the x, y, z values from a string a puts them into a Propetry3f object
	bool extractProperty(const std::string & strLine, const std::string & strProperty, std::vector<Property3f> & propertyStorage);
	// Extracts all the vertex sets and stores them as a Face object
	bool extractFace(const std::string & strLine, Object & lastObject);
	// Converts string to integer
	int toInt(const std::string & str);
	// Converts string to float
	float toFloat(const std::string & str);

	// Used to hold 3D objects
	class Object
	{
	public:
		Object(const std::string & name) :
			m_name(name) { }
		std::string getName(void) const { return m_name; }
		void addFace(const Face & face) { m_faces.push_back(face); }
		std::vector<Face> & getFaces(void) { return m_faces; }
		static const Object * findByName(const std::vector<Object> & objects, const std::string & name);

	private:
		std::string m_name;
		std::vector<Face> m_faces;
	};

	// Used to store face definitions of 3D objects
	class Face
	{
	public:
		void addVertexSet(const VertexSet & vertSet) { m_vertexSets.push_back(vertSet); }
		std::vector<VertexSet> & getVertexSets(void) { return m_vertexSets; }

	private:
		std::vector<VertexSet> m_vertexSets;
	};

	// Used to store sets vertex indexes (vertex, texture coordinates, normal)
	class VertexSet
	{
	public:
		// Parse the vertex set from a string
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
		int getVertex() const { return m_vertex; }
		int getTexture() const { return m_texture; }
		int getNormal() const { return m_normal; }

	private:
		int m_vertex;
		int m_texture;
		int m_normal;
	};

	// Used to store vertices, texture coordinates and normals
	class Property3f
	{
	public:
		Property3f(const float & x, const float & y, const float & z) :
			m_x(x), m_y(y), m_z(z) { }
		float getX(void) const { return m_x; }
		float getY(void) const { return m_y; }
		float getZ(void) const { return m_z; }

	private:
		float m_x;
		float m_y;
		float m_z;
	};
}
