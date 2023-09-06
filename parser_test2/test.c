#include <stdio.h>
#include "redi.h"
#include "test.h"

int	ft_putlist(t_list *lst)
{
	t_redi	*redi;
	int		i;

	i = 0;
	while (lst)
	{
		redi = lst->content;
		printf("[%d]---------------------\n", i++);
		printf("type: \"%s\"\n", redi->type);
		printf("text: \"%s\"\n", redi->path);
		lst = lst->next;
	}
	printf("=========================\n");
	return (0);
}
