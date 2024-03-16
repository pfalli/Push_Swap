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


int	error_syntax(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
    //check if first char is a digit or a sign

    //check if the first char is a sign and the second char is a digit

    //loop and return 1 if entcount a non digit

    return(0);
}

int	error_duplicate(t_stack *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
    
}


void	free_stack(t_stack **stack) //Define a function to free a stack if there are errors


void	free_errors(t_stack **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
