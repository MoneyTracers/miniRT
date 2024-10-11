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

int hit(t_vec3 *center, t_ray *ray, double radius, double ray_tmin, double ray_tmax, t_hitrecord*rec);
void set_face_normal(t_hitrecord *rec, const t_ray *ray, t_vec3 *outward_normal);
#endif
