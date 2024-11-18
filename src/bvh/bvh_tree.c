/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh_tree.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:40:34 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/18 17:38:59 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <bvh.h>

int	box_compare(t_object *a, t_object *b, int axis_index)
{
	t_interval a_axis_interval;
	t_interval b_axis_interval;

	a_axis_interval = axis_interval(a->bbox, axis_index);
	b_axis_interval = axis_interval(b->bbox, axis_index);
	// printf("radius %f a min: %f b min: %f\n", a->radius, a_axis_interval.min, b_axis_interval.min);
	return(a_axis_interval.min < b_axis_interval.min);
}

int box_x_compare (t_object *a, t_object *b)
{
	return (box_compare(a,b,0));
}

int box_y_compare (t_object *a, t_object *b)
{
	return (box_compare(a,b,1));
}

int box_z_compare (t_object *a, t_object *b)
{
	return (box_compare(a,b,2));
}

int hit(t_object *world ,t_ray ray, t_interval ray_i, t_hitrecord *rec)
{
	(void)world;
	(void)ray;
	(void)ray_i;
	(void)rec;
	
	// t_vec3 oc;
	// t_vec3 outward_normal;
	// t_vec3 current_center;
	// double a;
	// double h;
	// double c;
	// double discriminant;
	// double sqrtd;
	// double root;

	// current_center = ray_at(world->center, world->center.time);
	// oc = vec_sub(current_center, ray.org);
	// a = vec_len_sqr(ray.dir);
	// h = dot(ray.dir, oc);
	// c = vec_len_sqr(oc) - (world->radius*world->radius);
	// discriminant = (h * h) - (a *c);
	// if (discriminant < 0)
	// 	return (0);
	// sqrtd = sqrt(discriminant);
	// root = (h - sqrtd) / a;
	// if (!surround(ray_i, root))
	// {
	// 	root = (h + sqrtd) / a;
	// 	if (!surround(ray_i, root))
	// 		return (0);
	// }
	// rec->t = root;
	// rec->p = ray_at(ray, rec->t);
	// outward_normal = vec_div(vec_sub(rec->p, current_center), world->radius);
	// set_face_normal(&rec, &ray, &outward_normal);
	// rec->mat = world->mat;
	return (1);
}


t_bvh	*bvh_node(t_object **world, size_t start, size_t end)
{
	int axis;
	t_bvh *node;
	size_t object_span;
	size_t mid;
	int (*comparator) (t_object* a, t_object* b);


	node = calloc(1, sizeof(t_bvh));
	node->left = calloc(1, sizeof(t_bvh));
	node->right = calloc(1, sizeof(t_bvh));
	for (size_t i = start; i < end; i++)
	{
		node->bbox = aabb_const(node->bbox, world[i]->bbox);
	}
	axis = longest_axis(node->bbox);
	if (axis == 0)
		comparator = &box_x_compare;
	else if (axis == 1)
		comparator = &box_y_compare;
	else 
		comparator = &box_z_compare;
	object_span = end - start;
	debugger(BLU"object_span %lu\n"RESET, object_span);
	if (object_span == 1)
	{
		node->left->object = world[start];
		node->right->object = world[start];
		node->bbox = world[start]->bbox;
		node->left->bbox = world[start]->bbox;
		node->right->bbox = world[start]->bbox;
		debugger(GRN"object 1 \n"RESET);
		debugger(MAG "span bbox \tx.min: %f x.max: %f\n\
bbox \t\ty.min: %f y.max: %f\n\
bbox \t\tz.min: %f z.max: %f\n"RESET, \
	 node->bbox.x.min, node->bbox.x.max,
	 node->bbox.y.min, node->bbox.y.max,
	 node->bbox.z.min, node->bbox.z.max);
	}
	else if (object_span == 2)
	{
		node->left->object = world[start];
		node->right->object = world[start+1];
		node->left->bbox = world[start]->bbox;
		node->right->bbox = world[start+1]->bbox;
		node->bbox = aabb_const(world[start]->bbox, world[start + 1]->bbox);
		debugger(GRN"object 2 \n"RESET);
		debugger(MAG"span bbox \tx.min: %f x.max: %f\n\
bbox \t\ty.min: %f y.max: %f\n\
bbox \t\tz.min: %f z.max: %f\n"RESET, \
	 node->bbox.x.min, node->bbox.x.max,
	 node->bbox.y.min, node->bbox.y.max,
	 node->bbox.z.min, node->bbox.z.max);
	}
	else
	{
		sort(world, start, end - 1, comparator);
		debugger(YEL"sort array\n"RESET);
		for (unsigned long i = 0; world[i]; i++)
		{
		t_interval temp;
		temp = axis_interval(world[i]->bbox, 0);
		debugger(YEL"world[%lu] min: %f\n"RESET, i, temp.min);
		}
		mid = start + object_span / 2;
		node->left = bvh_node(world, start, mid);
		node->right = bvh_node(world, mid, end);
	}
	debugger(RED"node bbox \tx.min: %f x.max: %f\n\
bbox \t\ty.min: %f y.max: %f\n\
bbox \t\tz.min: %f z.max: %f\n"RESET, \
	 node->bbox.x.min, node->bbox.x.max,
	 node->bbox.y.min, node->bbox.y.max,
	 node->bbox.z.min, node->bbox.z.max);
	return (node);
}

int bvh_hit(t_bvh *node, t_ray r, t_interval ray_t, t_hitrecord *rec)
{
	int hit_left;
	int hit_right;
	if (!aabb_hit(node->bbox, r, ray_t))
		return (0);
	if (node->left->object)
	{
		hit_left = hit(node->left->object, r, ray_t, rec);
		if (hit_left)
			hit_right = hit(node->right->object, r, inv(ray_t.min, rec->t), rec);
		else
			hit_right = hit(node->right->object, r, inv(ray_t.min, ray_t.max), rec);	
		return (hit_left || hit_right);
	}
	else
	{
		hit_left = bvh_hit(node->left, r, ray_t, rec);
		if (hit_left)
			hit_right = bvh_hit(node->right, r, inv(ray_t.min, rec->t), rec);
		else
			hit_right = bvh_hit(node->right, r, inv(ray_t.min, ray_t.max), rec);
		return (hit_left || hit_right);
	}
}
