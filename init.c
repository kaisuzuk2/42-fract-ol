/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:12:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/19 17:58:07 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_window *win, t_img *img)
{
	win->width = 1000;
	win->height = 1000;
	win->zoom = 1.0;
	win->offset_x = 0;
	win->offset_y = 0;
	win->x_min = -2.0; // このあたりの初期値はあとで再確認しよう
	win->x_max = 2.0;
	win->y_min = -1.5;
	win->y_max = 1.5;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, "test");
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	// mlx_put_image_to_window(win->mlx, win->mlx_win, img->img, win->height,
	// 	win->width);
}