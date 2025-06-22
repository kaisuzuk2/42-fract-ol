/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:29:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 19:37:28 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex pix, t_complex z0, int max_iter)
{
	double		x_tmp;
	int			iter;
	t_complex	z;
	t_complex	c;

	z = z0;
	c = pix;
	iter = 0;
	while (z.real * z.real + z.imag * z.imag <= 4.0 && iter < max_iter)
	{
		x_tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = x_tmp;
		iter++;
	}
	return (iter);
}
