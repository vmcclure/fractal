/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkey.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:37:25 by vmcclure          #+#    #+#             */
/*   Updated: 2019/04/26 17:04:22 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	for_mkey1(t_fl *cam, long double *dx, long double *dy)
{
	// int			bits_per_pixel;
	// int			size_line;
	// int			endian;

	// mlx_destroy_image(cam[0].mlx_ptr, cam[0].img_ptr);
	 mlx_clear_window(cam[0].mlx_ptr, cam[0].win_ptr);
	// cam[0].img_ptr = mlx_new_image(cam[0].mlx_ptr, cam[0].sizex, cam[0].sizey);
	// cam[0].img_str = (int *)mlx_get_data_addr(cam[0].img_ptr,
	// &bits_per_pixel, &size_line, &endian);
	inic(cam);
	*dx = (cam[0].maxx - cam[0].minx) / cam[0].sizex / cam[0].zoom;
	*dy = (cam[0].maxy - cam[0].miny) / cam[0].sizey / cam[0].zoom;
}

void	zoom_out(int k, t_fl *cam)
{
	int			i;
	int			l;
	long long	x00;
	long long	y00;

	i = 0;
	l = 120;
	if (k == 4)
	{
		i = 0;
		while (i < l)
		{
			x00 = cam[i].x00;
			y00 = cam[i].y00;
			cam[i].x00 += ((cam[i].sizex / 2 - x00) / 2);
			cam[i].y00 += ((cam[i].sizey / 2 - y00) / 2);
			cam[i].zoom = cam[i].zoom / 2;
			i++;
		}
	}
}

void	zoom_in(int k, t_fl *cam, int x1, int y1)
{
	int			i;
	int			l;
	long long	x00;
	long long	y00;

	i = 0;
	l = 120;
	if (k == 5)
	{
		i = 0;
		while (i < l)
		{
			x00 = cam[i].x00;
			y00 = cam[i].y00;
			cam[i].x00 = (cam[i].x00 + ((cam[i].x00 - x1)) * 0.2 / cam[i].zoom * cam[i].zoom);
			cam[i].y00 = (cam[i].y00 + ((cam[i].y00 - y1)) * 0.2 /	cam[i].zoom * cam[i].zoom);
			//  cam[i].x00 = (cam[i].x00  - x1 * cam[i].zoom) ;
			//  cam[i].y00 = (cam[i].y00  - y1 * cam[i].zoom );
			cam[i].zoom = cam[i].zoom * 1.2;
			i++;
		}
	}
}

int		mkey(int k, int x1, int y1, t_fl *cam)
{
	// int			bits_per_pixel;
	// int			size_line;
	// int			endian;
	int			i;
	int			l;

	i = 0;
	l = 120;
	// mlx_destroy_image(cam[0].mlx_ptr, cam[0].img_ptr);
	 mlx_clear_window(cam[0].mlx_ptr, cam[0].win_ptr);
	// cam[0].img_ptr = mlx_new_image(cam[0].mlx_ptr, cam[0].sizex, cam[0].sizey);
	// cam[0].img_str = (int *)mlx_get_data_addr(cam[0].img_ptr,
	// &bits_per_pixel, &size_line, &endian);
	inic(cam);
	zoom_in(k, cam, x1, y1);
	zoom_out(k, cam);
	ft_thread(cam);
	mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->img_ptr, 0, 0);
	return (0);
}

int		mkey1(int x1, int y1, t_fl *cam)
{
	int			i;
	long double	dx;
	long double	dy;

	i = -1;
	if (cam[0].fraktal == 2)
	{
		for_mkey1(cam, &dx, &dy);
		while (i++ < 120)
		{
			cam[i].c.re = cam[0].minx + (x1 - (cam[0].x00)) * dx;
			cam[i].c.im = cam[0].miny + (y1 - (cam[0].y00)) * dy;
		}
		ft_thread(cam);
		mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, cam->img_ptr, 0, 0);
	}
	return (0);
}
