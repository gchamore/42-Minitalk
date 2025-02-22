/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:25:30 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/19 10:56:06 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("\033[1;32m\n");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝");
	ft_printf("\033[0m\n\n");
	ft_printf("\033[1;33mHey bud ! Welcome to my serv !\033[0m\n\n");
	ft_printf("✔️  \033[1;32mIf you want to send me a message my PID is : ");
	ft_printf("\033[1;33m- %d -\033[5;33m\n\n", getpid());
	ft_printf("------------------ 🌈 PRINT ZONE BELOW 🌈 ------------------");
	ft_printf("\033[0m\n\n");
	signal_received.sa_sigaction = ft_get_signal;
	signal_received.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_received.sa_mask);
	if (sigaction(SIGUSR1, &signal_received, NULL) == -1 || \
	sigaction(SIGUSR2, &signal_received, NULL) == -1)
		ft_error_handler(1);
	while (1)
		pause();
	return (0);
}

void	ft_get_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	result = 0;
	static int				bit = 1;
	static int				id = 0;
	static char				*final;

	if (!final)
	{
		final = ft_strdup("");
		if (!final)
			exit(EXIT_FAILURE);
	}
	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (signal == SIGUSR2)
		result += bit;
	bit *= 2;
	if (bit == 256)
	{
		bit = 1;
		get_signal_2(result, id, &final);
		result = 0;
	}
	if (kill(id, SIGUSR1) == -1)
		ft_error_handler(0);
}

void	get_signal_2(unsigned char result, int id, char **final)
{
	if (!final)
		exit(EXIT_FAILURE);
	*final = char_to_str(*final, result);
	if (!final)
		exit(EXIT_FAILURE);
	if (result == 0)
	{
		ft_print_final_str(*final, id);
		free(*final);
		*final = NULL;
	}
}

char	*char_to_str(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1)
		exit(EXIT_FAILURE);
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free ((void *)(s1));
	return (tab);
}

void	ft_print_final_str(char *final, int id)
{
	if (!final)
		exit(EXIT_FAILURE);
	ft_printf("🚀 \033[1;32mMessage from space X ship 🚀     =     ");
	ft_printf("\033[1;33m...%s... \033[0m\n", final);
	if (ft_strncmp(final, "stop", 5) == 0)
	{
		if (kill(id, SIGUSR2) == -1)
			ft_error_handler(0);
		ft_printf("\033[1;32m");
		ft_printf("Received 'stop' command. Shutting down in 5... 💣 \n");
		sleep(1);
		ft_printf("4...............\n");
		sleep(1);
		ft_printf("3...........\n");
		sleep(1);
		ft_printf("2.......\n");
		sleep(1);
		ft_printf("1.....\n");
		sleep(1);
		ft_printf("0..\033[0m\n");
		free(final);
		exit(0);
	}
	if (kill(id, SIGUSR2) == -1)
		ft_error_handler(0);
}
