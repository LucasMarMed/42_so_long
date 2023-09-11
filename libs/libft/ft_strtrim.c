/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:13:56 by lumarque          #+#    #+#             */
/*   Updated: 2023/04/19 21:02:26 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function allocates memory and returns a copy of the string passed in the
 * parameter but without any kind of blank spaces at the start or the end of
 * the string. This function considers blank spaces to be the characters ' ',
 * a standard space, '\n', a new line, and '\t', which is a tabulation space.
 * If there are no spaces at the beginning and end of the parameter string s
 * the function returns a copy of s. If the allocation of memory fails the
 * function returns NULL.*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
