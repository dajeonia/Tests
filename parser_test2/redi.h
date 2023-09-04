#include "../libft/incs/libft.h"

typedef struct s_redi
{
	char	*type;
	char	*path;
}	t_redi;

void	ft_txtclear(t_list **text);
t_list	*ft_txtnew(char *type, char *path);
t_redi	*ft_txtbase(char *type, char *path);
void	ft_txtdel(void *param);
