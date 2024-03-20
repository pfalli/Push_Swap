/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:22:22 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/20 10:22:22 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s) // atoi that return long
{
	long value;
    int negative = 1;

    while (*s)
    {
        if(*s >= 9 && *s <= 13 || *s == ' ')
            s++;
    }
    if(*s == '-' || *s == '+')
    {
        if(*s == '-')
            negative = -1;
        s++;
    }
    while((*s >= '0' && *s <= '9'))
    {
        value = value * 10 +(*s - '0');
        s++;
    }
    return(value * negative);
}

