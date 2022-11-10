/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:34:25 by asekkak           #+#    #+#             */
/*   Updated: 2022/10/19 14:36:36 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = *lst;
	if (*lst)
	{
		while (lastnode->next)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = new;
	}
	else
		*lst = new;
}
