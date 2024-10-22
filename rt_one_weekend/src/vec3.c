#include <rt.h>

void	DefaultVectorConstructor(t_vec3* vec3)
{
	vec3->e[0]= 0;
	vec3->e[1]= 0;
	vec3->e[2]= 0;
}

void	ParamVectorConstructor(t_vec3* vec3, double e0, double e1, double e2)
{
	vec3->e[0]= e0;
	vec3->e[1]= e1;
	vec3->e[2]= e2;
}

void	OperatorMinus(t_vec3* vec3)
{
	vec3->e[0]= vec3->e[0] * -1;
	vec3->e[1]= vec3->e[1] * -1;
	vec3->e[2]= vec3->e[2] * -1;
}
double	OperatorGet(t_vec3* vec3, int i)
{
	return (vec3->e[i]);
}
double	*OperatorSet(t_vec3* vec3, int i, double value)
{
	vec3->e[i] = value;
	return (&vec3->e[i]);
}

t_vec3* VectorAddition(t_vec3	*vec3, t_vec3	*nvec)
{
	vec3->e[0] += nvec->e[0];
	vec3->e[1] += nvec->e[1];
	vec3->e[2] += nvec->e[2];
	return (vec3);
}

t_vec3* VectorDeduction(t_vec3	*vec3, t_vec3	*nvec)
{
	vec3->e[0] -= nvec->e[0];
	vec3->e[1] -= nvec->e[1];
	vec3->e[2] -= nvec->e[2];
return (vec3);
}

t_vec3* VectorMultiplication(t_vec3	*vec3, double t)
{
	vec3->e[0] *= t;
	vec3->e[1] *= t;
	vec3->e[2] *= t;
	return (vec3);
}

t_vec3* VectorDivide(t_vec3	*vec3, double t)
{
	VectorMultiplication(vec3, 1/t);
	return (vec3);
}


t_vec3 vec_mul(t_vec3	vec3, double t)
{
	t_vec3 new;

	new.e[0] =vec3.e[0]* t;
	new.e[1] =vec3.e[1]* t;
	new.e[2] =vec3.e[2]* t;
	return (new);
}

t_vec3 vec_vec_mul(t_vec3	vec3, t_vec3 other)
{
	t_vec3 new;

	new.e[0] =vec3.e[0]* other.e[0];
	new.e[1] =vec3.e[1]* other.e[1];
	new.e[2] =vec3.e[2]* other.e[2];
	return (new);
}

t_vec3 vec_div(t_vec3	vec3, double t)
{
	t_vec3 new;
	new = vec_mul(vec3, 1/t);
	return (new);
}

t_vec3 vec_sub(t_vec3	minu, t_vec3	s)
{
	t_vec3 new;
	new.e[0] = minu.e[0] - s.e[0];
	new.e[1] = minu.e[1] - s.e[1];
	new.e[2] = minu.e[2] - s.e[2];
	return (new);
}
t_vec3 vec_add(t_vec3	add, t_vec3	ends)
{
	t_vec3 new;
	new.e[0] = add.e[0] + ends.e[0];
	new.e[1] = add.e[1] + ends.e[1];
	new.e[2] = add.e[2] + ends.e[2];
	return (new);
}

double vec_len_sqr(t_vec3	vec3)
{
	double e0;
	double e1;
	double e2;
	
	e0 = vec3.e[0];
	e1 = vec3.e[1];
	e2 = vec3.e[2];

	return ((e0*e0)+(e1*e1)+(e2*e2));
}

double vec_len(t_vec3	vec3)
{
	double len;
	len = sqrt(vec_len_sqr(vec3));
	return (sqrt(vec_len_sqr(vec3)));
}

t_vec3 unit_vec(t_vec3	vec3)
{
	return (vec_div(vec3, vec_len(vec3)));
}

t_vec3 vec(double x, double y, double z)
{
	t_vec3 new;

	new.e[0] = x;
	new.e[1] = y;
	new.e[2] = z;
	return (new);
}
t_vec3 dvec(void)
{
	t_vec3 new;

	new.e[0] = 0;
	new.e[1] = 0;
	new.e[2] = 0;
	return (new);
}

t_vec3	sample_square()
{
	return (vec(random_double() -0.5, random_double() -0.5, 0));
}


double dot(const t_vec3 u, const t_vec3 v)
{
	return ((u.e[0] * v.e[0]) +(u.e[1] * v.e[1])+(u.e[2] * v.e[2]));
}

t_vec3 vec_ran(void)
{
	return (vec(random_double(), random_double(), random_double()));
}

t_vec3 vec_ran_par(double min, double max)
{
	return (vec(random_double_between(min, max), random_double_between(min, max), random_double_between(min, max)));
}

t_vec3 random_unit_vec()
{
	t_vec3 p;
	double lensq;

	while (1)
	{
		p = vec_ran_par(-1, 1);
		lensq = vec_len_sqr(p);
		if (1e-160 < lensq && lensq <= 1)
			return (vec_div(p, sqrt(lensq)));
	}
}

t_vec3 random_on_hemisphere(t_vec3 normal)
{
	t_vec3 on_unit_sphere;
	
	on_unit_sphere = random_unit_vec();
	if (dot(on_unit_sphere, normal) > 0.0)
		return (on_unit_sphere);
	else
		return (vec_mul(on_unit_sphere, -1));
}

int near_zero(t_vec3 vec)
{
	double s;

	s= 1e-8;
	if ((fabs(vec.e[0])) < s && (fabs(vec.e[1])) < s && (fabs(vec.e[2]) < s))
		return (1);
	return (0);
}

t_vec3 reflect(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_mul(n, 2*dot(v, n))));
}