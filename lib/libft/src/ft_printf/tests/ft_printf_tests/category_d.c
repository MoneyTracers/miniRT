/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:04:35 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_d(void)
{
	int	test_count;

	test_count = 1;
	printf(BMAG "%%d\n" RESET);
	test_count = test_util(test_count, "%d", 0);
	test_count = test_util(test_count, "%d", -10);
	test_count = test_util(test_count, "%d", -200000);
	test_count = test_util(test_count, "%d", -6000023);
	test_count = test_util(test_count, "%d", 10);
	test_count = test_util(test_count, "%d", 10000);
	test_count = test_util(test_count, "%d", 10000023);
	test_count = test_util(test_count, "%d", INT_MAX);
	test_count = test_util(test_count, "%d", INT_MIN);
	test_count = test_util(test_count, "dgs%dxx", 10);
	test_count = test_util(test_count, "%d%dd%d", 1, 2, -3);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
