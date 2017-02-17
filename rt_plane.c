/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:13:51 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/16 18:34:05 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_plane_intersec(t_object *obj, t_ray ray)
{
	double	t;
	double	v;

	v = ft_dotprod(ray.dir, ft_normalize(obj->rotation));
	if (!v)
		return (0);
	t = -(ft_dotprod(ft_vdiff_s(ray.orig, obj->position),
		ft_normalize(obj->rotation)) / v);
	if (t < 0)
		return (0);
	obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir, t));
	obj->normal = v < 0 ? ft_normalize(obj->rotation) : ft_vnegative(
		ft_normalize(obj->rotation));
	return (1);
}
