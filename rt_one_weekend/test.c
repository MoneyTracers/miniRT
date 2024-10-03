#include <stdio.h>
#include <stdarg.h>
#include "vec3.h"

void DefaultConstructor(t_vec3* vec3)
{
	vec3->e[0]= 0;
	vec3->e[1]= 0;
	vec3->e[2]= 0;
}

void ParamConstructor(t_vec3* vec3, double e0, double e1, double e2)
{
	vec3->e[0]= e0;
	vec3->e[1]= e1;
	vec3->e[2]= e2;
}

void OperatorMinus(t_vec3* vec3)
{
	vec3->e[0]= vec3->e[0] * -1;
	vec3->e[1]= vec3->e[1] * -1;
	vec3->e[2]= vec3->e[2] * -1;
}

int main ()
{
	t_vec3 vec3;

	vec3.def_const = &DefaultConstructor;
	vec3.par_const = &ParamConstructor;
	vec3.def_const(&vec3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.par_const(&vec3, 1.533, 2, 3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.x = &vec3.e[0];
	vec3.y = &vec3.e[1];
	vec3.z = &vec3.e[2];
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.minus = &OperatorMinus;
	vec3.minus(&vec3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	// int image_width = 256;
	// int image_height = 256;
	// double r;
	// double g;
	// double b = 0.0;
	// int ir;
	// int ig;
	// int ib;

	// printf("P3\n");
	// printf("%d ", image_width);
	// printf("%d", image_height);
	// printf("\n255\n");

	// for (int j = 0; j < image_height; j++)
	// {
	// 	dprintf(2, "lines remaining %d\n", (image_height - j));
	// 	for (int i = 0; i < image_width; i++)
	// 	{
	// 		r = (double)i / (image_width - 1);
	// 		g = (double)j / (image_height - 1);

	// 		ir = 255.99 * r;
	// 		ig = 255.99 * g;
	// 		ib = 255.99 * b;
	// 		printf("%d %d %d\n", ir, ig, ib);
	// 	}
	// }
}
