/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/28 22:38:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_app_data	app;

	app_init(&app);
	if(parse_input(argc, argv, &app))
		return (1);
	if(app_setup(&app))
	{
		app_destroy(&app); // TODO: implement
		return (1);
	}
	//run_simulation(&app);
	app_destroy(&app);
	return (0);
}
