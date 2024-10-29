/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:28:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/10/29 16:59:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

enum identifiers
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cyl,
	unidentified
};

void parse(int argc, char **argv);

#endif

