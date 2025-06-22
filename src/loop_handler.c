/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:20:25 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 20:28:51 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	render(data, 300 + log(data->win.zoom) * 50);
	return (0);
}
