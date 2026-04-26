#pragma once

#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"

class vec3
{
	public:
		double m_e[3];

		vec3() : m_e{0, 0, 0} {}
		vec3(double i_e0, double i_e1, double i_e2) : m_e{ i_e0, i_e1, i_e2 } {}

		double x() const { return m_e[0]; }
		double y() const { return m_e[1]; }
		double z() const { return m_e[2]; }

		vec3 operator-() const { return vec3(-m_e[0], -m_e[1], -m_e[2]); }
		double operator[](int i) const { return m_e[i]; }
		double& operator[](int i) { return m_e[i]; }

		vec3& operator+=(const vec3& v)
		{
			m_e[0] += v.m_e[0];
			m_e[1] += v.m_e[1];
			m_e[2] += v.m_e[2];

			return *this;
		}

		vec3& operator*=(double t)
		{
			m_e[0] *= t;
			m_e[1] *= t;
			m_e[2] *= t;

			return *this;
		}

		vec3& operator/=(double t)
		{
			return *this *= 1 / t;
		}

		double length() const
		{
			return std::sqrt(length_squared());
		}

		double length_squared() const
		{
			return (m_e[0] * m_e[0]) + (m_e[1] * m_e[1]) + (m_e[2] * m_e[2]);
		}
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& o_v)
{
	return out << o_v.m_e[0] << ' ' << o_v.m_e[1] << ' ' << o_v.m_e[2];
}

inline vec3 operator+(const vec3 & o_u, const vec3 & o_v)
{
	return vec3(o_u.m_e[0] + o_v.m_e[0], o_u.m_e[1] + o_v.m_e[1], o_u.m_e[2] + o_v.m_e[2]);
}

inline vec3 operator-(const vec3& o_u, const vec3& o_v)
{
	return vec3(o_u.m_e[0] - o_v.m_e[0], o_u.m_e[1] - o_v.m_e[1], o_u.m_e[2] - o_v.m_e[2]);
}

inline vec3 operator*(const vec3& o_u, const vec3& o_v)
{
	return vec3(o_u.m_e[0] * o_v.m_e[0], o_u.m_e[1] * o_v.m_e[1], o_u.m_e[2] * o_v.m_e[2]);
}

inline vec3 operator*(double i_t, const vec3& o_u)
{
	return vec3(o_u.m_e[0] * i_t, o_u.m_e[1] * i_t, o_u.m_e[2] * i_t);
}

inline vec3 operator*(const vec3& o_u, double i_t)
{
	return i_t * o_u;
}

inline vec3 operator/(const vec3& o_u, double i_t)
{
	return 1 / i_t * o_u;
}

inline double dot(const vec3& o_u, const vec3& o_v)
{
	return (o_u.m_e[0] * o_v.m_e[0]) + (o_u.m_e[1] * o_v.m_e[1]) + (o_u.m_e[2] * o_v.m_e[2]);
}

inline vec3 cross(const vec3& o_u, const vec3& o_v)
{
	return vec3(o_u.m_e[1] * o_v.m_e[2] - o_u.m_e[2] * o_v.m_e[1], 
				o_u.m_e[2] * o_v.m_e[0] - o_u.m_e[0] * o_v.m_e[2],
				o_u.m_e[0] * o_v.m_e[1] - o_u.m_e[1] * o_v.m_e[0]
	);
}

inline vec3 unit_vector(const vec3& o_u)
{
	return o_u / o_u.length();
}

#endif // ! VEC3_H
