/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 16:31:07 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


#include <stdio.h>


bool	init(t_data *data);

int	main(void)
{
	t_data data;
	t_window *win;
	t_img *img;
	
	if (!init(&data))
		return (0); // 適宜エラー処理
	win = &data.win;
	img = &data.img;
	
	mlx_loop_hook(win->mlx, loop_handler, &data);
	mlx_hook(win->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_handler, win);
	mlx_hook(win->mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, event_handler, win);
	mlx_mouse_hook(win->mlx_win, mouse_handler , &data);
	
	mlx_loop(win->mlx);
}