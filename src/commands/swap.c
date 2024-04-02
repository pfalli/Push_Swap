/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:49:55 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:49:55 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
    if ((*head) || (*head)->next)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}


void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
    swap(a);
    if (print)
        ft_printf("sa\n");
}


void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
    swap(b);
    if(print)
        ft_printf("sb\n");
}


void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
    swap(a);
    swap(b);
    if(print)
        ft_printf("ss\n");
}


//  int main()
//      {
//          t_stack_node *head = malloc(sizeof(t_stack_node));
//          t_stack_node *second = malloc(sizeof(t_stack_node));
//      
//          head->data = 1;
//          head->next = second;
//          head->prev = NULL;
//      
//          second->data = 2;
//          second->next = NULL;
//          second->prev = head;
//      
//          printf("Before swap: %d %d\n", head->data, second->data);
//          swap(&head);
//          printf("After swap: %d %d\n", head->data, head->next->data);
//      
//       
//      
//          return 0;
//      }