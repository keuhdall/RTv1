/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:07:09 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/22 17:09:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_if_plane(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_square(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_sphere(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_cylinder(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}

int	ft_check_if_cone(char *s)
{
	if (!ft_strcmp(s, "<scene>"))
		return (1);
	else if (!ft_strcmp(s, "</scene>"))
		return (-1);
	else
		return (0);
}
