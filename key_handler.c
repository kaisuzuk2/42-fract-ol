/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:34:10 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 16:30:28 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int esc_key_event(int keycode, t_window *win)
{
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}	
	return (0);
}

static int arrow_event(int keycode, t_window *win)
{
	const double move = (win->x_max - win->x_min) * 0.1;
	
	if (keycode == XK_RIGHT)
		(win->x_max += move, win->x_min += move);
	else if (keycode == XK_LEFT)
		(win->x_max -= move, win->x_min -= move);
	else if (keycode == XK_UP)
		(win->y_max += move, win->y_min += move);
	else if(keycode == XK_DOWN)
		(win->y_max -= move, win->y_min -= move);
	return (0);	
}

int key_handler(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	esc_key_event(keycode, &data->win);
	arrow_event(keycode, &data->win);
	render_mandelbrot(&data->win, &data->img, 300);
	return (0);
}