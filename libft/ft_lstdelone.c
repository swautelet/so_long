/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:49:41 by swautele          #+#    #+#             */
/*   Updated: 2022/02/24 16:19:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone_c(t_list_c *lst, void (*del)(void*))
{
	(*del)((*lst).content);
	free (lst);
}

void	ft_lstdelone_v(t_list_v *lst, void (*del)(void*))
{
	(*del)((*lst).content);
	free (lst);
}
