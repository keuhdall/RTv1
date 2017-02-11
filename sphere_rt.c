/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/11 14:45:51 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_solve_eq(t_dpoint_3d eq, double delta)
{
	t_dpoint_3d	t;

	if (!delta)
		t.z = -eq.y;
	else
	{
		t.x = (-eq.y + delta) / (2 * eq.x);
		t.y = (-eq.y - delta) / (2 * eq.x);
		if (t.x < 0 || t.y < 0)
			return (0);
		t.z = (t.x < t.y ? t.x : t.y);
	}
	return (t.z);
}

int			ft_sphere_intersec(t_object *obj, t_ray ray)
{
	t_dpoint_3d	p;
	double		delta;

	p.x = ft_dotprod(ray.dir, ray.dir);
	p.y = 2 * ft_dotprod(ray.dir, obj->position);
	p.z = ft_dotprod(obj->position, obj->position) - obj->size * obj->size;
	delta = pow(p.y, 2) - 4 * p.x * p.z;
	if (delta < 0)
		return (0);
	else
	{
		obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir,
			ft_solve_eq(p, (double)sqrt(delta))));
		obj->normal = ft_vquo(ft_vdiff_s(obj->intersec, obj->position),
			obj->radius);
		return (1);
	}
}
