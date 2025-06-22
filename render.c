/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:22:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 16:39:09 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff));
}

static int cr(int n)
{
	n = n % 256;
	return (n * (256 - n)) / 65;
}

static void color_put(t_img *img, int x, int y, int iter, int max_iter)
{
	int color;

	if (iter == max_iter)
		color = rgb(0, 0, 0);
	else
	{
		int r = cr(iter);
		int g = cr(iter * 2);
		int b = cr(iter * 3);
		color = rgb(r, g, b);
	}
	buf_mlx_pixel_put(img, x, y, color);
}

t_complex	pixel_to_complex(t_window const *win, int x, int y)
{
	t_complex z;

	z.real =  win->x_min +(x / (double)win->width) * (win->x_max - win->x_min);
	z.imag = win->y_max - (y / (double)win->height) * (win->y_max - win->y_min);
	return (z);
}

void	render(t_data *data, int max_iter)
{
	int x;
	int y;
	int iter;
	
	y = 0;
	while (y < data->win.height)
	{
		x = 0;
		while (x < data->win.width)
		{
			iter = data->f(pixel_to_complex(&data->win, x, y), data->z0, max_iter);
			color_put(&data->img, x, y, iter, max_iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->img.img, 0, 0);
}