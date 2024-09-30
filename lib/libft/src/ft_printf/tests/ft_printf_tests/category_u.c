/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:16:36 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_u(void)
{
	int	tc;

	tc = 1;
	printf(BMAG "%%u\n" RESET);
	tc = test_util(tc, "%u", 0);
	tc = test_util(tc, "%u", -10);
	tc = test_util(tc, "%u", -200000);
	tc = test_util(tc, "%u", -6000023);
	tc = test_util(tc, "%u", 10);
	tc = test_util(tc, "%u", 10000);
	tc = test_util(tc, "%u", 10000023);
	tc = test_util(tc, "%u", INT_MAX);
	tc = test_util(tc, "%u", INT_MIN);
	tc = test_util(tc, "dgs%uxx", 10);
	tc = test_util(tc, "%u%ud%u", 1, 2, -3);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
