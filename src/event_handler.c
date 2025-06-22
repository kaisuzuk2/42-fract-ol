/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:33:50 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 19:33:46 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	event_handler(t_data *data)
{
	mlx_destroy_image(data->win.mlx, data->img.img);
	mlx_destroy_window(data->win.mlx, data->win.mlx_win);
	exit(0);
}
