/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:20:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/17 19:22:36 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

// 取り急ぎ定義　この値が正確なものか後で要確認
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -1.5
# define Y_MAX 1.5

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}			t_window;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

#endif