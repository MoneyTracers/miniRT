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
#endif


