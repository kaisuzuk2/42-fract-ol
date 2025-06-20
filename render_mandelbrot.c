/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:29:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 11:51:07 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
		x_tmp = x * x - y * y + z.a;
		y = 2 * x * y + z.bi;
		x = x_tmp;
		iter++;
	}
	return (iter);
}

static void	color_put(t_img *img, int x, int y, int iter)
{
	if (iter == 300)
		my_mlx_pixel_put(img, x, y, 0x000000);
	else
		my_mlx_pixel_put(img, x, y, (iter * 0x0F0F0F)); //発散回数に合わせて色を決めているね　具体的な意味がわからんね
}

void	render_mandelbrot(t_window const *win, t_img *img, int max_iter)
{
	int x;
	int y;
	int iter;

	y = 0;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			iter = mandelbrot_iter_count(pixel_to_complex(win, x, y), max_iter);
			color_put(img, x, y, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, img->img, 0, 0);
}