#include <rt.h>

int main ()
{
	t_hittable *world;
	t_camera	cam;

	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	world = lstnew(sphere, vec(0, -100.5, -1), 100);
	lstadd(&world, lstnew(sphere, vec(0, 0, -1), 0.5));

	render(&cam, world);
	return (0);
}
