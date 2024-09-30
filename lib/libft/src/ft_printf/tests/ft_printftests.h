/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftests.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:23 by spenning          #+#    #+#             */
/*   Updated: 2024/05/17 08:19:07 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFTESTS_H
# define FT_PRINTFTESTS_H

//these inclusions are needed to be able to use the write function from
// unistd library. and malloc and free from the stdlib library.

# include "../inc/ft_printf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# define NORMFOLDER "../../ft_printf"
# define NORMLOGS "logs/norminette_output.txt"
# define NORMLOCLOGS "logs/norminette_location.txt"

# define RED   "\x1B[31m"
# define GRN   "\x1B[1;32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define BMAG   "\x1B[1;35m"
# define CYN   "\x1B[36m"
# define BCYN   "\x1B[1;36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

int		compareFile(FILE *fPtr1, FILE *fPtr2, int *line, int *col);
int		compare_length(int test_count, int ft_outcome, int outcome);
int		compare_files(int test_count);
void	category_c(void);
void	category_s(void);
void	category_p(void);
void	category_d(void);
void	category_i(void);
void	category_u(void);
void	category_x(void);
void	category_cx(void);
int		test_util(int tc, char *format, ...);
#endif
