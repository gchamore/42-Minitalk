/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:30:55 by gchamore          #+#    #+#             */
/*   Updated: 2024/03/18 19:23:01 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

void	ft_error_handler(int i)
{
	if (i == 0)
	{
		ft_printf("Error KILL\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("Error SIGACTION\n");
		exit(1);
	}
}

// Symboles unicode :
//😀
//❤️
//☀️
//⚽
//🍕
// 🌍
// 🎉
// 🎵
// 📷
// 🚀
// 🌈