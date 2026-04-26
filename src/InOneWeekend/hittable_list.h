#pragma once

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "rtweekend.h"

#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable
{
	public:

		std::vector<shared_ptr<hittable>> m_objects;

		hittable_list() {}
		hittable_list(shared_ptr<hittable> i_object) { add(i_object); }

		void clear() { m_objects.clear(); }

		void add(shared_ptr<hittable> i_object)
		{
			m_objects.push_back(i_object);
		}

		bool hit(const ray& i_r, double i_ray_tmin, double i_ray_tmax, hit_record& i_rec) const override
		{
			hit_record temp_rec;
			bool hit_anything = false;
			auto closest_so_far = i_ray_tmax;

			for (const auto& object : m_objects)
			{
				if (object->hit(i_r, i_ray_tmin, closest_so_far, temp_rec))
				{
					hit_anything = true;
					closest_so_far = temp_rec.m_t;
					i_rec = temp_rec;
				}
			}

			return hit_anything;
		}
};

#endif //HITTABLE_LIST_H
