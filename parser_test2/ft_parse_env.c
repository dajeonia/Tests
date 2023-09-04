t_list	*ft_parse_env(t_info *info, char *s, int *i)
{
	char	*val;
	char	*key;
	int		i;
	t_list	*list;
	t_list	*node;

	if (env_getkey(&key, s, i) < 0)
		return (NULL);
	val = env_getval(info, s, i);
	free(key);
	if (val == NULL)
		return (NULL);
	list = NULL;
	i = 0;
	while (val[i])
	{
		if (val[i] == ' ')
			node = ft_parse_dup(s, i, " ");
		else
			node = ft_parse_token(s, i, " ");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	return (val);
}

int	env_getkey(char **key, char *s, int *i)
{
	int		len;

	*i += 1;
	len = ft_toklen(s, *i, "\"\' <|>?!$");
	if (len == 0)
	{
		if (ft_isin(s[*i], " <|>"))
		{
			*key = NULL; // "$"
			return (0);
		}
		else if (ft_isin(s[*i], "\"\'"))
			*key = ft_substr(s, *i, 0); // ""
		else if (ft_isin(s[*i], "!?$"))
			*key = ft_substr(s, *i, 1); // "!, ?, $"
		*i += 1;
	}
	else
	{
		*key = ft_substr(s, *i, len);
		*i += len;
	}
	if (*key == NULL)
		return (-1);
	return (0);
}

t_list	*env_getval(t_info *info, char *key)
{
	t_env	*env_list;

	if (key == NULL)
		return (ft_strdup("$"));
	else if (key[0] == '\0')
		return (ft_strdup(""));
	else if (ft_strcmp(key, "$"))
		return ();
	else if (ft_strcmp(key, "?"))
		return ();
	else if (ft_strcmp(key, "!"))
		return ();
	else
		return (ft_env(info, key))
}
