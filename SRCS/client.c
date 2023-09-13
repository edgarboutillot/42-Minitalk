/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:05:52 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/08 17:17:40 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minitalk.h"

int			ft_atoi(const char *str);
static void	ft_send_string(int pid, char *str);
static void	ft_send_char(int pid, char c);
static void	ft_handler(int signal, siginfo_t *info, void *context);

int	g_global;

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3 || !is_number(av[1]))
	{
		ft_printf("./client [PID] [message]\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (!pid || pid < 0)
	{
		ft_printf("PID invalid\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_send_string(pid, av[2]);
	return (0);
}

static void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR2)
		ft_printf("Message reçu\n");
	if (signal == SIGUSR1)
		g_global = 1;
}

static void	ft_send_string(int pid, char *str)
{
	int	i;

	i = 0;
	if (kill(pid, 0) < 0)
	{
		ft_printf("Can't send to PID %d", pid);
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}

static void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_global = 0;
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_global)
			usleep(1);
		bit++;
	}
}
