/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:37:27 by saeby             #+#    #+#             */
/*   Updated: 2022/10/25 15:27:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	to_trim(const char *set, char c);
static char	*new_str(const char *s1, size_t start, size_t end);

char	*ft_strtrim(const char *s1, const char *set)
{
	//char	*res;
	int		i;
	int		j;
	//int		k;

	/*res = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (NULL);*/
	i = 0;
	j = ft_strlen(s1) - 1;
	//k = 0;
	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, 1));
		//res[0] = 0;
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	/*
	while (k < j - (i - 1))
	{
		res[k] = s1[i + k];
		k++;
	}
	res[k] = '\0'; */
	return (new_str(s1, i, j - (i - 1)));
}

static char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start > len)
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("%s", ft_strtrim("ab cd  f    ", " "));
}
*/