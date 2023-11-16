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

static void	signal_confirmation(int signal);
static void	send_msg(pid_t pid, char *string);

size_t	g_wait_signal = WAIT;

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;
	char				*message;

	if (!argv || argc != 3)
		ft_handle_error(INVALIDS_ARGUMENTS_MESSAGE);
	if (!ft_atoi(argv[1]))
		ft_handle_error(INVALID_PID_MESSAGE);
	if (!argv[2] || !*argv[2])
		ft_handle_error(EMPTY_STRING_MESSAGE);
	sig_action.sa_handler = signal_confirmation;
	sig_action.sa_flags = SA_DEFAULT;
	if (sigaction(SIGUSR1, &sig_action, NULL))
		ft_handle_error(SIGACTION_ERROR_MESSAGE);
	message = ft_strjoin(argv[2], "\n");
	send_msg(ft_atoi(argv[1]), message);
	free(message);
	return (EXIT_SUCCESS);
}

static void	signal_confirmation(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd(BIT_CONFIRMATION_MESSAGE, STDOUT_FILENO);
		g_wait_signal = CONTINUE;
	}
}

static void	send_msg(pid_t pid, char *string)
{
	size_t	byte_index;

	while (*string)
	{
		byte_index = 8;
		ft_putstr_color_fd(ANSI_COLOR_YELLOW,
			SENDING_BYTE_MESSAGE, STDOUT_FILENO);
		write(STDOUT_FILENO, string, CHAR_SIZE);
		write(STDOUT_FILENO, "\n", CHAR_SIZE);
		while (byte_index--)
		{
			g_wait_signal = WAIT;
			kill(pid, ft_ternary(*string >> byte_index & 1, SIGUSR2, SIGUSR1));
			while (!g_wait_signal)
				;
		}
		string++;
	}
}
