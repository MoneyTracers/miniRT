#ifndef VEC3_H
#define VEC3_H

# include <math.h>
# include <stdio.h>
# include <stdarg.h>

// REFERENCE: https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/addingaprogressindicator
typedef struct s_vec3 t_vec3;

typedef   void (*Dconst)(t_vec3* vec3);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Pconst)(t_vec3* vec3, double e0, double e1, double e2);
typedef   void (*Ominus)(t_vec3* vec3);
typedef   double (*Oget)(t_vec3* vec3, int i);
typedef   double* (*Oset)(t_vec3* vec3, int i, double value);
typedef   t_vec3* (*Vadd)(t_vec3	*vec3, t_vec3	*nvec);
typedef   t_vec3* (*Vmul)(t_vec3	*vec3, double t);
typedef   t_vec3* (*Vdiv)(t_vec3	*vec3, double t);
typedef   double (*LenSqr)(t_vec3	*vec3);
typedef   double (*Len)(t_vec3	*vec3);

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
	Vadd vadd;
	Vmul vmul;
	Vdiv vdiv;
	LenSqr lensqr;
	Len len;
}t_vec3;


#endif
