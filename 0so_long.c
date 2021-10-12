/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:20:33 by guilmira          #+#    #+#             */
/*   Updated: 2021/10/12 15:40:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

/* if (!game->window) //might need to free window later on. check manual..
		full_shutdown(game, 3); */

/** PURPOSE : recieve argumens, build map2D and execute parser.
 * 1. Declare list and read file.ber.
 * 2. Get dimensions of map and built it into a 2D array.
 * 3. Clear list.
 * 4. Exceute parser of map. */
static void	parser_and_management(t_program *game)
{
	int		parser;
	t_list	*list_map;

	parser = 0;
	list_map = NULL;
	list_map = read_map();
	//list_map = NULL; si lo usas mete fullclear
	if (!list_map)
		full_shutdown(game, 2);
	game->array_dimensions = get_dimensions(list_map);
	game->map2D = fix_map(list_map, game->array_dimensions);
	ft_fullclear(list_map);
	parser = parser_map(game->map2D, game->array_dimensions);
	//game->map2D = NULL; //aqui puede Leaks. serio.
	if (!(game->map2D))
		full_shutdown(game, 2);
	if (parser)
		full_shutdown(game, parser);
	game->total_collectables = get_collectables(game->map2D, \
	game->array_dimensions);
}

/** PURPOSE : load images, animations, and write both into screen. */
static void	images_and_layers(t_program *game)
{
	game->static_images = load_images(game);
	game->animations = load_animations(game);
	game->animations_exit = load_animations2(game);
	game->character_coords = element_position(game->map2D, \
	game->array_dimensions, CHARACTER);
	game->exit_coords = element_position(game->map2D, \
	game->array_dimensions, EXIT);
	put_layers(game);
}

/** PURPOSE : execute main routine of program */
static void	hooks_and_loops(t_program *game)
{
	mlx_key_hook(game->window, movement_character, game);
	mlx_loop_hook(game->mlx_pointer, next_frame, game);
	mlx_loop(game->mlx_pointer);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures. */
int	main(void)
{
	t_program	*game;

	//atexit(leaks);
	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_shutdown();
	init_game(game);
	/* if (1)
	{
		printf("HEyyy\n");
		full_shutdown(game, 2);
	} */
	parser_and_management(game);
	init_window(game, get_window_dimensions(game->array_dimensions));
	images_and_layers(game);
	hooks_and_loops(game);
	return (0);
}
