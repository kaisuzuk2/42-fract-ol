/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:40:21 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/21 19:48:06 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



#include <unistd.h>


static void print_usage(void)
{
	ft_printf("usage: \n");
	ft_printf("mandelbrot: ./fractol m\n");
	ft_printf("julia     : ./fractol j <real> <imag>\n");
}

bool parse(int argc, char *argv[], t_data *data)
{
	if (argc < 2)
		return (print_usage(), event_handler(&data->win), FALSE); // これもひどいね
	if (!ft_strncmp(argv[1], "m", 1) && argc == 2)
	{
		data->f = mandelbrot;
		data->c.real = 0;
		data->c.imag = 0;
	}
	else if (!ft_strncmp(argv[1], "j", 1) && argc == 4)
	{
		data->f = julia;
		data->c.real = ft_atof(argv[2]);
		data->c.imag = ft_atof(argv[3]);	
	}
	else
		return (print_usage(), event_handler(&data->win), FALSE); // これはひどいね
	return (TRUE);
}