/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:29:00 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/15 16:59:48 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft.h"

typedef struct s_toolbox
{
	char		*final;
	unsigned char result;
	int id;


	
}	t_toolbox;


//////////////////////////
//         CLIENT       //
//////////////////////////

void	ft_to_server(int pid, char *message);
void	ft_message_is_over(int pid);
void	ft_confirmation_handler(int signal, siginfo_t *info, void *context);

//////////////////////////
//         SERVER       //
//////////////////////////

void	ft_get_signal(int signal, siginfo_t *info, void *context);
int		ft_power(int nb, int power);
char	*char_to_str(char const *s1, char const letter);
void	ft_print_final_str(char *final, int id);
int	check_signal(int signal, int *bit, char result);


//////////////////////////
//         SERVER       //
//////////////////////////

void	ft_error_handler(int i);

#endif