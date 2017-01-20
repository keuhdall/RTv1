/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/20 00:48:55 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define W_WIDTH 800
# define W_HEIGHT 600

enum					e_env
{
						SCENE,
						NAME,
						CAMERA,
						OBJECTS,
						COLOR
};

enum					e_objects
{
						PLANE,
						SQUARE,
						SPHERE,
						CYLINDER,
						CONE
};

enum					e_errors
{
						ERR_FILE_OPEN,
						ERR_FILE_SYNTAX,
						ERR_INTERNAL_FAILURE
};

typedef	struct			s_img
{
	void				*img;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_meta
{
	void				*mlx;
	void				*win;
	t_img				img;
}						t_meta;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_dpoint
{
	double				x;
	double				y;
}						t_dpoint;

typedef struct			s_env
{
}						t_env;

#endif
