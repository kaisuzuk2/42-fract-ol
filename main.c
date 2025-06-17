/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/17 21:30:51 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_window *win, t_img *img);
void draw_mandelbrot(t_img *img, int height, int width);

int	main(void)
{
	t_window win;
	t_img img;

	init(&win, &img);
	draw_mandelbrot(&img, win.height, win.width);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	
	mlx_loop(win.mlx);
}