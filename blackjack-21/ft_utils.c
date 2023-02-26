/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:03:07 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 15:03:32 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

int	random_generator(int min, int max)
{
	struct	timeval tv;
	int	range;
	int	random_number;
	unsigned int seed;

	range = max - min + 1;
	gettimeofday(&tv, NULL);
	seed = tv.tv_sec + tv.tv_usec;
	srandom(seed);
	random_number = (int)(double)range * random() / (RAND_MAX + 1.0) + min; 
	return (random_number);
}