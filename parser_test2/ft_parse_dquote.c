t_list	*ft_parse_escape(char *s, int *i);

t_list	*ft_parse_dquote(t_info *info, char *s, int *i)
{
	t_list	*ret;
	t_list	*list;

	list = ft_parse_dquote_token(info, s, i);
	if (list == NULL)
		return (NULL);
	if (s[*i] == '\0')
	{
		error("bash: ");
		ft_txtclear(&list);
		return (NULL);
	}
	*i += 1;
}

t_list	*ft_parse_dquote_token(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	*i += 1;
	list = empty_string();
	if (list == NULL)
		return (NULL);
	while (s[*i])
	{
		if (s[*i] == '\"')
			break ;
		else if (s[*i] == '$')
			node = ft_parse_env(info, s, i);
		else if (s[*i] == '\\')
			node = ft_parse_escape(s, i, "$\"\\");
		else
			node = ft_parse_token(s, i, "$\"\\");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (list);
}

t_list	*ft_dquote_node(t_info *info, char *s, int *i)
{
	t_list	*node;

}

t_list	*ft_emptynew(void)
{
	char	*s;
	t_list	*node;

	s = ft_strdup("");
	if (s == NULL)
		return (NULL);
	node = ft_txtnew("text", s);
	if (node == NULL)
	{
		free(s);
		return (NULL);
	}
	return (node);
}


