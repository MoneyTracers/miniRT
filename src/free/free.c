/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:43:48 by marieke           #+#    #+#             */
/*   Updated: 2024/11/06 13:42:19 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <free.h>
#include <mlx.h>

void	free_mlx(t_mlx *data)
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

void	free_objects(t_object **head)
{
	t_object	*cur;
	t_object	*next;

	if (!head || !*head)
		return ;
	cur = (*head);
	while (cur)
	{
		next = cur->next;
		free_matrix(cur->transformation.grid, 4);
		if (cur->inverted)
		{
			free_matrix(cur->inverted->grid, 4);
			free(cur->inverted);
		}
		if (cur->type == CYLINDER || cur->type == CONE)
			free(cur->cylinder);
		if (cur->type == PLANE)
			free(cur->plane);
		if (cur->type == SPHERE)
			free(cur->sphere);
		free(cur);
		cur = next;
	}
	(*head) = NULL;
}

void	free_lights(t_light **head)
{
	t_light	*cur;
	t_light	*tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

void	free_transformation_matrix(t_transformation *transform)
{
	free_matrix(transform->rotate.grid, 4);
	free_matrix(transform->scale.grid, 4);
	free_matrix(transform->translation.grid, 4);
}
