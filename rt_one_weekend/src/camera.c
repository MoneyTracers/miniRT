#include <rt.h>

//TODO: reduce amount of variables and funtion calls here
t_vec3 ray_color_camera(t_ray *ray, t_hittable *world)
{
	t_hitrecord *rec;
	t_vec3		hit_vec;
	t_vec3		unit_direction;
	t_vec3		color;
	t_vec3		color_mul;
	double		a;

	rec = calloc(1, sizeof(t_hitrecord));
	if (hit_check(world, ray, inv(0, INFINITY), &rec))
	{
		ParamVectorConstructor(&hit_vec, 1, 1 ,1);
		VectorAddition(&rec->normal, &hit_vec);
		VectorMultiplication(&rec->normal, 0.5);
		return (rec->normal);
	}
	unit_direction = UnitVector(ray->dir);
	a = (0.5*(unit_direction.e[1] + 1.0));
	ParamVectorConstructor(&color, 1.0, 1.0, 1.0);
	VectorMultiplication(&color, (1.0 - a));
	ParamVectorConstructor(&color_mul, 0.5, 0.7, 1.0);
	VectorMultiplication(&color, a);
	VectorAddition(&color, &color_mul);
	return (color);
}

void init_cam(t_camera *cam)
{
	t_vec3 viewport_u_half;
	t_vec3 viewport_v_half;

	cam->image_heigth = cam->image_width / cam->aspect_ratio;
	if (cam->image_heigth < 1)
		cam->image_heigth = 1;

	//determine viewport dimension
	cam->focal_length = 1.0;
	cam->viewport_heigth = 2.0;
	cam->viewport_width = cam->viewport_heigth * ((double)cam->image_width/cam->image_heigth);

	//calculate the vectors across horizontal and vertical viewport edges
	cam->viewport_u = vec(cam->viewport_width, 0, 0);
	cam->viewport_v = vec(0, cam->viewport_heigth * -1,0);
	
	//calculate the horizontal and vertical delta vectors from pixel to pixel
	cam->pixel_delta_u = vec_div(cam->viewport_u, cam->image_width);
	cam->pixel_delta_v = vec_div(cam->viewport_v, cam->image_heigth);

	//calculate the location of upper left pixel
	cam->viewport_upper_left = vec_sub(cam->center, vec(0, 0, cam->focal_length));
	VectorCopy(&viewport_u_half, &cam->viewport_u);
	viewport_u_half = vec_div(viewport_u_half, 2);
	VectorCopy(&viewport_v_half, &cam->viewport_v);
	viewport_v_half = vec_div(viewport_v_half, 2);
	cam->viewport_upper_left = vec_sub(cam->viewport_upper_left, viewport_u_half);
	cam->viewport_upper_left = vec_sub(cam->viewport_upper_left, viewport_v_half);
	cam->pixel00_loc = vec_add(cam->pixel_delta_u, cam->pixel_delta_u);
	cam->pixel00_loc = vec_add(cam->pixel_delta_u, cam->pixel_delta_u);
	VectorDivide(&cam->pixel00_loc, 2);
	cam->pixel00_loc = vec_add(cam->viewport_upper_left, cam->pixel00_loc);
}

//TODO: reduce amount of variables and funtion calls here
void render(t_camera *cam, t_hittable *world)
{
	init_cam(cam);
	t_vec3	color;
	t_vec3	pixe_add;
	t_vec3	pixel_center;
	t_vec3	ray_direction;
	t_vec3	camera_center;
	t_ray	ray;

	//render 
	printf("P3\n");
	printf("%d ", cam->image_width);
	printf("%d", cam->image_heigth);
	printf("\n255\n");

	for (int j = 0; j < cam->image_heigth; j++)
	{
		dprintf(2, "lines remaining %d\n", (cam->image_heigth - j));
		for (int i = 0; i < cam->image_width; i++)
		{
			VectorCopy(&pixel_center, &cam->pixel00_loc);
			VectorCopy(&pixe_add, &cam->pixel_delta_u);
			VectorMultiplication(&pixe_add, i);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&pixe_add, &cam->pixel_delta_v);
			VectorMultiplication(&pixe_add, j);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&ray_direction, &pixel_center);
			VectorDeduction(&ray_direction, &camera_center);
			ParamRayConstructor(&ray, &camera_center, &ray_direction);
			color = ray_color_camera(&ray, world);
			write_color(&color);
		}
	}
	dprintf(2, "done\n");
}
