#include "../includes/cub3d.h"

void	along_map(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != '2' &&
			tab[i][j] != '0' && tab[i][j] != ' ' && tab[i][j] != 'N' &&
			tab[i][j] != 'S' && tab[i][j] != 'W' && tab[i][j] != 'E')
			{
				printf("MAP ERROR");
			}
			j++;
		}
		i++;
	}
}

void	map_extract(t_game *game, char *line, int fd)
{
	char	*str;
	char	*tmp;
	char	*new_line;
	int		gnl;

	gnl = -1;
	if (game->file.args != 8)
		printf("ERROR: WRONG NUMBER ARGUMENTS");
	str = ft_strjoin(line, "@");
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &new_line);
		if (new_line[0] == '\0')
			new_line[0] = ' ';
		tmp = str;
		str = ft_strjoin(str, new_line);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, "@");
		free(tmp);
		free(new_line);
	}
	game->file.tab = ft_split(str, '@');
	free(str);
	game->file.map_row = ft_strlen_ptr(game->file.tab);
}

void	map_error(t_game *game)
{
	int		x;
	int		y;
	char	**tmp;

	x = 0;
	while (game->file.tab[x] != NULL)
	{
		y = 0;
		tmp = ft_split(game->file.tab[x], ' ');
		while (tmp[y] != NULL)
		{
			if ((tmp[y][0] != '1' && tmp[y][0] != ' ')
				|| (tmp[y][ft_strlen(tmp[y]) - 1] != '1'
				&& tmp[y][ft_strlen(tmp[y]) - 1] != ' '))
			{
				printf("ERROR: MAP NOT CLOSED");
			}
			y++;
		}
		x++;
		table_free(tmp);
	}
}

void	map_check(t_game *game, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->file.max_line)
	{
		i = 0;
		while (i < game->file.map_row)
		{
			if (tab[i][j] == ' ')
			{
				if (i > 0)
					if (tab[i - 1][j] != '1' && tab[i - 1][j] != ' ')
						printf("ERROR: MAP ERROR");
				if (i < game->file.map_row - 1)
					if (tab[i + 1][j] != '1' && tab[i + 1][j] != ' ')
						printf("ERROR: MAP ERROR");
			}
			i++;
		}
		j++;
	}
}

void	is_map_closed(t_game *game, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < game->file.max_line)
	{
		if ((tab[0][j] != '1' && tab[0][j] != ' ')
			|| (tab[game->file.map_row - 1][j] != '1'
			&& tab[game->file.map_row - 1][j] != ' '))
			printf("ERROR: MAP NOT CLOSED");
		j++;
	}
}
