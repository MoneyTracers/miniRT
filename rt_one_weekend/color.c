#include "vec3.h"
#include "color.h"

void write_color(t_vec3 *vec3)
{
	int rbyte;
	int gbyte;
	int bbyte;
	
	rbyte = 255.99*(vec3->e[0]);
	gbyte = 255.99*(vec3->e[1]);
	bbyte = 255.99*(vec3->e[2]);
	printf("%d %d %d\n", rbyte, gbyte, bbyte);
}
