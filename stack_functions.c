#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "stack_functions.h"

///In stack, insertion/deletion is done at the top
struct element pop(struct node ** top) ///As we will modify 'top'. Hence, pass by reference
{
    struct element temp = (*top)->data;     /// I copy the data at the top node into a temporary variable
                                            ///because we will return it later
    struct node * ptr_temp = (*top)->next;  ///this can also be written as *top = *top->next;

    free(*top);  ///removing top
    *top = ptr_temp;

    return(temp);
}

void push(struct node ** top, struct element new_data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node)); ///Memory allocation

    new_node->data = new_data;      /// I can assign one struct to another if the type is the same

    new_node->next = *top;
    *top = new_node;
}

bool isStackEmpty(struct node ** top)
{
    return(*top == NULL); ///condition to check whether the stack is empty or not
}
