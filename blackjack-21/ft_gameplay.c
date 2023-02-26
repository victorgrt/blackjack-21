/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:19 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 22:27:30 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

char demande_decision()
{
    char decision;
    do {
        printf("Voulez-vous (c)arte, (s)top ou (a)bandonner ? ");
        scanf(" %c", &decision);
    } while (decision != 'c' && decision != 's' && decision != 'a');
    return decision;
}

// int main(void)
// {
//     char test;

//     test = demande_decision();
//     printf("%c", test);
//     return (0);
// }