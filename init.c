/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:12:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 17:28:45 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	win_init(t_window *win)
{
	win->width = 500;
	win->height = 500;
	win->zoom = 1.0;
	win->x_min = -2.0; // このあたりの初期値はあとで再確認しよう
	win->x_max = 2.0;
	win->y_min = -1.5;
	win->y_max = 1.5;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, "test");
}

static void	img_init(t_data *data)
{
	t_window *win;
	t_img *img;
	
	win = &data->win;
	img = &data->img;
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

bool	init(t_data *data)
{
	win_init(&data->win);
	img_init(data);
	data->f = julia;
	return (TRUE);
}