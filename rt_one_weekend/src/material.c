#include <rt.h>

int scatter_lamb(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3 scatter_direction;

	(void)r_in;
	scatter_direction = vec_add(rec.normal, random_unit_vec());
	if (near_zero(scatter_direction))
		scatter_direction = rec.normal;
	*scattered = par_ray(rec.p, scatter_direction);
	*attenuation = mat.color;
	return (1);
}

int scatter_met(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3 reflected;
	reflected = reflect(r_in.dir, rec.normal);
	reflected = vec_add(unit_vec(reflected), vec_mul(random_unit_vec(), mat.fuzz));
	*scattered = par_ray(rec.p, reflected);
	*attenuation = mat.color; 
	return (1);
}

int scatter_die(t_material mat, t_ray r_in, t_hitrecord rec, t_vec3 *attenuation, t_ray *scattered)
{
	double ri;
	double cos_theta;
	double sin_theta;
	t_vec3 unit_direction;
	t_vec3 direction;

	*attenuation = vec(1.0,1.0,1.0);
	if (rec.front_face != 0)
		ri = (1.0/mat.refraction_index);
	else 
		ri = mat.refraction_index;
	unit_direction = unit_vec(r_in.dir);
	cos_theta = fmin(dot(vec_mul(unit_direction, -1), rec.normal), 1);
	sin_theta = sqrt(1.0 - cos_theta*cos_theta);

	if (ri * sin_theta > 1.0 || reflectance(cos_theta, ri) > random_double())
		direction = reflect(unit_direction, rec.normal);
	else
		direction = refract(unit_direction, rec.normal, ri);
	*scattered = par_ray(rec.p, direction);
	return (1);
}

t_material init_mat(int type, t_vec3 color, double fuzz, double refraction_index)
{
	t_material mat;

	mat.type = type;
	mat.color = color;
	if (type == lambertian)
		mat.scat = &scatter_lamb;
	if (type == metal)
		mat.scat = &scatter_met;
	if (type == dielectric)
		mat.scat = &scatter_die;
	if (fuzz > 1)
		mat.fuzz = 1;
	else
		mat.fuzz = fuzz;
	mat.refraction_index = refraction_index;
	return (mat);
}