#include "obj_Object.hpp"

namespace obj
{
	Object::Object(const std::string & name) :
		m_name(name) { }

	std::string Object::getName(void) const
	{
		return m_name;
	}

	void Object::addFace(const Face & face)
	{
		m_faces.push_back(face);
	}

	std::vector<Face> & Object::getFaces(void)
	{
		return m_faces;
	}

	void Object::setPosition(const Property3f & position)
	{
		m_position = position;
	}

	void Object::setPosition(const float & x, const float & y, const float & z)
	{
		m_position.Set(x, y, z);
	}

	void Object::Move(const Property3f & position)
	{
		m_position += position;
	}

	void Object::Move(const float & x, const float & y, const float & z)
	{
		m_position += Property3f(x, y, z);
	}

	void Object::setRotation(const Property3f & rotation)
	{
		m_rotation = rotation;
	}

	void Object::setRotation(const float & x, const float & y, const float & z)
	{
		m_rotation.Set(x, y, z);
	}

	void Object::Rotate(const Property3f & rotation)
	{
		m_rotation += rotation;
	}

	void Object::Rotate(const float & x, const float & y, const float & z)
	{
		m_rotation += Property3f(x, y, z);
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
}