/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:49 by jovicto2          #+#    #+#             */
/*   Updated: 2023/11/06 13:47:51 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	handle_signal(int signal, siginfo_t *info,
				__attribute__((unused)) void *ucontext);

size_t g_bit;

int	main(void)
{
	struct sigaction	sig_action;

	sig_action.sa_sigaction = handle_signal;
	sig_action.sa_flags = SA_SIGINFO;
	ft_putstr_color_fd(ANSI_COLOR_GREEN,
		SERVER_PID_MESSAGE, STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_color_fd(ANSI_COLOR_YELLOW,
		WAITING_FOR_CONNECTION_MESSAGE, STDOUT_FILENO);
	if (sigaction(SIGUSR1, &sig_action, NULL)
		|| sigaction(SIGUSR2, &sig_action, NULL))
		ft_handle_error(SIGACTION_ERROR_MESSAGE);
	while (THE_NUMBER_OF_THE_BEAST)
		pause();
}

static void	handle_signal(int signal, siginfo_t *siginfo,
				__attribute__((unused)) void *context)
{
	static u_char	byte;

	if (signal == SIGUSR2)
		byte |= 1;
	g_bit++;
	if (g_bit >= 8)
	{
		write(STDOUT_FILENO, &byte, CHAR_SIZE);
		g_bit = 0;
		byte = '\0';
	}
	byte <<= 1;
	if (kill(siginfo->si_pid, SIGUSR1))
		ft_handle_error(CONFIRMATION_MESSAGE_ERROR_MESSAGE);
}
