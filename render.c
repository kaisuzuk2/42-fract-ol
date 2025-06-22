/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:22:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 14:09:14 by kaisuzuk         ###   ########.fr       */
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


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


t_complex	pixel_to_complex(t_window const *win, int x, int y)
{
	t_complex z;

	z.real =  win->x_min +(x / (double)win->width) * (win->x_max - win->x_min);
	z.imag = win->y_max - (y / (double)win->height) * (win->y_max - win->y_min);
	return (z);
}
