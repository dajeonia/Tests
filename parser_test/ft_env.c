typedef struct s_info
{
	int		exit_status;
	t_env	*env;
}	t_info;

char	*ft_env_getkey(const char *s, int start, int size);
t_env	*envsearch(t_env *envlst, char *name);

/*
char	*ft_env_dquote(t_env *env, const char *s, int *i)
{
	if (redi)
	{

	}
}

char	*ft_env_param(t_env *env, const char *s, int *i)
{
	
}

*/
char	*ft_envspace(t_info *info, const char *s, int *i)
{
	int		size;
	char	*key;
	char	*value;

	*i += 1;
	size = ft_get_envsize(s, i);
	if (size < 0)
		return (ft_strdup("$"));
	key = ft_env_getkey(s, i, size);
	if (key == NULL)
		return (NULL);
	value = ft_getenv(info, key);
	free(key);
	if (value == NULL)
		return (NULL);
	return (value);
}


char	*ft_getenv_pid(void)
{
	return (ft_strdup(""));
}

char	*ft_getenv_status(void)
{
	return (ft_strdup(""));
}

int	ft_env_getkeysize(const char *s, int *i)
{
	int	len;

	len = ft_toklen(s, *i, "?\"\'$ <|>");
	if (len > 0)
		return (len);
	if (s[*i] == '?')
		len = 1;
	else if (s[*i] == ' ' || s[*i] == '\0')
		len = -1;
	/*
	else if (s[*i] == '$')
		len = 1;
		*/
	return (len);
}

char	*ft_env_getvalue(t_info *info, const char *key)
{
	t_env	*node;
	char	*value;
	
	/*
	else if (ft_strcmp(key, "$") == 0)
		value = ft_getenv_pid();
	*/
	// key == "" ?
	else if (ft_strcmp(key, "?") == 0)
		value = ft_getenv_status();
	else
	{
		node = envsearch(env, key);
		if (node == NULL)
			value = ft_strdup("");
		else
			value = ft_strdup(node->value);
	}
	return (value);
}
