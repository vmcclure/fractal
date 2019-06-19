/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:30:51 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/03 18:25:22 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		complexadd(t_complex x, t_complex y)
{
	t_complex	result;

	result.re = (x.re + y.re);
	result.im = (x.im + y.im);
	return (result);
}

t_complex		complexmult(t_complex x, t_complex y, t_fl **cam)
{
	t_complex	result;

	if (cam[0]->fraktal == 1 || cam[0]->fraktal == 2 || cam[0]->fraktal == 5)
	{
		result.re = x.re * y.re - x.im * y.im;
		result.im = x.re * y.im + y.re * x.im;
	}
	if (cam[0]->fraktal == 3)
	{
		result.re = x.re * y.re - x.im * y.im;
		result.im = fabsl(x.re * y.im + y.re * x.im);
	}
	return (result);
}

float			complexabs(t_complex x)
{
	return (x.re * x.re + x.im * x.im);
}

void			inic(t_fl *cam)
{
	int i;
	int l;

	l = 120;
	i = -1;
	while (i++ < l)
	{
		cam[i].fraktal = cam[0].fraktal;
		cam[i].mlx_ptr = cam[0].mlx_ptr;
		cam[i].win_ptr = cam[0].win_ptr;
		cam[i].img_ptr = cam[0].img_ptr;
		cam[i].img_str = cam[0].img_str;
		if (!cam[i].minx)
			cam[i].color = 0x6a4a8a;
		cam[i].minx = -2;
		cam[i].maxx = 2;
		cam[i].miny = -1;
		cam[i].maxy = 2;
		cam[i].sizex = 900;
		cam[i].sizey = 600;
		if (!cam[i].zoom)
			cam[i].zoom = 1;
		cam[i].i = i;
		cam[i].k = l;
	}
}
