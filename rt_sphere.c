/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/17 19:18:31 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double		ft_solve_sphere(t_dpoint_3d eq, double delta, char *boolean)
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
		{
			if (t.x > 0)
				return (t.x);
			else if (t.y > 0)
				return (t.y);
			else
			{
				*boolean = 1;
				return (0);
			}
		}
		t.z = (t.x < t.y ? t.x : t.y);
	}
	return (t.z);
}

int					ft_sphere_intersec(t_object *obj, t_ray ray)
{
	t_dpoint_3d	p;
	t_dpoint_3d	px;
	double		delta;
	double		t;
	char		boolean;

	boolean = 0;
	px = ft_vdiff_s(ray.orig, obj->position);
	p.y = ft_dotprod(px, ray.dir);
	p.z = ft_dotprod(px, px) - (obj->size * obj->size);
	delta = pow(p.y, 2) - p.z;
	if (delta < 0)
		return (0);
	else
	{
		t = ft_solve_sphere(p, delta, &boolean);
		if (boolean)
			return (0);
		obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir,
			t));
		obj->normal = ft_vquo(ft_vdiff_s(obj->intersec, obj->position),
			obj->size);
		return (1);
	}
}
