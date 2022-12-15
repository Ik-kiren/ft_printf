/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:20:53 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/15 11:48:31 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	printf("t1(%i)", ft_printf(" %x ", 450));
	printf("%c", '\n');
	printf("t2(%i)", printf(" %x ", 450));
	printf("%c", '\n');
	printf("t1(%i)", ft_printf(" %c", '0' - 256));
	printf("%c", '\n');
	printf("t2(%i)", printf(" %c", '0' - 256));
	printf("%c", '\n');
	printf("t1(%i)", ft_printf("%c%c%c", 'a', '\t', 'b'));
	printf("%c", '\n');
	printf("t2(%i)", printf("%c%c%c", 'a', '\t', 'b'));
	printf("%c", '\n');
}
