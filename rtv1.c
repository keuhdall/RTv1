/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 01:22:53 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <sys/wait.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		err;
	t_env	env;

	err = 0;
	ft_init_tabs(&env);
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	ft_read_file(argv[1], &env, &err);
	if (ft_check_all(&env) && env.scene.name)
		printf("scene name : %s\n", env.scene.name);
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
