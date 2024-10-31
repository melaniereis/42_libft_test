/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:15:14 by meferraz          #+#    #+#             */
/*   Updated: 2024/10/22 10:31:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../includes/libft.h"

// COLORS
# define RESET "\033[0m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define BLUE "\033[0;34m"

// For final summary test
extern void save_test_results(const char *test_name, int total, int failed);

// Mandatory Part 1
void	ft_isalpha_test(void);
void	ft_isdigit_test(void);
void	ft_isupper_test(void);
void	ft_islower_test(void);
void	ft_isalnum_test(void);
void	ft_isascii_test(void);
void	ft_isprint_test(void);
void	ft_strlen_test(void);
void	ft_memset_test(void);	
void	ft_bzero_test(void);
void	ft_memcpy_test(void);
void	ft_memmove_test(void);
void	ft_strlcpy_test(void);
void	ft_strlcat_test(void);
void	ft_toupper_test(void);
void	ft_tolower_test(void);
void	ft_strchr_test(void);
void	ft_strrchr_test(void);
void	ft_strncmp_test(void);
void	ft_memchr_test(void);
void	ft_memcmp_test(void);
void	ft_strnstr_test(void);
void	ft_atoi_test(void);
void	ft_calloc_test(void);
void	ft_strdup_test(void);

// Mandatory Part 2
void	ft_substr_test(void);
void	ft_strjoin_test(void);
void	ft_strtrim_test(void);
void	ft_split_test(void);
void	ft_itoa_test(void);
void	ft_strmapi_test(void);
void	ft_striteri_test(void);
void	ft_putchar_fd_test(void);
void	ft_putstr_fd_test(void);
void	ft_putendl_fd_test(void);
void	ft_putnbr_fd_test(void);

// Bonus Part
void	ft_lstnew_test(void);
void	ft_lstadd_front_test(void);
void	ft_lstsize_test(void);
void	ft_lstlast_test(void);
void	ft_lstadd_back_test(void);
void	ft_lstdelone_test(void);
void	ft_lstclear_test(void);
void	ft_lstiter_test(void);
void	ft_lstmap_test(void);

#endif
