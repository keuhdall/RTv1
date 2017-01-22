/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:53:20 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/22 17:06:09 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_if_scene(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_camera(char *s)
{
	if (!ft_strcmp(s, "<camera>"))
		return (1);
	else if (!ft_strcmp(s, "</camera>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_objects(char *s)
{
	if (!ft_strcmp(s, "<objects>"))
		return (1);
	else if (!ft_strcmp(s, "</objects>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_spot(char *s)
{
	if (!ft_strcmp(s, "<spot>"))
		return (1);
	else if (!ft_strcmp(s, "</spot>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_color(char *s)
{
	if (!ft_strcmp(s, "<color>"))
		return (1);
	else if (!ft_strcmp(s, "</color>"))
		return (-1);
	else
		return (0);
}
