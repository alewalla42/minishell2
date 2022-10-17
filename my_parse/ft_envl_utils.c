/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:04:16 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/07 14:30:16 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_get_name(char *str , char stop)
{
    int     i;
    char    *name;

    i = 0;
    while (str[i] && str[i] != stop)
        i++;
    if((str[i]))
    {
        name = (char *)malloc(sizeof(char) * i + 1);
        name[i] = '\0';
        while (--i >= 0)
            name[i] = str[i];
        return (name);
    }
    return (NULL);
}

char    *ft_get_value(char *str)
{
    int i;
    int len;
    int lim;
    char *ret;

    i = 0;
    while (str[i] && str[i] != '=')
        i++;
    if(str[i])
    {
        lim = i;
        len = 0;
        while (str[++i])
            len++;
        ret = (char *)malloc(sizeof(char) * len + 1);
        ret[len] = '\0';
        while (--len  >= 0)
            ret[len] = str[--i];
        return (ret);
    }
    return (NULL);
}

char    *ft_get_value_from_envl(t_env *envl, char *name)
{
    t_env   *tmp;

    tmp = envl->next_link;
    while(tmp->next_link != NULL)
    {
        if (ft_strcmp(name , tmp->name) == 0)
            return(tmp->value);
        tmp = tmp->next_link;
    }
    if (ft_strcmp(name , tmp->name) == 0)
            return(tmp->value);
    return ("\0");
}

void    ft_print_envl(t_env *envl)
{
    t_env *tmp;

    tmp = envl->next_link;
    while (tmp->next_link != NULL)
    {
        printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next_link;
    }
    printf("%s=%s\n", tmp->name, tmp->value);
    return;
}

void	ft_change_value(t_env *envl, char *name, char *value)
{
	t_env	*tmp;

	tmp = envl->next_link;
	while (tmp->next_link != NULL && (ft_strcmp(tmp->name, name) != 0))
		tmp = tmp->next_link;
	if (ft_strncmp(tmp->name, name, ft_strlen(name)))
		return ;
	tmp->value = value;
}

void	ft_join_value(t_env	*envl, char *name, char *value)
{
	t_env	*tmp;
	char	*buff;

	tmp = envl->next_link;
	while (tmp->next_link != NULL && (ft_strcmp(tmp->name, name) != 0))
		tmp = tmp->next_link;
	buff = ft_strjoin(tmp->value, value);
	free(tmp->value);
	tmp->value = buff;
}

int	ft_is_in_envl(t_env *envl, char *name)
{
	t_env	*tmp;

	tmp = envl->next_link;
	while (tmp->next_link != NULL)
	{
		if (ft_strncmp(name, tmp->name, ft_strlen(name)) == 0)
			return (1);
		tmp = tmp->next_link;
	}
	if (ft_strncmp(name, tmp->name, ft_strlen(name)) == 0)
		return (1);
	return (0);
}