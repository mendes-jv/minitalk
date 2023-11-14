/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:48:02 by jovicto2          #+#    #+#             */
/*   Updated: 2023/11/06 13:48:07 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//Headers
# include "../libraries/libft/includes/libft.h"
# include <signal.h>

//Macros
# ifndef BYTE_CONFIRMATION_MESSAGE
#  define BYTE_CONFIRMATION_MESSAGE "Byte has been successfully received\n"
# endif //BYTE_CONFIRMATION_MESSAGE

# ifndef CONFIRMATION_MESSAGE_ERROR_MESSAGE
#  define CONFIRMATION_MESSAGE_ERROR_MESSAGE "Failed to send confirmation\n"
# endif //CONFIRMATION_MESSAGE_ERROR_MESSAGE

# ifndef EMPTY_STRING_MESSAGE
#  define EMPTY_STRING_MESSAGE "Empty message, there's nothing to send\n"
# endif //EMPTY_STRING_MESSAGE

# ifndef INVALIDS_ARGUMENTS_MESSAGE
#  define INVALIDS_ARGUMENTS_MESSAGE "Invalid arguments\n"
# endif //INVALIDS_ARGUMENTS_MESSAGE

# ifndef INVALID_PID_MESSAGE
#  define INVALID_PID_MESSAGE "Invalid PID\n"
# endif //INVALID_PID_MESSAGE

# ifndef MINIMAL_DELAY
#  define MINIMAL_DELAY 50
# endif //MINIMAL_DELAY

# ifndef SERVER_PID_MESSAGE
#  define SERVER_PID_MESSAGE "\nServer PID: "
# endif //SERVER_PID_MESSAGE

# ifndef SENDING_BYTE_MESSAGE
#  define SENDING_BYTE_MESSAGE "Sending byte: "
# endif //SENDING_BYTE_MESSAGE

# ifndef SIGACTION_ERROR_MESSAGE
#  define SIGACTION_ERROR_MESSAGE "Failed to change signals' behaviour\n"
# endif //SIGACTION_ERROR_MESSAGE

# ifndef THE_NUMBER_OF_THE_BEAST
#  define THE_NUMBER_OF_THE_BEAST 666
# endif //THE_NUMBER_OF_THE_BEAST

# ifndef WAITING_FOR_CONNECTION_MESSAGE
#  define WAITING_FOR_CONNECTION_MESSAGE "\n\nWaiting for signals...\n\n"
# endif //WAITING_FOR_CONNECTION_MESSAGE

#endif //MINITALK_H
