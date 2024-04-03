# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "inc\push_swap.h"
#include <assert.h>

#include "../inc/push_swap.h"

void	set_index(t_stack_node *stack) // give index and above_median to nodes
{
	int i = 0;
	int median;

	if(!stack)
		return;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
		else	
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}



static void	set_target_node_a(t_stack_node *a, t_stack_node *b)//find target_node from stack B
{
	t_stack_node *target_node_temp;
	t_stack_node *current_b;
	long best_matched;
	while (a)
	{
		best_matched = LONG_MIN;
		current_b = b;
		while(b)
		{
			if (a->data > current_b->data && best_matched < current_b->data)
			{
				best_matched = current_b->data;
				target_node_temp = current_b;
			}
			current_b = current_b->next;
		}
		if (best_matched == LONG_MIN)
		{
			a->target_node = find_max(b);
		}
		else
		{
			a->target_node = target_node_temp;
		}
		a = a->next;
	}
}


static void	set_on_top_cost(t_stack_node *a, t_stack_node *b) // cost analisis to rotate inside the same stack before to push. it calculates how many times we have to rotate to bring the number top of the stack
{
	int	len_a; 
	int	len_b;

	//	if (!a || !b)
    //	    return;

	len_a = stack_len(a);
	len_b = stack_len(b);

	while (a)
	{
		//	if (!a->target_node)
        //	    return;
		a->on_top_cost = a->index;
		if (!(a->above_median))
			a->on_top_cost = len_a - (a->index);
		if ((a->target_node->above_median))
			a->on_top_cost += a->target_node->index;
		else
			a->on_top_cost += len_b - (a->target_node->index);
		a = a->next;
	}
	
}


void	set_cheapest(t_stack_node *stack) // cheapest bool
{
	long cheapest_value;
	t_stack_node *node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while(stack)
	{
		if (stack->on_top_cost < cheapest_value)
		{
			cheapest_value = stack->on_top_cost;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
}


void	info_nodes_a(t_stack_node *a, t_stack_node *b) 
//Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	set_on_top_cost(a, b);
	set_cheapest(a);
}