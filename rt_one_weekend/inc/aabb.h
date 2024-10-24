#ifndef AABB_H
#define AABB_H

#include <rt.h>
#include "interval.h"

typedef struct s_aabb
{
	t_interval x;
	t_interval y;
	t_interval z;
} t_aabb;

t_aabb aabb(t_interval x, t_interval y, t_interval z);
t_aabb aabb_vec(t_vec3 a, t_vec3 b);
t_aabb aabb_aabb(t_aabb a, t_aabb b);
int aabb_hit(t_aabb aabb, t_ray r, t_interval ray_t);
t_interval axis_interval(t_aabb aabb, int n);
t_aabb sphere_bbox(t_vec3 center, double radius);

#endif


