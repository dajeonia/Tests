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
	t_list	*param;
	t_list	*text;
	t_redi	*redi;

	text = ft_textnew(info, s, i);
	if (text == NULL)
		return (NULL);
	while (text)
	{
		redi = (t_redi*)(text->content);
	}
}

void	ft_skip(t_list **text)
{

}

t_list	*ft_textnew(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (1)
	{
		*i += ft_duplen(s, *i, " ");
		if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
			break ;
		else if (s[*i] == '$')
			node = ft_parse_env(info, s, i);
		else if (s[*i] == '\"')
			node = ft_parse_dquote(info, s, i);
		else if (s[*i] == '\'')
			node = ft_parse_quote(s, i);
		else
			node = ft_parse_token(s, i);
		if (node == NULL)
		{
			ft_rediclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}
