/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:13:51 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/16 10:38:08 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dpoint_3d	ft_v_unit(t_dpoint_3d v)
{
	return (ft_vquo(v, sqrt(ft_dotprod(v, v))));
}

int			ft_plane_intersec(t_object *obj, t_ray ray)
{
	double	t;
	double	v;

	v = ft_dotprod(ray.dir, ft_v_unit(obj->rotation));
	if (!v)
		return (0);
	t = -(ft_dotprod(ft_vdiff_s(ray.orig, obj->position),
		ft_v_unit(obj->rotation)) / v);
	if (t < 0)
		return (0);
	obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir, t));
	obj->normal = v < 0 ? ft_v_unit(obj->rotation) : ft_vnegative(ft_v_unit(
		obj->rotation));
	//printf("intersec = %f %f %f\n", obj->intersec.x, obj->intersec.y, obj->intersec.z);
	printf("normal = %f %f %f\n", obj->normal.x, obj->normal.y, obj->normal.z);
	return (1);
}
