/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:53:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/31 20:27:55 by lmarques         ###   ########.fr       */
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

int		ft_check_object(t_env *env)
{
	int	count;

	count = -1;
	while (++count < MAX_INDEX_OBJECT)
	{
		if (env->object_filled[count] == 0)
			return (0);
	}
	return (1);
}

void	ft_reset_object(t_env *env)
{
	int	count;

	count = -1;
	while (++count < MAX_INDEX_OBJECT)
		env->object_filled[count] = 0;
}
