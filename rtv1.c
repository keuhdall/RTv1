/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/18 18:34:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_intersect_obj(t_obj_lst *obj_lst, t_ray ray)
{
	if (obj_lst->obj.type == SPHERE)
	{
		if (ft_sphere_intersec(&obj_lst->obj, ray))
			return (1);
	}
	else if (obj_lst->obj.type == PLANE)
	{
		if (ft_plane_intersec(&obj_lst->obj, ray))
			return (1);
	}
	else if (obj_lst->obj.type == CYLINDER)
	{
		if (ft_cylinder_intersec(&obj_lst->obj, ray))
			return (1);
	}
	else if (obj_lst->obj.type == CONE)
	{
		if (ft_cone_intersec(&obj_lst->obj, ray))
			return (1);
	}
	return (0);
}

t_object	*ft_get_closest_obj(t_env *env, t_ray ray)
{
	t_obj_lst	*tmp_obj;
	t_object	*closest_obj;
	t_dpoint	dists;

	tmp_obj = env->obj_lst;
	closest_obj = NULL;
	dists.x = 999999;
	while (tmp_obj)
	{
		if (ft_intersect_obj(tmp_obj, ray))
		{
			dists.y = ft_dotprod(ft_vdiff_s(tmp_obj->obj.intersec, ray.orig),
								ft_vdiff_s(tmp_obj->obj.intersec, ray.orig));
			if (dists.y < dists.x)
			{
				dists.x = dists.y;
				closest_obj = &tmp_obj->obj;
			}
		}
		tmp_obj = tmp_obj->next;
	}
	return (closest_obj);
}

t_color		ft_raytrace(t_env *env, t_ray ray)
{
	t_color		final_color;
	t_spot_lst	*tmp_spot;
	t_object	*closest;

	final_color = (t_color){0.0, 0.0, 0.0};
	tmp_spot = env->spot_lst;
	closest = ft_get_closest_obj(env, ray);
	if (!closest || !tmp_spot)
		return ((t_color){0.0, 0.0, 0.0});
	while (tmp_spot)
	{
		if (!ft_intersect_light(env, closest, tmp_spot->spot))
			final_color = ft_add_color(ft_calc_shade(*closest, tmp_spot->spot),
				final_color);
		tmp_spot = tmp_spot->next;
	}
	return (final_color);
}

void		ft_draw(t_env *env)
{
	int		color;
	t_point	p;
	t_ray	ray;

	p.y = -1;
	while (++p.y < env->scene.size.y)
	{
		p.x = -1;
		while (++p.x < env->scene.size.x)
		{
			ray.orig = env->camera.position;
			ray.dir = ft_calc_vdir(env, (double)p.x, (double)p.y);
			ray.dir = ft_normalize(ray.dir);
			color = ft_color_int(ft_raytrace(env, ray));
			env->mlx.img.data[p.y * env->scene.size.x + p.x] = color;
		}
	}
}

int			main(int argc, char *argv[])
{
	t_env		env;

	env.obj_lst = NULL;
	env.spot_lst = NULL;
	ft_init_tabs(&env);
	ft_read_file(argv[1], &env);
	ft_init_struct(&env);
	if (argc != 2)
	{
		ft_puterr(ERR_WRONG_ARGS);
		return (-1);
	}
	if (ft_check_all(&env))
	{
		if (!env.obj_lst)
			ft_puterr(ERR_NO_OBJ);
	}
	else
		ft_puterr(ERR_FILE_SYNTAX);
	ft_draw(&env);
	mlx_key_hook(env.mlx.win, &ft_exit_key, 0);
	mlx_hook(env.mlx.win, 17, (1L << 17), &ft_exit, 0);
	mlx_put_image_to_window(env.mlx.ptr, env.mlx.win, env.mlx.img.ptr, 0, 0);
	mlx_loop(env.mlx.ptr);
	return (0);
}
