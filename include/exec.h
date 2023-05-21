/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:17:10 by efirmino          #+#    #+#             */
/*   Updated: 2023/05/19 18:31:50 by efirmino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define TRUE 1
# define FALSE 0

/* WINDOW */
# define WIDTH 900
# define HEIGHT 900
# define FOV 60
# define SPEED 2.2

/* MINIMAP */
# ifndef MINIMAP
#  define MINIMAP

#  define WALL_COLOR  0x00220092
#  define SPACE_COLOR 0x00000000
#  define MINIMAP_RATE 4

# endif

# define PI  3.1415926
# define PI2 1.5707963
# define PI3 4.7123889
# define DEG 0.0174533
# define DEFDIST 120000

/* BUTTONS */
# ifndef BUTTONS
#  define BUTTONS

#  define ESC_KEY 53

#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2

#  define CAM_L_KEY 123
#  define CAM_R_KEY 124
# endif

typedef struct s_ray
{
	double			ray_x;
	double			ray_y;
	double			angle;
	double			dist;
	int				type;
	char			or;
	struct s_ray	*next;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	dor_x;
	double	dor_y;
}	t_player;

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		b_pp;
	int		len;
	int		endian;
	int		img_width;
	int		img_height;
}	t_mlx_img;

typedef struct s_img
{
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
	int			f_color;
	int			c_color;
	t_mlx_img	*img_no;
	t_mlx_img	*img_so;
	t_mlx_img	*img_we;
	t_mlx_img	*img_ea;
}	t_img;

typedef struct s_map
{
	char		**mapy;
	int			**map;
	int			width;
	int			height;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			delta_x;
	int			delta_y;
	t_mlx_img	*minimap;
}	t_map;

typedef struct s_all
{
	void		*id;
	void		*window;
	t_map		*map;
	t_player	*player;
	t_img		*imgs;
	t_mlx_img	*render;
	t_ray		*rays;
}	t_all;

void	ft_launch(t_all *all);
void	ft_move_player(int keycode, t_all **all);
void	ft_move_cam(int keycode, t_all **all);
void	ft_draw_minimap(t_all *all);
void	ft_check_h(t_all *all, double angle, t_ray **ray);
void	ft_check_v(t_all *all, double angle, t_ray **ray);

/* UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS - UTILS */
void	ft_init_all(t_all **all);
int		ft_exit_button(t_all **all);
int		ft_key_handler(int keycode, t_all **all);
int		rgb_to_int(double r, double g, double b);
void	img_pxl_put(t_mlx_img *img, int x, int y, int color);
void	ft_draw_player(t_all *all);
void	ft_draw_minimap_wall(t_all *all);
double	ft_div(double a, double b);
void	ft_draw_floor_celling(t_all *all);
int		hit_a_wall_h(t_all *all, double x, double y, double angle);
double	ft_dist(t_all *all, double rx, double ry);
void	ft_add_ray(t_all **all, t_ray *good, int type);
int		ft_is_free_space(t_all *all, char dir);
void	ft_init_all_render_img(t_all **all);
void	ft_draw_some_lines(t_all *all);
void	ft_init_all_render_img(t_all **all);
int		ft_init_texture_img(t_all *all);
void	ft_free_rays(t_ray **rays);
void	ft_safe_stop(t_all *all);
void	ft_check_h_angle(double angle, t_all *all, double *rxy, double *rdxy);
double	ft_get_closest_y(t_all *all, int top);
double	ft_get_closest_x(t_all *all, int top);
void	ft_check_v(t_all *all, double angle, t_ray **ray);
int		hit_a_wall_h(t_all *all, double x, double y, double angle);
int		hit_a_wall_v(t_all *all, double x, double y, double angle);
void	ft_get_f_dist(double *f_dist, t_all *all, t_ray *ray);
double	ft_repair_angle(double angle);
void	ft_print_texture(double f_dist, int start, t_ray *rays, t_all *all);
void	plot_line(t_all *all, int *x, int x1, int y1);
void	print_no(t_all *all, double *start, double y, int r);
void	print_so(t_all *all, double *start, double y, int r);
void	print_we(t_all *all, double *start, double y, int r);
void	print_ea(t_all *all, double *start, double y, int r);
double	ratio(t_all *all);

// END
#endif
