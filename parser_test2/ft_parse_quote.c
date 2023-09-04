t_list	*ft_parse_quote(char *s, int *i)
{
	t_list	*node;
	char	*text;

	*i += 1;
	text = ft_parse_token(s, *i, "\'");
	if (text == NULL)
		return (NULL);
	if (s[*i] == '\0')
	{
		free(text);
		error("bash: ");
		return (NULL);
	}
	node = ft_lstnew(text);
	if (node == NULL)
	{
		free(text);
		return (NULL);
	}
	return (node);
}

t_list	*ft_parse_dquote(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;
	char	*text;

	*i += 1;
	list = NULL;
	while (s[*i] != '\"')
	{
		if (s[*i] == '\0')
		{
			error("bash: ");
			ft_txtclear(&list);
			return (NULL);
		}
		else if (s[*i] == '\"')
			break ;
		else if (s[*i] == '$')
			node = ;
		else
			node = ft_parse_tok(s, *i, "\"$");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	*i += 1;
	return (list);
}

t_list	*empty_string(void)
{
	char	*s;
	t_list	*node;

	s = ft_strdup("");
	if (s == NULL)
		return (NULL);
	node = ft_lstnew(s);
	if (node == NULL)
	{
		free(s);
		return (NULL);
	}
	return (node);
}
