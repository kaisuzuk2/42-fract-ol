/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:20:25 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/23 00:28:35 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	render(data, MAX_ITER + log(data->win.zoom) * 50);
	return (0);
}
