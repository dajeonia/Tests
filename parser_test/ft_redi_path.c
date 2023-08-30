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
	char	*text;

	if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
		return (NULL);
	else if (s[*i] == '\'')
		text = ft_parse_quote(s, i);
	else if (s[*i] == '\"')
		text = ft_parse_dquote(s, i);
	else if (s[*i] == '$')
		text = ft_parse_env_path(redi, s, i);
	else 
		text = ft_parse_token(s, i, "\'\"$ <|>");
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
