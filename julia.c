/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:33:43 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 17:31:01 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int julia_iter_count(t_complex z, t_complex c, int max_iter)
{
	int iter = 0;
	double tmp;

	while (z.a * z.a + z.bi * z.bi < 4.0 && iter < max_iter)
	{
		tmp = z.a * z.a - z.bi * z.bi + c.a;
		z.bi = 2.0 * z.a * z.bi + c.bi;
		z.a = tmp;
		iter++;
	}
	return iter;
}


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
	my_mlx_pixel_put(img, x, y, color);
}


void julia(t_window *win, t_img *img, int max_iter)
{
	int a;
	int b;
	int iter;
	t_complex c;


	c.a = -0.8;
	c.bi = 0.156;

	b = 0;
	while (b < win->height)
	{
		a = 0;
		while (a < win->width)
		{
			iter = julia_iter_count(pixel_to_complex(win, a, b), c, max_iter);
			color_put(img, a, b, iter, max_iter);
			a++;
		}
		b++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, img->img, 0, 0);
}