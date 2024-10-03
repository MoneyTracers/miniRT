#ifndef VEC3_H
#define VEC3_H

// REFERENCE: https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/addingaprogressindicator
typedef struct s_vec3 t_vec3;

typedef   void (*Dconst)(t_vec3* vec3);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Ominus)(t_vec3* vec3);

typedef struct s_vec3
{
	double e[3];
	Dconst def_const;
	Pconst par_const;
	double *x;
	double *y;
	double *z;
	Ominus minus;
}t_vec3;


#endif
