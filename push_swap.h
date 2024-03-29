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
    int on_top_cost; // number of commands
    int index; // number of rotation to do to bring the number on top of the stack, before to push
    bool above_median; 
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack_node;

// Handle errors
int	            error_syntax(char *argv);
int	            error_duplicate(t_stack_node *a, int n);
void	        free_stack(t_stack_node **stack);
void	        free_errors(t_stack_node **a);

// Stack initialization
static long	    ft_atol(const char *s);
static void	    append_node(t_stack_node **stack, int n);
void	        init_stack_node_a(t_stack_node **a, char **argv);

// Nodes initialization
void	        set_index(t_stack_node *stack);
static void	    set_target_node_a(t_stack_node *a, t_stack_node *b);
static void	    set_on_top_cost(t_stack_node *a, t_stack_node *b);
void	        set_cheapest(t_stack_node *stack);
void	        info_nodes_a(t_stack_node *a, t_stack_node *b);

// Stack utils
t_stack_node	*find_last(t_stack_node *stack);
int	            stack_len(t_stack_node *stack);
bool	        stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

// Commands
void            ra(t_stack_node **a, bool print);
void            rb(t_stack_node **b, bool print);
void            rr(t_stack_node **a, t_stack_node **b, bool print);
void            rra(t_stack_node **a, bool print);
void            rrb(t_stack_node **b, bool print);
void            rrr(t_stack_node **a, t_stack_node **b, bool print);
void            pa(t_stack_node **a, t_stack_node **b , bool print);
void            pb(t_stack_node **a, t_stack_node **b, bool print);
void        	sa(t_stack_node	**a, bool print);
void        	sb(t_stack_node **b, bool print);
void        	ss(t_stack_node **a, t_stack_node **b, bool print);
// Algorithm
void	        sort_three(t_stack_node **a);
void	        sort_stacks(t_stack_node **a, t_stack_node **b); 

#endif