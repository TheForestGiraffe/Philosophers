/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/03/02 11:37:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: Implement app_destroy.c

int	main(int argc, char **argv)
{
	t_app_data	app;
	int			rc;

	app_init(&app);
	rc = app_setup(argc, argv, &app);
	if (rc)
	{
		app_destroy(&app);
		return (rc);
	}
	rc = run_dinner_simulation(&app);
	app_destroy(&app);
	return (rc);
}
