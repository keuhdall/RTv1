/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:13:47 by lmarques          #+#    #+#             */
/*   Updated: 2017/02/06 14:54:03 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_init_struct(t_env *env)
{
	env->mlx.ptr = mlx_init();
	env->mlx.win = mlx_new_window(env->mlx.ptr, env->scene.size.x,
		env->scene.size.y, env->scene.name);
	env->mlx.img.ptr = mlx_new_image(env->mlx.ptr, env->scene.size.x,
		env->scene.size.y);
	env->mlx.img.data = (int *)mlx_get_data_addr(env->mlx.img.ptr,
		&env->mlx.img.bpp, &env->mlx.img.size_line, &env->mlx.img.endian);
	env->camera.vp_height = 1.0;
	env->camera.vp_width = 1.0 / ((double)env->scene.size.y /
		(double)env->scene.size.x);
	env->camera.vp_dist = 1.0;
	env->camera.vp_pos = ft_vsum_s(env->camera.position,
		ft_vdiff_s(ft_vsum_s(ft_vprod(VEC_DIR, env->camera.vp_dist),
		ft_vprod(VEC_UP, (env->camera.vp_height / 2.0))),
		ft_vprod(VEC_RIGHT, (env->camera.vp_width / 2.0))));
}

void		ft_free_split(char **tab)
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

void		ft_puterr(int err)
{
	if (err == ERR_FILE_OPEN)
		ft_putendl("Error : could not open this file");
	else if (err == ERR_FILE_SYNTAX)
		ft_putendl("Error : invalid file");
	else if (err == ERR_INTERNAL_FAILURE)
		ft_putendl("Fatal : internal failure. What have you done ?!");
	else if (err == ERR_NO_OBJ)
		ft_putendl("Error : no object found, it's either incomplete or empty");
	exit(1);
}

t_dpoint_3d	ft_normalize(t_dpoint_3d v)
{
	double		len;
	t_dpoint_3d	normalized;

	len = sqrt(ft_dotprod(v, v));
	normalized = ft_vquo(v, len);
	return (normalized);
}
