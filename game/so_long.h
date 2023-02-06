/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:40:01 by vpescete          #+#    #+#             */
/*   Updated: 2023/02/06 19:28:39 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include <zlib.h>
# include "../ft_printf/ft_printf.h"
# include <sys/time.h>

typedef struct s_object {
	int	player;
	int	collectibles;
	int	escape;
}				t_object;

typedef struct s_textures {
	void	*background;
	void	*wall;
	void	*escape[12];
	void	*player[2];
	void	*collectible[12];
	void	*win_screen[2];
}				t_textures;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_game {
	void			*mlx;
	void			*mlx_win;
	char			**map;
	t_textures		*images;
	t_object		*object;
	t_vector		*vector;
	t_vector		*vect_exit;
	int				count;
	int				coins_collected;
	struct timeval	curr_tm;
	int				index;
	int				widht;
	int				height;
	int				counter;
	int				color;
	int				pov;
}				t_game;

/* function to check possible errors */

int			ft_check_error(int ac, char **av);
int			ft_check_lenline(char **map, int count);
void		check_wall(char **map, int count);
int			check_min_requires(t_game *game);
int			check_ber_ext(char *av, size_t len);
void		ft_check_rect(t_game *game);

/* function to load the map and the img */
t_game		*ft_preload(char *map_name, t_game *game, void *mlx);
char		**ft_load_map(char *map_name);
void		ft_load_obj(t_game *game);
void		ft_load_img(t_game *game);
void		ft_base_layer(int count, int len,
				t_textures *textures, t_game *game);
void		ft_check_w_and_b(t_game *game, int i, int j);
void		ft_check_e_p_c(t_game *game, int i, int j);
void		ft_load_frame_escape(t_game *game);
void		ft_load_frame_coin(t_game *game);
void		ft_load_frame_player(t_game *game);
void		ft_load_frame_winscreen(t_game *game);

/* function for keyboard */
void		ft_close(t_game *vars);
int			ft_key_control(int keycode, t_game *vars);
void		ft_move_right(t_game *vars);
void		ft_move_left(t_game *vars);
void		ft_move_up(t_game *vars);
void		ft_move_down(t_game *vars);

int			ft_map_height(char	*map_name);
void		ft_charge_map_on_screen(t_game *game);
void		ft_win(t_game *game);
int			ft_gettimestamp(t_game *game);
int			ft_next_frame(t_game *game);
char		*ft_itoa(int n);
int			create_trgb(unsigned char t, unsigned char r, unsigned char g,
			unsigned char b);
void		ft_put_img_to_win(t_game *game);

#endif