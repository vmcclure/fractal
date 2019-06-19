/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:36:12 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/03 16:39:22 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef	struct	s_complex
{
	double	re;
	double	im;
}				t_complex;
typedef struct	s_frac
{
	t_complex	z;
	t_complex	c;
	long double	zoom;
	int			i;
	long long	x00;
	long long	y00;
	void		*win_ptr;
	void		*img_ptr;
	void		*mlx_ptr;
	int			*img_str;
	int			sizex;
	int			sizey;
	int			color;
	long double	minx;
	long double	miny;
	long double	maxx;
	long double	maxy;
	int			k;
	int			fraktal;
}				t_fl;
typedef struct	s_one_time
{
	double	dx;
	double	dy;
	int			i;
	int			x;
	int			y;
	int			color;
}				t_ot;
void			inic(t_fl *cam);
t_complex		complexmult(t_complex x, t_complex y, t_fl **cam);
float			complexabs(t_complex x);
t_complex		complexadd(t_complex x, t_complex y);
void			*drow(void *cam);
void			ft_thread(t_fl *cam);
int				mkey(int k, int x1, int y1, t_fl *cam);
void			zoom_out(int k, t_fl *cam);
int				input(int argc, char **argv, t_fl *cam);
void			zoom_in(int k, t_fl *cam, int x1, int y1);
int				tkey(int key, t_fl *cam);
void			move_and_reset(int key, t_fl *cam, int l);
int				mkey1(int x1, int y1, t_fl *cam);
#endif
