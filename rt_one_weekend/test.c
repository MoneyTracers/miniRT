#include "vec3.h"
#include "color.h"

void	DefaultConstructor(t_vec3* vec3)
{
	vec3->e[0]= 0;
	vec3->e[1]= 0;
	vec3->e[2]= 0;
}

void	ParamConstructor(t_vec3* vec3, double e0, double e1, double e2)
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

	return (e0*e0+e1*e1+e2*e2);
}

double VectorLength(t_vec3	*vec3)
{
	return (sqrt(vec3->lensqr(vec3)));
}

void vec_class_init(t_vec3 *vec3)
{
	vec3->def_const = &DefaultConstructor;
	vec3->par_const = &ParamConstructor;
	vec3->minus = &OperatorMinus;
	vec3->get = &OperatorGet;
	vec3->set = &OperatorSet;
	vec3->vadd = &VectorAddition;
	vec3->vmul = &VectorMultiplication;
	vec3->vdiv = &VectorDivide;
	vec3->lensqr = &VectorLengthSquared;
	vec3->len = &VectorLength;
}

void test ()
{
	t_vec3 vec3;
	t_vec3 nvec3;

	vec_class_init(&vec3);
	vec_class_init(&nvec3);
	vec3.def_const(&vec3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.par_const(&vec3, 1.533, 2, 3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.x = &vec3.e[0];
	vec3.y = &vec3.e[1];
	vec3.z = &vec3.e[2];
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.minus(&vec3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	printf("0 %f \n", vec3.get(&vec3, 0));
	printf("0 %f \n", *vec3.set(&vec3, 0, 10));
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	nvec3.par_const(&nvec3, 10, 10, 10);
	vec3.vadd(&vec3, &nvec3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.vmul(&vec3, 2);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.vdiv(&vec3, 3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	printf("lensqr %f \n", vec3.lensqr(&vec3));
	printf("len %f \n", vec3.len(&vec3));
}

int main ()
{
	t_vec3	vec3;
	int		image_width = 256;
	int		image_height = 256;

	printf("P3\n");
	printf("%d ", image_width);
	printf("%d", image_height);
	printf("\n255\n");
	vec_class_init(&vec3);
	vec3.def_const(&vec3);
	for (int j = 0; j < image_height; j++)
	{
		dprintf(2, "lines remaining %d\n", (image_height - j));
		for (int i = 0; i < image_width; i++)
		{
			vec3.par_const(&vec3, (double)i / (image_width - 1), (double)j / (image_height - 1), 0);
			write_color(&vec3);
		}
	}
	dprintf(2, "done\n");
}
