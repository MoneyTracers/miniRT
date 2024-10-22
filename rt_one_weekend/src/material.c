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
	*scattered = par_ray(rec.p, reflected);
	*attenuation = mat.color; 
	return (1);
}

t_material init_mat(int type, t_vec3 color)
{
	t_material mat;

	mat.type = type;
	mat.color = color;
	if (type == lambertian)
		mat.scat = &scatter_lamb;
	if (type == metal)
		mat.scat = &scatter_met;
	return (mat);
}