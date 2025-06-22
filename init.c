/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:12:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 13:37:31 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	win_init(t_window *win)
{
	win->width = 800;
	win->height = 800;
	win->zoom = 1.0;
	win->x_min = -2.0; 
	win->x_max = 1.0;
	win->y_min = -1.5;
	win->y_max = 1.5;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (FALSE);
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, "test");
	if (!win->mlx_win)
		return (FALSE);
	return (TRUE);
}

static bool	img_init(t_data *data)
{
	t_window *win;
	t_img *img;
	
	win = &data->win;
	img = &data->img;
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	if (!img->img)
		return (FALSE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (TRUE);
}

bool	init(t_data *data)
{
	if (!win_init(&data->win))
		return (FALSE);
	if (!img_init(data))
	{
		mlx_destroy_window(data->win.mlx, data->win.mlx_win);
		return (FALSE);
	}
	return (TRUE);
}