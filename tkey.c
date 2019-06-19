/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkey.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:34:56 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/03 18:24:52 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	stop_this(int key, t_fl *cam, int l)
{
	int i;

	i = -1;
	if (key == 1)
		while (i++ < l)
			cam[i].fraktal = 5;
	if (key == 2)
		while (i++ < l)
			cam[i].fraktal = 2;
	if (key == 3)
		while (i++ < l)
			cam[i].fraktal = 1;
	if (key == 0)
		while (i++ < l)
			cam[i].fraktal = 3;
}

void	move_and_reset(int key, t_fl *cam, int l)
{
	int i;

	i = -1;
	if (key == 124)
		while (i++ < l)
			cam[i].x00 += 20;
	if (key == 126)
		while (i++ < l)
			cam[i].y00 -= 20;
	if (key == 123)
		while (i++ < l)
			cam[i].x00 -= 20;
	if (key == 125)
		while (i++ < l)
			cam[i].y00 += 20;
	if (key == 15)
		while (i++ < l)
		{
			cam[i].y00 = 0;
			cam[i].x00 = 0;
			cam[i].k = l;
			cam[i].zoom = 1;
			cam[i].color = 0x6a4a8a;
		}
}

void	ft_color(int key, t_fl *cam, int l, int i)
{
	if (key == 86)
		while (i++ < l)
			cam[i].color += 0x100000;
	if (key == 87)
		while (i++ < l)
			cam[i].color += 0x001000;
	if (key == 88)
		while (i++ < l)
			cam[i].color += 0x000010;
	if (key == 83)
		while (i++ < l)
			cam[i].color -= 0x100000;
	if (key == 84)
		while (i++ < l)
			cam[i].color -= 0x001000;
	if (key == 85)
		while (i++ < l)
			cam[i].color -= 0x000010;
	if (cam[0].color < 0)
	{
		i = -1;
		while (i++ < l)
			cam[i].color = 0;
	}
}

int		tkey(int key, t_fl *cam)
{
	// int bits_per_pixel;
	// int size_line;
	// int endian;
	int l;

	l = 120;
	// mlx_destroy_image(cam[0].mlx_ptr, cam[0].img_ptr);
	 mlx_clear_window(cam[0].mlx_ptr, cam[0].win_ptr);
	// cam[0].img_ptr = mlx_new_image(cam[0].mlx_ptr, cam[0].sizex, cam[0].sizey);
	// cam[0].img_str = (int *)mlx_get_data_addr(cam[0].img_ptr,
	// &bits_per_pixel, &size_line, &endian);
	inic(cam);
	if (key == 53)
		exit(0);
	move_and_reset(key, cam, l);
	ft_color(key, cam, l, -1);
	stop_this(key, cam, l);
	ft_thread(cam);
	mlx_put_image_to_window(cam[0].mlx_ptr, cam[0].win_ptr,
	cam[0].img_ptr, 0, 0);
	return (0);
}
