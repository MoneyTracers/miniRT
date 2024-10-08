/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_coords.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:49:54 by spenning          #+#    #+#             */
/*   Updated: 2024/05/20 17:46:59 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	map_init_coords_values_vc_clr(t_data *data, char **b, int r, int c)
{
	int	clr;
	int	len;

	clr = trgb(0, 255, 255, 255);
	len = ft_strlen(b[1]);
	ft_debug("&b[1][2] %s\n", &b[1][2]);
	ft_debug("&b[1][4] %s\n", &b[1][4]);
	ft_debug("&b[1][6] %s\n", &b[1][6]);
	(void)len;
	if (len == 4 || len == 5)
		clr = trgb(0, nhti(&b[1][2], 2), 255, 255);
	if (len == 6 || len == 7)
		clr = trgb(0, nhti(&b[1][2], 2), nhti(&b[1][4], 2), 255);
	if (len == 8 || len == 9)
		clr = trgb(0, nhti(&b[1][2], 2), nhti(&b[1][4], 2), nhti(&b[1][6], 2));
	data->map[r][c] = ft_atoi(b[0]);
	data->map_color[r][c] = clr;
}

void	map_init_coords_values_vc_dft(t_data *data, char *buf, int r, int c)
{
	ft_debug("r %d c %d\n", r, c);
	ft_debug("map_init_coords_values_vc_dft buf %s\n", buf);
	data->map[r][c] = ft_atoi(buf);
	ft_debug("map_init_crds_values_vc_dft tgrb %d\n", trgb(0, 255, 255, 255));
	data->map_color[r][c] = trgb(0, 255, 255, 255);
}

int	map_init_coords_values_vc(t_data *data, char *buf, int r, int c)
{
	char	**splitbuf;
	int		index;

	index = 0;
	splitbuf = ft_split(buf, ',');
	ft_debug("map init coords_values_vc buf %s\n", buf);
	if (splitbuf == NULL)
		return (EXIT_FAILURE);
	while (splitbuf[index] != NULL)
	{
		ft_debug("map init crds_values_vc sb[index] %s\n", splitbuf[index]);
		index++;
	}
	ft_debug("index: %d\n", index);
	if (index == 1)
		map_init_coords_values_vc_dft(data, splitbuf[0], r, c);
	else if (index == 2)
		map_init_coords_values_vc_clr(data, splitbuf, r, c);
	ft_debug("map init coords_values_vc pre free_char_array\n");
	free_char_array(splitbuf);
	ft_debug("map init coords_values_vc after free_char_array\n");
	return (EXIT_SUCCESS);
}

int	map_init_coords_values(t_data *data, char *buf, int row)
{
	int		col;
	char	**splitbuf;

	col = 0;
	splitbuf = ft_split(buf, ' ');
	ft_debug("map init coords_values buf %s\n", buf);
	if (splitbuf == NULL)
		return (EXIT_FAILURE);
	while (splitbuf[col] != NULL)
	{
		ft_debug("map init coords_values splitbuf[col] %s\n", splitbuf[col]);
		if (map_init_coords_values_vc(data, splitbuf[col], row, col))
		{
			free_char_array(splitbuf);
			return (EXIT_FAILURE);
		}
		col++;
	}
	ft_debug("map init coords_values before free char array\n");
	free_char_array(splitbuf);
	ft_debug("map init coords_values after free char array\n");
	return (EXIT_SUCCESS);
}

// ft_printf("map init buf == NULL && index < data->rows\n");
// ft_printf("map init buf  %s", buf);
// ft_printf("map init if(map_init_coords_values(data, buf, index)\n");
// ft_printf("if(buf)\n");
void	map_init_coords(t_data *data)
{
	int		fd;
	int		index;
	char	*buf;

	index = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
		free_all_mlx(data);
	get_next_line(fd, 2);
	while (index < data->rows)
	{
		buf = get_next_line(fd, 0);
		if (buf == NULL && index < data->rows)
			free_all_mlx(data);
		if (map_init_coords_values(data, buf, index))
		{
			free(buf);
			free_all_mlx(data);
			exit(EXIT_FAILURE);
		}
		if (buf)
			free(buf);
		index++;
	}
}
