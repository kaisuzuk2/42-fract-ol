/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:34:14 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 00:33:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


#include <stdio.h>


void update_viewport(t_window *win)
{
	double scale = 1.0 / win->zoom;

	win->x_min = -2.0 * scale + win->offset_x;
	win->x_max = 2.0 * scale + win->offset_x;
	win->y_min = -1.5 * scale + win->offset_y;
	win->y_max = 1.5 * scale + win->offset_y;
}

// void zoom(t_data *data, double scale_per, int x, int y)
// {
// 	t_window *win;

// 	win = data->win;
	
// 	t_complex mouse_abi = pixel_to_complex(win, x, y);
	
// 	win->zoom *= scale_per;

// 	win->offset_x = mouse_abi.a - ((win->x_max - win->x_min) / win->width) * x;
// 	win->offset_y = mouse_abi.bi - ((win->y_max - win->y_min) / win->height) * y;
	
// 	update_viewport(win);
// 	render_mandelbrot(data->win, data->img);
// }

void zoom(t_data *data, double scale_per, int x, int y)
{
	t_window *win;
	t_complex mouse;
	double old_width;
	double old_height;
	double new_width;
	double new_height;

	win = data->win;
	mouse = pixel_to_complex(win, x, y);

	old_width = win->x_max - win->x_min;
	old_height = win->y_max - win->y_min;
	
	win->zoom *= scale_per;
	
	new_width = old_width / scale_per;
	new_height = old_height / scale_per;
	
	win->x_min = mouse.a - (new_width / 2);
	win->x_max = mouse.a + (new_width / 2);
	win->y_min = mouse.bi - (new_height / 2);
	win->y_max = mouse.bi + (new_height / 2);
	render_mandelbrot(win, data->img);
}

int mouse_handler(int button, int x, int y, void *param)
{
	if (button == BUTTON_PRESS)
		zoom(param, 1.1, x, y);
	else if (button == BUTTON_RELEASE)
		zoom(param, 0.9, x, y);
	return (0);
}
