/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:34:14 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 16:09:59 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void zoom(t_data *data, double scale_per, int x, int y)
{
	t_window *win;
	t_complex mouse;
	double old_width;
	double old_height;
	double new_width;
	double new_height;
	double raito_x;
	double raito_y;
	win = &data->win;
	mouse = pixel_to_complex(win, x, y);

	old_width = win->x_max - win->x_min;
	old_height = win->y_max - win->y_min;
	
	win->zoom *= scale_per;
	
	new_width = old_width / scale_per;
	new_height = old_height / scale_per;

	raito_x = x / (double)win->width;
	raito_y = y / (double)win->height;

	win->x_min = mouse.a - raito_x * new_width;
	win->x_max = win->x_min + new_width;

	win->y_max = new_height * raito_y + mouse.bi;
	win->y_min = win->y_max - new_height;
	
	
	render_mandelbrot(win, &data->img, 50);
}

int mouse_handler(int button, int x, int y, void *param)
{	
	if (button == BUTTON_PRESS)
		zoom(param, 1.1, x, y);
	else if (button == BUTTON_RELEASE)
		zoom(param, 0.9, x, y);
	
	return (0);
}
