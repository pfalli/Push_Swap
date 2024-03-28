// Include necessary headers
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
// Define the structure of a stack node 
struct Node 
{ 
    int data; 
    struct Node* next;
};

// Function to create a new node 
struct Node* createNode(int data) 
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
}

// Function to check if the stack is empty 
int isEmpty(struct Node* top) 
{ 
    return top == NULL; 
}

// Function to push an element onto the stack 
void push(struct Node** top, int data) { 
    struct Node* newNode = createNode(data); 
    newNode->next = *top; 
    *top = newNode; 
    printf("%d pushed to the stack.\n", data); 
} 

// Function to pop an element from the stack 
int pop(struct Node** top) { 
    if (isEmpty(*top)) { 
        printf("Stack underflow!\n"); 
        return INT_MIN; 
    } 
    struct Node* temp = *top; 
    int popped = temp->data; 
    *top = (*top)->next; 
    free(temp); 
    return popped; 
}

// Function to display the stack 
void displayStack(struct Node* top) { 
    if (isEmpty(top)) { 
        printf("Stack is empty!\n"); 
        return; 
    } 
    struct Node* current = top; 
    printf("Stack: "); 
    while (current != NULL) { 
        printf("%d ", current->data); 
        current = current->next; 
    } 
    printf("\n"); 
}

// Main function 
int main() { 
    struct Node* top = NULL; 
    push(&top, 10); 
    push(&top, 20); 
    push(&top, 30); 
    displayStack(top); 
    printf("%d popped from the stack.\n", pop(&top)); 
    displayStack(top); 
    return 0; 
}