t_list	*ft_parse_quote(char *s, int *i)
{
	t_list	*text;

	*i += 1;
	text = ft_parse_token(s, *i, "\'");
	if (text == NULL)
		return (NULL);
	if (s[*i] == '\0')
	{
		ft_txtclear(&text);
		error("bash: ");
		return (NULL);
	}
	*i += 1;
	return (node);
}
