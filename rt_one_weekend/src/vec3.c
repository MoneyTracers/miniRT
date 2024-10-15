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

double VectorLengthSquared(t_vec3	*vec3)
{
	double e0;
	double e1;
	double e2;
	
	e0 = vec3->e[0];
	e1 = vec3->e[1];
	e2 = vec3->e[2];

	return ((e0*e0)+(e1*e1)+(e2*e2));
}

double VectorLength(t_vec3	*vec3)
{
	double len;
	len = sqrt(VectorLengthSquared(vec3));
	return (sqrt(VectorLengthSquared(vec3)));
}

void VectorCopy(t_vec3	*dest, t_vec3	*src)
{
	dest->e[0] = src->e[0];
	dest->e[1] = src->e[1];
	dest->e[2] = src->e[2];
}

void vec_class_init(t_vec3 *vec3)
{
	vec3->def_const = &DefaultVectorConstructor;
	vec3->par_const = &ParamVectorConstructor;
	vec3->minus = &OperatorMinus;
	vec3->get = &OperatorGet;
	vec3->set = &OperatorSet;
	vec3->vadd = &VectorAddition;
	vec3->vded = &VectorDeduction;
	vec3->vmul = &VectorMultiplication;
	vec3->vdiv = &VectorDivide;
	vec3->lensqr = &VectorLengthSquared;
	vec3->len = &VectorLength;
	vec3->copy = &VectorCopy;
}

t_vec3 UnitVector(t_vec3	*vec3)
{
	float len;
	t_vec3 univec;
	len = VectorLength(vec3);
	VectorCopy(&univec, vec3);
	VectorDivide(&univec, len);
	return (univec);
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
