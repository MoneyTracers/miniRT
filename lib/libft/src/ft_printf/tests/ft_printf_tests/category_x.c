/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:17:37 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_x(void)
{
	int	tc;

	tc = 1;
	printf(BMAG "%%x\n" RESET);
	tc = test_util(tc, "%x", 0);
	tc = test_util(tc, "%x", -10);
	tc = test_util(tc, "%x", -200000);
	tc = test_util(tc, "%x", -6000023);
	tc = test_util(tc, "%x", 10);
	tc = test_util(tc, "%x", 10000);
	tc = test_util(tc, "%x", 10000023);
	tc = test_util(tc, "%x", INT_MAX);
	tc = test_util(tc, "%x", INT_MIN);
	tc = test_util(tc, "dgs%xxx", 10);
	tc = test_util(tc, "%x%xd%x", 1, 2, -3);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
