int	ft_parse_quote()
{
	
}

char	*ft_parse_quote(const char *s, int *i)
{
	char	*text;

	*i += 1;
	if (ft_toklen_zero(s, *i, "\'") < 0)
	{
		ft_error();
		return (NULL);
	}
	text = ft_parse_tok(s, i, "\'");
	*i += 1;
	return (text);
}

