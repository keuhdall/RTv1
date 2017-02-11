/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:46:18 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/11 02:20:15 by lmarques         ###   ########.fr       */
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
		t.x = (-eq.y + delta) / (2 * eq.x);
		t.y = (-eq.y - delta) / (2 * eq.x);
		t.z = (t.x < t.y ? t.x : t.y);
	}
	return (t.z);
}

int			ft_sphere_intersec(t_env *env, t_ray ray, t_object *obj)
{
	t_dpoint_3d	p;
	double		delta;

	p.x = ft_dotprod(ray.dir, ray.dir);
	p.y = 2 * ft_dotprod(ray.dir, obj->position);
	p.z = ft_dotprod(obj->position, obj->position) - obj->size * obj->size;
	delta = pow(p.y, 2) - 4 * p.x * p.z;
	if (delta < 0)
		return (0);
	else
	{
		//env->camera.dist_obj = ft_solve_eq(p, (double)sqrt(delta));
		env->camera.dist_obj = env->camera.dist_obj;;
		obj->intersec = ft_vsum_s(ray.orig, ft_vprod(ray.dir,
			ft_solve_eq(p, (double)sqrt(delta))));
		return (1);
	}
}
