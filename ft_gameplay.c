/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:19 by victor            #+#    #+#             */
/*   Updated: 2023/02/27 15:56:02 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

int ft_parier()
{
    int mise = 0;
    
    printer_wallet();
    printf("\nVous avez : %d, combien voulez-vous miser ?\n", ft_get_wallet());
    scanf(" %d", &mise);
    ft_update_wallet(-mise);
    return (mise);
}

int ft_bank(hand *hand_bank, hand *hand_player)
{
    hand *new_cart;
    char *bank = "BANK'S HAND";
    char *you = "YOUR HAND";

    if (ft_player_score(hand_bank) <= 17)
    {
        new_cart = ft_generate_hand(1);
        hand_bank->next = new_cart;
        printer_hand(hand_bank, bank);
        printer_hand(hand_player, you);
        print_score(hand_bank, hand_player);
        if (ft_player_score(hand_bank) <= 17)
        {
            new_cart = ft_generate_hand(1);
            hand_bank->next->next = new_cart;
            printer_hand(hand_bank, bank);
            printer_hand(hand_player, you);
            print_score(hand_bank, hand_player);
            if (ft_player_score(hand_bank) < 17)
            {
                new_cart = ft_generate_hand(1);
                hand_bank->next->next->next = new_cart;
                printer_hand(hand_bank, bank);
                printer_hand(hand_player, you);
                print_score(hand_bank, hand_player);
            }
            if (ft_player_score(hand_bank) < 17)
            {
                new_cart = ft_generate_hand(1);
                hand_bank->next->next->next->next = new_cart;
                printer_hand(hand_bank, bank);
                printer_hand(hand_player, you);
                print_score(hand_bank, hand_player);
            }
        }
        if (ft_player_score(hand_bank) > 21)
        {
            printf("BANK BUSTED, YOU WIN !");
            return 1;
        }
        else if (ft_player_score(hand_bank) >= ft_player_score(hand_player))
        {
            printf("Perdu");
            return 0;
        }
    }
    printf("GG !");
    return 1;
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