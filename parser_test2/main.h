#include "redi.h"
#include "../libft/incs/libft.h"

int	ft_toklen(const char *s, int start, const char *set);
int	ft_duplen(const char *s, int start, const char *set);
int	ft_toklen_zero(const char *s, int start, const char *set);
int	ft_isin(int a, const char *set);

t_list	*ft_parse_list(char *s);
t_list	*ft_parse_token(char *s, int *i, const char *set);
t_list	*ft_parse_space(char *s, int *i, const char *set);
