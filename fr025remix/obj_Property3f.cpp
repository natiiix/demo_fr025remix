#include "obj_Property3f.hpp"

namespace obj
{
	Property3f::Property3f(void) :
		m_x(0), m_y(0), m_z(0) { }

	Property3f::Property3f(const float & x, const float & y, const float & z) :
		m_x(x), m_y(y), m_z(z) { }

	void Property3f::Set(const float & x, const float & y, const float & z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void Property3f::Reset(void)
	{
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}

	float Property3f::getX(void) const
	{
		return m_x;
	}

	float Property3f::getY(void) const
	{
		return m_y;
	}

	float Property3f::getZ(void) const
	{
		return m_z;
	}

	Property3f & Property3f::operator+=(const Property3f & operand)
	{
		m_x += operand.getX();
		m_y += operand.getY();
		m_z += operand.getZ();

		return *this;
	}
}
