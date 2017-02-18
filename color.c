/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:37:54 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/17 20:46:22 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_color_int(t_color c)
{
	t_point_3d	color;

	c.r = c.r > 1 ? 1 : c.r;
	c.g = c.g > 1 ? 1 : c.g;
	c.b = c.b > 1 ? 1 : c.b;
	color.x = (((int)(c.r * 255) & 0xff) << 16);
	color.y = (((int)(c.g * 255) & 0xff) << 8);
	color.z = (((int)(c.b * 255) & 0xff));
	return (color.x + color.y + color.z);
}

t_color	ft_add_color(t_color a, t_color b)
{
	return ((t_color){a.r + b.r, a.g + b.g, a.b + b.b});
}

t_color	ft_mult_color(t_color c, double i)
{
	return ((t_color){c.r * i, c.g * i, c.b * i});
}

t_color	ft_calc_shade(t_object obj, t_spot spot)
{
	double		shade;

	shade = ft_dotprod(obj.normal, ft_vnegative(
		ft_normalize(ft_vdiff_s(obj.intersec, spot.position))));
	if (shade > 1)
		shade = 1;
	if (shade <= 0)
		return ((t_color){0.0, 0.0, 0.0});
	else
		return (ft_mult_color(ft_mult_color(obj.color, 1.0), shade *
			spot.intensity));
}

int		ft_intersect_light(t_env *env, t_object *closest, t_spot spot)
{
	t_obj_lst	*tmp;
	t_dpoint_3d	v;
	t_ray		ray;
	double		dist;

	tmp = env->obj_lst;
	v = ft_vdiff_s(closest->intersec, spot.position);
	ray.orig = spot.position;
	ray.dir = ft_normalize(v);
	dist = sqrt(ft_dotprod(v, v));
	while (tmp)
	{
		if (&tmp->obj != closest)
		{
			if (ft_intersect_obj(tmp, ray))
			{
				if (sqrt(ft_dotprod(ft_vdiff_s(tmp->obj.intersec,
					spot.position), ft_vdiff_s(tmp->obj.intersec,
					spot.position))) < dist)
					return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
