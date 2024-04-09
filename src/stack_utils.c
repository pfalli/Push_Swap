/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:45:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 14:51:48 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int count = 0;

	if (!stack)
		return(0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return(count);
}

t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if(!stack)
		return NULL;
	while (stack->next) // stack points to the current node....stack->next points to the next node
	{
		stack = stack->next;
	}
	return(stack);
}

bool	stack_sorted(t_stack_node *stack) //Define a function that checks if the stack is sorted in ascending order
{
	if (!stack)
		return 1;
	//Loop until the second last of the stack is reached
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return false;
		stack = stack->next;
	}
	return true;
}

t_stack_node	*find_min(t_stack_node *stack) //Define a function that searches a stack and returns the pointer node with the smallest number
{
	long min;
	t_stack_node *small_node = NULL;

	if (!stack)
		return NULL;
	min = LONG_MAX;
	while(stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			small_node = stack;
		}
		stack = stack->next;
	}	
	return (small_node);
}

t_stack_node	*find_max(t_stack_node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long max;
	t_stack_node *big;

	if(!stack)
		return NULL;
	max = LONG_MIN;
	while (stack)
	{
		if(stack->data > max)
		{
			max = stack->data;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}

t_stack_node	*get_cheapest_node(t_stack_node *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	free(stack);
	return (NULL);
}

void	put_to_top(t_stack_node **stack, t_stack_node *top_node, char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}