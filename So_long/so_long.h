/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:21:38 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:30:17 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define     PL_FT "xpms/player_front.xpm"
# define     GR "xpms/game_ground.xpm"
# define     WLL "xpms/wall.xpm"
# define     COIN "xpms/coin.xpm"
# define     DOR "xpms/door.xpm"

# include <stdarg.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	int		mat_y;
	int		mat_x;
	void	*mlx;
	void	*mlx_window;
	void	**img;
	char	*x;
	int		imgx;
	int		imgy;
	int		position_x;
	int		position_y;
	int		key;
	char	**map;
	char	**controlmap;
	int		height;
	int		width;
	int		step;
	int		collectnum;
	int		coin;
	int		exit;
	int		player_num;
}				t_data;

int		find_player_x(char *map[]);
int		find_player_y(char *map[]);

void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);

int		ft_keyboard(int keyhook, t_data *data);
void	map_is_space(t_data *data);

void	find_player(t_data *data);
void	recursive_control(t_data *data, int y, int x);
void	start_control(t_data *data, int y, int x);
void	second_control(t_data *data, int y, int x);
void	third_control(t_data *data, int y, int x);
void	fourth_control(t_data *data, int y, int x);

void	exit_check(char *map[]);
void	coin_check(char *map[]);

void	left_top_wall_control(t_data *data);
void	right_bottom_wall_control(t_data *data);
void	playable_control(t_data *data);
void	map_checking(t_data *data);

void	line_control(t_data *data);
void	collectable_control(t_data *data);
void	unreachable_exit_control(t_data *data);
void	door_control(t_data *data);
int		bercheck(char *s);
void	hookles(t_data *data);
void	ft_putimages1(t_data *data, int mat_x, int mat_y);
void	ft_key_hook(int keyhook, t_data *data);
void	can_go_exit(t_data *data);
void	ft_putimages(t_data *data);
void	ft_window(t_data *data);
void	*ft_calloc(size_t count, size_t size);
int		map_width(char *map[]);
int		map_height(char *map[]);
int		ft_close(int key, t_data *data);
int		mouse(int button, int x, int y, t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

void	mapreader(t_data *data, char *map);
void	player_num_control(t_data *data);

void	ft_putstr(char *s, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putchar(char c, int *result);
void	ft_dhex(unsigned int i, int *result);
void	ft_uhex(unsigned int i, int *result);
void	ft_unsigned(unsigned int i, int *result);
void	ft_pointer(unsigned long long i, int *result);
void	ft_check(va_list *list, char a, int *result);
int		ft_printf(const char *s, ...);

void	ft_argcheck(char *map[]);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ftcount(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_read(int fd, char *left_str);
int		exit_function(t_data *data);

#endif
