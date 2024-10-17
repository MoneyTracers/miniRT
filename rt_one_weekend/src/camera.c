#include <rt.h>

t_vec3 ray_color(t_ray ray, int depth, t_hittable *world)
{
	t_hitrecord *rec;
	t_vec3 direction;
	t_vec3 unit_direction;
	double a;

	if (depth <= 0)
		return (dvec());
	rec = calloc(1, sizeof(t_hitrecord));
	if (hit_check(world, ray, inv(0.001, INFINITY), &rec))
	{
		direction = random_on_hemisphere(rec->normal);
		return (vec_mul(ray_color(par_ray(rec->p, direction), depth - 1, world), 0.5));
	}
	unit_direction = unit_vec(ray.dir);
	a = (0.5 * (unit_direction.e[1] + 1.0));
	return (vec_add(vec_mul(vec(1, 1, 1), 1.0 - a), vec_mul(vec(0.5, 0.7, 1.0), a)));
}

void init_cam(t_camera *cam)
{
	t_vec3 viewport_u_half;
	t_vec3 viewport_v_half;

	cam->image_heigth = cam->image_width / cam->aspect_ratio;
	if (cam->image_heigth < 1)
		cam->image_heigth = 1;
	cam->samples_per_pixel = 100;
	cam->pixel_samples_scale = 1.0 / cam->samples_per_pixel;
	cam->max_depth = 50;

	// determine viewport dimension
	cam->focal_length = 1.0;
	cam->viewport_heigth = 2.0;
	cam->viewport_width = cam->viewport_heigth * ((double)cam->image_width / cam->image_heigth);

	// calculate the vectors across horizontal and vertical viewport edges
	cam->viewport_u = vec(cam->viewport_width, 0, 0);
	cam->viewport_v = vec(0, cam->viewport_heigth * -1, 0);

	// calculate the horizontal and vertical delta vectors from pixel to pixel
	cam->pixel_delta_u = vec_div(cam->viewport_u, cam->image_width);
	cam->pixel_delta_v = vec_div(cam->viewport_v, cam->image_heigth);

	// calculate the location of upper left pixel
	cam->viewport_upper_left = vec_sub(cam->center, vec(0, 0, cam->focal_length));
	viewport_u_half = vec_div(cam->viewport_u, 2);
	viewport_v_half = vec_div(cam->viewport_v, 2);
	cam->viewport_upper_left = vec_sub(cam->viewport_upper_left, viewport_u_half);
	cam->viewport_upper_left = vec_sub(cam->viewport_upper_left, viewport_v_half);
	cam->pixel00_loc = vec_add(cam->pixel_delta_u, cam->pixel_delta_u);
	cam->pixel00_loc = vec_add(cam->pixel_delta_u, cam->pixel_delta_u);
	cam->pixel00_loc = vec_div(cam->pixel00_loc, 2);
	cam->pixel00_loc = vec_add(cam->viewport_upper_left, cam->pixel00_loc);
}

t_ray get_ray(t_camera *cam, int i, int j)
{
	t_vec3 offset;
	t_vec3 pixel_sample;
	t_vec3 ray_direction;
	t_ray ray;

	offset = sample_square();
	pixel_sample = vec_add(cam->pixel00_loc, vec_mul(cam->pixel_delta_u, i + offset.e[0]));
	pixel_sample = vec_add(pixel_sample, vec_mul(cam->pixel_delta_v, j + offset.e[1]));
	ray_direction = vec_sub(pixel_sample, cam->center);

	ray.org = cam->center;
	ray.dir = ray_direction;
	return (ray);
}

void render(t_camera *cam, t_hittable *world)
{
	init_cam(cam);
	t_ray ray;
	t_vec3 pixel_color;

	// render
	printf("P3\n");
	printf("%d ", cam->image_width);
	printf("%d", cam->image_heigth);
	printf("\n255\n");

	pixel_color = dvec();
	for (int j = 0; j < cam->image_heigth; j++)
	{
		dprintf(2, "lines remaining %d\n", (cam->image_heigth - j));
		for (int i = 0; i < cam->image_width; i++)
		{
			pixel_color = dvec();
			for (int sample = 0; sample < cam->samples_per_pixel; sample++)
			{
				ray = get_ray(cam, i, j);
				pixel_color = vec_add(pixel_color, ray_color(ray, cam->max_depth, world));
			}
			write_color(vec_mul(pixel_color, cam->pixel_samples_scale));
		}
	}
	dprintf(2, "done\n");
}
