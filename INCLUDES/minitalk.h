/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:21:34 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/08 17:17:25 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// INCLUDE --------------------------------------
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

// TYPEDEF ------------------------------------------------
typedef struct s_list	t_list;

// STRUCT -------------------------------------------------
struct s_list
{
	char	data;
	t_list	*next;
};

// UTILS ----------------------------------------
int		ft_printf(const char *format, ...);
void	ft_lstadd_back(t_list **lst, char data);
int		ft_atoi(const char *str);
int		is_number(char *str);
int		is_digit(char c);

#endif
