/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:24 by kaan              #+#    #+#             */
/*   Updated: 2023/12/02 12:47:56 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	byteread;
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		return (NULL);
	}
	byteread = read(fd, buffer, BUFFER_SIZE);
	if (byteread == -1)
	{
		free(buffer);
		return (NULL);
	}
	else if (byteread == 0)
	{
		free(buffer);
		return (NULL);
	}
	else
	{
		//look for the first new line
		ft_strchr(buffer, '\n');

	}
	buffer[byteread] = '\0';
	return (buffer);
}

int main()
{
	const char  *filename = "test";
    char	    *buffer;
	int         fd;

    fd = open(filename, O_RDONLY);
    buffer = get_next_line(fd);
	printf("\n\n\n");
	buffer = get_next_line(fd);

	//printf("fd:%d\n", fd);
	//printf("%s\n", buffer);
    free(buffer);
	close(fd);
}
