/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:33:43 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 19:34:08 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex pix, t_complex z0, int max_iter)
{
	int			iter;
	double		tmp;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z = pix;
	c = z0;
	while (z.real * z.real + z.imag * z.imag < 4.0 && iter < max_iter)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		iter++;
	}
	return (iter);
}
