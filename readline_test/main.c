#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("hello: \n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int	main(void)
{
	char	*buf;

	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		buf = readline("hello: ");
		if (buf == NULL)
		{
			printf("\033[10C");
			printf("\033[1A");
			printf("\b\b\bexit\n");
			exit(1);
		}
		add_history(buf);
		free(buf);
		buf = NULL;
	}
	return (0);
}

char	*env(char *parse)
{
	t_list	*text;
	int		i;
	int		flag;

	i = 0;
	text = NULL;
	flag = 0;
	while (parse[i])
	{
		ft_toklen
	}
}
