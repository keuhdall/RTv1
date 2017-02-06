/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 14:25:55 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_sphere_intersec(t_ray ray, t_object obj)
{
	t_dpoint_3d	p;
	double		delta;

	p.x = ft_dotprod(ray.dir, ray.dir);
	p.y = 2 * ft_dotprod(ray.dir, obj.position);
	p.z = ft_dotprod(obj.position, obj.position) - RADIUS * RADIUS;
	delta = pow(p.y, 2) - 4 * p.x * p.z;
	if (delta < 0)
		return (0);
	else
		return (1);
}
