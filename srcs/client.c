/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:13 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/19 10:56:40 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	confirmation_action;

	confirmation_action.sa_sigaction = ft_confirmation_handler;
	confirmation_action.sa_flags = SA_SIGINFO;
	sigemptyset(&confirmation_action.sa_mask);
	if (sigaction(SIGUSR1, &confirmation_action, NULL) == -1 || \
	sigaction(SIGUSR2, &confirmation_action, NULL) == -1)
		ft_error_handler(1);
	if (ac != 3)
	{
		ft_printf("⚠️  \033[1;31m");
		ft_printf("Utilisez le format: ./client <PID> <String>\033[0m\n");
		exit(EXIT_FAILURE);
	}
	ft_to_server(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}

void	ft_to_server(int pid, char *message)
{
	static int	bit = 0;
	static char	*message_bis = 0;

	if (message)
		message_bis = message;
	if (*message_bis)
	{
		if ((((unsigned char)*message_bis >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);
		if ((((unsigned char)*message_bis >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		bit++;
		if (bit == 8)
		{
			message_bis++;
			bit = 0;
		}
		usleep(50);
	}
	if (!(*message_bis))
		ft_message_is_over(pid);
}

void	ft_message_is_over(int pid)
{
	static int	i = 0;

	if (i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error_handler(0);
	}
	i++;
}

void	ft_confirmation_handler(int signal, siginfo_t *info, void *context)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (signal == SIGUSR1)
		ft_to_server(id, NULL);
	if (signal == SIGUSR2)
		exit(EXIT_SUCCESS);
	usleep(50);
}
