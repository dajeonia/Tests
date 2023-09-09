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
