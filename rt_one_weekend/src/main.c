#include <rt.h>

int main ()
{
	t_hittable *world;
	t_camera	cam;
	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	world = lstnew(sphere, vec(0, -100.5, -1), 100, init_mat(lambertian, vec(0.8, 0.8, 0), 0, 0));
	lstadd(&world, lstnew(sphere, vec(0, 0, -1.2), 0.5, init_mat(lambertian, vec(0.1, 0.2, 0.5), 0, 0)));
	lstadd(&world, lstnew(sphere, vec(-1, 0, -1), 0.5, init_mat(dielectric, vec(0, 0, 0), 0, 1.5)));
	lstadd(&world, lstnew(sphere, vec(-1, 0, -1), 0.4, init_mat(dielectric, vec(0, 0, 0), 0, 1/1.5)));
	lstadd(&world, lstnew(sphere, vec(1, 0, -1), 0.5, init_mat(metal, vec(0.8, 0.6, 0.2), 1, 0)));
	render(&cam, world);
	return (0);
}
