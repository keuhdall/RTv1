/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:39:53 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/13 17:00:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_spot_position(t_env *env, char **tab, t_spot *spot, char *found)
{
	if (!ft_strcmp(tab[0], "position.x"))
	{
		spot->position.x = ft_atof(tab[1]);
		env->spot_filled[0] = 1;
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "position.y"))
	{
		spot->position.y = ft_atof(tab[1]);
		env->spot_filled[1] = 1;
		*found = 1;
	}
	else if (!ft_strcmp(tab[0], "position.z"))
	{
		spot->position.z = ft_atof(tab[1]);
		env->spot_filled[2] = 1;
		*found = 1;
	}
}

void	ft_fill_spot_intensity(t_env *env, char **tab, t_spot *spot,
	char *found)
{
	if (!ft_strcmp(tab[0], "intensity"))
	{
		spot->intensity = ft_atof(tab[1]);
		env->spot_filled[3] = 1;
		*found = 1;
	}
}
