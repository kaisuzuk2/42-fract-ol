/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:29:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/17 21:30:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	mandelbrot_iter_count(double a, double b, int max_iter)
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
		x_tmp = x * x - y * y + a;
		y = 2 * x * y + b;
		x = x_tmp;
		iter++;
	}
	return (iter);
}

static int	pixel_to_complex(int x, int y, const int height, const int width)
{
	double	a;
	double	b;
	int		iter;

	a = X_MIN + (x / (double)width) * (X_MAX - X_MIN);
	b = Y_MAX - (y / (double)height) * (Y_MAX - Y_MIN);
	iter = mandelbrot_iter_count(a, b, 50);
	return (iter);
}

static void	color_put(t_img *img, int x, int y, int iter)
{
	if (iter == 50)
		my_mlx_pixel_put(img, x, y, 0x000000);
	else
		my_mlx_pixel_put(img, x, y, (iter * 0x0F0F0F)); //発散回数に合わせて色を決めているね　具体的な意味がわからんね
}

void	draw_mandelbrot(t_img *img, const int height, const int width)
{
	int x;
	int y;
	int iter;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			iter = pixel_to_complex(x, y, height, width);
			color_put(img, x, y,  iter);
			x++;
		}
		y++;
	}
}