/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:22:39 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/19 15:50:25 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex(t_window const *win, int x, int y)
{
	t_complex z;

	z.a =  win->x_min +(x / (double)win->width) * (win->x_max - win->x_min);
	z.bi = win->y_max - (y / (double)win->height) * (win->y_max - win->y_min);
	return (z);
}
