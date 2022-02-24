/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:59:04 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:35:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_lstcopy_c(t_list_c *lst, t_list_c *new, void *(*f)(void *))
{
	if (lst != NULL)
	{
		new->next = ft_lstnew_c(f(lst->content));
		ft_lstcopy_c(lst->next, new->next, f);
	}
	else
		new->next = NULL;
}

t_list_c	*ft_lstmap_c(t_list_c *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_c	*new;

	if (!lst || !*f)
		return (NULL);
	new = ft_lstnew_c(f(lst->content));
	ft_lstcopy_c(lst->next, new, f);
	if (ft_lstsize_c(new) != ft_lstsize_c(lst))
	{
		ft_lstclear_c(&new, del);
		return (NULL);
	}
	return (new);
}

static void	ft_lstcopy_v(t_list_v *lst, t_list_v *new, void *(*f)(void *))
{
	if (lst != NULL)
	{
		new->next = ft_lstnew_v(f(lst->content));
		ft_lstcopy_v(lst->next, new->next, f);
	}
	else
		new->next = NULL;
}

t_list_v	*ft_lstmap_v(t_list_v *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_v	*new;

	if (!lst || !*f)
		return (NULL);
	new = ft_lstnew_v(f(lst->content));
	ft_lstcopy_v(lst->next, new, f);
	if (ft_lstsize_v(new) != ft_lstsize_v(lst))
	{
		ft_lstclear_v(&new, del);
		return (NULL);
	}
	return (new);
}
