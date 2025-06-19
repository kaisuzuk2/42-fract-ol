/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:34:10 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/19 11:55:35 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int esc_key_event(int keycode, t_window *win)
{
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}	
	return (0);
}