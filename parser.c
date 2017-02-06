/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:54:38 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 20:14:30 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_fill_env(t_env *env, char *ln)
{
	if (env->entity_type == SCENE)
		ft_fill_scene(env, ln);
	else if (env->entity_type == OBJECTS)
		ft_fill_objects(env, ln);
	else if (env->entity_type == CAMERA)
		ft_fill_camera(env, ln);
	else if (env->entity_type == SPOTS)
		ft_fill_spots(env, ln);
	else
		ft_puterr(ERR_FILE_SYNTAX);
}

void	ft_get_entity(t_env *env, char *ln)
{
	if (!ft_strcmp(ln, "[scene]"))
		env->entity_type = SCENE;
	else if (!ft_strcmp(ln, "[camera]"))
		env->entity_type = CAMERA;
	else if (!ft_strcmp(ln, "[objects]"))
		env->entity_type = OBJECTS;
	else if (!ft_strcmp(ln, "[spots]"))
		env->entity_type = SPOTS;
	else
		ft_puterr(ERR_FILE_SYNTAX);
}

void	ft_parse_line(t_env *env, char *ln)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_epur_str(ln);
	tmp2 = ft_strtrim(tmp1);
	if (tmp2[0] == '[' && tmp2[ft_strlen(tmp2) - 1] == ']')
		ft_get_entity(env, tmp2);
	else
		ft_fill_env(env, tmp2);
	free(tmp1);
	free(tmp2);
}

void	ft_read_file(char *name, t_env *env)
{
	int		fd;
	int		ret;
	char	*ln;

	ln = NULL;
	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &ln)))
	{
		if (ret == -1)
			ft_puterr(ERR_FILE_OPEN);
		if (ft_strcmp(ln, ""))
			ft_parse_line(env, ln);
		free(ln);
	}
	free(ln);
}
