/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:32:03 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/07 12:51:21 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>   //////Delete This!!!!   TODO

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// typedef struct s_element
// {
// 	int		value;
// 	struct	s_element *prev;
// 	struct	s_element *next;
// } t_element;

typedef struct s_stack 
{
	int value;
	int	index;
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


//////AKS
int	len_stack(t_stack **stack);
int	len_stack_index_assign(t_stack **stack);
int	bubble_swap(int small, int big);




/// Operations
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	rotate_stack_a(t_stack **stack);
void	rotate_stack_b(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
/// Shifting
void	shifting(t_stack **stack_a, t_stack **stack_b);

/// Utils
int	count_biggest_index_in_binary(t_stack **stack);

//// Libft
long	ft_atoi(const char *str);
int		ft_isdigit(int c);

// Indexing
void    bubble_sort(t_stack **stack);
int		bubble_swap(int small, int big);
void	index_assignment(t_stack **stack_a, t_stack **stack_sorted);
int		len_stack_index_assign(t_stack **stack);

// Checkers
int	more_than_int(int argc, char **argv);
int	has_duplicates(int argc, char **argv);
int	more_than_digits(int argc, char **argv);

/////Just for Testing
void	print(t_stack *stack);
void	print_stack(t_stack **stack);
void	print_index(t_stack **stack);


//// Testing with Edvinas
int    bitlength(int num);
#endif