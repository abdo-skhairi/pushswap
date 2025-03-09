/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:00:01 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 14:58:00 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	total;

	total = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total = total * 10 + (*str - '0');
		str++;
	}
	if ((sign == 1 && total > INT_MAX)
		|| (sign == -1 && total > (long long)INT_MAX + 1))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (total * sign);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	validation(char *str)
{
	int	i;

	i = 0;
	if ((!(str[0] >= '0' && str[0] <= '9') && str[1] == '\0') || str[0] == '\0')
		return (-1);
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (!str[i])
			break ;
		while ((str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] != '\0'
			&& !ft_strchr(" \t+-", str[i]) && !(str[i] >= '0' && str[i] <= '9'))
			return (-1);
	}
	return (0);
}
