/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:48:29 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/24 21:42:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	return (0);
}
