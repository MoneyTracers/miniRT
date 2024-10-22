#include <rt.h>

int main ()
{
	t_hittable *world;
	t_camera	cam;

	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	world = lstnew(sphere, vec(1, 0, -1), 0.5, metal, vec(0.8, 0.6, 0.2));
	lstadd(&world, lstnew(sphere, vec(-1.0, -0, -1), 0.5, metal, vec(0.8, 0.8, 0.8)));
	lstadd(&world, lstnew(sphere, vec(0, 0, -1.2), 0.5, lambertian, vec(0.1, 0.2, 0.5)));
	lstadd(&world, lstnew(sphere, vec(0, -100.5, -1), 100, lambertian, vec(0.8, 0.8, 0)));

	render(&cam, world);
	return (0);
}
