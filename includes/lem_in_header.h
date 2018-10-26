/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:38:57 by lmatvien          #+#    #+#             */
/*   Updated: 2018/09/21 11:38:58 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_HEADER_H
# define LEM_IN_HEADER_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

# define ULLI		unsigned long long int
# define COMMENT		999
# define START_P		1
# define END_P		2
# define ORDNR_P		0
# define CHAIN		3
# define ERR			-1
# define SMLR_DATA	1
# define EMPTY_Q		0
# define ERR_2		-2
# define MOD_INFO 		2
# define MOD_WAYS	1
# define MOD_TOGTHR		3
# define MOD_ORDNR	0

int					g_fl;

typedef	struct		s_data
{
	int				x;
	int				y;
	int				id;
	char			*name;
	int				p_stts;
}					t_data;

typedef struct		s_rm
{
	char			*name;
	int				x;
	int				y;
	ULLI			id;
	ULLI			deep;
	int				p_stts;
	int				ant;
	short int		visited;
}					t_rm;

typedef struct		s_lst
{
	t_rm			*data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_tools
{
	int				s_name_0;
	int				s_name_1;
	t_lst			*point0;
	t_lst			*point1;
	t_lst			*lst_begin;
}					t_tools;

typedef struct		s_chain
{
	t_rm			*node;
	t_rm			*neighbor;
	struct s_chain	*next;
}					t_chain;

typedef	struct		s_queue
{
	t_rm			*data;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_road
{
	ULLI			*road;
	ULLI			*way;
	ULLI			*par;
}					t_road;

typedef struct		s_way
{
	ULLI			*way;
	ULLI			deep;
	struct s_way	*next;
}					t_way;

typedef struct		s_trush
{
	char			*line;
	struct s_trush	*next;
}					t_trush;

typedef struct		s_taker_lst
{
	int				ants;
	t_lst			*begin;
	t_lst			*curr;
	t_chain			*chain;
	t_chain			*chain_begin;
	t_queue			*queue_begin;
	t_queue			*queue_curr;
	t_way			ways;
	t_trush			*input_begin;
	t_trush			*input_curr;
}					t_taker_lst;

int					ln_reader(t_taker_lst *lst);
int					ln_alive_ant(t_taker_lst *lst);
int					ln_vertex(char *str, t_lst **lst, t_lst *begin, int *p_tts);
int					ln_wave_node(t_taker_lst *lst);
t_lst				*create_list(void);
t_chain				*create_chain_lst(void);
t_queue				*create_queue(void);
t_trush				*crt_list_trush(void);
int					ln_push_back_trush(t_trush **lst, char *line);
int					ln_queue_push_back(t_queue **q, t_rm *data, ULLI deep);
int					ln_queue_first_pop(t_queue **begin);
int					ln_push_back(t_lst **lst, t_data *data);
int					ln_push_chain(t_chain **cur, t_lst *data0, t_lst *data1);
int					push_back_way_lst(t_way **lst, ULLI deep);
void				lem_in_trush_prnt(t_trush *list);
int					ln_parse_chain(t_taker_lst *lst);
int					ln_analyzing_hash_param(char *str);
void				lem_in_test_print(t_lst *lst);
int					ln_print_ways(t_taker_lst *lst);
void				lem_in_ls_chain_print(t_chain *lst);
void				lem_in_ls_queue_print(t_queue *lst);
void				ln_lst_destroy(t_lst *lst);
void				ln_chain_destroy(t_chain *chain);
void				ln_queue_destroy(t_queue *lst);
void				ln_trsh_destroy(t_trush *lst);
char				*ln_undef_symbol(char *str);
int					ln_hash(char *str);
int					ln_cmp_lst_data(t_lst *lst, t_data *new_data);
int					ln_analyzing_data_chain(char *str, t_taker_lst *lst);
int					ln_point_stts(int status, int *p_stts);
void				ln_now_ants_will_go(t_taker_lst *lst);
void				ln_print(t_road *box, t_taker_lst *lst, ULLI deep);
int					lem_in_error_name(char *n0, char *n1);
int					ln_data_error(char *str);
int					ant_err(void);
#endif
