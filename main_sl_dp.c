/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sl_dp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/02 22:37:32 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_sorted;
	t_stack	*stack_b;
	t_variables	var;
	int		j;

	if (argc == 1)
		return (0);
	if (argc < 3 || more_than_digits(argc, argv) || \
		more_than_int(argc, argv) || has_duplicates(argc, argv))
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
	j = 1;
	while (j < argc)
	{
		ft_lstadd_back(&stack_sorted, create_stack_value(ft_atoi(argv[j])));
		j++;
	}
	
	print_stack(&stack_a);
	print_stack(&stack_sorted);
	bubble_sort(&stack_sorted);
	print_stack(&stack_sorted);
	print_index(&stack_sorted);
	printf("1---------------\n");
	index_assignment(&stack_a, &stack_sorted);
	printf("---------------\n");
	print_stack(&stack_a);
	print_index(&stack_a);
	// // len_stack_index_assign(&stack_a);
	// print_index(&stack_a);
	// print_index(&stack_a);




	
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	// printf("-----------\n");

	// print_stack(&stack_a);
	// printf("-----------\n");
	// push(&stack_a, &stack_b);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	
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


int	len_stack(t_stack **stack)
{
	t_stack *temp;
	int	counter;
	
	temp = *stack;
	counter = 0;   //// moved in, nested IF with value 1
	if (*stack != NULL)
	{
		counter = 1; 
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
		printf("List is Empty\n");
	if (*stack != NULL)
	{	
		while (temp_p->next != NULL)
		{
			printf("%s", "In List: ");
			// printf("%d", temp_p->value);
			printf("%d\n", temp_p->value);
			temp_p = temp_p->next;
		}
		printf("%s", "In List: ");
		printf("%d\n", temp_p->value);
	}
}
void	print_index(t_stack **stack)
{
	/* Printing Function */
	t_stack *temp_p;
	
	temp_p = *stack;
	if (*stack == NULL)
		printf("List is Empty\n");
	if (*stack != NULL)
	{	
		while (temp_p->next != NULL)
		{
			printf("%s", "In Index: ");
			// printf("%d", temp_p->value);
			printf("%d\n", temp_p->index);
			temp_p = temp_p->next;
		}
		printf("%s", "In Index: ");
		printf("%d\n", temp_p->index);
		printf("End of Print Function\n");
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

