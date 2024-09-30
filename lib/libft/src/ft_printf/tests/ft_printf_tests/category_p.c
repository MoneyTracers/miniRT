/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:10:04 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_p(void)
{
	int	tc;

	tc = 1;
	printf(BMAG "%%p\n" RESET);
	tc = test_util(tc, "%p", "");
	tc = test_util(tc, "%p", NULL);
	tc = test_util(tc, "%p", (void *)-14523);
	tc = test_util(tc, "0x%p-", (void *)ULONG_MAX);
	tc = test_util(tc, "%pp%p", (void *)LONG_MAX + 423856, (void *)0);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
