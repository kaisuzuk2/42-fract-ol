/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:40:21 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/22 16:36:52 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static void	print_usage(void)
{
	ft_printf("usage: \n");
	ft_printf("mandelbrot: ./fractol m\n");
	ft_printf("julia     : ./fractol j <real> <imag>\n");
}

static bool	check_num(const char *nptr)
{
	int	dot_count;

	dot_count = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr) && !(*nptr == '.'))
			return (FALSE);
		if (*nptr == '.')
			dot_count++;
		nptr++;
	}
	if (dot_count > 1)
		return (FALSE);
	return (TRUE);
}

bool	parse(int argc, char *argv[], t_data *data)
{
	if (argc < 2)
		return (print_usage(), FALSE);
	if (!ft_strcmp(argv[1], "m") && argc == 2)
	{
		data->f = mandelbrot;
		data->z0.real = 0;
		data->z0.imag = 0;
	}
	else if (!ft_strcmp(argv[1], "j") && argc == 4)
	{
		if (!check_num(argv[2]) || !check_num(argv[3]))
			return (print_usage(), FALSE);
		data->f = julia;
		data->z0.real = ft_atof(argv[2]);
		data->z0.imag = ft_atof(argv[3]);
	}
	else
		return (print_usage(), FALSE);
	return (TRUE);
}