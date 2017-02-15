#pragma once

namespace obj
{
	// Used to properties that consist of 3 float values (vertices, texture coordinates, normals)
	class Property3f
	{
	public:
		// Initializes a property with 3 float values
		Property3f(void);
		Property3f(const float & x, const float & y, const float & z);

		// Sets x, y, z values to specified values
		void Set(const float & x, const float & y, const float & z);

		// Sets x, y, z values to 0
		void Reset(void);

		// Returns the x member
		float getX(void) const;
		// Returns the y member
		float getY(void) const;
		// Returns the z member
		float getZ(void) const;

		// Increments values of this property by values of another property
		Property3f & operator+=(const Property3f & operand);

	private:
		float m_x;
		float m_y;
		float m_z;
	};
}
