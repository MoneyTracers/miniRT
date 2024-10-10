#include "ray.h"
#include "vec3.h"
#include "color.h"

void	DefaultVectorConstructor(t_vec3* vec3)
{
	vec3->e[0]= 0;
	vec3->e[1]= 0;
	vec3->e[2]= 0;
}

void	ParamVectorConstructor(t_vec3* vec3, double e0, double e1, double e2)
{
	vec3->e[0]= e0;
	vec3->e[1]= e1;
	vec3->e[2]= e2;
}

void	OperatorMinus(t_vec3* vec3)
{
	vec3->e[0]= vec3->e[0] * -1;
	vec3->e[1]= vec3->e[1] * -1;
	vec3->e[2]= vec3->e[2] * -1;
}
double	OperatorGet(t_vec3* vec3, int i)
{
	return (vec3->e[i]);
}
double	*OperatorSet(t_vec3* vec3, int i, double value)
{
	vec3->e[i] = value;
	return (&vec3->e[i]);
}

t_vec3* VectorAddition(t_vec3	*vec3, t_vec3	*nvec)
{
	vec3->e[0] += nvec->e[0];
	vec3->e[1] += nvec->e[1];
	vec3->e[2] += nvec->e[2];
	return (vec3);
}

t_vec3* VectorDeduction(t_vec3	*vec3, t_vec3	*nvec)
{
	// printf("here\n");
	vec3->e[0] -= nvec->e[0];
	// printf("%f\n", vec3->e[0]);
	vec3->e[1] -= nvec->e[1];
	// printf("%f\n", vec3->e[1]);
	vec3->e[2] -= nvec->e[2];
	// printf("%f\n", vec3->e[2]);
return (vec3);
}

t_vec3* VectorMultiplication(t_vec3	*vec3, double t)
{
	vec3->e[0] *= t;
	vec3->e[1] *= t;
	vec3->e[2] *= t;
	return (vec3);
}

t_vec3* VectorDivide(t_vec3	*vec3, double t)
{
	vec3->vmul(vec3, 1/t);
	return (vec3);
}

double VectorLengthSquared(t_vec3	*vec3)
{
	double e0;
	double e1;
	double e2;
	
	e0 = vec3->e[0];
	e1 = vec3->e[1];
	e2 = vec3->e[2];

	return ((e0*e0)+(e1*e1)+(e2*e2));
}

double VectorLength(t_vec3	*vec3)
{
	double len;
	len = sqrt(vec3->lensqr(vec3));
	return (sqrt(vec3->lensqr(vec3)));
}

void VectorCopy(t_vec3	*dest, t_vec3	*src)
{
	dest->e[0] = src->e[0];
	dest->e[1] = src->e[1];
	dest->e[2] = src->e[2];
}



void vec_class_init(t_vec3 *vec3)
{
	vec3->def_const = &DefaultVectorConstructor;
	vec3->par_const = &ParamVectorConstructor;
	vec3->minus = &OperatorMinus;
	vec3->get = &OperatorGet;
	vec3->set = &OperatorSet;
	vec3->vadd = &VectorAddition;
	vec3->vded = &VectorDeduction;
	vec3->vmul = &VectorMultiplication;
	vec3->vdiv = &VectorDivide;
	vec3->lensqr = &VectorLengthSquared;
	vec3->len = &VectorLength;
	vec3->copy = &VectorCopy;
}

t_vec3 UnitVector(t_vec3	*vec3)
{
	float len;
	t_vec3 univec;
	vec_class_init(&univec);
	len = vec3->len(vec3);
	vec3->copy(&univec, vec3);
	vec3->vdiv(&univec, len);
	return (univec);
}


void DefaultRayConstructor(t_ray *ray)
{
	t_vec3 *dir;
	t_vec3 *orig;

	dir = malloc(sizeof(t_vec3));
	orig = malloc(sizeof(t_vec3));
	vec_class_init(dir);
	vec_class_init(orig);
	dir->def_const(dir);
	ray->dir = dir;
	orig->def_const(orig);
	ray->org = orig;
}

void ParamRayConstructor(t_ray *ray, t_vec3 *org, t_vec3 *dir)
{
	ray->dir = dir;
	ray->org = org;
}

const t_vec3* RayOrigin(t_ray *ray)
{
	return((const t_vec3*)ray->org);
}

const t_vec3* RayDirection(t_ray *ray)
{
	return((const t_vec3*)ray->dir);
}

t_vec3 RayAt(t_ray *ray, double t)
{
	t_vec3 vec;
	vec_class_init(&vec);
	vec.copy(&vec, ray->dir);
	vec.vmul(&vec, t);
	vec.vadd(&vec, ray->org);
	return (vec);
}

void ray_class_init(t_ray *ray)
{
	ray->def_const = &DefaultRayConstructor;
	ray->par_const = &ParamRayConstructor;
	ray->ray_orig = &RayOrigin;
	ray->ray_dir = &RayDirection;
	ray->at = &RayAt;
}

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
	vec3.x = &vec3.e[0];
	vec3.y = &vec3.e[1];
	vec3.z = &vec3.e[2];
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.minus(&vec3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	printf("0 %f \n", vec3.get(&vec3, 0));
	printf("0 %f \n", *vec3.set(&vec3, 0, 10));
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	nvec3.par_const(&nvec3, 10, 10, 10);
	vec3.vadd(&vec3, &nvec3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.vmul(&vec3, 2);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
	vec3.vdiv(&vec3, 3);
	printf("x: %f y: %f z: %f\n", *vec3.x, *vec3.y, *vec3.z);
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
	double b;
	double c;
	double discriminant;

	vec_class_init(&oc);
	oc.copy(&oc, center);
	oc.vded(&oc, ray->org);
	a = dot(ray->dir, ray->dir);
	b = -2.0 * dot(ray->dir, &oc);
	c = dot(&oc, &oc) - (radius*radius);
	discriminant = (b * b) - (4 *a *c);
	if (discriminant < 0)
		return (-1.0);
	else
	{
		return (((b * -1) - sqrt(discriminant)) / (2.0 *a));
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

	vec_class_init(&unit_direction);
	vec_class_init(&color);
	vec_class_init(&center);
	vec_class_init(&second_color);
	vec_class_init(&N);
	vec_class_init(&N_cal);
	center.par_const(&center, 0, 0, -1);
	t = hit_sphere(&center, 0.5, ray);
	if (t > 0.0)
	{
		N_cal = ray->at(ray, t);
		// printf("N_cal e[0] %f N_cal e[1] %f N_cal e[2] %f\n", N_cal.e[0],N_cal.e[1],N_cal.e[2]);
		// printf("center e[0] %f center e[1] %f center e[2] %f\n", center.e[0],center.e[1],center.e[2]);
		N_cal.vded(&N_cal, &center);
		// printf("N_cal e[0] %f N_cal e[1] %f N_cal e[2] %f\n", N_cal.e[0],N_cal.e[1],N_cal.e[2]);
		N = UnitVector(&N_cal);
		// printf("N e[0] %f N e[1] %f N e[2] %f\n", N.e[0],N.e[1],N.e[2]);
		color.par_const(&color, (N.e[0]+1), (N.e[1]+1), (N.e[2]+1));
		// printf("color e[0] %f color e[1] %f color e[2] %f\n", color.e[0],color.e[1],color.e[2]);
		color.vmul(&color, 0.5);
		// printf("color e[0] %f color e[1] %f color e[2] %f\n", color.e[0],color.e[1],color.e[2]);
		return(color);
	}
	unit_direction = UnitVector(ray->dir);
	a = (unit_direction.e[1] + 1.0);
	a = a * 0.5;
	// printf("unit_direction.e[1]: %f a : %f\n", unit_direction.e[1], a);
	color.par_const(&color, 1.0, 1.0, 1.0);
	second_color.par_const(&second_color, 0.5, 0.7, 1.0);
	a_mod = 1.0 - a;
	color.vmul(&color, a_mod);
	second_color.vmul(&second_color, a);
	color.vadd(&color, &second_color);
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
	vec_class_init(&camera_center);
	camera_center.def_const(&camera_center);

	// calculate vectors accross the horizontal and vertical viewport edges
	vec_class_init(&viewport_u);
	vec_class_init(&viewport_v);
	viewport_u.par_const(&viewport_u, viewport_width, 0, 0);
	viewport_v.par_const(&viewport_v, 0, viewport_height, 0);
	viewport_v.e[1] = viewport_v.e[1] * -1;
	
	// calculate horizontal and vertical dela vectors from pixel to pixel
	vec_class_init(&pixel_delta_u);
	vec_class_init(&pixel_delta_v);
	pixel_delta_u.copy(&pixel_delta_u, &viewport_u);
	pixel_delta_u.vdiv(&pixel_delta_u, image_width);
	pixel_delta_v.copy(&pixel_delta_v, &viewport_v);
	pixel_delta_v.vdiv(&pixel_delta_v, image_height);

	//calculate upper left location
	vec_class_init(&viewport_upper_left);
	vec_class_init(&viewport_u_half);
	vec_class_init(&viewport_v_half);
	vec_class_init(&pixel00_loc);
	vec_class_init(&pixel_delta_half);
	vec_class_init(&upper_left_focal);
	viewport_upper_left.copy(&viewport_upper_left, &camera_center);
	upper_left_focal.par_const(&upper_left_focal, 0, 0, focal_length);
	viewport_u_half.copy(&viewport_u_half, &viewport_u);
	viewport_v_half.copy(&viewport_v_half, &viewport_v);
	viewport_u_half.vdiv(&viewport_u_half, 2);
	viewport_v_half.vdiv(&viewport_v_half, 2);
	viewport_upper_left.vded(&viewport_upper_left, &upper_left_focal);
	viewport_upper_left.vded(&viewport_upper_left, &viewport_u_half);
	viewport_upper_left.vded(&viewport_upper_left, &viewport_v_half);
	pixel_delta_half.copy(&pixel_delta_half, &pixel_delta_u);
	pixel_delta_half.vadd(&pixel_delta_half, &pixel_delta_v);
	pixel_delta_half.vmul(&pixel_delta_half, 0.5);
	pixel00_loc.copy(&pixel00_loc, &viewport_upper_left);
	pixel00_loc.vadd(&pixel00_loc, &pixel_delta_half);


	//render 
	vec_class_init(&pixel_center);
	vec_class_init(&pixe_add);
	vec_class_init(&ray_direction);
	vec_class_init(&color);
	ray_class_init(&ray);

	printf("P3\n");
	printf("%d ", image_width);
	printf("%d", image_height);
	printf("\n255\n");

	for (int j = 0; j < image_height; j++)
	{
		dprintf(2, "lines remaining %d\n", (image_height - j));
		for (int i = 0; i < image_width; i++)
		{
			// printf("pixelloc_00 e[0] %f e[1] %f e[2] %f\n", pixel00_loc.e[0], pixel00_loc.e[1], pixel00_loc.e[2]);
			pixel_center.copy(&pixel_center, &pixel00_loc);
			pixe_add.copy(&pixe_add, &pixel_delta_u);
			// printf("pixe_add e[0] %f e[1] %f e[2] %f\n", pixe_add.e[0], pixe_add.e[1], pixe_add.e[2]);
			pixe_add.vmul(&pixe_add, i);
			// printf("pixe_add e[0] %f e[1] %f e[2] %f\n", pixe_add.e[0], pixe_add.e[1], pixe_add.e[2]);
			pixel_center.vadd(&pixel_center, &pixe_add);
			pixe_add.copy(&pixe_add, &pixel_delta_v);
			// printf("pixe_delta_v e[0] %f e[1] %f e[2] %f\n", pixel_delta_v.e[0], pixel_delta_v.e[1], pixe_add.e[2]);
			// printf("pixe_add e[0] %f e[1] %f e[2] %f\n", pixe_add.e[0], pixe_add.e[1], pixe_add.e[2]);
			pixe_add.vmul(&pixe_add, j);
			pixel_center.vadd(&pixel_center, &pixe_add);
			// printf("pixel_Center e[0] %f e[1] %f e[2] %f\n", pixel_center.e[0], pixel_center.e[1], pixel_center.e[2]);
			ray_direction.copy(&ray_direction, &pixel_center);
			// printf("ray_direction e[0] %f e[1] %f e[2] %f\n", ray_direction.e[0], ray_direction.e[1], ray_direction.e[2]);
			ray_direction.vded(&ray_direction, &camera_center);
			ray.par_const(&ray, &camera_center, &ray_direction);
			color = ray_color(&ray);
			write_color(&color);
		}
	}
	dprintf(2, "done\n");


}

int main ()
{
	// ray_test();
	// vec3_test();
	// print_image();
	render_basic_image();
	return (0);
}
