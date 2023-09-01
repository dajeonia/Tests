t_list	*ft_redi_path_node(t_redi *redi, const char *s, int *i)
{
	t_list	*node;
	char	*text;
	
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

t_list	*ft_redi_path_text(const char *s, int *i)
{
	t_list	*node;

	if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
		return (NULL);
	else if (s[*i] == '\'')
		node = ft_parse_quote(s, i);
	else if (s[*i] == '\"')
		node = ft_parse_dquote(s, i);
	else if (s[*i] == '$')
		node = ft_parse_env("redi", s, i);
	else 
		node = ft_parse_token(s, i, "\'\"$ <|>");
	if (node == NULL)
		return (NULL);
	return (node);
}
