/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/02 02:40:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_sphere_intersec(t_env *env, t_ray ray)
{
	t_dpoint_3d	p;
	double		delta;

	p.x = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	p.y = 2 * (env->camera.position.x * ray.dir.x + env->camera.position.y *
		ray.dir.y + env->camera.position.z * ray.dir.z);
	p.z = pow(env->camera.position.x, 2) + pow(env->camera.position.y, 2) +
		pow(env->camera.position.z, 2) - pow(100, 2);
	delta = pow(p.y, 2) - 4 * p.x * p.z;
	if (delta < 0)
		return (0);
	else
		return (1);
}
