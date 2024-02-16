/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:16:35 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/16 14:24:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	data;

	if (argc != 5)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MESSAGE_ARGS);
		exit(EXIT_FAILURE);
	}
	init_pipex_data(&data);
	get_env_paths(&data, envp);
	get_commands(&data, argc, argv);
	make_pipes(&data);
	exec_commands(&data);
	wait_pids(&data);
	return (0);
}
