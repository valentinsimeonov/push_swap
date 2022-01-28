/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:32:03 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/27 20:38:10 by vsimeono         ###   ########.fr       */
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
	struct s_stack *prev;
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

void	stack_add_bottom(t_stack *stack_a, int value);

t_stack	*create_stack_value(int value);
t_stack	*create_stack_empty(void);

/// Operations
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);

// t_element	*create_element(int value);
int	ft_atoi(const char *str);

/////Just for Testing
void print(t_stack *stack);




#endif