/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/03 04:06:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_sphere_intersec(t_ray ray, t_object obj)
{
	t_dpoint_3d	tmp;
	double		delta;
	double		a, b, c;

	tmp = ray.dir;
	a = ft_dotprod(tmp, tmp);
	b = 2 * ft_dotprod(tmp, obj.position);
	c = ft_dotprod(obj.position, obj.position) - RADIUS * RADIUS;
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (0);
	else
		return (1);
}
