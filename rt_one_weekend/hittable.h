#ifndef HITTABLE_H
#define HITTABLE_H


#include "ray.h"
#include "vec3.h"

typedef struct s_hitrecord
{
	t_vec3	p;
	t_vec3	normal;
	double	t;
	int		front_face;
}t_hitrecord;

int hit(const t_ray *ray, double ray_tmin, double ray_tmax, t_hitrecord*rec);
void set_face_normal(const t_ray *ray, const t_vec3 *outward_normal);
#endif
