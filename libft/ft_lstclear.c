/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:56:11 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 19:26:38 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear_c(t_list_c **lst, void (*del)(void*))
{
	t_list_c	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (**lst).next;
			ft_lstdelone_c((*lst), del);
			*lst = temp;
		}
	}
}

void	ft_lstclear_v(t_list_v **lst, void (*del)(void*))
{
	t_list_v	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (**lst).next;
			ft_lstdelone_v((*lst), del);
			*lst = temp;
		}
	}
}
