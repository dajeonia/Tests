t_list	*ft_emptynew(void);
t_list	*ft_parse_escape(char *s, int *i);

t_list	*ft_parse_dquote(t_info *info, char *s, int *i)
{
	t_list	*node;

	node = ft_parse_dquote_(info, s, i);
	if (s[*i] == '\0')
	{
		error("bash: ");
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
		ft_txtclear(&token);
	node = ft_dquote_merge(token);
	ft_txtclear(&token);
	if (node == NULL)
	{
		
	}
	*i += 1;
}

t_list	*ft_parse_dquote(t_info *info, char *s, int *i)
{
	t_list	*merge;
	t_list	*list;
	t_list	*node;

	*i += 1;
	list = NULL;
	while (s[*i])
	{
		if (s[*i] == '\"')
			break ;
		node = ft_dquote_node(info, s, i);
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	merge = ft_dquote_merge(list);
	ft_txtclear(&list);
	return (merge);
}

t_list	*ft_dquote_node(t_info *info, char *s, int *i)
{
	if (s[*i] == '$')
		node = ft_parse_env(info, s, i);
	else if (s[*i] == '\\')
		node = ft_parse_escape(s, i, "$\"\\");
	else
		node = ft_parse_token(s, i, "$\"\\");
}

char	*ft_dquote_lstjoin(t_list *list)
{
	t_redi	*redi;
	char	*join;
	char	*temp;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	while (list)
	{
		redi = list->content;
		temp = join;
		join = ft_strjoin(join, redi->path);
		free(temp);
		if (join == NULL)
			return (NULL);
		list = list->next;
	}
	return (join);
}

t_list	*ft_dquote_merge(t_list *list)
{
	t_list	*node;
	char	*path;

	path = ft_dquote_lstjoin(list);
	if (path == NULL)
		return (NULL);
	node = ft_txtnew("text", path);
	if (node == NULL)
	{
		free(path);
		return (NULL);
	}
	return (node);
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
