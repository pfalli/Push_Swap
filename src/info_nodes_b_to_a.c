/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:48:15 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:48:15 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_b(t_stack_node *a, t_stack_node *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
    t_stack_node *target_node_temp;
    t_stack_node *current_a;
    long best_matched;
    while (b)
    {
        best_matched = LONG_MIN;
        current_a = a;
        while(a)
        {
            if (b->data < current_a->data && best_matched < current_a->data )
            {
                best_matched = current_a->data;
                target_node_temp = current_a;
            }
            current_a = current_a->next;
        }
        if (best_matched == LONG_MIN)
            b->target_node = find_min(a);
            else
            b->target_node = target_node_temp;
        b = b->next;
    }

}

void	info_nodes_b(t_stack_node *a, t_stack_node *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
    set_index(a);
    set_index(b);
    set_target_node_b(a, b);
}