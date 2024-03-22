/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:52:52 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/08 09:52:52 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
    int data;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack_node;

// Handle errors
int	error_syntax(char *argv);
int	error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

// Stack initialization

// Nodes initialization

// Stack utils
t_stack_node	*find_last(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
// Commands

// Algorithm


#endif