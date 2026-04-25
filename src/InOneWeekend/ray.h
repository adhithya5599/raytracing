#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
	public:

		ray() {}
		ray(const point3& o_origin, const vec3& o_direction) : m_origin(o_origin), m_direction(o_direction) {}

		const point3& origin() const { return m_origin; }
		const vec3& direction() const { return m_direction; }

		point3 at(float i_t) const { return m_origin + i_t * m_direction; }

	private:

		point3 m_origin;
		vec3 m_direction;
};

#endif // !RAY_H
