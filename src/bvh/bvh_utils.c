/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:43:59 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:44:04 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int random_int(int min, int max)
{
	return ((int)random_double_between(min, max+1));
}
void sort_swap(t_object **a, t_object **b)
{
	t_object *temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void sort(t_object ** world, int start, int end, int (*comp) (t_object* a, t_object* b))
{
	// t_object *temp;
	t_object *ahead;
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


int longest_axis(t_aabb bbox)
{
	if (size(bbox.x) > size(bbox.y))
	{
		if (size(bbox.x) > size(bbox.z))
			return (0);
		else
			return (2);
	}
	else 
	{
		if (size(bbox.y) > size(bbox.z))
			return (1);
		else 
			return (2);
	}
}