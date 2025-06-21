/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:20:25 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 17:29:43 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int loop_handler(void *param)
{
	t_data *data = (t_data *)param;

	data->f(&data->win, &data->img, 300 + log(data->win.zoom) * 50); // logになるようにしよう　倍率に応じて倍倍になっていくようにね
	return (0);
}