#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_isalpha(int value);
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int value);
int	ft_isascii(int value);
int	ft_isdigit(int value);
int	ft_isprint(int value);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int ch, size_t len);
size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif