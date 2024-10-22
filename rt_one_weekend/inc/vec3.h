#ifndef VEC3_H
#define VEC3_H

# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

// REFERENCE: https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/addingaprogressindicator
typedef struct s_vec3 t_vec3;

typedef struct s_vec3
{
	double e[3];
}t_vec3;

t_vec3 unit_vec(t_vec3	vec3);
t_vec3 vec(double x, double y, double z);
t_vec3 dvec(void);
t_vec3 vec_mul(t_vec3	vec3, double t);
t_vec3 vec_div(t_vec3	vec3, double t);
t_vec3 vec_sub(t_vec3	minu, t_vec3	s);
t_vec3 vec_add(t_vec3	add, t_vec3	ends);
double vec_len_sqr(t_vec3	vec3);
double vec_len(t_vec3	vec3);
t_vec3	sample_square();
double dot(const t_vec3 u, const t_vec3 v);
t_vec3 vec_ran(void);
t_vec3 vec_ran_par(double min, double max);
t_vec3 random_unit_vec();
t_vec3 random_on_hemisphere(t_vec3 normal);
int near_zero(t_vec3 vec);
t_vec3 reflect(t_vec3 v, t_vec3 n);
t_vec3 vec_vec_mul(t_vec3	vec3, t_vec3 other);
t_vec3 refract(t_vec3 uv, t_vec3 n, double etai_over_etat);
double reflectance(double cosine, double refraction_index);

#endif
