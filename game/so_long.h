/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:40:01 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/05 18:51:01 by vpescete         ###   ########.fr       */
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
# include "../ft_printf/ft_printf.h"

typedef struct	s_object {
	int	player;
	int	collectibles;
	int	escape;
}				t_object;

typedef struct s_textures {
	void	*background;
	void	*wall;
	void	*escape;
	void	*player;
	void	*collectible;
	void	*mlx;
}				t_textures;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_textures	*images;
	t_object	*object;
	t_vector	*vector;
	t_vector	*vect_exit;
	int			count;
	int			coins_collected;
	
}				t_game;

/* function to check possible errors */ 

int			ft_check_error(int ac, char **av);
int			ft_check_lenline(char **map, int count);
int			check_wall(char **map, int count);
int			check_min_requires(char **map, int count, t_game *game);
int			check_ber_ext(char *av, size_t len);

/* function to load the map and the img */ 
char		**ft_load_map(char *map_name);
t_game		*ft_load_game(t_textures *images, void *mlx);
t_textures	*ft_load_img(void *mlx);
void		ft_base_layer(int count, int len, t_textures *textures, t_game *game);

/* function for keyboard */
void		ft_close(t_game *vars);
int 		ft_key_control(int keycode, t_game *vars);
void		ft_move_right(t_game *vars);
void		ft_move_left(t_game *vars);
void		ft_move_up(t_game *vars);
void		ft_move_down(t_game *vars);

int			ft_map_height(char	*map_name);
void		ft_charge_map_on_screen(t_game *game);


#endif