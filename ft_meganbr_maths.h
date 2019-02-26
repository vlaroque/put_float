/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meganbr_maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:20:51 by vlaroque          #+#    #+#             */
/*   Updated: 2019/02/26 19:23:14 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEGANBR_MATHS_H
# define FT_MEGANBR_MATHS_H

# include "ft_float_2_str.h"

ullong	*meganbr_multiplybytwo(ullong *meganbr);
ullong	*meganbr_dividebytwo(ullong *meganbr);
ullong	*meganbr_two_exp(int exp);
ullong	*meganbr_exp(ullong *meganbr, int exp);
ullong	*meganbr_add(ullong *meganbr, ullong *added);

#endif