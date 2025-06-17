/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:21:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/17 14:23:24 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_window *win, t_img *img);

int	main(void)
{
	t_window win;
	t_img img;

	init(&win, &img);
	
	// 描画処理

	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, win.height,
		win.width);
	mlx_loop(win.mlx);
}