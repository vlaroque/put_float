/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_2_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:46:16 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/23 17:44:11 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long double	two_expt(int expt)
{
	long double		res;

	res = 1.0;
	if (expt == 0)
		return((long double)1.0);
	else if (expt == 1)
		return ((long double)2.0);
	else if (expt < 0)
		while (expt++ < 0)
			res /= 2.0;
	else if (expt > 0)
		while (expt-- > 0)
			res *= 2.0;
	return (res);
}

int			get_exp(long double nbr)
{
	int		expt;

	expt = 0;
	if (nbr >= 1)
	{
		while (nbr >= 1)
		{
			nbr /= 2.0;
			expt += 1;
		}
		expt -= 1;
	}
	else if (nbr < 1)
	{
		while (nbr < 1)
		{
			nbr *= 2.0;
			expt -= 1;
		}
	}
	return (expt);
}

char		*ft_ldbl_2_str(long double nbr)
{
	int		expt;
	int		sign;

	sign = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		sign = -1;
	}
	expt = get_exp(nbr);
	nbr /= two_expt(expt);
	while(nbr > 0.0)
	{
		if (nbr >= 1.0L)
		{
			printf("1");
			nbr = nbr - 1.0L;
		}
		else
			printf ("0");
		nbr *= 2.0;
		expt--;
	}
	while (expt-- >= 0)
		printf("0");
	printf("\n");
	//printf("expt = %d\n", expt);
	return (0);
}