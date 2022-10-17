/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:27:54 by alewalla          #+#    #+#             */
/*   Updated: 2022/03/24 11:40:30 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    int fd[2];
    int desc;
    int file;
    int pid1;
    int pid2;
    int d;

    if (pipe(fd) == -1)
        return (1);
    pid1 = fork();
    if(pid1 < 0)
        return(0);
    if (pid1 == 0)
    {
        dup2(fd[0], STDOUT_FILENO);
        close(desc);
        close(fd[0]);
        close(fd[1]);
        execve("echo", av, envp);
    }
    pid2 = fork();
    if(pid1 < 0)
        return(0);
    if(pid2 == 0)
    {
        dup2(fd[1], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve("pwd", av, envp);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}