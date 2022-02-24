/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/23 16:37:40 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_sorted;
	t_stack	*stack_b;
	t_variables	var;

	if (argc == 1 || argc == 2)
		return (0);
	if ((argc < 3) || more_than_digits(argc, argv) || \
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
	var.j = 1;
	while (var.j < argc)
	{
		ft_lstadd_back(&stack_sorted, create_stack_value(ft_atoi(argv[var.j])));
		var.j++;
	}
	bubble_sort(&stack_sorted);
	index_assignment(&stack_a, &stack_sorted);
	if (is_sorted(&stack_a))
		return (0);
	if (argc == 3 && stack_a->index != 1)
	{
		swap_a(&stack_a);
		return (0);
	}
	if (argc == 4 || argc == 6)
		manual_sort(&stack_a, &stack_b, argc);
	else if (argc == 5 || argc > 6)
		shifting(&stack_a, &stack_b);
	return (0);
}

void	manual_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 4)
		sort_3(stack_a);
	if (argc == 6)
		sort_5(stack_a, stack_b);
}

void	shifting(t_stack **stack_a, t_stack **stack_b)
{
	int	shift;
	int	i;
	int	count;
	int	biggest_index;

	count = len_stack(stack_a);
	biggest_index = bitlength(count);
	shift = 0;
	i = 0;
	while (shift < biggest_index)
	{
		i = 0;
		while (i < count)
		{
			if ((*stack_a)->index >> shift & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			i++;
		}
		while (*stack_b)
		{
			push_a(stack_b, stack_a);
		}
		shift++;
	}
}

int	bitlength(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
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
