/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:13:47 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/27 18:40:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_free_split(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
	{
		free(tab[count]);
		count++;
	}
	free(tab);
}

void	ft_puterr(int err)
{
	if (err == ERR_FILE_OPEN)
		ft_putendl("Error : could not open this file");
	else if (err == ERR_FILE_SYNTAX)
		ft_putendl("Error : invalid file");
	else if (err == ERR_INTERNAL_FAILURE)
		ft_putendl("Fatal : internal failure. What have you done ?!");
	exit(1);
}
