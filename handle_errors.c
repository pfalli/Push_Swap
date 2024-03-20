/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanlde_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:46:41 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:46:41 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	error_syntax(char *argv) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
    //check if first char is a digit or a sign
    int i = 0;
    if (argv[i]>= '0' && argv[i]<= '9' || argv[i] == '-' || argv[i] == '+')
        return 1;
    //check if the first char is a sign and the second char is a digit
    if ((argv[i] == '-' || argv[i] == '+') && argv[1]>= '0' && argv[1]<= '9')
        return 1;
    //loop and return 1 if entcount a non digit
    while (argv[i] <= '0' || argv[i]>= '9')
    {
        i++;
        return 1;
    }
    return(0);
}

int	error_duplicate(t_stack_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
    if (!a)
        return NULL;
    while (a)
    {
        if(a->data == n)        /// DIDNT CHECK
            return 1;
        a = a->next;
    }
    return 0;
}


void	free_stack(t_stack_node **stack) //Define a function to free a stack if there are errors
{
    t_stack_node *current;
    t_stack_node *temp;

    current = *stack;
    while (current)
    {
        temp = current->next; // move to the end using a temporary var
        free(current);
        current = temp;
    }
    *stack = NULL;
}


void	free_errors(t_stack_node **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
    free_stack(a);
    ft_printf("Error\n");
    exit(1);
}
