/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:57:15 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/13 16:26:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_object_color(t_env *env, char **tab, t_object *obj)
{
	char	**tmp_colors;

	tmp_colors = ft_strsplit(tab[1], ' ');
	if (!tmp_colors[0] || !tmp_colors[1] || !tmp_colors[2])
		ft_puterr(ERR_FILE_SYNTAX);
	else
	{
		obj->color.r = (double)(ft_atof(tmp_colors[0]) / 255);
		obj->color.g = (double)(ft_atof(tmp_colors[1]) / 255);
		obj->color.b = (double)(ft_atof(tmp_colors[2]) / 255);
		env->object_filled[0] = 1;
	}
	ft_free_split(tmp_colors);
}

void	ft_fill_object_type(t_env *env, char **tab, t_object *obj, char *found)
{
	if (!ft_strcmp(tab[0], "type"))
	{
		if (!ft_strcmp(tab[1], "PLANE"))
			obj->type = PLANE;
		else if (!ft_strcmp(tab[1], "SPHERE"))
			obj->type = SPHERE;
		else if (!ft_strcmp(tab[1], "CYLINDER"))
			obj->type = CYLINDER;
		else if (!ft_strcmp(tab[1], "CONE"))
			obj->type = CONE;
		else
			ft_puterr(ERR_UNKNOWN_OBJ);
		env->object_filled[1] = 1;
		*found = 1;
	}
}

void	ft_fill_object_position(t_env *env, char **tab, t_object *obj,
			char *found)
{
	if (!ft_strcmp(tab[0], "position.x"))
	{
		env->object_filled[2] = 1;
		obj->position.x = ft_atof(tab[1]);
		*found = 1;
	}
	if (!ft_strcmp(tab[0], "position.y"))
	{
		env->object_filled[3] = 1;
		obj->position.y = ft_atof(tab[1]);
		*found = 1;
	}
	if (!ft_strcmp(tab[0], "position.z"))
	{
		env->object_filled[4] = 1;
		obj->position.z = ft_atof(tab[1]);
		*found = 1;
	}
}

void	ft_fill_object_rotation(t_env *env, char **tab, t_object *obj,
			char *found)
{
	if (!ft_strcmp(tab[0], "rotation.x"))
	{
		env->object_filled[5] = 1;
		obj->rotation.x = ft_atof(tab[1]);
		*found = 1;
	}
	if (!ft_strcmp(tab[0], "rotation.y"))
	{
		env->object_filled[6] = 1;
		obj->rotation.y = ft_atof(tab[1]);
		*found = 1;
	}
	if (!ft_strcmp(tab[0], "rotation.z"))
	{
		env->object_filled[7] = 1;
		obj->rotation.z = ft_atof(tab[1]);
		*found = 1;
	}
}

void	ft_fill_object_size(t_env *env, char **tab, t_object *obj, char *found)
{
	if (!ft_strcmp(tab[0], "size"))
	{
		env->object_filled[8] = 1;
		obj->size = ft_atof(tab[1]);
		*found = 1;
	}
}
