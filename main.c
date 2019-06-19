/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:35:48 by vmcclure          #+#    #+#             */
/*   Updated: 2019/04/04 19:12:35 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_fl	cam[121];

	if (!input(argc, argv, cam))
		return (0);
	cam[0].mlx_ptr = mlx_init();
	cam[0].win_ptr = mlx_new_window(cam[0].mlx_ptr, 900, 600, "hello");
	cam[0].img_ptr = mlx_new_image(cam[0].mlx_ptr, 900, 600);
	cam[0].img_str = (int *)mlx_get_data_addr(cam[0].img_ptr,
	&bits_per_pixel, &size_line, &endian);
	inic(cam);
	ft_thread(cam);
	mlx_put_image_to_window(cam[0].mlx_ptr, cam[0].win_ptr,
	cam[0].img_ptr, 0, 0);
	mlx_hook(cam[0].win_ptr, 2, 0, tkey, &cam);
	mlx_hook(cam[0].win_ptr, 4, 0, mkey, &cam);
	mlx_hook(cam[0].win_ptr, 6, 0, mkey1, &cam);
	mlx_loop(cam[0].mlx_ptr);
	return (0);
	
}
