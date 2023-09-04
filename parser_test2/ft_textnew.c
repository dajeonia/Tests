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
