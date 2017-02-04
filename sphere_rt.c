/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/04 23:08:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_sphere_intersec(t_ray ray, t_object obj)
{
	double		delta;
	double		a, b, c;

	a = ft_dotprod(ray.dir, ray.dir);
	b = 2 * ft_dotprod(ray.dir, obj.position);
	c = ft_dotprod(obj.position, obj.position) - RADIUS * RADIUS;
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (0);
	else
		return (1);
}
