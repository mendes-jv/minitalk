/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:35 by jovicto2          #+#    #+#             */
/*   Updated: 2023/11/06 13:47:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	set_signals(void);
static void	signal_confirmation(int signal);
static void	send_msg(pid_t pid, char *string);

static size_t	g_bytes_sent;

int	main(int argc, char **argv)
{
	char *message;

	if (!argv || argc != 3)
		ft_handle_error(INVALIDS_ARGUMENTS_MESSAGE);
	if (!ft_atoi(argv[1]))
		ft_handle_error(INVALID_PID_MESSAGE);
	if (!argv[2] || !*argv[2])
		ft_handle_error(EMPTY_STRING_MESSAGE);
	set_signals();
	message = ft_strjoin(argv[2], "\n");
	send_msg(ft_atoi(argv[1]), message);
	free(message);
	while (g_bytes_sent < ft_strlen(argv[2]) - 1)
		pause();
	exit(EXIT_SUCCESS);
}

static void	set_signals(void)
{
	struct sigaction	sig_action;

	sig_action.sa_handler = signal_confirmation;
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_action, NULL)
		|| sigaction(SIGUSR2, &sig_action, NULL))
		ft_handle_error(SIGACTION_ERROR_MESSAGE);
}

static void	signal_confirmation(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd(BYTE_CONFIRMATION_MESSAGE, STDOUT_FILENO);
		g_bytes_sent++;
	}
}

static void	send_msg(pid_t pid, char *string)
{
	size_t	byte_index;
	u_char	byte;

	while (*string)
	{
		byte = *string;
		byte_index = 8;
		ft_putstr_color_fd(ANSI_COLOR_YELLOW,
			SENDING_BYTE_MESSAGE, STDOUT_FILENO);
		write(STDOUT_FILENO, &byte, sizeof(char));
		write(STDOUT_FILENO, "\n", sizeof(char));
		while (byte_index--)
		{
			kill(pid, ft_ternary(byte >> byte_index & 1, SIGUSR2, SIGUSR1));
			usleep(MINIMAL_DELAY);
		}
		string++;
	}
}
