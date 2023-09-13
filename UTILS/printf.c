/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:24:21 by edboutil          #+#    #+#             */
/*   Updated: 2022/12/19 15:11:32 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#define BASE_DEC "0123456789"
#define BASE_HEXL "0123456789abcdef"
#define BASE_HEXU "0123456789ABCDEF"

#define LLU_INT long long unsigned int

static void	ft_putchar(char c, int *len)
{
	if (*len == -1)
		return ;
	if (write(1, &c, 1) == 1)
		(*len)++;
	else
		*len = -1;
}

static void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, len);
}

static void	ft_putnbr_base(LLU_INT n, char *base, int len_base, int *len)
{
	if (n >= (LLU_INT)len_base)
		ft_putnbr_base(n / len_base, base, len_base, len);
	ft_putchar(base[n % len_base], len);
}

static void	ft_conversion(va_list args, const char format, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'i' || format == 'd')
		ft_putnbr_base(va_arg(args, int), BASE_DEC, 10, len);
	else if (format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_DEC, 10, len);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_HEXL, 16, len);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), BASE_HEXU, 16, len);
	else if (format == '%')
		ft_putchar('%', len);
	else
		ft_putchar(format, len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] && len != -1)
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_conversion(args, format[++i], &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
