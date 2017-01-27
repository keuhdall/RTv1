/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:53:58 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/27 18:49:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_scene_size(t_env *env, char **tab)
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
		ft_puterr(ERR_FILE_SYNTAX);
}
