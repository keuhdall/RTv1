/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:54:38 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/22 16:52:35 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_get_entity(char *ln, int *e)
{
	return (0);
}

void	ft_parse_line(t_env *env, char *ln, int *e)
{
	char	**tmp;

	tmp[0] = ft_epur_str(ln);
	tmp[1] = ft_strtrim(tmp[0]);
}

void	ft_read_scene(char *name, t_env *env, int *e)
{
	int		fd;
	int		ret;
	char	*ln;

	ln = NULL;
	fd = open(name, O_RDONLY);
	if (fd <= 0)
		
	while ((ret = get_next_line(fd, &ln)))
	{
		ft_parse_line(env, ln, e);
		free(ln);
	}
	free(ln);
}
