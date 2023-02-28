/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:07:55 by victor            #+#    #+#             */
/*   Updated: 2023/02/28 13:34:30 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

int    ft_player_score(hand *player)
{
    int player_score = 0;
    
    while (player)
    {
        player_score += player->carte->points;
        player = player->next;
    }
    return (player_score);
}

int ft_get_value(card *carte)
{
    int valeur = 0;

    if (strcmp(carte->value, "Ace") == 0)
        valeur = 11;
    else if (strcmp(carte->value, "2") == 0)
        valeur = 2;
    else if (strcmp(carte->value, "3") == 0)
        valeur = 3;
    else if (strcmp(carte->value, "4") == 0)
        valeur = 4;
    else if (strcmp(carte->value, "5") == 0)
        valeur = 5;
    else if (strcmp(carte->value, "6") == 0)
        valeur = 6;
    else if (strcmp(carte->value, "7") == 0)
        valeur = 7;
    else if (strcmp(carte->value, "8") == 0)
        valeur = 8;
    else if (strcmp(carte->value, "9") == 0)
        valeur = 9;
    else if (strcmp(carte->value, "10") == 0)
        valeur = 10;
    else if (strcmp(carte->value, "Jack") == 0)
        valeur = 10;
    else if (strcmp(carte->value, "Queen") == 0)
        valeur = 10;
    else if (strcmp(carte->value, "King") == 0)
        valeur = 10;
    return valeur;
}