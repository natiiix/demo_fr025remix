#pragma once

#include "obj_Object.hpp"
#include "obj_Face.hpp"
#include "obj_Property3f.hpp"
#include "str.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

namespace obj
{
	// Used to parse 3D objects from Wavefront .obj files
	void objParse(const std::string & objPath, std::vector<Object> & objects,
		std::vector<Property3f> & vertices, std::vector<Property3f> & textures, std::vector<Property3f> & normals);

	// Extracts the x, y, z values from a string a puts them into a Propetry3f object
	bool extractProperty(const std::string & strLine, const std::string & strProperty, std::vector<Property3f> & propertyStorage);

	// Extracts all the vertex sets and stores them as a Face object
	bool extractFace(const std::string & strLine, Object & lastObject);
}
