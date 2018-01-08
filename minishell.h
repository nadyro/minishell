/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:24:01 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/12/07 05:52:01 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

char	**add_env(char **env, char *n);
void	bt_cd(char **as, char **env);
void	bt_echo(char **as);
char	**bt_setenv(char **as, char **env);
void	bt_unsetenv(char **as, char **env);
void	bt_env(char **as, char **env);
void	bt_exit(char **as, char **env);
void	cd_dash_n_go(char *d, char **env);
void	cd_home(char *h, char **env);
int		check_binary(char **as);
char	**copy_env(char **new_env, char **env, int x);
char	*check_env(char *as);
void	del_env(char **env, char *todel);
char	**dispatch_builtin(char **as, char **env);
char	**elag_env(char **env, char *pwd);
char	**fork_monastery(char *line, char **env);
void	free_tabz(char **as, char *tab);
char	*get_from_env(char **env, char *object, int l);
int		get_equal(char *env);
char	**get_path(char **env, char *path_name, char c);
void	get_child(char **as, char **env);
int		is_builtin(char **as);
char	*join_path(char *path, char *as);
void	path_rights(char *d);
void	print_bn(char **as, int i);
void	print_echo(char **as);
char	**swap_env(char **env, char *element, char *new_e);
void	terminate_fork(int x, char **as, char **env);
void	replace_env(char **env, char *to_r);
#endif
