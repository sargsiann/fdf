/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:44:07 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/20 00:33:01 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *c);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c, int flag);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);


#endif