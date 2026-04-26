#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include "rtweekend.h"

class sphere : public hittable
{
	public:

		sphere(const point3& i_center, double i_radius) : m_center(i_center), m_radius(std::fmax(0, i_radius)) {}

		bool hit(const ray& i_r, double i_ray_tmin, double i_ray_tmax, hit_record& i_rec) const override
		{
			vec3 oc = m_center - i_r.origin();
			auto a = i_r.direction().length_squared();
			auto h = dot(i_r.direction(), oc);
			auto c = oc.length_squared() - (m_radius * m_radius);

			auto discriminant = (h * h) - (a * c);
			if (discriminant < 0)
				return false;
			
			auto sqrtd = std::sqrt(discriminant);

			auto root = (h - sqrtd) / a;
			if (root <= i_ray_tmin || i_ray_tmax <= root)
			{
				root = (h + sqrtd) / a;
				if (root <= i_ray_tmin || i_ray_tmax <= root)
					return false;
			}

			i_rec.m_t = root;
			i_rec.m_p = i_r.at(i_rec.m_t);
			vec3 outward_normal = (i_rec.m_p - m_center) / m_radius;
			i_rec.set_face_normal(i_r, outward_normal);

			return true;
		}

	private:

		point3 m_center;
		double m_radius;
};

#endif // !SPHERE_H
