/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 09:52:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/17 20:46:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_cone_intersec(t_object *obj, t_ray ray)
{
	t_dpoint_3d	v;
	t_dpoint_3d	x;
	t_dpoint_3d	eq;
	t_dpoint_3d	p;
	char		boolean;

	boolean = 0;
	v = ft_normalize(obj->rotation);
	x = ft_vdiff_s(ray.orig, obj->position);
	eq.x = ft_dotprod(ray.dir, ray.dir) - ((1 + obj->size * obj->size) *
		pow(ft_dotprod(ray.dir, v), 2));
	eq.y = 2 * (ft_dotprod(ray.dir, x) - (1 + obj->size * obj->size) *
		ft_dotprod(ray.dir, v) * ft_dotprod(x, v));
	eq.z = ft_dotprod(x, x) - ((1 + obj->size * obj->size)) *
		pow(ft_dotprod(x, v), 2);
	p.x = pow(eq.y, 2) - 4 * eq.x * eq.z;
	p.z = ft_solve_eq(eq, p.x, &boolean);
	if (boolean || p.x < 0)
		return (0);
	obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir, p.z));
	p.y = ft_dotprod(ray.dir, v) * p.z + ft_dotprod(x, v);
	obj->normal = ft_normalize(ft_vdiff_s(ft_vsum_s(ft_vprod(ray.dir, p.z), x),
		ft_vprod(ft_vprod(v, 1 + obj->size * obj->size), p.y)));
	return (1);
}
