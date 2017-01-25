/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:53:58 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 20:00:31 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_scene_size(t_env *env, char **tab, int *e)
{
	if (!ft_strcmp(tab[0], "size.x"))
	{
		env->scene_filled[0] = 1;
		env->scene.size.x = ft_atoi(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "size.y"))
	{
		env->scene_filled[1] = 1;
		env->scene.size.y = ft_atoi(tab[1]);
	}
	else
		*e = 1;
}
