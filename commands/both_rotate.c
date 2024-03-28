/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:39:15 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/27 09:39:15 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) // rotate both if it's the cheapest move
{
	if (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rr(a, b, false);
		set_index(a);
		set_index(b);
	}
}