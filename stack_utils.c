/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:45:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:45:29 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int count = 0;

	if (!stack)
		return(0);
	while (stack)
		stack = stack->next;
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
	t_stack_node *big = NULL;

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

