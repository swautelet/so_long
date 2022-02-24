/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:29:25 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:22:56 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize_c(t_list_c *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}

int	ft_lstsize_v(t_list_v *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}
