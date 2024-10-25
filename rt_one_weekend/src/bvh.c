/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/25 16:21:02 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int random_int(int min, int max)
{
	return ((int)random_double_between(min, max+1));
}

int	box_compare(t_hittable *a, t_hittable *b, int axis_index)
{
	t_interval a_axis_interval;
	t_interval b_axis_interval;

	a_axis_interval = axis_interval(a->bbox, axis_index);
	b_axis_interval = axis_interval(b->bbox, axis_index);
	// printf("radius %f a min: %f b min: %f\n", a->radius, a_axis_interval.min, b_axis_interval.min);
	return(a_axis_interval.min < b_axis_interval.min);
}

int box_x_compare (t_hittable *a, t_hittable *b)
{
	return (box_compare(a,b,0));
}

int box_y_compare (t_hittable *a, t_hittable *b)
{
	return (box_compare(a,b,1));
}

int box_z_compare (t_hittable *a, t_hittable *b)
{
	return (box_compare(a,b,2));
}

void sort_swap(t_hittable **a, t_hittable **b)
{
	t_hittable *temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void sort(t_hittable ** world, int start, int end, int (*comp) (t_hittable* a, t_hittable* b))
{
	// t_hittable *temp;
	t_hittable *ahead;
	int	out_i;
	int	in_i;

	out_i = start;
	in_i = start;
	// temp = world[start];
	// printf("start: %d end: %d\n", start, end);
	while (world[out_i] != world[end])
	{
		// printf("out_i: %d\n", out_i);
		ahead = world[out_i];
		while (ahead != world[end])
		{
			ahead = world[++in_i];
			// printf("in_i: %d\n", in_i);
			// printf("w[end]:\t%p\nahead:\t%p\n", world[end], ahead);
			if (ahead == NULL)
			break;
			if (comp(ahead, world[out_i]))
				sort_swap(&world[out_i], &world[in_i]);
			// for (unsigned long i = 0; world[i]; i++)
			// {
			// 	t_interval temp;
			// 	temp = axis_interval(world[i]->bbox, 0);
			// 	printf("world[%lu] min: %f\n", i, temp.min);
			// }
		}
		in_i = out_i;
		out_i++;
	}
	return;
}

t_bvh	*bvh_node(t_hittable **world, size_t start, size_t end)
{
	int axis;
	t_bvh *node;
	size_t object_span;
	size_t mid;
	int (*comparator) (t_hittable* a, t_hittable* b);
	
	axis = random_int(0, 2);
	if (axis == 0)
		comparator = &box_x_compare;
	else if (axis == 1)
		comparator = &box_y_compare;
	else 
		comparator = &box_z_compare;
	object_span = end - start;
	// printf("object_span %lu\n", object_span);
	node = calloc(1, sizeof(t_bvh));
	node->left = calloc(1, sizeof(t_bvh));
	node->right = calloc(1, sizeof(t_bvh));
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
	node->bbox = aabb_aabb(node->left->bbox, node->right->bbox);
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