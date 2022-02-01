/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:32:03 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/31 21:41:31 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>   //////Delete This!!!!   TODO


// typedef struct s_element
// {
// 	int		value;
// 	struct	s_element *prev;
// 	struct	s_element *next;
// } t_element;

typedef struct s_stack 
{
	int value;
	struct s_stack *next;
} t_stack;

typedef struct s_variables
{
	int		i;
	int		arguments_count;
	// int		j;
	// int		k;

} t_variables;

void	stack_add_bottom(t_stack **stack, int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

t_stack	*create_stack_value(int value);
t_stack	*create_stack_empty(void);

int	len_stack(t_stack **stack);


/// Operations
void	swap_a(t_stack **stack);
void	swap_b(t_stack *stack);


void	rotate_stack(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);


// t_element	*create_element(int value);


//// Libft
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

/////Just for Testing
void print(t_stack *stack);
void	print_stack(t_stack **stack);



#endif