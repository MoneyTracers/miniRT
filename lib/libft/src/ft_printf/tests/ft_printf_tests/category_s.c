/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 19:13:56 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_s(void)
{
	int	tc;

	tc = 1;
	printf(BMAG "\n%%s\n" RESET);
	tc = test_util(tc, "lol %s", "lololol");
	tc = test_util(tc, "lol %s", "\200");
	tc = test_util(tc, "%s", "");
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
