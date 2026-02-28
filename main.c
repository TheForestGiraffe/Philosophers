/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:54:31 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/28 16:01:58 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_app_data	app;

	if(validate_and_parse_input(argc, argv, &app))
		return (1);
	if(app_setup(&app)) // TODO: implement
	{
		app_destroy(&app); // TODO: implement
		return (1);
	}
	
	return (0);
}
