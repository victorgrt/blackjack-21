/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:18 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 19:52:27 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

hand *ft_create_hand(card *deck)
{
    hand *new_hand = malloc(sizeof(hand));
    if (!new_hand)
        return NULL;
    
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
    
    return new_hand;
}

void    ft_add_card(hand *main, card *carte)
{
    main->next_card = carte;
}

// int main(void)
// {
//     card *deck = ft_generate_deck();
//     hand *main = ft_create_hand(deck);
//     int random = random_generator(1, 52);
//     card *carte_banque = ft_pick_hand_bank(deck, random);
//     ft_add_card(main, carte_banque);

//     while (main->next_card)
//     {
//         printf("%s of %s\n", main->value, main->suit);
//         main = main->next_card;
//     }
//     return (0);
// }