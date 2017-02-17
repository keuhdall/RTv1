/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/16 15:14:46 by lmarques         ###   ########.fr       */
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
		delta = (double)sqrt(delta);
		t.x = (-eq.y + delta);
		t.y = (-eq.y - delta);
		if (t.x < 0 || t.y < 0)
			return (0);
		t.z = (t.x < t.y ? t.x : t.y);
	}
	return (t.z);
}

int			ft_sphere_intersec(t_object *obj, t_ray ray)
{
	t_dpoint_3d	p;
	t_dpoint_3d	px;
	double		delta;

	px = ft_vdiff_s(ray.orig, obj->position);
	p.y = ft_dotprod(px, ray.dir);
	p.z = ft_dotprod(px, px) - (obj->size * obj->size);
	delta = pow(p.y, 2) - p.z;
	if (delta < 0)
		return (0);
	else
	{
		obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir,
			ft_solve_eq(p, delta)));
		obj->normal = ft_vquo(ft_vdiff_s(obj->intersec, obj->position),
			obj->size);
		return (1);
	}
}
