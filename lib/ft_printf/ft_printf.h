/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:33:39 by ggochita          #+#    #+#             */
/*   Updated: 2023/03/23 22:34:29 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdint.h>

int		ft_printf(const char *strf, ...);
int		ft_format(va_list args, const char format);
int		ft_hex_len(unsigned int num);

int		ft_putnbr_len(int c);
int		ft_putstr_len(char *str);
int		ft_print_hex(unsigned int num);
int		ft_print_hex_upr(unsigned int num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_uint(unsigned int n);

void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);

#endif
