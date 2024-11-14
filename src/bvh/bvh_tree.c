/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh_tree.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:40:34 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:47:07 by mynodeus      ########   odam.nl         */
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
		node->bbox = aabb_aabb(node->bbox, world[i]->bbox);
	}
	axis = longest_axis(node->bbox);
	if (axis == 0)
		comparator = &box_x_compare;
	else if (axis == 1)
		comparator = &box_y_compare;
	else 
		comparator = &box_z_compare;
	object_span = end - start;
	// printf("object_span %lu\n", object_span);
	if (object_span == 1)
	{
		node->left->object = world[start];
		node->right->object = world[start];
		node->bbox = world[start]->bbox;
		node->left->bbox = world[start]->bbox;
		node->right->bbox = world[start]->bbox;
	// 	printf("object 1 span bbox x.min: %f x.max: %f\n\
	// bbox y.min: %f y.max: %f\n, \
	// bbox z.min: %f z.max: %f\n", \
	//  node->bbox.x.min, node->bbox.x.max,
	//  node->bbox.y.min, node->bbox.y.max,
	//  node->bbox.z.min, node->bbox.z.max);
	}
	else if (object_span == 2)
	{
		node->left->object = world[start];
		node->right->object = world[start+1];
		node->left->bbox = world[start]->bbox;
		node->right->bbox = world[start+1]->bbox;
		node->bbox = aabb_aabb(world[start]->bbox, world[start + 1]->bbox);
	// 	printf("object 2 span bbox x.min: %f x.max: %f\n\
	// bbox y.min: %f y.max: %f\n, \
	// bbox z.min: %f z.max: %f\n", \
	//  node->bbox.x.min, node->bbox.x.max,
	//  node->bbox.y.min, node->bbox.y.max,
	//  node->bbox.z.min, node->bbox.z.max);
	}
	else
	{
		sort(world, start, end - 1, comparator);
		// for (unsigned long i = 0; world[i]; i++)
		// {
		// t_interval temp;
		// temp = axis_interval(world[i]->bbox, 0);
		// printf("world[%lu] min: %f\n", i, temp.min);
		// }
		// exit (0);
		mid = start + object_span / 2;
		node->left = bvh_node(world, start, mid);
		node->right = bvh_node(world, mid, end);
	}
	// printf("node bbox x.min: %f x.max: %f\n\
	// bbox y.min: %f y.max: %f\n, \
	// bbox z.min: %f z.max: %f\n", \
	//  node->bbox.x.min, node->bbox.x.max,
	//  node->bbox.y.min, node->bbox.y.max,
	//  node->bbox.z.min, node->bbox.z.max);
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
