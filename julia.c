/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:33:43 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 14:09:50 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int julia_iter_count(t_complex z, t_complex c, int max_iter)
{
	int iter = 0;
	double tmp;

	while (z.real * z.real + z.imag * z.imag < 4.0 && iter < max_iter)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		iter++;
	}
	return iter;
}

void julia(t_data *data, int max_iter)
{
	int real;
	int imag;
	int iter;
	
	imag = 0;
	while (imag < data->win.height)
	{
		real = 0;
		while (real < data->win.width)
		{
			iter = julia_iter_count(pixel_to_complex(&data->win, real, imag), data->c, max_iter);
			color_put(&data->img, real, imag, iter, max_iter);
			real++;
		}
		imag++;
	}
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->img.img, 0, 0);
}