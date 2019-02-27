/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meganbr_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:19:15 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/27 11:22:08 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_meganbr.h"

ullong	*meganbr_multiplybytwo(ullong *meganbr)
{
	int		i;
	ullong	carry;
	ullong	tmp;

	i = MEGALEN - 1;
	carry = 0;
	while (i >= 0)
	{
		tmp = ((meganbr[i] * 2) + carry);
		meganbr[i] = tmp % 1000000000000000000;
		carry = tmp / 1000000000000000000;
		i--;
	}
	return (meganbr);
}

ullong	*meganbr_dividebytwo(ullong *meganbr)
{
	int		i;
	ullong	tmp;
	ullong	carry;

	i = 0;
	carry = 0;
	while (i <= MEGALEN)
	{
		tmp = meganbr[i] + (carry * 1000000000000000000);
		meganbr[i] = tmp / 2;
		carry = tmp % 2;
		i++;
	}
	return (meganbr);
}

ullong	*meganbr_two_exp(int exp)
{
	ullong	*meganbr;

	if (!(meganbr = malloc(sizeof(ullong) * MEGALEN)))
		return (NULL);
	meganbr[MEGAUNIT] = 1;
	if (exp > 0)
	{
		while (exp > 0)
		{
			meganbr = meganbr_multiplybytwo(meganbr);
			exp--;
		}
	}
	else if (exp < 0)
	{
		while (exp < 0)
		{
			meganbr = meganbr_dividebytwo(meganbr);
			exp++;
		}
	}
	return (meganbr);
}

ullong	*meganbr_exp(ullong *meganbr, int exp)
{
	if (exp > 0)
	{
		while (exp > 0)
		{
			meganbr = meganbr_multiplybytwo(meganbr);
			exp--;
		}
	}
	else if (exp < 0)
	{
		while (exp < 0)
		{
			meganbr = meganbr_dividebytwo(meganbr);
			exp++;
		}
	}
	return (meganbr);
}

ullong	*meganbr_add(ullong *meganbr, ullong *added)
{
	int		i;
	ullong	carry;
	ullong	save;

	i = MEGALEN - 1;
	carry = 0;
	while (i >= 0)
	{
		save = meganbr[i] + added[i] + carry;
		meganbr[i] = save % 1000000000000000000;
		carry = save / 1000000000000000000;
		i--;
	}
	return (meganbr);
}
