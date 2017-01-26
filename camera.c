/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:29:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/26 19:00:15 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	ft_fill_camera_position(t_env *env, char **tab, char *found)
{
	if (!ft_strcmp(tab[0], "position.x"))
	{
		env->camera_filled[0] = 1;
		env->camera.position.x = ft_atof(tab[1]);
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "position.y"))
	{
		env->camera_filled[1] = 1;
		env->camera.position.y = ft_atof(tab[1]);
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "position.z"))
	{
		env->camera_filled[2] = 1;
		env->camera.position.z = ft_atof(tab[1]);
		*found = 1;
	}
}

void	ft_fill_camera_rotation(t_env *env, char **tab, int *e)
{
	if (!ft_strcmp(tab[0], "rotation.x"))
	{
		env->camera_filled[3] = 1;
		env->camera.rotation.x = ft_atof(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "rotation.y"))
	{
		env->camera_filled[4] = 1;
		env->camera.rotation.y = ft_atof(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "rotation.z"))
	{
		env->camera_filled[5] = 1;
		env->camera.rotation.z = ft_atof(tab[1]);
	}
	else
		*e = 1;
}
