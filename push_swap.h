/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:32:03 by vsimeono          #+#    #+#             */
/*   Updated: 2022/02/26 15:45:42 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	int				index;
	struct	s_stack	*next;
} t_stack;

typedef struct s_variables
{
	int		i;
	int		j;
	int		arguments_count;
} t_variables;


/* Linked List */
void	stack_add_bottom(t_stack **stack, int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*create_stack_value(int value);
void	free_stack(t_stack **stack_a);

/*  AKS   */
int	len_stack(t_stack **stack);
int	len_stack_index_assign(t_stack **stack);
int	bubble_swap(int small, int big);
int	count_biggest_index_in_binary(t_stack **stack);
int	bitlength(int num);


/* Operations  */
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	reverse_rotate_a(t_stack **stack);
void	reverse_rotate_b(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

/* Sort Few   */
void	manual_sort(t_stack **stack_a, t_stack **stack_b, int argc);
void	sort_3(t_stack  **stack);
t_stack	*sort_3_for_4_and_5(t_stack  **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
t_stack   *sort_4_for_5(t_stack **stack_a, t_stack **stack_b);
void    sort_5(t_stack **stack_a, t_stack **stack_b);

/* Shifting   */
void	shifting(t_stack **stack_a, t_stack **stack_b);

/* Libft  */
long	ft_atoi(const char *str);
int		ft_isdigit(int c);

/* Indexing   */
void	bubble_sort(t_stack **stack);
int		bubble_swap(int small, int big);
void	index_assignment(t_stack **stack_a, t_stack **stack_sorted);
int		len_stack_index_assign(t_stack **stack);

/* Checkers   */
int	more_than_int(int argc, char **argv);
int	has_duplicates(int argc, char **argv);
int	more_than_digits(int argc, char **argv);
int	is_sorted(t_stack ** stack);

/*   Just for Testing  */
void	print(t_stack *stack);
void	print_stack(t_stack **stack);
void	print_index(t_stack **stack);

#endif