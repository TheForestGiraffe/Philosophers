/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/01 00:18:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_app_data	app;

	app_init(&app);
	if(app_setup(argc, argv, &app))
	{
		app_destroy(&app); // TODO
		return (1);
	}
	// TODO: run_simulation(&app);
	app_destroy(&app);
	return (0);
}
