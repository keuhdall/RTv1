/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/27 14:03:52 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
//# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

enum					e_env
{
						SCENE,
						CAMERA,
						OBJECTS,
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

typedef struct			s_point_3d
{
	int					x;
	int					y;
	int					z;
}						t_point_3d;

typedef struct			s_dpoint_3d
{
	double				x;
	double				y;
	double				z;
}						t_dpoint_3d;

typedef struct			s_scene
{
	char				*name;
	t_point				size;
}						t_scene;

typedef struct			s_camera
{
	t_dpoint_3d			position;
	t_dpoint_3d			rotation;
}						t_camera;

typedef struct			s_object
{
	int					type;
	int					color;
	t_dpoint_3d			position;
	t_dpoint_3d			rotation;
}						t_object;

typedef struct			s_obj_lst
{
	t_object			obj;
	struct s_obj_lst	*next;
}						t_obj_lst;

typedef struct			s_env
{
	t_meta				meta;
	int					entity_type;
	t_scene				scene;
	t_camera			camera;
	t_obj_lst			*obj_lst;
	char			scene_filled[2];
	char			camera_filled[6];
	char			object_filled[8];
}						t_env;

void					ft_init_tabs(t_env *env);
void					ft_read_file(char *name, t_env *env, int *e);
int						ft_check_all(t_env *env);
int						ft_check_object(t_env *env);
void					ft_reset_object(t_env *env);
void					ft_check_split(char **tab);
void					ft_fill_scene(t_env *env, char *ln, int *e);
void					ft_fill_scene_size(t_env *env, char **tab, int *e);
void					ft_fill_camera(t_env *env, char *ln, int *e);
void					ft_fill_camera_position(t_env *env, char **tab,
							char *found);
void					ft_fill_camera_rotation(t_env *env, char **tab, int *e);
void					ft_fill_objects(t_env *env, char *ln, int *e);
void					ft_fill_object_type(t_env *env, char **tab,
							t_object *obj, char *found);
void					ft_fill_object_position(t_env *env, char **tab,
							t_object *obj, char *found);
void					ft_fill_object_rotation(t_env *env, char **tab,
							t_object *obj, char *found);

#endif
