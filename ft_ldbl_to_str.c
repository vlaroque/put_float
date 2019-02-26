/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbl_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:31:20 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/26 19:59:23 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float_2_str.h"
#include "ft_meganbr_maths.h"

int		ullong_to_printf(ullong *meganbr)
{
	int i;

	i = 0;
	while (i < MEGALEN)
	{
		if (meganbr[i])
			printf("%018lld.", meganbr[i]);
		i++;
	}
	return (0);
}

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
	//printf(">>%s\n", strnbr);
	return (0);
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
	if (nbr == 0.0)
		return (0);
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
		added = meganbr_dividebytwo(added);
		if (nbr >= 1.0)
		{
			meganbr = meganbr_add(meganbr, added);
			nbr = nbr - 1.0;
		}
		nbr *= 2.0;
	}
	free(added);
	meganbr = meganbr_exp(meganbr, expt);
	meganbr_be_str(meganbr);
	ullong_to_printf(meganbr);
	return (0);
}