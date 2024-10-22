#include <rt.h>

int main ()
{
	t_hittable *world;
	t_camera	cam;
	double 		r;
	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	r = cos(pi/4);
	//world 
	world = lstnew(sphere, vec(r * -1, 0, -1), r, init_mat(lambertian, vec(0, 0, 1), 0, 0));
	lstadd(&world, lstnew(sphere, vec(r, 0, -1), r, init_mat(lambertian, vec(1, 0, 0), 0, 0)));
	render(&cam, world);
	return (0);
}
