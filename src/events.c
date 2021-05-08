#include "../includes/cub3d.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->data.mlx, game->data.win);
	free(game->ray.dist_wall);
	exit(true);
	return (true);
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	if (key == W)
		game->player.walk_direction = +1;
	if (key == S)
		game->player.walk_direction = -1;
	if (key == A)
		game->player.left_right = +1;
	if (key == D)
		game->player.left_right = -1;
	if (key == RIGHT)
		game->player.turn_direction = +1;
	if (key == LEFT)
		game->player.turn_direction = -1;
	return (0);
}

int	release_key(int key, t_game *game)
{
	if (key == W)
		game->player.walk_direction = 0;
	if (key == S)
		game->player.walk_direction = 0;
	if (key == A)
		game->player.left_right = 0;
	if (key == D)
		game->player.left_right = 0;
	if (key == RIGHT)
		game->player.turn_direction = 0;
	if (key == LEFT)
		game->player.turn_direction = 0;
	return (0);
}
