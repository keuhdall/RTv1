/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:26:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/17 19:49:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_solve_eq(t_dpoint_3d eq, double delta, char *boolean)
{
	t_dpoint_3d	t;

	if (!delta)
		t.z = -eq.y / (2 * eq.x);
	else
	{
		delta = (double)sqrt(delta);
		t.x = (-eq.y + delta) / (2 * eq.x);
		t.y = (-eq.y - delta) / (2 * eq.x);
		if (t.x < 0 || t.y < 0)
		{
			if (t.x < 0 && t.y < 0)
			{
				*boolean = 1;
				return (0);
			}
			return (t.x > t.y ? t.x : t.y);
		}
		t.z = (t.x < t.y ? t.x : t.y);
	}
	return (t.z);
}

int		ft_cylinder_intersec(t_object *obj, t_ray ray)
{
	t_dpoint_3d	v;
	t_dpoint_3d	x;
	t_dpoint_3d	eq;
	char		boolean;
	double		delta;
	double		t;

	boolean = 0;
	v = ft_normalize(obj->rotation);
	x = ft_vdiff_s(ray.orig, obj->position);
	eq.x = ft_dotprod(ray.dir, ray.dir) - pow(ft_dotprod(ray.dir, v), 2);
	eq.y = 2 * (ft_dotprod(ray.dir, x) - ft_dotprod(ray.dir, v) *
		ft_dotprod(x, v));
	eq.z = ft_dotprod(x, x) - pow(ft_dotprod(x, v), 2) - obj->size * obj->size;
	delta = pow(eq.y, 2) - 4 * eq.x * eq.z;
	t = ft_solve_eq(eq, delta, &boolean);
	if (boolean || delta < 0)
		return (0);
	obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir, t));
	obj->normal = ft_normalize(ft_vdiff_s(ft_vdiff_s(ft_vsum_s(ray.orig,
		ft_vprod(ray.dir, t)), obj->position), ft_vprod(ft_normalize(
		obj->rotation), ft_dotprod(ray.dir, ft_vprod(v,t)) + ft_dotprod(
		x, ft_normalize(obj->rotation)))));
	return (1);
}
