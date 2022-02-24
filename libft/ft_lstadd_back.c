/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:47:27 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:33:40 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back_c(t_list_c **alst, t_list_c *new)
{
	t_list_c	*last;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			last = ft_lstlast_c(*(alst));
			last->next = new;
		}
	}
}
void	ft_lstadd_back_v(t_list_v **alst, t_list_v *new)
{
	t_list_v	*last;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			last = ft_lstlast_v(*(alst));
			last->next = new;
		}
	}
}
