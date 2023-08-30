t_list	*ft_param_text_node(t_list *param_list, const char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	while (1)
	{
		if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
			break ;
		else if (s[*i] == '\'')
			node = ft_parse_quote(s, i);
		else if (s[*i] == '\"')
			node = ft_parse_dquote(s, i);
		else if (s[*i] == '$')
			node = ft_parse_env_param(env, param_list, s, i);
		else 
			node = ft_parse_token(s, i, "\'\"$ <|>");
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_env_param()
{
	
}
