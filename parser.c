/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:54:38 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/26 20:04:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_env(t_env *env, char *ln, int *e)
{
	if (env->entity_type == SCENE)
		ft_fill_scene(env, ln, e);
	else if (env->entity_type == OBJECTS)
		ft_fill_objects(env, ln, e);
	else if (env->entity_type == CAMERA)
		ft_fill_camera(env, ln, e);
	else
		*e = 1;
}

void	ft_get_entity(t_env *env, char *ln, int *e)
{
	if (!ft_strcmp(ln, "[scene]"))
		env->entity_type = SCENE;
	else if (!ft_strcmp(ln, "[camera]"))
		env->entity_type = CAMERA;
	else if (!ft_strcmp(ln, "[objects]"))
		env->entity_type = OBJECTS;
	else
		*e = 1;
}

void	ft_parse_line(t_env *env, char *ln, int *e)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_epur_str(ln);
	tmp2 = ft_strtrim(tmp1);
	if (tmp2[0] == '[' && tmp2[ft_strlen(tmp2) - 1] == ']')
		ft_get_entity(env, tmp2, e);
	else
		ft_fill_env(env, tmp2, e);
	free(tmp1);
	free(tmp2);
}

void	ft_read_file(char *name, t_env *env, int *e)
{
	int		fd;
	int		ret;
	char	*ln;

	ln = NULL;
	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &ln)))
	{
		if (ft_strcmp(ln, ""))
			ft_parse_line(env, ln, e);
		free(ln);
	}
	free(ln);
}
