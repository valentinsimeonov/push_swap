/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:37:22 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/07 19:02:26 by vsimeono         ###   ########.fr       */
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
	int		temp;

	temp = 0;
	if (argc == 1 || argc == 2)
		return (0);
	if ((argc < 3) || more_than_digits(argc, argv) || \
		more_than_int(argc, argv) || has_duplicates(argc, argv))  /// Need to Add if sorted
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
	bubble_sort(&stack_sorted);
	index_assignment(&stack_a, &stack_sorted);
	if (argc == 3 && stack_a->index != 1)
	{
		swap_a(&stack_a);
		return (0);
	}
	// if (argc > 3 && argc > 6)
	// 	manual_sort(&stack_a);

	if (argc > 4)
		shifting(&stack_a, &stack_b);
	return (0);
}

void	manual_sort(t_stack **stack)
{
	
}

void	shifting(t_stack **stack_a, t_stack **stack_b)
{
    int        shift;
    int        i;
	int			count;
    int        biggest_index;

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
                rotate_stack_a(stack_a);
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
int    bitlength(int num)
{
    int    bits;

    bits = 0;
    while ((num >> bits) != 0)
        bits++;
    return (bits);
}

// int	count_biggest_index_in_binary(t_stack **stack)
// {
// 	int		max_index;
// 	int		max_bits;

// 	max_bits = 0;
// 	max_index = len_stack(stack);
// 	while (max_index >> max_bits)
// 		max_bits++;
// 	return (max_bits);
// }




// void	shifting(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		shift;
// 	int		count;
// 	int		i;
// 	int		biggest_index;
// 	t_stack	*temp;

// 	temp = *stack_a;

// 	count = len_stack(stack_a);
// 	biggest_index = count_biggest_index_in_binary(stack_a);
// 	shift = 0;
// 	i = 0;
// 	while (shift <= biggest_index)
// 	{	i = 0;
// 		if (*stack_a)
// 		{
// 			while (i < count && *stack_a)
// 			{
// 				if ((*stack_a)->index >> shift & 1)
// 					// push(stack_a, stack_b);
// 					rotate_stack_a(stack_a);
// 				else 
// 					// rotate_stack(stack_a);
// 					push_b(stack_a, stack_b);
// 					// reverse_rotate(stack_a);
// 				// printf("Stack A\n");
// 				// print_index(stack_a); 
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 				i++;
// 			}
// 				// printf("Stack A\n");
// 				// print_index(stack_a);
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 		}
// 		if (*stack_b)
// 		{
// 			while (*stack_b)
// 			{
// 				// if (((*stack_b)->index >> shift & 1) == 1)
// 				// 	// push(stack_a, stack_b);
// 				// 	rotate_stack_a(stack_a);
// 				// else 
// 				// 	// rotate_stack(stack_a);
// 				// 	push_b(stack_a, stack_b);
				
				
// 				push_a(stack_b, stack_a);


				
// 				// print_stack(stack_a);
// 			}
// 				// printf("Stack A\n");
// 				// print_index(stack_a);
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 				// sleep(1);
// 		}
// 		shift++;
// 	}
// }

// int	count_biggest_index_in_binary(t_stack **stack)
// {
// 	int		max_index;
// 	int		max_bits;

// 	max_bits = 0;
// 	max_index = len_stack(stack);
// 	while (max_index >> max_bits)
// 		max_bits++;
// 	return (max_bits);
// }

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



// void	shifting(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		shift;
// 	int		count;
// 	int		i;
// 	int		biggest_index;
// 	t_stack	*temp;

// 	temp = *stack_a;

// 	count = len_stack(stack_a);
// 	biggest_index = count_biggest_index_in_binary(stack_a);
// 	shift = 0;
// 	i = 0;
// 	while (shift <= biggest_index)
// 	{	i = 0;
// 		if (*stack_a)
// 		{
// 			while (i < count && *stack_a)
// 			{
// 				if (((*stack_a)->index >> shift & 1)
// 					// push(stack_a, stack_b);
// 					rotate_stack_a(stack_a);
// 				else 
// 					// rotate_stack(stack_a);
// 					push_b(stack_a, stack_b);
// 					// reverse_rotate(stack_a);
// 				// printf("Stack A\n");
// 				// print_index(stack_a); 
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 				i++;
// 			}
// 				// printf("Stack A\n");
// 				// print_index(stack_a);
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 		}
// 		if (*stack_b)
// 		{
// 			while (*stack_b)
// 			{
// 				// if (((*stack_b)->index >> shift & 1) == 1)
// 				// 	// push(stack_a, stack_b);
// 				// 	rotate_stack_a(stack_a);
// 				// else 
// 				// 	// rotate_stack(stack_a);
// 				// 	push_b(stack_a, stack_b);
				
				
// 				push_a(stack_b, stack_a);


				
// 				// print_stack(stack_a);
// 			}
// 				// printf("Stack A\n");
// 				// print_index(stack_a);
// 				// printf("Stack B\n");
// 				// print_index(stack_b);
// 				// sleep(1);
// 		}
// 		shift++;
// 	}
// }