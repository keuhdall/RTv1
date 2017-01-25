/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:53:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 00:15:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_tabs(t_env *env)
{
	int	count;

	count = -1;
	while (++count < 2)
		env->scene_filled[count] = 0;
	count = -1;
	while (++count < 6)
		env->camera_filled[count] = 0;
	count = -1;
	while (++count < 7)
		env->object_filled[count] = 0;
}

int		ft_check_all(t_env *env)
{
	int	count;

	count = -1;
	while (++count < 2)
	{
		if (env->scene_filled[count] == 0)
			return (0);
	}
	count = -1;
	while (++count < 6)
	{
		if (env->camera_filled[count] == 0)
			return (0);
	}
	count = -1;
	while (++count < 7)
	{
		if (env->object_filled[count] == 0)
			return (0);
	}
	return (1);
}

int		ft_check_object(t_env *env)
{
	int	count;

	count = -1;
	while (++count < 7)
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
	while (++count < 7)
		env->object_filled[count] = 0;
}

void	ft_check_split(char **tab)
{
	if (!tab[1])
	{
		ft_putendl("error");
		exit(1);
	}
}
