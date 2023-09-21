/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:18:44 by croy              #+#    #+#             */
/*   Updated: 2023/09/21 15:20:35 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	count_lines(char const *str, char c)
{
	size_t	i;
	size_t	lines;

	i = 0;
	lines = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			lines++;
		i++;
	}
	return (lines);
}

static char	*write_word(char *s1, char c)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	set_string(char **tab, char *str, char c)
{
	size_t	i;
	size_t	lines;
	size_t	was_sep;

	i = 0;
	was_sep = 1;
	lines = 0;
	while (str[i])
	{
		if (str[i] != c && was_sep)
		{
			tab[lines] = write_word(str + i, c);
			if (!tab[lines])
				return (free_tab(tab));
			lines++;
		}
		was_sep = (str[i] == c);
		i++;
	}
}

/**
 * @brief allocates a memory area and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter.
 * array ends with NULL pointer
 *
 * @param s string to split
 * @param c delimiter character
 * @return char** array of new strings resulting from the split,
 * NULL if allocation fails
 */
char	**ft_split(char const *s, char c)
{
	size_t	lines;
	char	**tab;

	tab = NULL;
	lines = 0;
	if (!s)
		return (NULL);
	lines = count_lines(s, c);
	tab = ft_calloc(lines + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	set_string(tab, (char *)s, c);
	if (tab)
		tab[lines] = NULL;
	return (tab);
}
