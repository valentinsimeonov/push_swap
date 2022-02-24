/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:17:02 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/23 15:07:29 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack  **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	/* ("2, 1, 3"); */
	if (first->index > second->index && second->index < third->index \
	&& first->index < third->index)
		swap_a(stack);
	/* ("2, 3, 1"); */
	else if (first->index < second->index && second->index > third->index \
	&& first->index > third->index)
		reverse_rotate_a(stack);
	/* ("3, 2, 1"); */
	else if (first->index > second->index && second->index > third->index && \
	first->index > third->index)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	/* ("1, 3, 2"); */
	else if (first->index < second->index && second->index > third->index && \
	first->index < third->index)
	{
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	/* ("3, 1, 2"); */
	else if (first->index > second->index && second->index < third->index && \
	first->index > third->index)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
}

t_stack	*sort_3_for_4_and_5(t_stack  **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	/* ("2, 1, 3"); */
	if (first->index > second->index && second->index < third->index && \
	first->index < third->index)
		swap_a(stack);
	/* ("2, 3, 1"); */
	else if (first->index < second->index && second->index > third->index \
	&& first->index > third->index)
		reverse_rotate_a(stack);
	/* ("3, 2, 1"); */
	else if (first->index > second->index && second->index > third->index \
	&& first->index > third->index)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	/* ("1, 3, 2"); */
	else if (first->index < second->index && second->index > third->index \
	&& first->index < third->index)
	{
		rotate_a(stack);
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	/* ("3, 1, 2"); */
	else if (first->index > second->index && second->index < third->index \
	&& first->index > third->index)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	return (*stack);
}

void sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;
	int		i;
	int		j;

	first = *stack_a;
	second = first->next;
	temp = *stack_a;
	i = 1;
	j = 1;
	while (temp->next != NULL && temp->index != 1)
	{
		i++;
		if (temp->index == 1)
			break ;
		temp = temp->next;
	}
	temp = *stack_a;
	while (temp->next != NULL && temp->index != 2)
	{
		j++;
		if (temp->index == 2)
			break ;
		temp = temp->next;
	}
	if (i == 1 && j == 2)
	{
		/* ("1 2 3 4 5"); */
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 2 && j == 1)
	{
		/* ("2 1 3 4 5"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 3 && j == 1)
	{
		/* ("2 3 1 4 5"); */
		rotate_a(stack_a);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 4 && j == 1)
	{
		/* ("2 3 4 1 5"); */
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		swap_b(stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 5 && j == 1)
	{
		/* ("2 3 4 5 1"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 3 && j == 2)
	{
		/* ("3 2 1 4 5"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 4  && j == 2)
	{
		/* ("3 2 4 1 5"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		swap_b(stack_b);
		sort_3_for_4_and_5(stack_a);	
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 5  && j == 2)
	{
		/* ("3 2 4 5 1"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);	
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 1  && j == 3)
	{
		/* ("1 3 2 4 5"); */
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);	
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 2  && j == 3)
	{
		/* ("3 1 2 4 5"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);	
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 4  && j == 3)
	{
		/* ("3 4 2 1 5"); */
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 5  && j == 3)
	{
		/* ("3 4 2 5 1"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 1  && j == 4)
	{
		/* ("1 3 4 2 5"); */
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 2  && j == 4)
	{
		/* ("3 1 4 2 5"); */
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 3  && j == 4)
	{
		/* ("3 4 1 2 5"); */
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 5  && j == 4)
	{
		/* ("3 4 5 2 1"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 1 && j == 5)
	{
		/* ("1 3 4 5 2"); */
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 2 && j == 5)
	{
		/* ("3 1 4 5 2"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 3 && j == 5)
	{
		/* ("3 4 1 5 2"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
	else if (i == 4 && j == 5)
	{
		/* ("3 4 5 1 2"); */
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_3_for_4_and_5(stack_a);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		push_a(stack_b, stack_a);
	}
}
