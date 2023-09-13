/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:05:52 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/08 17:17:04 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minitalk.h"

static void	ft_handler(int signal, siginfo_t *info, void *context);
static void	ft_print_string(t_list *lst);

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID is : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

static void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static int		i = 0;
	static t_list	*lst = NULL;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			ft_print_string(lst);
			kill(info->si_pid, SIGUSR2);
			lst = NULL;
		}
		ft_lstadd_back(&lst, i);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	ft_print_string(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		ft_printf("%c", lst->data);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	ft_printf("\n");
}
