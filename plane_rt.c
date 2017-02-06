/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:13:51 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 14:17:43 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_plane_intersec(t_ray ray, t_object obj)
{
	t_dpoint_3d	tmp;
	tmp.x = RADIUS;
	tmp.y = RADIUS;
	tmp.z = RADIUS;
	tmp = ft_normalize(tmp);
	double	a, b;

	a = ft_dotprod(tmp, ft_vdiff_s(ray.orig, obj.position));
	b = ft_dotprod(tmp, ray.dir);
	if (!b)
		return (0);
	return (a / b < 0 ? 0 : 1);
}
