char	*env_getval_base(t_info *info, char *key);
t_list	*ft_parse_list(char *s);

t_list	*ft_parse_env(t_info *info, char *s, int *i)
{
	t_list	*value;
	char	*key;

	if (env_getkey(&key, s, i) < 0)
		return (NULL);
	value = env_getval(info, key);
	free(key);
	if (value == NULL)
		return (NULL);
	return (value);
}

int	env_getkey(char **key, const char *s, int *i)
{
	int		len;

	*i += 1;
	len = ft_toklen(s, *i, "\"\' <|>?!$");
	if (len == 0)
	{
		if (s[*i] == '\0' || ft_isin(s[*i], " <|>"))
		{
			*key = NULL;
			return (0);
		}
		else if (ft_isin(s[*i], "\"\'"))
			*key = ft_substr(s, *i, 0);
		else if (ft_isin(s[*i], "!?$"))
			*key = ft_substr(s, *i, 1);
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
	char	*value;
	t_list	*list;
	t_list	*node;
	int		i;

	i = 0;
	val = env_getval_base(info, key);
	if (val == NULL)
		return (NULL);
	list = NULL;
	while (val[i])
	{
		if (val[i] == ' ')
			node = ft_parse_space(val, &i, " ");
		else
			node = ft_parse_token(val, &i, " ");
		if (node == NULL)
		{
			ft_txtclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
	}
	free(val);
	return (list);
}

char	*env_getval_base(t_info *info, char *key)
{
	if (key == NULL)
		return (ft_strdup("$"));
	else if (key[0] == '\0')
		return (ft_strdup(""));
	else if (ft_strcmp(key, "$") == 0)
		return (ft_strdup(""));
	else if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(info->status));
	else if (ft_strcmp(key, "!") == 0)
		return (ft_itoa(info->lastpid));
	else
		return (env_getfrominfo(info, key));
}

char	*env_getfrominfo(t_info *info, char *key)
{
	t_env	*node;

	if (key == NULL)
		return (ft_strdup(""));
	else if (key[0] == '\0')
		return (ft_strdup(""));
	node = envsearch(info->envlst, key);
	if (node == NULL || node->value == NULL)
		return (ft_strdup(""));
	return (ft_strdup(node->value));
}
