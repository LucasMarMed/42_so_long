/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:30:16 by lumarque          #+#    #+#             */
/*   Updated: 2023/04/23 18:48:31 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (last occurence)
**
** DESCRIPTION:
** 		The strrchr() function locates the last occurrence of c (converted to a
**	char) in the string s.  If c is `\0', strrchr() locates the terminating
**	`\0'.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*str;

	str = (char *)s;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (str[l] == ((char)c))
			return (&str[l]);
		l--;
	}
	return (0);
}
