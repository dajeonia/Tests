t_list	*ft_param_list(t_list *text_list)
{
	t_list	*list;
	t_list	*node;
	t_list	*cur;
	char	*path;

	cur = redi_list;
	list = NULL;
	while (cur)
	{
		ft_skip_space(&cur);
		if (cur == NULL)
			break ;
		node = ft_paramnew(&cur);
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		cur = cur->next;
	}
	return (list);
}

t_list	*ft_paramnew(t_list **cur)
{
	t_list	*node;
	char	*path;

	path = ft_lstjoin(&cur);
	if (path == NULL)
		return (NULL);
	node = ft_txtnew("param", path);
	if (node == NULL)
	{
		free(path);
		return (NULL);
	}
	return (node);
}

int	ft_skip_space(t_list **list)
{
	t_redi	*redi;

	while (*list)
	{
		redi = (*list)->content;
		if (ft_strcmp(redi->type, "text"))
			break ;
		*list = (*list)->next;
	}
	return (0);
}

char	*ft_lstjoin(t_list **list)
{
	t_redi	*redi;
	char	*join;
	char	*temp;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	while (*list)
	{
		redi = (*list)->content;
		if (ft_strcmp(redi->type, "space"))
			break ;
		temp = join;
		join = ft_strjoin(join, redi->path);
		free(temp);
		if (join == NULL)
			return (NULL);
		*list = (*list)->next;
	}
	if (*join = '\0')
	{
		free(join);
		join = NULL;
	}
	return (join);
}
