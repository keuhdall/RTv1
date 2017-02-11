/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/11 14:48:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int		ft_color_int(t_color c)
{
	return ((c.r * 255) + (c.g * 255) + (c.b * 255));
}

void	ft_ppixel(t_env *env, int x, int y, t_color c)
{
	int	i;

	i = x * 4 + y * env->scene.size.x;
	env->mlx.img.data[i] = (int)(c.b * 255);
	env->mlx.img.data[++i] = (int)(c.g * 255);
	env->mlx.img.data[++i] = (int)(c.r * 255);
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

	printf("intersec = %f; %f; %f\n", obj.intersec.x, obj.intersec.y, obj.intersec.z);
	printf("normal = %f; %f; %f\n", obj.normal.x, obj.normal.y, obj.normal.z);
	shade = ft_dotprod(
			//ft_normalize(ft_vdiff_s(spot.position, obj.intersec)),
			obj.normal,
			ft_vnegative(ft_normalize(ft_vdiff_s(obj.intersec, spot.position))));
	//printf("shade = %f\n", shade);
	return (shade < 0 ? (t_color){0.0, 0.0, 0.0} : ft_mult_color(
		ft_mult_color(obj.color2, 1.0), shade * 1.0));
}

int	ft_intersect_obj(t_obj_lst *obj_lst, t_ray ray)
{
	if (obj_lst->obj.type == SPHERE)
	{
		if (ft_sphere_intersec(&obj_lst->obj, ray))
			return (1);
	}
	else if (obj_lst->obj.type == PLANE)
	{
		if (ft_plane_intersec(ray, obj_lst->obj))
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
			//dists.x = dists.y < dists.x ? dists.y : dists.x;
			//closest_obj = dists.y < dists.x ? &tmp_obj->obj : closest_obj;
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

t_color	ft_raytrace(t_env *env, t_ray ray)
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
		//ft_normalize(ft_vdiff_s(tmp_spot->spot.position, closest->intersec));
		final_color = ft_add_color(ft_calc_shade(*closest, tmp_spot->spot),
			final_color);
		//return ((t_color){1.0, 1.0, 1.0});
		tmp_spot = tmp_spot->next;
	}
	return (final_color);
}

int	main(int argc, char *argv[])
{
	t_ray		ray;
	t_env		env;
	t_obj_lst	*tmp_obj;
	t_spot_lst	*tmp_spot;

	env.obj_lst = NULL;
	env.spot_lst = NULL;
	ft_init_tabs(&env);
	ft_read_file(argv[1], &env);
	ft_init_struct(&env);
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	if (ft_check_all(&env))
	{
		printf("=====SCENE=====\n");
		printf("scene name : %s\n", env.scene.name);
		printf("scene size.x : %d\n", env.scene.size.x);
		printf("scene size.y : %d\n", env.scene.size.y);
		printf("===============\n");
		printf("====CAMERA====\n");
		printf("camera position.x : %f\n", env.camera.position.x);
		printf("camera position.y : %f\n", env.camera.position.y);
		printf("camera position.z : %f\n", env.camera.position.z);
		printf("\n");
		printf("camera rotation.x : %f\n", env.camera.rotation.x);
		printf("camera rotation.y : %f\n", env.camera.rotation.y);
		printf("camera rotation.z : %f\n", env.camera.position.z);
		printf("==============\n");
		printf("\n");
		tmp_obj = env.obj_lst;
		tmp_spot = env.spot_lst;
		if (!tmp_obj)
			ft_puterr(ERR_NO_OBJ);
		while (tmp_obj)
		{
			printf("=====NEW OBJECT=====\n");
			printf("object size : %d\n", tmp_obj->obj.size);
			printf("object position.x : %f\n", tmp_obj->obj.position.x);
			printf("object position.y : %f\n", tmp_obj->obj.position.y);
			printf("object position.z : %f\n", tmp_obj->obj.position.z);
			printf("\n");
			printf("object rotation.x : %f\n", tmp_obj->obj.rotation.x);
			printf("object rotation.y : %f\n", tmp_obj->obj.rotation.y);
			printf("object rotation.z : %f\n", tmp_obj->obj.rotation.z);
			printf("color = %d\n", tmp_obj->obj.color);
			printf("====================\n");
			printf("\n");
			tmp_obj = tmp_obj->next;
		}
		while (tmp_spot)
		{
			printf("====NEW SPOT====\n");
			printf("spot position.x : %f\n", tmp_spot->spot.position.x);
			printf("spot position.y : %f\n", tmp_spot->spot.position.y);
			printf("spot position.z : %f\n", tmp_spot->spot.position.z);
			printf("================\n");
			printf("\n");
			tmp_spot = tmp_spot->next;
		}
	}
	else
	{
		printf("%d\n", ft_check_all(&env));
		ft_puterr(ERR_FILE_SYNTAX);
	}
	for (int y = 0; y < env.scene.size.y; y++)
		for (int x = 0; x < env.scene.size.x; x++)
		{
			ray.orig = env.camera.position;
			ray.dir = ft_calc_vdir(&env, (double)x, (double)y);
			ray.dir = ft_normalize(ray.dir);
			int color = ft_color_int(ft_raytrace(&env, ray));
			if (color)
				printf("color = %d\n", color);
			env.mlx.img.data[y * env.scene.size.x + x] = color;
			//ft_ppixel(&env, x, y, ft_raytrace(&env, ray));
		}
	mlx_put_image_to_window(env.mlx.ptr, env.mlx.win, env.mlx.img.ptr, 0, 0);
	mlx_loop(env.mlx.ptr);
	return (0);
}
