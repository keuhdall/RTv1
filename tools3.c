/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:46:12 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/01 22:03:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dpoint_3d	ft_vsum_s(t_dpoint_3d a, t_dpoint_3d b)
{
	t_dpoint_3d	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

t_dpoint_3d	ft_vdiff_s(t_dpoint_3d a, t_dpoint_3d b)
{
	t_dpoint_3d	diff;

	diff.x = a.x - b.x;
	diff.y = a.y - b.y;
	diff.z = a.z - b.z;
	return (diff);
}

t_dpoint_3d	ft_vprod_s(t_dpoint_3d a, t_dpoint_3d b)
{
	t_dpoint_3d	prod;

	prod.x = a.x * b.x;
	prod.y = a.y * b.y;
	prod.z = a.z * b.z;
	return (prod);
}

t_dpoint_3d	ft_vquo_s(t_dpoint_3d a, t_dpoint_3d b)
{
	t_dpoint_3d	quo;

	quo.x = a.x / b.x;
	quo.y = a.y / b.y;
	quo.z = a.z / b.z;
	return (quo);
}
