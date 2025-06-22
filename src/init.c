/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:12:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 23:45:26 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 500
#define HEIGHT 500

static t_bool	win_init(t_window *win)
{
	win->width = WIDTH;
	win->height = HEIGHT;
	win->zoom = 1.0;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (FALSE);
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, win->title);
	if (!win->mlx_win)
		return (FALSE);
	return (TRUE);
}

static void	init_viewport(t_data *data)
{
	t_window	*win;

	win = &data->win;
	if (data->f == mandelbrot)
	{
		win->x_min = -2.0;
		win->x_max = 1.0;
		win->y_min = -1.5;
		win->y_max = 1.5;
	}
	else
	{
		win->x_min = -2.0;
		win->x_max = 2.0;
		win->y_min = -1.5;
		win->y_max = 1.5;
	}
}

static t_bool	img_init(t_data *data)
{
	t_window	*win;
	t_img		*img;

	win = &data->win;
	img = &data->img;
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	if (!img->img)
		return (FALSE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (TRUE);
}

t_bool	init(t_data *data)
{
	if (!win_init(&data->win))
		return (FALSE);
	init_viewport(data);
	if (!img_init(data))
	{
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		return (FALSE);
	}
	return (TRUE);
}
