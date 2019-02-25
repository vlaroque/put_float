/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbl_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:31:20 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/25 21:32:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_float_2_str.h"

int		ullong_to_str(char *str, ullong nbr)
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

ullong	*meganbr_be_str(ullong *meganbr)
{
	int i;
	int j;
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
	printf(">>%s\n", strnbr);
	return (0);
}

ullong	*meganbr_multiplybytwo(ullong *meganbr)
{
	int		i;
	ullong	carry;
	ullong	tmp;

	i = MEGALEN - 1;
	carry = 0;
	while (i >= 0)
	{
		tmp = meganbr[i];
		meganbr[i] = ((tmp * 2) + carry) % 1000000000000000000;
		carry = ((tmp * 2) + carry) / 1000000000000000000;
		i--;
	}
	return (meganbr);
}

ullong	*meganbr_dividebytwo(ullong *meganbr)
{
	int		i;
	ullong 	tmp;
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

	if(!(meganbr = malloc(sizeof(ullong) * MEGALEN)))
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

static long double	two_exp(int exp)
{
	long double		res;

	res = 1.0;
	if (exp == 0)
		return((long double)1.0);
	else if (exp == 1)
		return ((long double)2.0);
	else if (exp < 0)
		while (exp++ < 0)
			res /= 2.0;
	else if (exp > 0)
		while (exp-- > 0)
			res *= 2.0;
	return (res);
}

static int			get_exp(long double nbr)
{
	int		pwr;

	pwr = 0;
	if (nbr >= 1)
	{
		while (nbr >= 1)
		{
			nbr /= 2.0;
			pwr += 1;
		}
		pwr -= 1;
	}
	else if (nbr < 1)
	{
		while (nbr < 1)
		{
			nbr *= 2.0;
			pwr -= 1;
		}
	}
	return (pwr);
}

static int	sign_ldbl(long double *nbr)
{
	int sign;

	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		sign = -1;
	}
	return (sign);
}

char		*ft_ldbl_2_str(long double nbr)
{
	int		expt;
	int		sign;
	ullong	*added;
	ullong	*meganbr;

	if (!(meganbr = malloc(sizeof(char) * LDBL_LEN)))
		return (NULL);
	sign = sign_ldbl(&nbr);
	expt = get_exp(nbr);
	nbr /= two_exp(expt);
	added = meganbr_two_exp(1);
	while(nbr > 0.0)
	{
		if (nbr >= 1.0)
		{
			added = meganbr_dividebytwo(added);
			meganbr = meganbr_add(meganbr, added);
			nbr = nbr - 1.0;
		}
		nbr *= 2.0;
	}
	free(added);
	meganbr = meganbr_exp(meganbr, expt);
	meganbr_be_str(meganbr);
	return (0);
}