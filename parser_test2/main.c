#include "redi.h"
#include <stdio.h>

int	ft_redi_test(t_list *text);

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	t_list	*list;
	t_list	*new;
	t_list	*new2;
	char	*test;
	char	*test2;

	//atexit(leaks);
	list = NULL;
	test = ft_strdup("why am I");
	test2 = ft_strdup("why are you");
	new = ft_txtnew("text", test);
	new2 = ft_txtnew("param", test2);
	ft_lstadd_back(&list, new);
	ft_lstadd_back(&list, new2);
	ft_redi_test(list);
	ft_txtclear(&list);
	return (0);
}

int	ft_redi_test(t_list *text)
{
	t_redi	*redi;
	int		i;

	i = 0;
	while (text)
	{
		redi = (t_redi *)(text->content);
		printf("[%d]: type: %s, text: %s\n", i++, redi->type, redi->path);
		text = text->next;
	}
	return (0);
}
