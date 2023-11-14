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

static void	set_signals(void);
static void	handle_signal(int signal, siginfo_t *info,
				__attribute__((unused)) void *ucontext);

int	main(void)
{
	ft_putstr_color_fd(ANSI_COLOR_GREEN,
		SERVER_PID_MESSAGE, STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_color_fd(ANSI_COLOR_YELLOW,
		WAITING_FOR_CONNECTION_MESSAGE, STDOUT_FILENO);
	while (THE_NUMBER_OF_THE_BEAST)
		set_signals();
}

static void	set_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL)
		|| sigaction(SIGUSR2, &sa, NULL))
		ft_handle_error(SIGACTION_ERROR_MESSAGE);
}

static void	handle_signal(int signal, siginfo_t *siginfo,
				__attribute__((unused)) void *context)
{
	static size_t	byte_count;
	static u_char	byte;

	if (signal == SIGUSR2)
		byte |= (0b10000000 >> byte_count);
	byte_count++;
	if (byte_count >= 8 && byte)
	{
		write(STDOUT_FILENO, &byte, sizeof(char));
		byte_count = 0;
		byte = '\0';
		if (kill(siginfo->si_pid, SIGUSR1))
			ft_handle_error(CONFIRMATION_MESSAGE_ERROR_MESSAGE);
	}
}
