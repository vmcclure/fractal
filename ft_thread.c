/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:26:13 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/01 17:18:54 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	ft_thread(t_fl *cam)
{
	int			**statusadr;
	pthread_t	thread[cam[0].k];
	int			i;

	i = 0;
	while (i < cam[i].k)
	{
		pthread_create(&thread[i], NULL, drow, &cam[i]);
		i++;
	}
	i = 0;
	while (i < cam[i].k)
	{
		pthread_join(thread[i], (void**)&statusadr);
		i++;
	}
}
