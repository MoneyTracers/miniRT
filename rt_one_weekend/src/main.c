#include <rt.h>

void print_image()
{
	t_vec3	vec3;
	int		image_width = 256;
	int		image_height = 256;

	printf("P3\n");
	printf("%d ", image_width);
	printf("%d", image_height);
	printf("\n255\n");
	vec_class_init(&vec3);
	vec3.def_const(&vec3);
	for (int j = 0; j < image_height; j++)
	{
		dprintf(2, "lines remaining %d\n", (image_height - j));
		for (int i = 0; i < image_width; i++)
		{
			vec3.par_const(&vec3, (double)i / (image_width - 1), (double)j / (image_height - 1), 0);
			write_color(&vec3);
		}
	}
	dprintf(2, "done\n");
}

void vec3_test()
{
	t_vec3 vec3;
	t_vec3 nvec3;

	vec_class_init(&vec3);
	vec_class_init(&nvec3);
	vec3.def_const(&vec3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.par_const(&vec3, 1.533, 2, 3);
	printf("e0: %f e1: %f e2: %f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
	vec3.minus(&vec3);
	printf("0 %f \n", vec3.get(&vec3, 0));
	printf("0 %f \n", *vec3.set(&vec3, 0, 10));
	nvec3.par_const(&nvec3, 10, 10, 10);
	vec3.vadd(&vec3, &nvec3);
	vec3.vmul(&vec3, 2);
	vec3.vdiv(&vec3, 3);
	printf("lensqr %f \n", vec3.lensqr(&vec3));
	printf("len %f \n", vec3.len(&vec3));
}


void ray_test()
{
	t_ray	ray;
	t_vec3	*vec_org;
	t_vec3	*vec_dir;
	const t_vec3	*const_org;
	const t_vec3	*const_dir;
	t_vec3	ray_at;

	ray_class_init(&ray);
	ray.def_const(&ray);
	printf("def ray vec %f\n", ray.dir->e[0]);
	vec_dir = malloc(sizeof(t_vec3));
	vec_org = malloc(sizeof(t_vec3));
	vec_class_init(vec_org);
	vec_class_init(vec_dir);
	vec_org->par_const(vec_org, 10, 100, 15);
	vec_dir->par_const(vec_dir, 20, 200, 30);
	ray.par_const(&ray, vec_org, vec_dir);
	printf("par ray vec org %f\n", ray.org->e[0]);
	printf("par ray vec dir %f\n", ray.dir->e[0]);
	const_org = ray.ray_orig(&ray);
	printf("ray ray_org %f\n", const_org->e[0]);
	const_dir = ray.ray_dir(&ray);
	printf("ray dir_org %f\n", const_dir->e[0]);
	printf("ray vec org e[0]: %f e[1]: %f e[2]: %f\n", ray.org->e[0], ray.org->e[1], ray.org->e[2]);
	printf("ray vec dir e[0]: %f e[1]: %f e[2]: %f\n", ray.dir->e[0], ray.dir->e[1], ray.dir->e[2]);
	ray_at = ray.at(&ray, 2);
	printf("ray at e[0] %f e[1] %f e[2] %f\n", ray_at.e[0],ray_at.e[1], ray_at.e[2]);
}
double dot(const t_vec3 *u, const t_vec3 *v)
{
	return ((u->e[0] * v->e[0]) +(u->e[1] * v->e[1])+(u->e[2] * v->e[2]));
}

double hit_sphere(t_vec3 *center, double radius, const t_ray *ray)
{
	t_vec3 oc;
	double a;
	double h;
	double c;
	double discriminant;

	VectorCopy(&oc, center);
	VectorDeduction(&oc, ray->org);
	a = VectorLengthSquared(ray->dir);
	h = dot(ray->dir, &oc);
	c = VectorLengthSquared(&oc) - (radius*radius);
	discriminant = (h * h) - (a *c);
	if (discriminant < 0)
		return (-1.0);
	else
	{
		return ((h - sqrt(discriminant)) / a);
	}
}

t_vec3 ray_color(t_ray *ray)
{
	t_vec3	unit_direction;
	t_vec3	color;
	t_vec3	second_color;
	t_vec3	center;
	t_vec3	N;
	t_vec3	N_cal;
	double	a;
	double	a_mod;
	double	t;

	ParamVectorConstructor(&center, 0, 0, -1);
	t = hit_sphere(&center, 0.5, ray);
	if (t > 0.0)
	{
		N_cal = RayAt(ray, t);
		VectorDeduction(&N_cal, &center);
		N = UnitVector(&N_cal);
		ParamVectorConstructor(&color, (N.e[0]+1), (N.e[1]+1), (N.e[2]+1));
		VectorMultiplication(&color, 0.5);
		return(color);
	}
	unit_direction = UnitVector(ray->dir);
	a = (unit_direction.e[1] + 1.0);
	a = a * 0.5;
	ParamVectorConstructor(&color, 1.0, 1.0, 1.0);
	ParamVectorConstructor(&second_color, 0.5, 0.7, 1.0);
	a_mod = 1.0 - a;
	VectorMultiplication(&color, a_mod);
	VectorMultiplication(&second_color, a);
	VectorAddition(&color, &second_color);
	return (color);
}


void render_basic_image()
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec3	camera_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_u_half;
	t_vec3	viewport_v_half;
	t_vec3	upper_left_focal;
	t_vec3	viewport_upper_left;
	t_vec3	pixel_delta_half;
	t_vec3	pixel00_loc;
	t_vec3	pixel_center;
	t_vec3	pixe_add;
	t_vec3	ray_direction;
	t_ray	ray;
	t_vec3	color;

	// calculate image height
	aspect_ratio = 16.0 / 9.0;
	image_width = 400;
	image_height = image_width / aspect_ratio;
	if (image_height < 1)
		image_height = 1;

	//camera
	focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)image_width/image_height);
	DefaultVectorConstructor(&camera_center);

	// calculate vectors accross the horizontal and vertical viewport edges
	ParamVectorConstructor(&viewport_u, viewport_width, 0, 0);
	ParamVectorConstructor(&viewport_v, 0, viewport_height, 0);
	viewport_v.e[1] = viewport_v.e[1] * -1;
	
	// calculate horizontal and vertical dela vectors from pixel to pixel
	VectorCopy(&pixel_delta_u, &viewport_u);
	VectorDivide(&pixel_delta_u, image_width);
	VectorCopy(&pixel_delta_v, &viewport_v);
	VectorDivide(&pixel_delta_v, image_height);

	//calculate upper left location
	VectorCopy(&viewport_upper_left, &camera_center);
	ParamVectorConstructor(&upper_left_focal, 0, 0, focal_length);
	VectorCopy(&viewport_u_half, &viewport_u);
	VectorCopy(&viewport_v_half, &viewport_v);
	VectorDivide(&viewport_u_half, 2);
	VectorDivide(&viewport_v_half, 2);
	VectorDeduction(&viewport_upper_left, &upper_left_focal);
	VectorDeduction(&viewport_upper_left, &viewport_u_half);
	VectorDeduction(&viewport_upper_left, &viewport_v_half);
	VectorCopy(&pixel_delta_half, &pixel_delta_u);
	VectorAddition(&pixel_delta_half, &pixel_delta_v);
	VectorMultiplication(&pixel_delta_half, 0.5);
	VectorCopy(&pixel00_loc, &viewport_upper_left);
	VectorAddition(&pixel00_loc, &pixel_delta_half);


	//render 
	printf("P3\n");
	printf("%d ", image_width);
	printf("%d", image_height);
	printf("\n255\n");

	for (int j = 0; j < image_height; j++)
	{
		dprintf(2, "lines remaining %d\n", (image_height - j));
		for (int i = 0; i < image_width; i++)
		{
			VectorCopy(&pixel_center, &pixel00_loc);
			VectorCopy(&pixe_add, &pixel_delta_u);
			VectorMultiplication(&pixe_add, i);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&pixe_add, &pixel_delta_v);
			VectorMultiplication(&pixe_add, j);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&ray_direction, &pixel_center);
			VectorDeduction(&ray_direction, &camera_center);
			ParamRayConstructor(&ray, &camera_center, &ray_direction);
			color = ray_color(&ray);
			write_color(&color);
		}
	}
	dprintf(2, "done\n");


}


t_vec3 ray_color_hittable(t_ray *ray, t_hittable *world)
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

void render_image_hittable()
{
	t_hittable *world;
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_vec3	center;
	t_vec3	camera_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_u_half;
	t_vec3	viewport_v_half;
	t_vec3	upper_left_focal;
	t_vec3	viewport_upper_left;
	t_vec3	pixel_delta_half;
	t_vec3	pixel00_loc;
	t_vec3	pixel_center;
	t_vec3	pixe_add;
	t_vec3	ray_direction;
	t_ray	ray;
	t_vec3	color;

	// calculate image height
	aspect_ratio = 16.0 / 9.0;
	image_width = 400;
	image_height = image_width / aspect_ratio;
	if (image_height < 1)
		image_height = 1;


	//world 
	ParamVectorConstructor(&center, 0, -100.5, -1);
	world = lstnew(sphere, &center, 100);
	ParamVectorConstructor(&center, 0, 0, -1);
	lstadd(&world, lstnew(sphere, &center, 0.5));

	//camera
	focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)image_width/image_height);
	DefaultVectorConstructor(&camera_center);

	// calculate vectors accross the horizontal and vertical viewport edges
	ParamVectorConstructor(&viewport_u, viewport_width, 0, 0);
	ParamVectorConstructor(&viewport_v, 0, viewport_height, 0);
	viewport_v.e[1] = viewport_v.e[1] * -1;
	
	// calculate horizontal and vertical dela vectors from pixel to pixel
	VectorCopy(&pixel_delta_u, &viewport_u);
	VectorDivide(&pixel_delta_u, image_width);
	VectorCopy(&pixel_delta_v, &viewport_v);
	VectorDivide(&pixel_delta_v, image_height);

	//calculate upper left location
	VectorCopy(&viewport_upper_left, &camera_center);
	ParamVectorConstructor(&upper_left_focal, 0, 0, focal_length);
	VectorCopy(&viewport_u_half, &viewport_u);
	VectorCopy(&viewport_v_half, &viewport_v);
	VectorDivide(&viewport_u_half, 2);
	VectorDivide(&viewport_v_half, 2);
	VectorDeduction(&viewport_upper_left, &upper_left_focal);
	VectorDeduction(&viewport_upper_left, &viewport_u_half);
	VectorDeduction(&viewport_upper_left, &viewport_v_half);
	VectorCopy(&pixel_delta_half, &pixel_delta_u);
	VectorAddition(&pixel_delta_half, &pixel_delta_v);
	VectorMultiplication(&pixel_delta_half, 0.5);
	VectorCopy(&pixel00_loc, &viewport_upper_left);
	VectorAddition(&pixel00_loc, &pixel_delta_half);


	//render 
	printf("P3\n");
	printf("%d ", image_width);
	printf("%d", image_height);
	printf("\n255\n");

	for (int j = 0; j < image_height; j++)
	{
		dprintf(2, "lines remaining %d\n", (image_height - j));
		for (int i = 0; i < image_width; i++)
		{
			VectorCopy(&pixel_center, &pixel00_loc);
			VectorCopy(&pixe_add, &pixel_delta_u);
			VectorMultiplication(&pixe_add, i);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&pixe_add, &pixel_delta_v);
			VectorMultiplication(&pixe_add, j);
			VectorAddition(&pixel_center, &pixe_add);
			VectorCopy(&ray_direction, &pixel_center);
			VectorDeduction(&ray_direction, &camera_center);
			ParamRayConstructor(&ray, &camera_center, &ray_direction);
			color = ray_color_hittable(&ray, world);
			write_color(&color);
		}
	}
	dprintf(2, "done\n");
}


void render_image_hittable_camera()
{
	t_hittable *world;
	t_camera	cam;
	t_vec3		center;

	// calculate image height
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;

	//world 
	//TODO: make lst new able to do without malloced vec
	ParamVectorConstructor(&center, 0, -100.5, -1);
	world = lstnew(sphere, &center, 100);
	ParamVectorConstructor(&center, 0, 0, -1);
	lstadd(&world, lstnew(sphere, &center, 0.5));

	render(&cam, world);

}

int main ()
{
	// ray_test();
	// vec3_test();
	// print_image();
	// render_basic_image();
	render_image_hittable();
	render_image_hittable_camera();
	return (0);
}
