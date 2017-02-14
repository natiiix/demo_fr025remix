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
			if (strBeginsWith(line, "o "))
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

	bool strBeginsWith(const std::string & str, const std::string & beginning)
	{
		for (int i = 0; i < (int)beginning.size(); i++)
		{
			if (str[i] != beginning[i])
				return false;
		}

		return true;
	}

	void strSplit(const std::string & strInput, std::vector<std::string> & strWords, const char & separator, const bool & removeEmpty)
	{
		strWords.clear();
		std::istringstream strstream(strInput);

		std::string sTemp;
		while (getline(strstream, sTemp, separator))
		{
			if (!removeEmpty || sTemp.length() > 0)
			{
				strWords.push_back(sTemp);
			}
		}
	}

	bool extractProperty(const std::string & strLine, const std::string & strProperty, std::vector<Property3f> & propertyStorage)
	{
		if (strBeginsWith(strLine, strProperty))
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
		if (strBeginsWith(strLine, "f "))
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

	int toInt(const std::string & str)
	{
		if (str.size() > 0)
		{
			std::stringstream ss(str);
			int i;
			ss >> i;
			return i;
		}

		return 0;
	}

	float toFloat(const std::string & str)
	{
		if (str.size() > 0)
		{
			std::stringstream ss(str);
			float f;
			ss >> f;
			return f;
		}

		return 0.0f;
	}

	const Object * Object::findByName(const std::vector<Object> & objects, const std::string & name)
	{
		int objLen = (int)objects.size();

		for (int i = 0; i < objLen; i++)
		{
			if (objects[i].getName() == name)
				return &objects[i];
		}

		return nullptr;
	}

	VertexSet::VertexSet(const std::string & strVertexSet)
	{
		std::vector<std::string> elements;
		strSplit(strVertexSet, elements, '/');

		// Indexes in .obj files are counted from 1, however the C++ ones start at 0
		m_vertex = toInt(elements[0]) - 1;
		m_texture = toInt(elements[1]) - 1;
		m_normal = toInt(elements[2]) - 1;
	}
}
