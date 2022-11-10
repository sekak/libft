/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:57:51 by asekkak           #+#    #+#             */
/*   Updated: 2022/10/27 15:09:03 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}

void del(void *s)
{
	free(s);
}

#include <stdio.h>
int main()
{
	t_list *lst;
	lst = ft_lstnew(ft_strdup("heelloo"));
	lst  -> next = ft_lstnew(ft_strdup(" rrr"));
	lst  -> next -> next = ft_lstnew(ft_strdup(" vvvv"));
 ft_lstdelone(lst,&del);
	while (lst)
	{
		printf("%s",lst->content);
		lst = lst->next;
	}
}