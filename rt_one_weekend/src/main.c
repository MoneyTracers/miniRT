#include <rt.h>

int main ()
{
	t_hittable	**world;
	t_bvh		*bvh;
	t_camera	cam;
	int			len;
	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	// world = lstnew(sphere, vec(0, -100.5, -1), 100, init_mat(lambertian, vec(0.8, 0.8, 0), 0, 0));
	// lstadd(&world, lstnew(sphere, vec(0, 0, -1.2), 0.5, init_mat(lambertian, vec(0.1, 0.2, 0.5), 0, 0)));
	// lstadd(&world, lstnew(sphere, vec(-1, 0, -1), 0.5, init_mat(dielectric, vec(0, 0, 0), 0, 1.5)));
	// lstadd(&world, lstnew(sphere, vec(-1, 0, -1), 0.4, init_mat(dielectric, vec(0, 0, 0), 0, 1/1.5)));
	// lstadd(&world, lstnew(sphere, vec(1, 0, -1), 0.5, init_mat(metal, vec(0.8, 0.6, 0.2), 1, 0)));
	//TODO: make world array
	world = arraynew(sphere, vec(0, -100.5, 0), 20, init_mat(lambertian, vec(0.8, 0.8, 0), 0, 0)); //! 1
	world = array_add(world, sphere, vec(200, 0, 0), 10, init_mat(lambertian, vec(0.1, 0.2, 0.5), 0, 0)); //! 2
	world = array_add(world, sphere, vec(0, 0, 300), 50, init_mat(dielectric, vec(0, 0, 0), 0, 1.5)); //! 0
	// world = array_add(world, sphere, vec(-1, 0, -1), 0.4, init_mat(dielectric, vec(0, 0, 0), 0, 1/1.5));
	// world = array_add(world, sphere, vec(1, 0, -1), 0.5, init_mat(metal, vec(0.8, 0.6, 0.2), 1, 0));

	len = 0;
	for (unsigned long i = 0; world[i]; i++)
	{
		t_interval temp;
		temp = axis_interval(world[i]->bbox, 0);
		printf("world[%d] min: %f\n",len, temp.min);
		len++;
	}
	
	//TODO:create bvh binary tree
	bvh = bvh_node(world, 0, len);
	exit(0);
	//TODO:pass binary tree struct instead of hittable struct
	// render(&cam, world);
	return (0);
}
