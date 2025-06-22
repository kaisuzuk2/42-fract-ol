/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:34:14 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/23 00:51:22 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_zoom_raito(t_window *win, double scale_per,
		double *new_width, double *new_height)
{
	const double	old_width = win->x_max - win->x_min;
	const double	old_height = win->y_max - win->y_min;

	win->zoom *= scale_per;
	*new_width = old_width / scale_per;
	*new_height = old_height / scale_per;
}

static void	zoom(t_data *data, double scale_per, int x, int y)
{
	t_complex	mouse;
	double		new_width;
	double		new_height;
	double		raito_x;
	double		raito_y;

	mouse = pixel_to_complex(&data->win, x, y);
	update_zoom_raito(&data->win, scale_per, &new_width, &new_height);
	raito_x = x / (double)data->win.width;
	raito_y = y / (double)data->win.height;
	data->win.x_min = mouse.real - raito_x * new_width;
	data->win.x_max = data->win.x_min + new_width;
	data->win.y_max = new_height * raito_y + mouse.imag;
	data->win.y_min = data->win.y_max - new_height;
}

int	mouse_handler(int button, int x, int y, void *param)
{
	int iter;
	t_data *data;
	
	data = (t_data *)param;
	if (button == BUTTON_PRESS)
		zoom(param, 1.1, x, y);
	else if (button == BUTTON_RELEASE)
		zoom(param, 0.9, x, y);
	iter = MIN_ITER + log(data->win.zoom) * 10;
	if (iter >= MAX_ITER)
		iter = MAX_ITER;
	render(data, iter);
	return (0);
}
