/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/02 12:43:48 by marieke       #+#    #+#                 */
/*   Updated: 2024/10/29 15:02:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

void	free_mlx(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->image);
	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}

void	free_matrix(float **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_intersection(t_intersection **intersection)
{
	t_intersection *cur;
	t_intersection *next;

	if (!intersection || !*intersection)
		return ;
	cur = (*intersection);
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	(*intersection) = NULL;
}

void	free_shapes(t_object **head)
{
	t_object	*cur;
	t_object	*next;

	if (!head || !*head)
		return ;
	cur = (*head);
	while (cur)
	{
		next = cur->next;
		free_matrix(cur->base->transformation.grid, 4);
		if (cur->base->inverted)
		{
			free_matrix(cur->base->inverted->grid, 4);
			free(cur->base->inverted);
		}
		free(cur->base);
		free(cur);
		cur = next;
	}
	(*head) = NULL;
}

void	free_transformation_matrix(t_transformation *transform)
{
	free_matrix(transform->rotate.grid, 4);
	free_matrix(transform->scale.grid, 4);
	free_matrix(transform->translation.grid, 4);
}
