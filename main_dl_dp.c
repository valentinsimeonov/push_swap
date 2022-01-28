/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:36:04 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/27 20:24:28 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_variables var;
	
	if (argc == 1)
		return (0);
	if (argc < 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	var.i = 1;
	printf("%d\n",ft_atoi(argv[var.i]));
	(*stack_a) = create_stack_value(ft_atoi(argv[var.i]));
	// (*stack_b) = create_stack_empty();
	var.i = 2;
	printf("%d\n",ft_atoi(argv[var.i]));
	while (var.i <= (argc - 1))
	{
		stack_add_bottom(stack_a, ft_atoi(argv[var.i]));
		var.i++;
	}
	swap_a(stack_a);

	// printf("%d\n", stack_a->value);
	// printf("%d\n", stack_a->next->value);
	
/* Printing Function */
	while ((*stack_a)->next != NULL)
	{
		printf("%s", "In List:");
		printf("%d", (*stack_a)->value);
        (*stack_a) = (*stack_a)->next;
    }
	printf("%s", "In List:");
	printf("%d", (*stack_a)->value);
	return (0);
}

t_stack	*create_stack_empty(void)
{
	t_stack **stack;

	(*stack) = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	// stack->value = value;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	return (*stack);
}

t_stack	*create_stack_value(int value)
{
	t_stack **stack;

	(*stack) = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	printf("%d", (*stack)->value);
	(*stack)->value = value;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	return (*stack);
}

void	stack_add_bottom(t_stack **stack, int value)
{
	t_stack *temp;
	t_stack *new;
	
	temp = (*stack);
	new = create_stack_value(value);
	if (temp)
	{
		while((*stack)->next != NULL)
			(*stack) = (*stack)->next;
		(*stack)->next = new;
		new->prev = temp;
	}
}

void	swap_a(t_stack **stack)
{
	t_stack *temp;

	if ((*stack)->next == NULL || !stack)
		return ;
	temp = (*stack)->next;
	if ((*stack)->next->next)
	{
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->prev = (*stack);
	}
	else
		(*stack)->next = NULL;
	(*stack)->prev = temp;
	temp->next = (*stack);
	temp->prev = NULL;
	(*stack) = temp;
	write(2, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	t_stack *temp;

	if ((*stack)->next == NULL || !stack)
		return ;
	temp = (*stack)->next;
	if ((*stack)->next->next)
	{
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->prev = (*stack);
	}
	else
		(*stack)->next = NULL;
	(*stack)->prev = temp;
	temp->next = (*stack);
	temp->prev = NULL;
	(*stack) = temp;
	write(2, "sb\n", 3);
}


// void	swap(t_stack *stack)
// {
// 	t_stack *temp;
// 	t_stack *first;
// 	t_stack *second;
// 	int	i;

// 	first = stack;
// 	i = 0;
// 	if(stack->next != NULL)
// 	{					
// 		second = stack->next;
// 		// i++;
// 	}
// 	temp = second;
// 	second->prev = NULL;
// 	second->next = first->next;
// 	first->prev = temp->prev; 
// 	first->next = temp->next;
// }












/*
int		stack_put_nexttom(t_stack *stack, int value)
{
	t_element	*element;

	element = create_element(value);
	if (!element)
		return (-1);
	element->next = stack->next;
	stack->next = element;
	stack->value = element->value; ///for Testing Purposes
	if (!element->next)
	{
		if (stack->prev != NULL)
			return (-1);
		stack->prev = element;
	}
	else
		element->next->prev = element;
	return (0);	
}
 
*/



// void	swap(t_stack *stack)
// {
// 	t_stack *temp;

// 	temp->prev = stack_a->next;
// 	stack_a->next = stack_a->prev;
// 	stack_a->prev = temp->prev;
	
// }


// t_element	*create_element(int value)
// {
// 	t_element	*element;

// 	element = malloc(sizeof(t_element));
// 	if (!element)
// 		return (NULL);
// 	element->value = value;
// 	element->prev = NULL;
// 	element->next = NULL;
// 	return (element);
// }

