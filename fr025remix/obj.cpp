#include "obj.hpp"

namespace obj
{
	void objParse(const std::string & objPath, std::vector<Object> & objects,
		std::vector<Property3f> & vertices, std::vector<Property3f> & textures, std::vector<Property3f> & normals)
	{
		objects.clear();
		std::ifstream inputFile(objPath);

		std::string line;
		while (getline(inputFile, line))
		{
			// new object definition
			if (str::beginsWith(line, "o "))
			{
				objects.push_back(Object(line.substr(2)));
				continue;
			}

			// vertex
			if (extractProperty(line, "v ", vertices))
				continue;

			// texture
			if (extractProperty(line, "vt ", textures))
				continue;

			// normal
			if (extractProperty(line, "vn ", normals))
				continue;

			if (objects.size() > 0)
			{
				// face
				if (extractFace(line, objects.back()))
					continue;
			}
		}
	}

	bool extractProperty(const std::string & strLine, const std::string & strProperty, std::vector<Property3f> & propertyStorage)
	{
		if (str::beginsWith(strLine, strProperty))
		{
			std::stringstream ss(strLine.substr(strProperty.size()));

			float f[3];
			ss >> f[0] >> f[1] >> f[2];

			propertyStorage.push_back(Property3f(f[0], f[1], f[2]));
			return true;
		}

		return false;
	}

	bool extractFace(const std::string & strLine, Object & lastObject)
	{
		if (str::beginsWith(strLine, "f "))
		{
			Face face;
			std::stringstream ss(strLine.substr(2));

			std::string strVertexSet;
			while (ss >> strVertexSet)
			{
				face.addVertexSet(VertexSet(strVertexSet));
			}

			lastObject.addFace(face);
			return true;
		}

		return false;
	}
}
