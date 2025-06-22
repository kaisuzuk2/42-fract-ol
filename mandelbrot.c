/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:29:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 14:09:42 by kaisuzuk         ###   ########.fr       */
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