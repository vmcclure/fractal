/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:21:45 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/03 18:55:18 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	for_drow(t_fl *cam, t_ot *ts)
{
	cam->z.re = cam->minx + (ts->x - (cam->x00)) * ts->dx;
	cam->z.im = cam->miny + (ts->y - (cam->y00)) * ts->dy;
	if (cam->fraktal == 1 || cam->fraktal == 3)
	{
		cam->c.re = cam->minx + (ts->x - (cam->x00)) * ts->dx;
		cam->c.im = cam->miny + (ts->y - (cam->y00)) * ts->dy;
	}
	ts->i = 0;
	ts->color = 0;
	while (ts->i <100 && (complexabs(cam->z)) < 4)
	{
		cam->z = complexadd(complexmult(cam->z, cam->z, &cam), cam->c);
		ts->i++;
		ts->color += cam->color;
	}
	// if (cam->color == 0x6a4a8a)
	// {
	// 	cam->color = 0xffffff;
	// }
	if (ts->x + (cam->sizex * ts->y) <= cam->sizex * cam->sizey
	&& ts->x < cam->sizex)
	{
		cam->img_str[ts->x + (cam->sizex * (ts->y))] = ts->color;
	}
}

void	*drow(void *cam1)
{
	t_fl			*cam;
	t_ot			ts;

	cam = (t_fl*)cam1;
	ts.dx = (cam->maxx - cam->minx) / cam->sizex / cam->zoom;
	ts.dy = (cam->maxy - cam->miny) / cam->sizey / cam->zoom;
	ts.y = cam->i;
	while (ts.y < cam->sizey)
	{
		ts.x = 0;
		while (ts.x < cam->sizex)
		{
			for_drow(&*cam, &ts);
			ts.x++;
		}
		ts.y += cam->k;
	}
	return (0);
}
