/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:59:54 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/01 22:02:57 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dpoint_3d	ft_vsum(t_dpoint_3d a, double b)
{
	t_dpoint_3d	sum;

	sum.x = a.x + b;
	sum.y = a.y + b;
	sum.z = a.z + b;
	return (sum);
}

t_dpoint_3d	ft_vdiff(t_dpoint_3d a, double b)
{
	t_dpoint_3d	diff;

	diff.x = a.x - b;
	diff.y = a.y - b;
	diff.z = a.z - b;
	return (diff);
}

t_dpoint_3d	ft_vprod(t_dpoint_3d a, double b)
{
	t_dpoint_3d	prod;

	prod.x = a.x * b;
	prod.y = a.y * b;
	prod.z = a.z * b;
	return (prod);
}

t_dpoint_3d	ft_vquo(t_dpoint_3d a, double b)
{
	t_dpoint_3d	quo;

	quo.x = a.x / b;
	quo.y = a.y / b;
	quo.z = a.z / b;
	return (quo);
}

t_dpoint_3d	ft_calc_vdir(t_env *env, double x, double y)
{
	t_dpoint	indent;
	t_dpoint_3d	tmp1;
	t_dpoint_3d	tmp2;

	indent.x = env->camera.vp_width / (double)env->scene.size.x;
	indent.y = env->camera.vp_height / (double)env->scene.size.y;
	tmp1 = ft_vprod(ft_vprod(VEC_RIGHT, indent.x), x);
	tmp2 = ft_vprod(ft_vprod(VEC_UP, indent.y), y);
	return (ft_vdiff_s(ft_vsum_s(env->camera.vp_pos, ft_vdiff_s(tmp1, tmp2)),
		env->camera.position));
}
