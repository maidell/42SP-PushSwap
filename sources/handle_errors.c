/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 01:46:24 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 04:13:36 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char *argv[])
{
	if (invalid_number(argv) ||
		has_duplicates(argc, argv))
	{
		error_message();
		exit(1);
	}
}

int	invalid_number(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (not_digit(argv[i]) || limits_int(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	error_message(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

int	not_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		return (1);
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	limits_int(char *str)
{
	char	*converted_str;

	if (str[0] == '+')
		str++;
	while (str[0] == '0' && str[1] != '\0')
		str++;
	converted_str = ft_itoa(ft_atoi(str));
	if (ft_strncmp(converted_str, str, ft_strlen(str)) != 0)
	{
		free(converted_str);
		return (1);
	}
	free(converted_str);
	return (0);
}



int	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	argc = argc - 1;
	argv = argv + 1;
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
