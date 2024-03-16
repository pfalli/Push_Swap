/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:49:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/12 10:49:32 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL)
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    head = prev;
    return(head);
}