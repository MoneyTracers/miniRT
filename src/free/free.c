/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:43:48 by marieke           #+#    #+#             */
/*   Updated: 2024/12/03 13:59:26 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <free.h>
#include <mlx.h>

void	free_mlx(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->img1.image);
	mlx_destroy_image(data->mlx, data->img2.image);
	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}

void	free_intersection(t_intersect **intersection)
{
	t_intersect	*cur;
	t_intersect	*next;

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

void	free_minirt(t_world *world)
{
	free_objects(&world->objects);
	free_lights(&world->lights);
	free_mlx(world->mlx_data);
}