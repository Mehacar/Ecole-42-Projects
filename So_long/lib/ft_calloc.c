/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:19:03 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:19:04 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	mem;

	mem = count * size;
	ptr = malloc(mem);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mem);
	return (ptr);
}
