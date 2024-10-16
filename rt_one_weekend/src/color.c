#include <rt.h>

void write_color(t_vec3 vec3)
{
	int rbyte;
	int gbyte;
	int bbyte;
	static t_interval intensity;
	intensity = inv(0.000, 0.999);
	rbyte = (int)256*(clamp(intensity, vec3.e[0]));
	gbyte = (int)256*(clamp(intensity, vec3.e[1]));
	bbyte = (int)256*(clamp(intensity, vec3.e[2]));
	printf("%d %d %d\n", rbyte, gbyte, bbyte);
}
