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
	vec3->vmul(vec3, 1/t);
	return (vec3);
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
	len = sqrt(vec3->lensqr(vec3));
	return (sqrt(vec3->lensqr(vec3)));
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
	vec_class_init(&univec);
	len = vec3->len(vec3);
	vec3->copy(&univec, vec3);
	vec3->vdiv(&univec, len);
	return (univec);
}

