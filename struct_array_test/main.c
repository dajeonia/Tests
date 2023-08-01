#include <stdlib.h>
#include <stdio.h>

typedef struct s_test
{
	int data;
}	t_test;

int	main(void)
{
	t_test	*array;
	int		i;

	array = (t_test *)malloc(sizeof(t_test) * 15);
	i = 0;
	while (i < 15)
	{
		array[i].data = i;
		i++;
	}
	i = 0;
	while (i < 15)
	{
		printf("array[%d].data: %d\n", i, array[i].data);
		i++;
	}
	return (0);
}
