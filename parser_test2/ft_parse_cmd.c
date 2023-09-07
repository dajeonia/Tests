#include <stdlib.h>

t_list	*ft_parse_cmd(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (1)
	{
		*i += ft_duplen(s, *i, " ");
		if (s[*i] == '|' || s[*i] == '\0')
			break ;
		else if (ft_isin(s[*i], "<>"))
			node = ft_redinew(info, s, i);
		else
			node = ft_paramnew(info, s, i);
		if (node == NULL)
		{
			ft_rediclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_paramnew(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	t_list	*text;
	t_redi	*redi;

	text = ft_textnew(info, s, i);
	if (text == NULL)
		return (NULL);
	list = NULL;
	while (text)
	{
		redi = (t_redi*)(text->content);
		if (ft_strcmp(redi->path, "space") == 0)
			text = text->next;
		else
		{
			node = ft_paramnew_join();
			if (node == NULL)
			{
				ft_txtclear(&list);
				return (NULL);
			}
			ft_lstadd_back(&list, node);
		}
	}
}

