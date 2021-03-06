/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_2_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:46:16 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/25 17:22:51 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_float_2_str.h"

char	*strnbr_bezero(char *str)
{
	int i;

	i = 0;
	while(i < LDBL_LEN)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*strnbr_bechars(char *str)
{
	int i;

	i = 0;
	while(i < LDBL_LEN)
	{
		str[i] = str[i] + '0';
		i++;
	}
	return (str);
}

char	*strnbr_multiplyby(char *str, int nbr)
{
	int i;
	int carry;
	int tmp;

	i = LDBL_LEN - 1;
	carry = 0;
	while (i >= 0)
	{
		tmp = str[i];
		str[i] = ((tmp * nbr) + carry) % 10;
		carry = ((tmp * nbr) + carry) / 10;
		i--;
	}
	return (str);
}

char	*strnbr_multiplybytwo(char *str)
{
	return (strnbr_multiplyby(str, 2));
}

char	*strnbr_dividebytwo(char *str)
{
	int i;

	i = LDBL_LEN - 1;
	str = strnbr_multiplyby(str, 5);
	while (i > 0)
	{
		str[i] = str[i - 1];
		i--;
	}
	return (str);
}

char	*strnbr_two_exp(int exp)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * LDBL_LEN)))
		return (NULL);
	str[UNIT] = 1;
	if (exp > 0)
	{
		while (exp > 0)
		{
			str = strnbr_multiplybytwo(str);
			exp--;
		}
	}
	else if (exp < 0)
	{
		while (exp < 0)
		{
			str = strnbr_dividebytwo(str);
			exp++;
		}
	}
	return (str);
}

char	*strnbr_exp(char *str, int exp)
{
	if (exp > 0)
	{
		while (exp > 0)
		{
			str = strnbr_multiplybytwo(str);
			exp--;
		}
	}
	else if (exp < 0)
	{
		while (exp < 0)
		{
			str = strnbr_dividebytwo(str);
			exp++;
		}
	}
	return (str);
}

char	*strnbr_add(char *strnbr, char *added)
{
	int i;
	int carry;
	int save;

	i = LDBL_LEN - 1;
	carry = 0;
	while(i >= 0)
	{
		save= strnbr[i];
		strnbr[i] = (save + added[i] + carry) % 10;
		carry = (save + added[i] + carry) / 10;
		i--;
	}
	return(strnbr);
}

long double	two_exp(int exp)
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

int			get_exp(long double nbr)
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
	char	*added;
	char	*nbr_str;

	if (!(nbr_str = malloc(sizeof(char) * LDBL_LEN)))
		return (NULL);
	sign = sign_ldbl(&nbr);
	expt = get_exp(nbr);
	nbr /= two_exp(expt);
	while(nbr > 0.0)
	{
		added = strnbr_two_exp(1);
		if (nbr >= 1.0)
		{
			added = strnbr_dividebytwo(added);
			nbr_str = strnbr_add(nbr_str, added);
			nbr = nbr - 1.0;
		}
		nbr *= 2.0;
		free(added);
	}
	nbr_str = strnbr_exp(nbr_str, expt);
	nbr_str = strnbr_bechars(nbr_str);
	printf(">>>nbrstr = |%s|\n", nbr_str);
	return (0);
}

/*
nbr : 	[0		-	19999] int part,
		[20000	-	39999] decimal part

	if (!(nbr_str = malloc(sizeof(char) * LDBL_LEN)))
		return (NULL);
	sign = sign_ldbl(&nbr);
	expt = get_exp(nbr);
	nbr /= two_exp(expt);
	while(nbr > 0.0)
	{
		if (nbr >= 1.0)
		{
			added = strnbr_two_exp(expt);
			nbr_str = strnbr_add(nbr_str, added);
			nbr = nbr - 1.0;
		}
		nbr *= 2.0;
		expt--;
	}
*/