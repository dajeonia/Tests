t_list	*parser(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i += ft_duplen(s, i, " ");
		
	}
}

t_list	*ft_redi_node(const char *s, int *i)
{
	t_redi	*redi;

	redi = ft_redi(s, i);
	if (redi == NULL)
		return (NULL);

}

t_redi	*ft_redi(const char *s, int *i)
{
	t_redi	*redi;
	char	*type;
	char	*path;
	
	type = ft_redi_type(s, i);
	if (type == NULL)
		return (NULL);
	path = ft_redi_path(s, i);
	if (path == NULL)
	{
		free(type);
		return (NULL);
	}
	redi->type = type;
	redi->path = path;
	return (redi);
}

char	*ft_param(const char *s, int *i)
{

}

char	*ft_redi_path(const char *s, int *i)
{
	t_list	*path_list;
	t_list	*path_node;
	char	*path;

	*i += ft_duplen(s, *i, " ");
	if (ft_redi_path_check(s, i) < 0)
		return (NULL);
	path_list = NULL;
	while (1)
	{
		if (s[*i] == '\0' || ft_isin(s[*i], " <>|"))
			break ;
		else
			path_node = ft_redi_path_node(s, i);

		
	}
}

int	ft_redi_path_check(const char *s, int *i)
{
	if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
	{
		ft_putchar_fd(2, "minishell: syntax error near unexpected token '<'");
		return (-1);
	}
	return (0);
}

t_list	*ft_redi_path_list(const char *s, int *i)
{

}

char	*ft_redi_type(const char *s, int *i)
{
	char	*type;

	*i += 1;
	if (ft_duplen(s, *i, "<") == 1)
		type = ft_strdup("infile");
	else if (ft_duplen(s, *i, ">") == 1)
		type = ft_strdup("outfile");
	else
	{
		*i += 1;
		if (ft_duplen(s, *i, "<") > 1)
			type = ft_strdup("here_doc");
		else if (ft_duplen(s, *i, ">") > 1)
			type = ft_strdup("append");
	}
	return (type);
}

t_list	*ft_param_node(const char *s, int *i)
{
}

