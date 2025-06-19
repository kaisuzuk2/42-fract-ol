/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/19 17:52:46 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


#include <stdio.h>


void	init(t_window *win, t_img *img);
void render_mandelbrot(t_window const *win, t_img *img);

int	main(void)
{
	t_data *data;
	t_window *win;
	t_img *img;
	
	data = (t_data *)malloc(sizeof(t_data));
	win = (t_window *)malloc(sizeof(t_window));
	img = (t_img *)malloc(sizeof(t_img));
	data->win = win;
	data->img = img;
	init(win, img);
	render_mandelbrot(win, img);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img->img, 0, 0);
	
	mlx_hook(win->mlx_win, KEY_PRESS, KEY_PRESS_MASK, esc_key_event, win);
	mlx_hook(win->mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, close_window_event, win);
	mlx_mouse_hook(win->mlx_win, mouse_handler , data);

	mlx_loop(win->mlx);
}