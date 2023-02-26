/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:19 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 23:39:49 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

void ft_bank(hand *hand_bank, hand *hand_player)
{
    hand *new_cart;

    if (ft_player_score(hand_bank) <= 17)
    {
        new_cart = ft_generate_hand(1);
        hand_bank->next = new_cart;
        printer_hand(hand_bank);
        printer_hand(hand_player);
        print_score(hand_bank, hand_player);
        if (ft_player_score(hand_bank) <= 17)
        {
            new_cart = ft_generate_hand(1);
            hand_bank->next = new_cart;
            printer_hand(hand_bank);
            printer_hand(hand_player);
            print_score(hand_bank, hand_player);
            if (ft_player_score(hand_bank) < 17)
            {
                new_cart = ft_generate_hand(1);
                hand_bank->next->next = new_cart;
                printer_hand(hand_bank);
                printer_hand(hand_player);
                print_score(hand_bank, hand_player);
            }
            if (ft_player_score(hand_bank) < 17)
            {
                new_cart = ft_generate_hand(1);
                hand_bank->next->next = new_cart;
                printer_hand(hand_bank);
                printer_hand(hand_player);
                print_score(hand_bank, hand_player);
            }
        }
        if (ft_player_score(hand_bank) > 21)
        {
            printf("Bank Busted");
            return ;
        }
        else if (ft_player_score(hand_bank) >= ft_player_score(hand_player))
        {
            printf("Perdu");
            return ;
        }
        else
        {
            printf("GG !");
            return ;
        }
    }
}

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