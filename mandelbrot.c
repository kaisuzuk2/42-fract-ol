/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:29:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 23:46:44 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	mandelbrot_iter_count(t_complex const z, int max_iter)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iter;

	x = 0.0;
	y = 0.0;
	iter = 0;
	while (x * x + y * y <= 4.0 && iter < max_iter)
	{
		x_tmp = x * x - y * y + z.real;
		y = 2 * x * y + z.imag;
		x = x_tmp;
		iter++;
	}
	return (iter);
}

// static void	color_put(t_img *img, int x, int y, int iter, int max_iter)
// {
// 	if (iter == max_iter)
// 		my_mlx_pixel_put(img, x, y, 0x000000);
// 	else
// 		my_mlx_pixel_put(img, x, y, (iter * 0x0F0F0F));
// 			//発散回数に合わせて色を決めているね　具体的な意味がわからんね
// }

int rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff));
}

int cr(int n)
{
	n = n % 256;
	return (n * (256 - n)) / 65;
}

void color_put(t_img *img, int x, int y, int iter, int max_iter)
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
	my_mlx_pixel_put(img, x, y, color);
}


void	mandelbrot(t_data *data, int max_iter)
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
			iter = mandelbrot_iter_count(pixel_to_complex(&data->win, x, y), max_iter);
			color_put(&data->img, x, y, iter, max_iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->img.img, 0, 0);
}