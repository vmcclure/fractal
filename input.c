/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:05:07 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/01 17:21:58 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input(int argc, char **argv, t_fl *cam)
{
	if (argc != 2)
	{
		write(1, "1 - mandelbrot\n2 - julia\n3 - Burning Ship", 41);
		return (0);
	}
	if (argc == 2 && (argv[1][0] == '1' || argv[1][0] == '2' ||
	argv[1][0] == '3') && argv[1][1] == '\0')
		cam[0].fraktal = (argv[1][0]) - 48;
	else
	{
		write(1, "1 - mandelbrot\n2 - julia\n3 - Burning Ship", 41);
		return (0);
	}
	return (1);
}
