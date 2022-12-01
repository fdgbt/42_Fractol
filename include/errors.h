/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:46:46 by fdagbert          #+#    #+#             */
/*   Updated: 2021/03/23 22:46:49 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H

# define ERRORS_H
# define D_ERR_MALLOC -1
# define D_MES_MALLOC "Memory limit (malloc)."
# define D_ERR_OPT_KEY -2
# define D_MES_OPT_KEY "Invalid option (wrong opt key)."
# define D_ERR_OPT_ARG -3
# define D_MES_OPT_ARG "Invalid option (wrong or missing opt arg)."
# define D_ERR_FRACTAL_WRONG -4
# define D_MES_FRACTAL_WRONG "Invalid argument (wrong fractal name)."
# define D_ERR_FRACTAL_MUCH -5
# define D_MES_FRACTAL_MUCH "Invalid argument (too much fractals)."
# define D_ERR_FRACTAL_MISS -6
# define D_MES_FRACTAL_MISS "Missing argument (no fractal name)."
# define D_ERR_MAN_OPEN -7
# define D_MES_MAN_OPEN "Failed to open man (man file missing)."
# define D_ERR_MAN_CLOSE -8
# define D_MES_MAN_CLOSE "Failed to close man (wrong fd value)."
# define D_ERR_MLX_INIT -9
# define D_MES_MLX_INIT "Failed to set up connection to server X (mlx_init)."
# define D_ERR_MLX_NEW_WIN -10
# define D_MES_MLX_NEW_WIN "Failed to create new window (mlx_new_window)."
# define D_ERR_MLX_NEW_IMG -11
# define D_MES_MLX_NEW_IMG "Failed to create new image (mlx_new_image)."
# define D_ERR_MLX_GET_DATA -12
# define D_MES_MLX_GET_DATA "Failed to get image infos (mlx_get_data_addr)."
# define D_ERR_THREAD_CREATE -13
# define D_MES_THREAD_CREATE "Failed to create new thread (pthread_create)."
# define D_ERR_THREAD_JOIN -14
# define D_MES_THREAD_JOIN "Failed to process multi-threading (pthread_join)."
# define D_ERR_FDF_CREATE -15
# define D_MES_FDF_CREATE "Failed to create FdF file (open)."
# define D_ERR_FDF_CLOSE -16
# define D_MES_FDF_CLOSE "Failed to close FdF file (close)."

#endif
