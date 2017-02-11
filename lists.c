/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:00:24 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/11 02:59:08 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj_lst	*ft_new_obj(t_object obj)
{
	t_obj_lst	*tmp;

	if (!(tmp = (t_obj_lst *)malloc(sizeof(t_obj_lst))))
		return (NULL);
	tmp->obj.type = obj.type;
	tmp->obj.size = obj.size;
	tmp->obj.position = obj.position;
	tmp->obj.rotation = obj.rotation;
	tmp->obj.color = obj.color;
	tmp->obj.color2 = (t_color){1.0, 1.0, 0.0};
	tmp->next = NULL;
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

t_spot_lst	*ft_new_spot(t_spot spot)
{
	t_spot_lst	*tmp;

	if (!(tmp = (t_spot_lst *)malloc(sizeof(t_spot_lst))))
		return (NULL);
	tmp->spot.position = spot.position;
	tmp->next = NULL;
	return (tmp);
}

void		ft_push_spot(t_spot_lst **spot_lst, t_spot_lst *new)
{
	t_spot_lst	*tmp;

	tmp = NULL;
	tmp = *spot_lst;
	if (!tmp)
		*spot_lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
