/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:53:47 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/13 17:06:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_fill_scene(t_env *env, char *ln)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = ft_strsplit(ln, '=');
	if (!tmp[1])
		ft_puterr(ERR_FILE_SYNTAX);
	if (!ft_strcmp(tmp[0], "name"))
		env->scene.name = ft_strdup(tmp[1]);
	else
		ft_fill_scene_size(env, tmp);
	ft_free_split(tmp);
}

void		ft_fill_objects(t_env *env, char *ln)
{
	char			found;
	char			**tmp;
	static t_object	obj;
	t_obj_lst		*obj_tmp;

	found = 0;
	tmp = ft_strsplit(ln, '=');
	if (!tmp[1])
		ft_puterr(ERR_FILE_SYNTAX);
	ft_fill_object_type(env, tmp, &obj, &found);
	if (!found)
		ft_fill_object_size(env, tmp, &obj, &found);
	if (!found)
		ft_fill_object_position(env, tmp, &obj, &found);
	if (!found)
		ft_fill_object_rotation(env, tmp, &obj, &found);
	if (!ft_strcmp(tmp[0], "color"))
		ft_fill_object_color(env, tmp, &obj);
	else if (!found)
		ft_puterr(ERR_FILE_SYNTAX);
	if (ft_check_entity(env, OBJECTS))
	{
		obj_tmp = ft_new_obj(obj);
		ft_push_obj(&env->obj_lst, obj_tmp);
		ft_reset(env, OBJECTS);
	}
	ft_free_split(tmp);
}

void		ft_fill_spots(t_env *env, char *ln)
{
	char			found;
	char			**tmp;
	static t_spot	spot;
	t_spot_lst		*spot_tmp;

	found = 0;
	tmp = ft_strsplit(ln, '=');
	if (!tmp[1])
		ft_puterr(ERR_FILE_SYNTAX);
	ft_fill_spot_position(env, tmp, &spot, &found);
	if (!found)
		ft_fill_spot_intensity(env, tmp, &spot, &found);
	if (!found)
		ft_puterr(ERR_FILE_SYNTAX);
	if (ft_check_entity(env, SPOTS))
	{
		spot_tmp = ft_new_spot(spot);
		ft_push_spot(&env->spot_lst, spot_tmp);
		ft_reset(env, SPOTS);
	}
	ft_free_split(tmp);
}

void		ft_fill_camera(t_env *env, char *ln)
{
	int		count;
	char	found;
	char	**tmp;

	found = 0;
	count = 0;
	tmp = ft_strsplit(ln, '=');
	if (!tmp[1])
		ft_puterr(ERR_FILE_SYNTAX);
	ft_fill_camera_position(env, tmp, &found);
	if (!found)
		ft_fill_camera_rotation(env, tmp);
	ft_free_split(tmp);
}
