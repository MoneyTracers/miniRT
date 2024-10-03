#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_vec3 t_vec3;

typedef   void (*RayDconst)(t_ray* ray);
typedef   void (*RayPconst)(t_ray* ray, t_vec3 *orig, t_vec3 *dir);
typedef   void (*RayOrig)(t_ray* ray);
typedef   void (*RayDir)(t_ray* ray, t_vec3 *orig, t_vec3 *dir);

typedef struct s_ray
{
	t_vec3 *orig;
	t_vec3 *dir;
	RayDconst def_const;
	RayPconst par_const;
	RayOrig ray_orig;
	RayDir ray_dir;
}t_ray;

#endif

