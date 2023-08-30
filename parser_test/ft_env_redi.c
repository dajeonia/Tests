
char	*ft_env_redi(t_info *info, const char *s, int *i)
{
	char	*key;
	char	*value;
	int		check;

	key = 
	value = ft_env(info, s, i);
	if (value == NULL)
		return (NULL);
	if (ft_env_redi_check(value))
	{
		ft_putendl(2, "minishell: ambiguous redirect");
	}

}

int	ft_env_redi_check(const char *value)
{
	return (ft_isempty(value) || ft_issplit(value));
}

int	ft_isempty(const char *value)
{
	int	i;

	i = 0;
	i += ft_duplen(value, i, " ");
	if (value[i] == '\0')
		return (1);
	return (0);
}

int	ft_issplit(const char *value)
{
	int	i;

	i = 0;
	i += ft_duplen(value, i, " ");
	i += ft_toklen(value, i, " ");
	i += ft_duplen(value, i, " ");
	if (value[i] == '\0')
		return (1);
	return (0);
}

