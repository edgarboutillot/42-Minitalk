/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:31:51 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/08 17:17:54 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minitalk.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
