/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sl_dp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/05 21:30:57 by vsimeono         ###   ########.fr       */
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
	
	printf("---------------\n");
	print_stack(&stack_sorted);
	print_index(&stack_sorted);
	
	// len_stack_index_assign(&stack_a);
	// print_index(&stack_a);
	// print_index(&stack_a);



	printf("-----------Shift to A Part1: ---------------\n");
	shifting(&stack_a, &stack_b);
	printf("-----------Shift to A Part1: ---------------\n");
	printf("Stack A\n");
	print_stack(&stack_a);
	print_index(&stack_a);
	printf("Stack B\n");
	print_stack(&stack_b);
	print_index(&stack_b);


	
	// printf("-----------Shift to B Part1: ---------------\n");
	// shifting_to_a(&stack_b, &stack_a);
	// printf("Stack A\n");
	// print_stack(&stack_a);
	// printf("Stack B\n");
	// print_stack(&stack_b);


	// printf("-----------Shift to A Part2: ---------------\n");
	// shifting_to_a(&stack_a, &stack_b);
	// printf("Stack A\n");
	// print_stack(&stack_a);
	// printf("Stack B\n");
	// print_stack(&stack_b);
	// printf("-----------Shift to B Part2: ---------------\n");
	// shifting_to_a(&stack_b, &stack_a);
	// printf("Stack A\n");
	// print_stack(&stack_a);
	// printf("Stack B\n");
	// print_stack(&stack_b);
	
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

	// printf("====== In List: ==========\n");
	// print_stack(&stack_a);
	// printf("====== Rotate Part2: ==========\n");
	// rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// printf("====== Rotate Part3: ==========\n");
	// rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// printf("====== Rotate Part4: ==========\n");
	// rotate_stack(&stack_a);
	// print_stack(&stack_a);
	// printf("====== Rotate Part5: ==========\n");
	// rotate_stack(&stack_a);
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

void	shifting(t_stack **stack_a, t_stack **stack_b)
{
	int		shift;
	int		count;
	int		i;
	int		biggest_index;
	t_stack	*temp;

	temp = *stack_a;

	count = len_stack(stack_a);
	biggest_index = count_biggest_index_in_binary(stack_a);
	shift = 0;
	i = 0;
	while (shift <= biggest_index)
	{	i = 0;
		// *stack_a = temp;
		if (*stack_a)
		{
			while (i < count && *stack_a)
			{
				if ((*stack_a)->index >> shift & 1)
					// push(stack_a, stack_b);
					rotate_stack(stack_a);
				else 
					// rotate_stack(stack_a);
					push(stack_a, stack_b);
					// reverse_rotate(stack_a);
				// printf("Stack A\n");
				// print_index(stack_a);
				// printf("Stack B\n");
				// print_index(stack_b);
				i++;
			}
				// printf("Stack A\n");
				// print_index(stack_a);
				// printf("Stack B\n");
				// print_index(stack_b);
		}
		if (*stack_b)
		{
			while (*stack_b)
			{
				push(stack_b, stack_a);
				print_stack(stack_a);
			}
				// printf("Stack A\n");
				// print_index(stack_a);
				// printf("Stack B\n");
				// print_index(stack_b);
				// sleep(1);
		}
		shift++;
	}
}



int	count_biggest_index_in_binary(t_stack **stack)
{
	int		shift;
	int		max_index;
	int		max_bits;
	// t_stack	*temp;

	// temp = stack_a;
	shift = 0;
	max_bits = 0;
	max_index = len_stack(stack);
	// printf("%d\n", max_index);
	// sleep(10);

	while (max_index >> max_bits)
		++max_bits;
	// printf("K: %d\n", max_bits);
	// sleep(10);
	// while (shift <= 31)
	// {
	// 	if (max_index >> shift & 1)
	// 		max_bits++;
	// 	shift++;
	// }
	// printf("V: %d\n", max_bits);
	// sleep(10);
	return (max_bits);
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

// void    ft_putnbr_bin(void *content)
// {
//     t_number    *num;
//     int 	i;
//     int		y;

//     y = 7;
//     num = content;
//     i = num->index;
//     while (y != -1)
//     {
//         if (((i >> y) & 1) == 1)
//             write(1, "1", 1);
//         else
//             write(1, "0", 1);
//         y--;
//     }
//     write(1, " ", 1);
// }    

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
