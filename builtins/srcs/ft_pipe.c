/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:47:15 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/11 15:17:58 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_pipe(char **f_input, char **f_ouput, char **envp)
{
	int fd[2];
	int pid1;
	int pid2;

	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();
	if (pid1 < 0)
		return (0);
	if (pid1 == 0)
	{
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(f_input[0], f_input, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (0);
	if (pid2 == 0)
	{
		dup2(fd[1], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(f_ouput[0], f_ouput, envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	ft_multi_pipe(char ***cmd, char **envp, int fd[2][2])
{
	int pid1;
	int pid2;
	int pid3;

	if (pipe(fd[0]) == -1)
		return ;
	if (pipe(fd[1]) == -1)
		return ;
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[0][0], STDOUT_FILENO);
		//close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[1][0]);
		execve(cmd[0][0], cmd[0], envp);
	}
	pid2= fork();
	if (pid2 == 0)
	{
		dup2(fd[0][1], STDIN_FILENO);
		dup2(fd[1][0], STDOUT_FILENO);
		close(fd[1][1]);
		close(fd[0][0]);
		execve(cmd[1][0], cmd[1], envp);
	}
	pid3 = fork();
	if (pid3 == 0)
	{
		dup2(fd[1][1], STDIN_FILENO);
		close(fd[1][0]);
		close(fd[0][0]);
		close(fd[0][1]);
	}
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
}

int main(int ac, char **av, char **envp)
{
	int fd[2][2];
	char *sleep1[] = {"/bin/cat", NULL};
	char *sleep2[] = {"/bin/cat", NULL};
	char *sleep3[] = {"/bin/ls", NULL};
	char **cmd[] = {sleep1, sleep2, sleep3, NULL};
	//ft_pipe(&av[1], &av[3], envp);
	ft_multi_pipe(cmd, envp, fd);
	return (0);
}