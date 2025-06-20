/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:20:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 16:26:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef int		bool;
# define TRUE 1
# define FALSE 0

# include "mlx.h"
# include <X11/keysym.h> // xライブラリのキーなどの定義 ->mlxが抽象化しているので、直接読み込むのを避けよう
# include <math.h>
# include <stdlib.h>

/*close_window*/
# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0L
/*esc*/
# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L << 0
# define XK_ESCAPE 0xff1b
/*mouse*/
# define BUTTON_PRESS 4 // zoom in
# define BUTTON_PRESS_MASK 1L << 2
# define BUTTON_RELEASE 5 // zoom out
# define BUTTON_RELEASE_MASK 1L << 3
/*arrow*/
# define XK_RIGHT 0xff53
# define XK_LEFT 0xff51
# define XK_UP 0xff52
# define XK_DOWN 0xff54

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	double		zoom;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
}				t_window;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
	t_window	win;
	t_img		img;
}				t_data;

typedef struct s_complex
{
	double		a;
	double		bi;
}				t_complex;

// イベント
int				key_handler(int keycde, void *param);
int				event_handler(t_window *win);
int				mouse_handler(int button, int x, int y, void *param);
int				loop_handler(void *param);

// 描画処理
t_complex		pixel_to_complex(t_window const *win, int x, int y);
void			render_mandelbrot(t_window const *win, t_img *img,
					int max_iter);

// ズーム処理
void			update_viewport(t_window *win);

#endif