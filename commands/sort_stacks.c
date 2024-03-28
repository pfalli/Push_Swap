/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:50:32 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b) 
{
	int length_a;

	length_a = stack_len(*a);
	if (length_a > 3 && !(stack_sorted))
		pa(a, b, false);
	if (length_a > 3 && !(stack_sorted))
		pa(a, b, false);
	while ((length_a > 3 && !(stack_sorted)))
	{
		info_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(*a);
	while (*b)
	{
		info_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(*a);
}



static void	move_a_to_b(t_stack_node **a, t_stack_node **b) 
{
	t_stack_node *cheapest_node = get_cheapest(a);
	// in case of both_rotate
	if (cheapest_node->above_median && cheapest_node->target_node->above_median )
		both_rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !cheapest_node->target_node->above_median)
		both_rev_rotate(a, b, cheapest_node);
	// in case only one rotate
	put_to_top(a, cheapest_node, 'a');
	put_to_top(b, cheapest_node->target_node, 'b');
	set_index(*a);
	set_index(*b);
	pb(b, a, false);
}


static void	move_b_to_a(t_stack_node **a, t_stack_node **b) // stack B is already in order
{
	put_to_top(a, (*b)->target_node, 'b');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{

	t_stack_node *node = find_min(*a);
	
	while (node->data != (*a)->data)
	{
		if (node->above_median)
			ra(a,false);
		else
			rra(a, false);
	}
}


