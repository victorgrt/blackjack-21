/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:20:19 by victor            #+#    #+#             */
/*   Updated: 2023/02/28 12:59:39 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

int ft_joueur_c(hand *hand_bank, hand *hand_player, int mise, int nb_next)
{
    char *your_hand = "YOUR HAND";
    hand *new_cart = ft_generate_hand(1);

    for (int i = 0; i < nb_next; i++)
        hand_player = hand_player->next;
    hand_player->next = new_cart;
    printer_hand(hand_player, your_hand);
    if (ft_player_score(hand_player) > 21)
    {
        printf("Perdu");
        ft_update_wallet(-mise);
        return (0);
    }
    print_score(hand_bank, hand_player);
    return (1);
}

int ft_parier()
{
    int mise = 0;
    
    //printer_wallet();
    printf("\n💰Tu as %d pépéttes, combien tu veux perdre (ou gagner biensûr😉) ?💰\n", ft_get_wallet());
    scanf(" %d", &mise);
    ft_update_wallet(-mise);
    return (mise);
}

int ft_bank(hand *hand_bank, hand *hand_player, int mise)
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
            print_score(hand_bank, hand_player);
            printf("\033[32m💸 +%d 💸 💥 BANK BUSTED 💥\033[0m\n", mise);
            return 1;
        }
        else if (ft_player_score(hand_bank) >= ft_player_score(hand_player))
        {
            print_score(hand_bank, hand_player);
            printf("\033[31m💀 -%d 💀 La maison gagne toujours 🃏\n\033[0m", mise);
            return 0;
        }
    }
    printf("\033[32m💸 +%d 💸 Reviens vite\033[0m\n", mise);
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