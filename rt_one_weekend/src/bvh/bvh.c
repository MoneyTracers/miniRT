/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/24 17:42:13 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <aabb.h>

int random_int(int min, int max)
{
	return ((int)random_double_between(min, max+1));
}

int	box_compare(t_hittable *a, t_hittable *b, int axis_index)
{
	t_interval a_axis_interval;
	t_interval b_axis_interval;

	a_axis_interval = axis_interval(a, axis_index);
	a_axis_interval = axis_interval(b, axis_index);
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

//TODO:add code
void sort(t_hittable *start, t_hittable *end, void (*comp) (t_hittable* a, t_hittable* b))
{
	return;
}

t_bvh	*bvh_node(t_hittable *world, size_t start, size_t end)
{
	int axis;
	t_bvh *node;
	size_t object_span;
	size_t mid;
	void (*comparator) (t_hittable* a, t_hittable* b);
	
	axis = random_int(0, 2);
	if (axis == 0)
		comparator = box_x_compare;
	else if (axis == 1)
		comparator = box_y_compare;
	else 
		comparator = box_z_compare;
	object_span = end - start;
	node = calloc(1, sizeof(t_bvh));
	if (object_span == 1)
	{
		node->left->object = &world[start];
		node->right->object = &world[start];
	}
	else if (object_span == 2)
	{
		node->left = &world[start];
		node->right = &world[start+1];
	}
	else
	{
		sort(&world[start], &world[end], comparator);
		mid = start + object_span / 2;
		node->left = bvh_node(world, start, mid);
		node->right = bvh_node(world, mid, end);
	}
	node->bbox = aabb_aabb(node->left->bbox, node->right->bbox);
	return (node);
}
