/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:53:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 22:38:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_tabs(t_env *env)
{
	int	count;

	count = -1;
	while (++count < MAX_INDEX_SCENE)
		env->scene_filled[count] = 0;
	count = -1;
	while (++count < MAX_INDEX_CAMERA)
		env->camera_filled[count] = 0;
	count = -1;
	while (++count < MAX_INDEX_OBJECT)
		env->object_filled[count] = 0;
	count = -1;
	while (++count < MAX_INDEX_SPOT)
		env->spot_filled[count] = 0;
}

int		ft_check_all(t_env *env)
{
	int	count;

	count = -1;
	while (++count < MAX_INDEX_SCENE)
	{
		if (env->scene_filled[count] == 0)
			return (0);
	}
	count = -1;
	while (++count < MAX_INDEX_CAMERA)
	{
		if (env->camera_filled[count] == 0)
			return (0);
	}
	return (1);
}

int		ft_check_entity(t_env *env, int entity_type)
{
	int	count;

	count = -1;
	if (entity_type == OBJECTS)
	{
		while (++count < MAX_INDEX_OBJECT)
		{
			if (env->object_filled[count] == 0)
				return (0);
		}
	}
	else if (entity_type == SPOTS)
	{
		while (++count < MAX_INDEX_SPOT)
		{
			if (env->spot_filled[count] == 0)
				return (0);
		}
	}
	return (1);
}

void	ft_reset(t_env *env, int entity_type)
{
	int	count;

	count = -1;
	if (entity_type == OBJECTS)
	{
		while (++count < MAX_INDEX_OBJECT)
			env->object_filled[count] = 0;
	}
	else if (entity_type == SPOTS)
	{
		while (++count < MAX_INDEX_SPOT)
			env->spot_filled[count] = 0;
	}
}
