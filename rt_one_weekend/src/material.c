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
	t_vec3 unit_direction;
	t_vec3 refracted;

	*attenuation = vec(1.0,1.0,1.0);
	if (rec.front_face != 0)
		ri = (1.0/mat.refraction_index);
	else 
		ri = mat.refraction_index;
	unit_direction = unit_vec(r_in.dir);
	refracted = refract(unit_direction, rec.normal, ri);
	*scattered = par_ray(rec.p, refracted);
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