t_list	*ft_parse_dquote(t_info *info, char *s, int *i)
{
	t_list	*list;
	t_list	*node;

	list = ft_emptynew();
	if (list == NULL)
		return (NULL);
	
		if (s[*i] == '\0')
		{
			error();
			ft_txtclear(&list);
			return (NULL);
		}
		else
	}
}
