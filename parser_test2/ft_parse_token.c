#include "main.h"

t_list	*ft_parse_escape(char *s, int *i)
{
	char	*text;
	t_list	*node;

	*i += 1;
	if (s[*i] == '\0')
		ft_error();
	text = ft_substr(s, *i, 1);
	if (text == NULL)
		return (NULL);
	node = ft_lstnew(text);
	if (node == NULL)
	{
		free(text);
		return (NULL);
	}
	return (node);
}

t_list	*ft_parse_list(char *s)
{
	t_list	*list;
	t_list	*node;
	int		i;

	i = 0;
	list = NULL;
	while (s[i])
	{
		if (s[i] == ' ')
			node = ft_parse_space(s, &i, " ");
		else
			node = ft_parse_token(s, &i, " ");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_parse_token(char *s, int *i, const char *set)
{
	t_list	*node;
	char	*text;
	int		len;

	len = ft_toklen(s, *i, set);
	text = ft_substr(s, *i, len);
	if (text == NULL)
		return (NULL);
	*i += len;
	node = ft_txtnew("text", text);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_list	*ft_parse_space(char *s, int *i, const char *set)
{
	t_list	*node;
	char	*text;
	int		len;

	len = ft_duplen(s, *i, set);
	text = ft_substr(s, *i, len);
	if (text == NULL)
		return (NULL);
	*i += len;
	node = ft_txtnew("space", text);
	if (node == NULL)
		return (NULL);
	return (node);
}
