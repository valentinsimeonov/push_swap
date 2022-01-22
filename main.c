/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:36:04 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/22 19:43:57 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	struct t_variables var;
	
	if (argc == 1)
		return (0);
	if (argc < 3)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stack_a = create_stack();
	stack_b = create_stack();
	var.i = 1;
	while (var.i < (argc - 1))
	{
		stack_put_bottom(stack_a, ft_atoi(argv[var.i]))
		var.i++;
	}
	
	return (0);
}

int		stack_put_bottom(t_stack *stack, int value)
{
	t_element	*element;

	element = create_element(value);
	if (!node)
		return (NULL);
	element->next = stack->bot;
	stack->bot = node;
	if (!element->next)
	{
		if (stack->top != NULL)
			return (NULL);
		stack->top = node;
	}
	else
		node->next->prev = node;
	return (0);	
}
 
t_stack	*create_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}

t_element	*create_element(int value)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->value = value;
	element->prev = NULL;
	element->next = NULL;
	return (element);
}