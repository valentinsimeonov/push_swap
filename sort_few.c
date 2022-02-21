#include "push_swap.h"

void    sort_3(t_stack  **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack;
    second = first->next;
    third = second->next;
    
    // printf("2, 1, 3");
    if (first->index > second->index && second->index < third->index && first->index < third->index)
        swap_a(stack);
    // printf("2, 3, 1");
    else if (first->index < second->index && second->index > third->index && first->index > third->index)
        reverse_rotate_a(stack);
    // printf("3, 2, 1");
    else if (first->index > second->index && second->index > third->index && first->index > third->index)
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    // printf("1, 3, 2");
    else if (first->index < second->index && second->index > third->index && first->index < third->index)
    {

        rotate_a(stack);
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    // printf("3, 1, 2");
    else if (first->index > second->index && second->index < third->index && first->index > third->index)
    {
        reverse_rotate_a(stack);
        reverse_rotate_a(stack);
    }
}

t_stack    *sort_3_for_4_and_5(t_stack  **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack;
    second = first->next;
    third = second->next;
    
    printf("2, 1, 3");
    if (first->index > second->index && second->index < third->index && first->index < third->index)
        swap_a(stack);
    // printf("2, 3, 1");
    else if (first->index < second->index && second->index > third->index && first->index > third->index)
        reverse_rotate_a(stack);
    
    // printf("3, 2, 1");
    else if (first->index > second->index && second->index > third->index && first->index > third->index)
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    
    // printf("1, 3, 2");
    else if (first->index < second->index && second->index > third->index && first->index < third->index)
    {

        rotate_a(stack);
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    
    // printf("3, 1, 2");
    else if (first->index > second->index && second->index < third->index && first->index > third->index)
    {
        reverse_rotate_a(stack);
        reverse_rotate_a(stack);
    }
    return (*stack);
}

void sort_4(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *temp;
    int     i;

    first = *stack;
    second = first->next;
    temp = *stack;
    i = 1;
    while (temp->next != NULL && temp->index != 1)
    {
        i++;
        if (temp->index == 1)
            break ;
        temp = temp->next;
    }
    if (i == 1)
    {
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 2)
    {
        swap_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 3)
    {
        reverse_rotate_a(stack);
        reverse_rotate_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 4)
    {
        reverse_rotate_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
}

t_stack   *sort_4_for_5(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *temp;
    int     i;

    first = *stack;
    second = first->next;
    temp = *stack;
    i = 1;
    while (temp->next != NULL && temp->index != 2)
    {
        i++;
        if (temp->index == 1)
            break ;
        temp = temp->next;
    }
    if (i == 1)
    {
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 2)
    {
        swap_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 3)
    {
        reverse_rotate_a(stack);
        reverse_rotate_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
    if (i == 4)
    {
        reverse_rotate_a(stack);
        first->next = sort_3_for_4_and_5(&second);
    }
    return (*stack);
}

void    sort_5(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *temp;
    int     i;

    first = *stack;
    second = first->next;
    temp = *stack;
    i = 1;
    while (temp->next != NULL && temp->index != 1)
    {
        i++;
        if (temp->index == 1)
            break ;
        temp = temp->next;
    }
    if (i == 1)
        first->next = sort_4_for_5(&second);
    if (i == 2)
    {
        swap_a(stack);
        first->next = sort_4_for_5(&second);
    }
    if (i == 3)
    {
        rotate_a(stack);
        rotate_a(stack);
        first->next = sort_4_for_5(&second);
    }
    if (i == 4)
    {
        reverse_rotate_a(stack);
        reverse_rotate_a(stack);
        first->next = sort_4_for_5(&second);
    }
     if (i == 5)
    {
        reverse_rotate_a(stack);
        first->next = sort_4_for_5(&second);
    }
}
