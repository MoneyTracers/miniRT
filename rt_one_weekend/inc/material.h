#ifndef MATERIAL_H
#define MATERIAL_H

# include <rt.h>
#include "ray.h"


enum e_mattypes
{
	lambertian,
	metal,
	dielectric,
};

typedef struct s_material t_material;

typedef struct s_hitrecord t_hitrecord;

typedef   int (*Scatter)(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered);


typedef struct s_material
{
	int type;
	t_vec3 color;
	Scatter scat;
	double fuzz;
	double refraction_index;
}t_material;

int scatter_met(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered);
int scatter_lamb(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered);
int scatter_die(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered);
t_material init_mat(int type, t_vec3 color, double fuzz, double refraction_index);

#endif

