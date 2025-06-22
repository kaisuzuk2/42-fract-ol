/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 13:44:10 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

bool	init(t_data *data);

int	main(int argc, char *argv[])
{
	t_data data;
	t_window *win;
	t_img *img;

	if (!parse(argc, argv, &data))
		return (0);
	if (!init(&data))
		return (0);
	win = &data.win;
	img = &data.img;

	mlx_loop_hook(win->mlx, loop_handler, &data);
	mlx_hook(win->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_handler, win);
	mlx_hook(win->mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, event_handler, win);
	mlx_mouse_hook(win->mlx_win, mouse_handler, &data);

	mlx_loop(win->mlx);
	
	mlx_destroy_image(win->mlx, img->img);
	mlx_destroy_window(win->mlx, win->mlx_win);
}