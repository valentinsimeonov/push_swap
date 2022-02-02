/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:22:43 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/02 22:04:06 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack *first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	// printf("first value: %d\n", first->value);
	second = first->next;
	// printf("second value: %d\n", second->value);
	// printf("second element: %p\n", second);
	// printf("first element: %p\n", first);
	third = second->next;
	// printf("third element: %p\n", third);
	second->next = first;
	// printf("second next: %p\n", second->next);
	// printf("%d\n", stack_a->value);
	first->next = third;
	// printf("first next: %p\n", first->next);
	// printf("%d\n", stack_a->value);
	*stack = second;
}

void	switch_first_last_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*before_last;
	t_stack	*last;
	t_stack	*temp;
	int	counter;
	int	j;

	counter = 1;
	j = 1;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	last = temp;
	// printf("%d\n", counter);
	// printf("last: %p\n", temp);
	// printf("last value%d\n", last->value);
	temp = *stack;
	// printf("temp: %p\n", temp);
	// printf("temp value%d\n", temp->value);
	while (j < (counter - 1))
	{
		temp = temp->next;
		j++;
	}
	// printf("%d\n", j);
	before_last = temp;
	// printf("before last: %p\n", before_last);
	// printf("before last value%d\n", before_last->value);
	first = *stack;
	// printf("first: %p\n", first);
	// printf("first value%d\n", first->value);
	second = first->next;
	// printf("second: %p\n", second);
	// 	printf("second value%d\n", second->value);
	last->next = second;
	// printf("last->next: %p\n", last->next);
	before_last->next = first;
	// printf("before_last->next: %p\n", before_last->next);
	// printf("last: %p\n", last);
	// 	printf("last value%d\n", last->value);
	first->next = NULL;
	*stack = last;
	// printf("stack: %p\n", *stack);
	// 	printf("stack value%d\n", (*stack)->value);
// 	printf("\nWhat I think is Inside the Stack: \n\n");
// printf("last value%d\n", last->value);
// 	printf("last: %p\n", last);
// printf("last->next: %p\n", last->next);

// printf("second value%d\n", second->value);
// 	printf("second: %p\n", second);
// printf("second->next: %p\n", second->next);

// 	printf("before last value%d\n", before_last->value);	
// 	printf("before last: %p\n", before_last);
// printf("before_last->next: %p\n", before_last->next);
	
// 	printf("first value%d\n", first->value);
// 	printf("first: %p\n", first);
// 	printf("first->next: %p\n", first->next);

	
	// printf("first: %p\n", first);
	// printf("second: %p\n", second);
	// printf("before last: %p\n", before_last);
	// printf("last: %p\n", last);
	// printf("stack: %p\n", *stack);
	
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	first = *stack;
	second = first->next;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp;
	last->next = first;
	first->next = NULL;
	*stack = second;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;
	int		counter;
	int		i;

	counter = 1;
	i = 1;
	temp = *stack;
	first = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	last = temp;
	last->next = first;
	temp = *stack;
	while (i < (counter - 1))
	{
		temp = temp->next;
		i++;
	}
	before_last = temp;
	before_last->next = NULL;
	*stack = last;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	// t_stack *first_b;
	// int	count;
	// int	i;

	// printf("%p\n", *stack_a);
	// printf("%p\n", *stack_b);

	// i = 0;
	// count = len_stack(stack_a);
		if (*stack_a == NULL)
		return ;
	// if (*stack_b == NULL)
	// {
	// 	first = *stack_a;
	// 	second = first->next;
	// 	*stack_a = second;
	// 	first->next = NULL;
	// 	*stack_b = first;
	// 	return ;
	// }
	// if ((len_stack(stack_a) > 1) && (*stack_b != NULL))
		// if ((len_stack(stack_a) > 1) && (*stack_b != NULL))
	// {
		printf("Second Condition\n");
		first = *stack_a;
		second = first->next;
		*stack_a = second;
		first->next = *stack_b;
		*stack_b = first;
		// return ;
	// }
	// if ((len_stack(stack_a) == 1) && (*stack_b != NULL))
	// {
	// 	printf("Third Condition\n");
	// 	first = *stack_a;
	// 	// *stack_a = NULL;
	// 	printf("%p", *stack_a);
	// 	first->next = *stack_b;
	// 	printf("first->next: %p\n", first->next);
	// 	*stack_b = first;
	// 	*stack_a = NULL;
	// 	return ;
	// }
}
