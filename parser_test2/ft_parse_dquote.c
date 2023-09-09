int	ft_dquote_check(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '\\')
		{
			i++;
			if (ft_isin(s[i], "$\"\\"))
		}
	}
}
