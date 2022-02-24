/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:58:26 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:19:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter_c(t_list_c *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while ((*lst).next != NULL)
	{
		(*f)((*lst).content);
		lst = (*lst).next;
	}
	(*f)((*lst).content);
}

void	ft_lstiter_v(t_list_v *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while ((*lst).next != NULL)
	{
		(*f)((*lst).content);
		lst = (*lst).next;
	}
	(*f)((*lst).content);
}
