#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_vec3 t_vec3;
typedef struct s_ray t_ray;

typedef   void (*RayDconst)(t_ray* ray);
typedef   void (*RayPconst)(t_ray* ray, t_vec3 *org, t_vec3 *dir);
typedef   const t_vec3*(*RayOrig)(t_ray* ray);
typedef   const t_vec3* (*RayDir)(t_ray* ray);
typedef   t_vec3 (*At)(t_ray* ray, double t);

typedef struct s_ray
{
	t_vec3 *org;
	t_vec3 *dir;
	RayDconst def_const;
	RayPconst par_const;
	RayOrig ray_orig;
	RayDir ray_dir;
	At at;
}t_ray;

void DefaultRayConstructor(t_ray *ray);

void ParamRayConstructor(t_ray *ray, t_vec3 *org, t_vec3 *dir);
const t_vec3* RayOrigin(t_ray *ray);
const t_vec3* RayDirection(t_ray *ray);
t_vec3 RayAt(t_ray *ray, double t);
void ray_class_init(t_ray *ray);

#endif

