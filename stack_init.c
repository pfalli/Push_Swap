/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:00 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/09 15:34:00 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s) // atoi that return long
{
	long value;
    int negative = 1;

    while (s)
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

static void	append_node(t_stack_node **stack, int n) //function that searches for the last node to append to the linked list
{
	t_stack_node *new_node;
	t_stack_node *last_node;

	if (!stack)
		return NULL;
	new_node = (t_stack_node*)malloc(sizeof(t_stack_node));
	if (!new_node)
		return NULL;
	new_node->next = NULL;
	new_node->data = n;
	if (!(*stack)) // stack empty so we put data new node
	{
		*stack = new_node;
		new_node-> prev = NULL;
	}
	else // stack has data, so we search the last to connect to the first
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_node_a(t_stack_node **a, char **argv) //function that initiates stack `a` by handling any errors and appending required nodes to complete a stack
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Check for overflow
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a); 
		append_node(a, (int)n); //If no errors, append the node to the linked list by, taking a pointer to stack `a`, create a new node and assign `num` to that new node
		i++;
	}
}
