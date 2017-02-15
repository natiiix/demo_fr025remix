#pragma once

#include "obj_Face.hpp"
#include "obj_Property3f.hpp"

#include <string>
#include <vector>

namespace obj
{
	// Used to store 3D objects
	class Object
	{
	public:
		// Initializes an object with a specified name
		Object(const std::string & name);

		// Returns name of the object
		std::string getName(void) const;

		// Appends a face to this object
		void addFace(const Face & face);

		// Returns all faces associated with this object
		std::vector<Face> & getFaces(void);

		// Sets object position
		void setPosition(const Property3f & position);
		void setPosition(const float & x, const float & y, const float & z);

		// Changes the position of this object relative to its current position
		void Move(const Property3f & position);
		void Move(const float & x, const float & y, const float & z);

		// Sets object rotation
		void setRotation(const Property3f & rotation);
		void setRotation(const float & x, const float & y, const float & z);

		// Changes the rotation of this object relative to its current rotation
		void Rotate(const Property3f & rotation);
		void Rotate(const float & x, const float & y, const float & z);

		// Finds an object with a specified name in a vector of objects and returns a pointer to it
		static const Object * findByName(const std::vector<Object> & objects, const std::string & name);

	private:
		std::string m_name;
		std::vector<Face> m_faces;
		Property3f m_position;
		Property3f m_rotation;
	};
}
