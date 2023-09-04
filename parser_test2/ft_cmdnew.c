t_list	*ft_cmdnew(t_info *info, char *s)
{
	t_list	*cmd;
	t_list	*pipe;
	int		i;

	i = 0;
	i += ft_duplen(s, i, " ");
	cmd = ft_parse_redis(info, s, &i);
	if (s[i] == '|')
	{
		if (cmd == NULL)
		{
			error();
			break ;
		}
		pipe = ft_pipenew(s, &i);
		if (pipe == NULL)
		{
			ft_cmddelone(cmd);
			return (NULL);
		}
	}
	return (cmd);
}

t_list	*ft_pipenew(char *s, int *i)
{
	t_list	*cmd;
	t_list	*pipe;
	
	*i += ft_duplen(s, *i, " ");
	if (s[i] == '\0' || s[i] == '|')
	{
		error();
		return (NULL);
	}
	cmd = ft_parse_redis(info, s, i);
	if (s[i] == '|')
	{
		if (cmd == NULL)
		{
			error();
			return (NULL);
		}
		pipe = ft_pipenew(s, i);
	}
}
