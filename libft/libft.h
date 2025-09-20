/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:13:46 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/13 01:52:16 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

/* Get Next Line Buffer Size */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* Libft functions */
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);

/* Get Next Line  */
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);

/* Printf */
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *form, ...);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_print_hexa(unsigned long long nb, int uppercase);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putpercent(void);
int		ft_print_ptr(void *ptr);

#endif
