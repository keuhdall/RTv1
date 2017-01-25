/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 20:49:09 by lmarques         ###   ########.fr       */
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
	ft_init_tabs(&env);
	tmp = env.obj_lst;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	ft_read_file(argv[1], &env, &err);
	if (ft_check_all(&env))
	{
		printf("scene name : %s\n", env.scene.name);
		printf("scene size.x : %d\n", env.scene.size.x);
		printf("scene size.y : %d\n", env.scene.size.y);
		while (tmp)
		{
			printf("color = %d\n", tmp->obj.color);
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
