/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/28 13:25:56 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_variables	var;

	if (argc == 1)
		return (0);
	if (argc < 3)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	var.i = 1;
	stack_a = create_stack_value(&stack_a, ft_atoi(argv[var.i]));
	while (var.i <= (argc - 1))
	{
		stack_add_bottom(&stack_a, ft_atoi(argv[var.i]));
		var.i++;
	}
	return (0);
}

t_stack	*create_stack_value(t_stack **stack, int value)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	(*stack)->value = value;
	(*stack)->next = NULL;
	
	return (stack);
}
