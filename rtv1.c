/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 23:43:13 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int	ft_intersect_obj(t_obj_lst *obj_lst, t_ray ray)
{
	if (obj_lst->obj.type == SPHERE)
	{
		if (ft_sphere_intersec(ray, obj_lst->obj))
			return (1);
	}
	else if (obj_lst->obj.type == PLANE)
	{
		if (ft_plane_intersec(ray, obj_lst->obj))
			return (1);
	}
	return (0);
}

int	ft_raytrace(t_env *env, t_ray ray)
{
	t_obj_lst	*tmp;

	tmp = env->obj_lst;
	while (tmp)
	{
		if (ft_intersect_obj(tmp, ray))
			return (tmp->obj.color);
		tmp = tmp->next;
	}
	return (0);
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
			env.mlx.img.data[y * env.scene.size.x + x] = ft_raytrace(&env, ray);
		}
	mlx_put_image_to_window(env.mlx.ptr, env.mlx.win, env.mlx.img.ptr, 0, 0);
	mlx_loop(env.mlx.ptr);
	return (0);
}
