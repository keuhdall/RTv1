/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:57:15 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 00:56:17 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_get_type(char *s)
{
	if (!ft_strcmp(s, "PLANE"))
		return (PLANE);
	else if (!ft_strcmp(s, "SQUARE"))
		return (SQUARE);
	else if (!ft_strcmp(s, "SPHERE"))
		return (SPHERE);
	else if (!ft_strcmp(s, "CYLINDER"))
		return (CYLINDER);
	else if (!ft_strcmp(s, "CONE"))
		return (CONE);
	else
	{
		ft_putendl("this type of object does not exist");
		exit(1);
		return (-1);
	}
}

void	ft_fill_object_type(t_env *env, char **tab, t_object *obj)
{
	if (!ft_strcmp(tab[0], "type"))
	{
		env->object_filled[0] = 1;
		obj->type = ft_get_type(tab[1]);
	}
}

void	ft_fill_object_position(t_env *env, char **tab, t_object *obj)
{
	if (!ft_strcmp(tab[0], "position.x"))
	{
		env->object_filled[1] = 1;
		obj->position.x = 0.0;//to be done
	}
	if (!ft_strcmp(tab[0], "position.y"))
	{
		env->object_filled[2] = 1;
		obj->position.y = 0.0;//to be done
	}
	if (!ft_strcmp(tab[0], "position.z"))
	{
		env->object_filled[3] = 1;
		obj->position.z = 0.0;//to be done
	}
}

void	ft_fill_object_rotation(t_env *env, char **tab, t_object *obj)
{
	if (!ft_strcmp(tab[0], "rotation.x"))
	{
		env->object_filled[4] = 1;
		obj->rotation.x = 0.0;//to be done
	}
	if (!ft_strcmp(tab[0], "rotation.y"))
	{
		env->object_filled[5] = 1;
		obj->rotation.y = 0.0;//to be done
	}
	if (!ft_strcmp(tab[0], "rotation.z"))
	{
		env->object_filled[6] = 1;
		obj->rotation.z = 0.0;//to be done
	}
}
