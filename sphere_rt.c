/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/02 14:40:30 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_sphere_intersec(t_ray ray, t_object obj)
{
	t_dpoint_3d	p;
	double		delta;

	//p.x = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	p.y = 2 * (obj.position.x * ray.dir.x + obj.position.y *
		ray.dir.y + obj.position.z * ray.dir.z);
	p.z = pow(obj.position.x, 2) + pow(obj.position.y, 2) +
		pow(obj.position.z, 2) - pow(RADIUS, 2);
	delta = pow(p.y, 2) - p.z;
	if (delta < 0)
		return (0);
	else
		return (1);
}
