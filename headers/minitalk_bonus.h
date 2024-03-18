/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:29:00 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/18 17:53:02 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft.h"

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
void	ft_print_final_str(char *final, int id);
char	*char_to_str(char const *s1, char const letter);
void	get_signal_2(unsigned char result, int id, char **final);

//////////////////////////
//         TOOLS        //
//////////////////////////

void	ft_error_handler(int i);

#endif