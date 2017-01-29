/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:29:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/29 23:13:00 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

void	ft_fill_camera_direction(t_env *env, char **tab, char *found)
{
	if (!ft_strcmp(tab[0], "direction.x"))
	{
		env->camera_filled[6] = 1;
		env->camera.direction.x = ft_atof(tab[1]);
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "direction.y"))
	{
		env->camera_filled[7] = 1;
		env->camera.direction.y = ft_atof(tab[1]);
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "direction.z"))
	{
		env->camera_filled[8] = 1;
		env->camera.direction.z = ft_atof(tab[1]);
		*found = 1;
	}
}

void	ft_fill_camera_rotation(t_env *env, char **tab)
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
		ft_puterr(ERR_FILE_SYNTAX);
}
