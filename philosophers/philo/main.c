/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:56:56 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 12:31:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo		*philos;
	pthread_t	*threads;

	if (ac < 5 || ft_atoi(av[1]) == 0 || ac > 6)
		return (1);

	philos = malloc(ft_atoi(av[1]) * sizeof(t_philo));
	if (!philos)
		return (1);
	if (ph_init(philos, av, ac))
		return (1);
	threads = malloc(ft_atoi(av[1]) * sizeof(pthread_t));
	if (!threads)
		return (1);
	if (ph_t_init(threads, ft_atoi(av[1]), philos))
		return (1);
	//ph_print(philos, ft_atoi(av[1]));
	ph_terminate(philos, threads, ft_atoi(av[1]));
	return (0);
}
