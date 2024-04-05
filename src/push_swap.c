/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:52:56 by pfalli            #+#    #+#             */
/*   Updated: 2024/03/08 09:52:56 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2) 
		argv = split(argv[1], ' '); 
	init_stack_node_a(&a, argv + 1); 
	if (!stack_sorted(a)) 
	{
		if (stack_len(a) == 2) 
			sa(&a, false);
		else if (stack_len(a) == 3) 
			sort_three(&a);
		else
			sort_stacks(&a, &b); 
	}
	free_stack(&a); 
	return (0);
}


//	int	main(int argc, char **argv)
//	{
//	    t_stack_node	*a;
//	    t_stack_node	*b;
//	
//	    a = NULL;
//	    b = NULL;
//	    if (argc == 1 || (argc == 2 && !argv[1][0]))
//	        return (1);
//	    else if (argc == 2) 
//	        argv = split(argv[1], ' '); 
//	
//	    printf("Debug: argc = %d\n", argc); // Print the value of argc
//	    for (int i = 0; i < argc; i++) {
//	        printf("Debug: argv[%d] = %s\n", i, argv[i]); // Print each argument
//	    }
//	
//	    init_stack_node_a(&a, argv + 1);
//	
//	    printf("Debug: a = %d\n", a->data); // Print the value of a
//	
//	    if (!stack_sorted(a)) 
//	    {
//	        if (stack_len(a) == 2) 
//	            sa(&a, false);
//	        else if (stack_len(a) == 3) 
//	            sort_three(&a);
//	        else
//	            sort_stacks(&a, &b); 
//	    }
//	
//		t_stack_node *temp = a;
//		int i = 0;
//		while (temp != NULL) {
//		    printf("Debug: a->next[%d] = %d\n", i, temp->data);
//		    temp = temp->next;
//		    i++;
//		}
//	    //	// print all the elements inside the struct: on_top, above_median, index, target_node
//	    //	while (a)
//	    //	{
//	    //	    printf("\nDebug: a->data = %d\n", a->data);
//	    //	    printf("Debug: a->on_top_cost = %d\n", a->on_top_cost);
//	    //	    printf("Debug: a->above_median = %d\n", a->above_median);
//	    //	    printf("Debug: a->index = %d\n", a->index);
//	    //	    printf("Debug: a->target_node->data = %d\n", a->target_node->data);
//	    //	    a = a->next;
//	    //	}
//	
//	
//	    free_stack(&a);
//	    return (0);
//	}