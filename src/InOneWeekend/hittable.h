#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record
{
	public:

		point3 m_p;
		vec3 m_normal;
		double m_t;
		bool m_front_face;

		void set_face_normal(const ray& i_r, const vec3& i_outward_normal)
		{
			m_front_face = dot(i_r.direction(), i_outward_normal) < 0;
			m_normal = m_front_face ? i_outward_normal : -i_outward_normal;
		}
};

class hittable
{
	public:

		virtual ~hittable() = default;

		virtual bool hit(const ray& i_r, double i_ray_tmin, double i_ray_tmax, hit_record& i_rec) const = 0;
};

#endif // !HITTABLE_H
