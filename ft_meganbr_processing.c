/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meganbr_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:50:55 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/27 12:22:21 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_meganbr.h"

int		ullong_to_str(char *str, t_ullong nbr)
{
	str = str + 17;
	while (nbr)
	{
		*str = (nbr % 10) + '0';
		nbr = nbr / 10;
		str--;
	}
	return (0);
}

char	*meganbr_be_str(t_ullong *meganbr)
{
	int		i;
	int		j;
	char	*strnbr;

	i = 0;
	j = 0;
	if (!(strnbr = malloc(sizeof(char) * (STRNBRLEN + 1))))
		return (NULL);
	while (j < STRNBRLEN)
		strnbr[j++] = '0';
	while (i < MEGALEN)
	{
		ullong_to_str((strnbr + (i * 18)), meganbr[i]);
		i++;
	}
	strnbr[STRNBRLEN] = '\0';
	return (strnbr);
}
