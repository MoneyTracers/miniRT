#include <rt.h>

int main ()
{
	t_hittable *world;
	t_camera	cam;
	t_hittable *temp;

	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	world = lstnew(sphere, vec(1, 0, -1), 0.5, init_mat(metal, vec(0.8, 0.6, 0.2), 0.3));
	lstadd(&world, lstnew(sphere, vec(-1.0, -0, -1), 0.5, init_mat(metal, vec(0.8, 0.8, 0.8), 0.4)));
	lstadd(&world, lstnew(sphere, vec(0, 0, -1.2), 0.5, init_mat(lambertian, vec(0.1, 0.2, 0.5), 0)));
	lstadd(&world, lstnew(sphere, vec(0, -100.5, -1), 100, init_mat(lambertian, vec(0.8, 0.8, 0.0), 0)));
	temp = world;
	// while(temp)
	// {
	// 	printf("list color %f %f %f\n", temp->mat.color.e[0], temp->mat.color.e[1], temp->mat.color.e[2]);
	// 	temp = temp->next;
	// }
	// exit(0);
	render(&cam, world);
	return (0);
}
