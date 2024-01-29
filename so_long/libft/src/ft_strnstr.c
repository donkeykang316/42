/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someng <someng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:37:47 by kaan              #+#    #+#             */
/*   Updated: 2023/11/22 11:45:38 by someng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && n >= needle_len)
	{
		if (*haystack == *needle
			&& ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		n--;
	}
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	return (NULL);
}
