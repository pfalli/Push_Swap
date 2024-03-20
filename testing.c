#include "push_swap.h"

t_stack_node* create_node(int data)
{
    t_stack_node* new_node = (t_stack_node*)malloc(sizeof(t_stack_node));

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int count = 0;

	if (!stack)
		return(0);
	while (stack)
    {
		stack = stack->next;
        count++;
    }
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

int main ()
{
    //create stack
    t_stack_node* stack = create_node(99);
    stack->next = create_node(45);
    stack->next->next = create_node(1);
    stack->next->next->next = create_node(10);

    //test the function
    int length = stack_len(stack);
    printf("the length is: %d\n", length);

    //print
    t_stack_node *temp = stack;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }


    //last node
    t_stack_node *last = find_last(stack);
    if (last != NULL) 
        printf("\nLast node is: %d", last->data);
    else
        printf("\nStack is empty.");


    // check if it's sorted
    int result = stack_sorted(stack);
    if (result)
        printf("\nIt is sorted.");
    else
        printf("\nIt's not sorted.");

    //find min number
    t_stack_node *small = find_max(stack);
    printf("\nthe max number is: %d", small->data);
}