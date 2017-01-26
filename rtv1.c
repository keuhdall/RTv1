/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/26 19:13:22 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <sys/wait.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int			err;
	t_env		env;
	t_obj_lst	*tmp;

	err = 0;
	env.obj_lst = NULL;
	ft_init_tabs(&env);
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	ft_read_file(argv[1], &env, &err);
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
		tmp = env.obj_lst;
		while (tmp)
		{
			printf("=====NEW OBJECT=====\n");
			printf("object position.x : %f\n", tmp->obj.position.x);
			printf("object position.y : %f\n", tmp->obj.position.y);
			printf("object position.z : %f\n", tmp->obj.position.z);
			printf("\n");
			printf("object rotation.x : %f\n", tmp->obj.rotation.x);
			printf("object rotation.y : %f\n", tmp->obj.rotation.y);
			printf("object rotation.z : %f\n", tmp->obj.position.z);
			printf("color = %d\n", tmp->obj.color);
			printf("====================\n");
			printf("\n");
			tmp = tmp->next;
		}
	}
	else if (err)
	{
		ft_putendl("error0");
	}
	else
	{
		printf("%d\n", ft_check_all(&env));
		ft_putendl("error1");
	}
	sleep(10000);
	return (0);
}
