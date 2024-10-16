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

#endif
