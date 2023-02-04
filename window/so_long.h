/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:40:01 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/04 11:48:14 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <stdio.h>
# include <zlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_textures {
	void	*background;
	void	*wall;
	void	*escape;
	void	*player;
}				t_textures;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	t_textures	*images;
}				t_game;

int		ft_check_lenline(char **map, int count);
int		check_wall(char **map, int count);
char	**ft_load_map(char *map_name);
int		ft_map_height(char	*map_name);
void	ft_load_img(t_textures *imges, t_game *game);
int		ft_check_error(int ac, char **av);
int		check_ber_ext(char *av, size_t len);
void	ft_charge_map_on_screen(char **map, int count, t_textures *texuters, t_game *game);
void	ft_load_game(t_game *game, t_textures *images);

// void	ft_open_win(void);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif