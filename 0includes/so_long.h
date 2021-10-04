/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:21:07 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/04 11:53:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# define UNIT_HEIGHT 70
# define UNIT_WIDTH 70
# define TOTAL_IMAGES 2
# define WINDOW_NAME "Aquelarre"

# define PATH_MAP "./0images/map2.ber"
# define PATH_CHARACTER "./0images/witch2.xpm"
# define PATH_CHARACTER2 "./0images/witch3.xpm"
# define PATH_BACKGROUND "./0images/grass.xpm"
# define PATH_WALL "./0images/wall.xpm"

//1920, 1080
//2560, 1440 mac screen
//36 de largo
//70 x 70

/** PURPOSE : struct of a vector, 2D representation. */
typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

/** PURPOSE : struct that stores image data. */
typedef struct	s_data
{
	void		*img;
	char		*addr;
	t_vector	coords;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_databaseimages
{
	t_data		*sprite1;
	t_data		*sprite2;
}				t_imagedb;

/** PURPOSE : struct that stores pointers of the mxl init and
 * the window init. Both pointers will be constantly refered to */
typedef struct	s_program
{
	void		*mlx_pointer;
	void		*window;
	t_vector	array_dimensions;
	char		**map2D;
	int			number_images;
	t_imagedb	*database;
}				t_program;




/* MAP PARSER */
t_vector	get_dimensions(t_list *list_map);
char		**fix_map(t_list *list_map, t_vector dimensions);
t_list		*read_map(void);
/* WINDOW CONTROL INIT AND HOOKS */
void		init_game(t_program *game);
void		init_window(t_program *game, t_vector window_dimensions);
/* WINDOW SIZE */
t_vector	get_window_dimensions(t_vector dimensions);
/* IMAGE TREATMENT */
void		initalize_image(t_program *game, t_data *image);
void		create_mold(t_data *image);
void		put_pixel(t_data *data, int x, int y, int color);
void		push_image_towindow(t_program *game, t_data *image, t_vector coords);
/* CREATE SPRITES */
t_data		*ft_newsprite(t_program *game, char *path);

void	put_floor_and_walls(t_program *game);

/* CLEAR MEMORY */
void	full_shutdown(t_program *game);

/* RNDM DRAWING */
void		ft_draw(t_program *game, int x, int y, int color);
void		ft_draw_up(t_program *game, int x, int y, int color);
#endif
