/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:22:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 17:55:05 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
