/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:29:18 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:32:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front_c(t_list_c **first, t_list_c *new)
{
	if (first == NULL || new == NULL)
		return ;
	new->next = *first;
	*first = new;
}

void	ft_lstadd_front_v(t_list_v **first, t_list_v *new)
{
	if (first == NULL || new == NULL)
		return ;
	new->next = *first;
	*first = new;
}
