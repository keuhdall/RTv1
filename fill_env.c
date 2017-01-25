/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:53:47 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/25 01:21:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj_lst	*ft_new_obj(t_object obj)
{
	t_obj_lst	*tmp;

	if (!(tmp = (t_obj_lst *)malloc(sizeof(t_obj_lst))))
		return (NULL);
	tmp->obj.position = obj.position;
	tmp->obj.rotation = obj.rotation;
	tmp->obj.color = obj.color;
	return (tmp);
}

void		ft_push_obj(t_obj_lst **obj_lst, t_obj_lst *new)
{
	t_obj_lst	*tmp;

	tmp = NULL;
	tmp = *obj_lst;
	if (!tmp)
		*obj_lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_fill_scene(t_env *env, char *ln, int *e)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = ft_strsplit(ln, '=');
	ft_check_split(tmp);
	if (!ft_strcmp(tmp[0], "name"))
		env->scene.name = tmp[1];
	else
		ft_fill_scene_size(env, tmp, e);
	while (tmp[count])
	{
		free(tmp[count]);
		count++;
	}
	free(tmp);
}

void		ft_fill_objects(t_env *env, char *ln, int *e)
{
	int				count;
	char			**tmp;
	static t_object	obj;
	t_obj_lst		*obj_tmp;

	count = 0;
	tmp = ft_strsplit(ln, '=');
	ft_check_split(tmp);
	ft_fill_object_type(env, tmp, &obj);
	ft_fill_object_position(env, tmp, &obj);
	ft_fill_object_rotation(env, tmp, &obj);
	if (!ft_strcmp(tmp[0], "color"))
	{
		env->object_filled[6] = 1;
		obj.color = ft_atoi(tmp[1]);
	}
	else
		*e = 1;
	if (ft_check_object(env))
	{
		obj_tmp = ft_new_obj(obj);
		ft_push_obj(&env->obj_lst, obj_tmp);
		ft_reset_object(env);
		free(obj_tmp);
	}
	while (tmp[count])
	{
		free(tmp[count]);
		count++;
	}
	free(tmp);
}

void		ft_fill_camera(t_env *env, char *ln, int *e)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = ft_strsplit(ln, '=');
	ft_check_split(tmp);
	ft_fill_camera_position(env, tmp);
	ft_fill_camera_rotation(env, tmp, e);
	while (tmp[count])
	{
		free(tmp[count]);
		count++;
	}
	free(tmp);
}