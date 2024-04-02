/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:56:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/01 13:56:29 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	error_syntax(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
    if (!a)
        return 0;
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