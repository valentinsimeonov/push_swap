/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:32:03 by vsimeono          #+#    #+#             */
/*   Updated: 2022/01/22 18:32:04 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>


typedef struct s_element
{
	int		value;
	struct	s_node *prev;
	struct	s_node *next;
} t_element;

typedef struct s_stack 
{
	struct s_stack *top;
	struct s_stack *bot;
} t_stack;

typedef struct s_variables
{
	int		i;
	int		arguments_count;
	// int		j;
	// int		k;

} t_variables;

#endif