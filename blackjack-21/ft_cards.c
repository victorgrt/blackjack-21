/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cards.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:26:44 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 20:44:50 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

card *ft_generate_deck()
{
    card *deck = malloc(sizeof(card) * 52);
    if (!deck)
        return (NULL);

    card *current_card = deck;

    char *values[] = {
        "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "Jack", "Queen", "King"
    };

    char *colors[] = {
        "Spades", "Hearts", "Diamonds", "Clubs"
    };


    int points[] = {
        11, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        10, 10, 10
    };

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            current_card->value = values[i];
            current_card->suit = colors[j];
            current_card->points = points[i];
            current_card++;
        }
    }

    return deck;
}

card *ft_pick_hand_bank(card *deck)
{
    int i = 1;
    int random = random_generator(1, 52);
    card *carte = malloc(sizeof(card) * 1);
    if (!carte)
        return (NULL);

    while (i <= random)
    {
        if (i == random)
        {
            carte->value = deck->value;
            carte->suit = deck->suit;
        }
        deck++;
        i++;
    }
    return (carte);
}

card *ft_pick_hand_player(card *deck)
{
    int i = 1;
    int random_1st = random_generator(1, 52);

    card *carte = malloc(sizeof(card) * 2);
    if (!carte)
        return (NULL);

    while (i <= random_1st)
    {
        if (i == random_1st)
        {
            carte->value = deck->value;
            carte->suit = deck->suit;
            carte->points = deck->points;
        }
        deck++;
        i++;
    }
    return (carte);
}

// int main(void)
// {
//     card *deck = ft_generate_deck();
//     int random = random_generator(1, 52);
//     card *carte_banque = ft_pick_hand_bank(deck, random);
//     card *carte_player = ft_pick_hand_player(deck, random);

//     printf("Carte banque : %s of %s\n", carte_banque->value, carte_banque->suit);
//     printf("Carte player : %s of %s\n", carte_player->value, carte_player->suit);
//     printf("valeur %d\n%d\n", ft_get_value(carte_banque), ft_get_value(carte_player));
//     // for (int i = 0; i < 52; i++)
//     // {
//     //     printf("%s of %s\n", deck[i].value, deck[i].color);
//     // }

//     free(deck);

//     return (0);
// }
