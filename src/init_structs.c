/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:07:52 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/11 14:07:57 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_position	inti_positions(void)
{
	t_position	new_positions;

	new_positions.x = 0;
	new_positions.y = 0;
	return (new_positions);
}