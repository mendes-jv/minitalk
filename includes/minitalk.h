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
#  define BYTE_CONFIRMATION_MESSAGE "Character has been sucessfully receieved\n"
# endif //BYTE_CONFIRMATION_MESSAGE

# ifndef SENDING_BYTE_MESSAGE
#  define SENDING_BYTE_MESSAGE "Sending byte: %c\n"
# endif //SENDING_BYTE_MESSAGE

# ifndef INVALIDS_ARGUMENTS_MESSAGE
#  define INVALIDS_ARGUMENTS_MESSAGE "Invalid arguments\n"
# endif //INVALIDS_ARGUMENTS_MESSAGE

# ifndef INVALID_PID_MESSAGE
#  define INVALID_PID_MESSAGE "Invalid PID\n"
# endif //INVALID_PID_MESSAGE

# ifndef SIGACTION_ERROR_MESSAGE
#  define SIGACTION_ERROR_MESSAGE "Failed to change signals' behaviour\n"
# endif //SIGACTION_ERROR_MESSAGE

# ifndef CONFIRMATION_MESSAGE_ERROR_MESSAGE
#  define CONFIRMATION_MESSAGE_ERROR_MESSAGE "Failed to send confirmation\n"
# endif //CONFIRMATION_MESSAGE_ERROR_MESSAGE

# ifndef EMPTY_STRING_MESSAGE
#  define EMPTY_STRING_MESSAGE "Empty message, there's nothing to send\n"
# endif //EMPTY_STRING_MESSAGE

# ifndef WAITING_FOR_CONNECTION_MESSAGE
#  define WAITING_FOR_CONNECTION_MESSAGE "Waiting for signals...\n\n"
# endif //WAITING_FOR_CONNECTION_MESSAGE

# ifndef SERVER_PID_MESSAGE
#  define SERVER_PID_MESSAGE "Server PID: %d\n"
# endif //SERVER_PID_MESSAGE

# ifndef THE_NUMBER_OF_THE_BEAST
#  define THE_NUMBER_OF_THE_BEAST 666
# endif //THE_NUMBER_OF_THE_BEAST

#endif //MINITALK_H
