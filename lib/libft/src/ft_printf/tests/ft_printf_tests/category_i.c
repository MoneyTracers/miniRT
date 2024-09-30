/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:17:41 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_i(void)
{
	int	test_count;

	test_count = 1;
	printf(BMAG "%%i\n" RESET);
	test_count = test_util(test_count, "%i", 0);
	test_count = test_util(test_count, "%i", -10);
	test_count = test_util(test_count, "%i", -200000);
	test_count = test_util(test_count, "%i", -6000023);
	test_count = test_util(test_count, "%i", 10);
	test_count = test_util(test_count, "%i", 10000);
	test_count = test_util(test_count, "%i", 10000023);
	test_count = test_util(test_count, "%i", INT_MAX);
	test_count = test_util(test_count, "%i", INT_MIN);
	test_count = test_util(test_count, "dgs%ixx", 10);
	test_count = test_util(test_count, "%i%id%i", 1, 2, -3);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
