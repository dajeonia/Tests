#include "test.h"
#include <stdio.h>
#include "main.h"

t_list	*ft_parse_list(char *s);

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	t_list	*list;
	/*
	t_list	*new;
	t_list	*new2;
	char	*test;
	char	*test2;
	*/

	//atexit(leaks);
	/*
	list = NULL;
	test = ft_strdup("why am I");
	test2 = ft_strdup("why are you");
	new = ft_txtnew("text", test);
	new2 = ft_txtnew("param", test2);
	ft_lstadd_back(&list, new);
	ft_lstadd_back(&list, new2);
	*/
	list = ft_parse_list("Hello, My name is    no");
	ft_putlist(list);
	ft_txtclear(&list);
	return (0);
}

