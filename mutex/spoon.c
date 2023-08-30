#include <pthread.h>

typedef phtread_mutex_t	t_fork; 

t_fork	*ft_forknew(void)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	pthread_mutex_init(fork, NULL);
	return (fork);
}

int	ft_forkdel(t_fork *fork)
{
	if (pthread_mutex_destroy(fork) != 0)
		return (-1);
	free(fork);
	return (0);
}

int	ft_take(t_fork *fork)
{
	return (pthread_mutex_lock(fork));
}

int	ft_release(t_fork *fork)
{
	return (pthread_mutex_unlock(fork));
}
