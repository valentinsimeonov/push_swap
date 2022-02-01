/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sl_dp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/31 21:45:22 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker_isdigit_max_min(int argc, char **argv)
{
	int i;
	int j;
	int	test;

	i = 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j] + '0'))
			{
				printf("%d\n", ft_atoi(&argv[i][j]));
				printf("%c\n", argv[i][j]);
				return (0);
			}
			j++;
		}
		if ((ft_atoi(argv[i]) > 2147483647) || (ft_atoi(argv[i]) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

// int		checker_duplicate(t_stack **stack)
// {
// 	t_stack	*check;
// 	t_stack	*runner;
// 	int		count;

// 	count = len_stack(stack);
	
// 	return (count);

	
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_variables	var;

	if (argc == 1)
		return (0);
	if (argc < 3 || !checker_isdigit_max_min(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	var.i = 1;
	while (var.i < argc)
	{
		ft_lstadd_back(&stack_a, create_stack_value(ft_atoi(argv[var.i])));
		var.i++;
	}
	// if (checker_duplicate(&stack_a))
	// {
	// 	write(2, "Error\n", 6);
	// 	return (-1);
	// }

	
	// stack_b = create_stack_empty();
	// ft_lstadd_back(&stack_b, create_stack_value(1000));
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("-----------\n");

	// print_stack(&stack_a);
	// printf("-----------\n");
	// push(&stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	
	// printf("-----------\n");
	// push(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	
	// printf("-----------\n");
	// push(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	
	// printf("4-----------\n");
	// push(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// // printf("-----------\n");

	// printf("5-----------\n");
	// push(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("Reverse-----------\n");

	// push(&stack_b, &stack_a);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("1-----------\n");

	// push(&stack_b, &stack_a);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("2-----------\n");

	// push(&stack_b, &stack_a);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("3-----------\n");

	// push(&stack_b, &stack_a);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("4-----------\n");

	// push(&stack_b, &stack_a);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("5-----------\n");

	// print_stack(&stack_a);
	// swap_a(&stack_a);
	// print_stack(&stack_a);
	// swap_a(&stack_a);
	// print_stack(&stack_a);
	// 	swap_a(&stack_a);
	// print_stack(&stack_a);
	// 	swap_a(&stack_a);
	// print_stack(&stack_a);


	// print_stack(&stack_a);
	// rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// 	rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// 	rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// 	rotate_stack(&stack_a);
	// print_stack(&stack_a);


	// print_stack(&stack_a);
	// reverse_rotate(&stack_a);
	// print_stack(&stack_a);
	// 	reverse_rotate(&stack_a);
	// print_stack(&stack_a);
	// 	reverse_rotate(&stack_a);
	// print_stack(&stack_a);
	// 	reverse_rotate(&stack_a);
	// print_stack(&stack_a);
	return (0);
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
int	len_stack(t_stack **stack)
{
	t_stack *temp;
	int	counter;
	
	temp = *stack;
	counter = 1;   //// To Check, Probably nest in IF Statement(next line)
	if (*stack != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			counter++;
		}
	}
	return (counter);
}

void	print_stack(t_stack **stack)
{
	/* Printing Function */
	t_stack *temp_p;
	
	temp_p = *stack;
	if (*stack == NULL)
		printf("List is Empty");
	if (*stack != NULL)
	{	
		while (temp_p->next != NULL)
		{
			printf("%s", "In List:");
			printf("%d", temp_p->value);
			temp_p = temp_p->next;
		}
		printf("%s", "In List:");
		printf("%d\n", temp_p->value);
	}
}

t_stack	*create_stack_value(int value)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = NULL;
	return (element);
}

t_stack	*create_stack_empty(void)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	// element->value = NULL;
	element->next = NULL;
	return (element);
}

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

