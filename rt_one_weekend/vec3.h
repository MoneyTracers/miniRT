#ifndef VEC3_H
#define VEC3_H

// REFERENCE: https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/addingaprogressindicator
typedef struct s_vec3 t_vec3;

typedef   void (*Dconst)(t_vec3* vec3);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Ominus)(t_vec3* vec3);
typedef   double (*Oget)(t_vec3* vec3, int i);
typedef   double* (*Oset)(t_vec3* vec3, int i, double value);

typedef struct s_vec3
{
	double e[3];
	Dconst def_const;
	Pconst par_const;
	double *x;
	double *y;
	double *z;
	Ominus minus;
	Oget get;
	Oset set;
}t_vec3;


#endif
