/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:23:02 by asekkak           #+#    #+#             */
/*   Updated: 2022/10/18 16:29:55 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	len_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	len_len_word(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	*ft_free(char **ptr, int j)
{
	while (j-- > 0)
		free(ptr[j]);
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	ptr = (char **)malloc(sizeof(char *) * (len_word(s, c) + 1));
	if (!ptr)
		return (0);
	while (j < len_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		ptr[j] = ft_substr(s, i, len_len_word(s, c, i));
		if (!ptr)
			ft_free(ptr, j);
		j++;
		i += len_len_word(s, c, i);
	}
	ptr[j] = 0;
	return (ptr);
}
