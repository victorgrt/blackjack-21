/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:28:16 by victor            #+#    #+#             */
/*   Updated: 2023/02/28 12:59:23 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

/*Distribuer 2 cartes et 1 au banquier #si blackjack des premier round seulement x1.5 la mise x0 si bj bank aussi
Joueur joue : stand, double, demander carte, surrender
Banquier joue : pioche jusqu'a minimum 17
*/

hand *ft_hand(card *carte1, card *carte2)
{
    hand *main = malloc(sizeof(hand));
    if (!main)
        return (NULL);

    if (carte1)
    {
        main->carte->points = carte1->points;
        main->carte->suit = carte1->suit;
        main->carte->value = carte1->value;
        if (carte2)
        {
            main->next->carte->points = carte2->points;
            main->next->carte->suit = carte2->suit;
            main->next->carte->value = carte2->value;
        }
        else   
            main->next = NULL;
    }
    return (main);
}


hand *ft_generate_hand(int nb)
{
    hand *main = malloc(sizeof(hand) * nb);
    card *deck = ft_generate_deck();
    card *carte_generated = ft_pick_hand_player(deck);

    if (nb == 1)
    {
        main->carte = carte_generated;
        main->next = NULL;
    }
    else if (nb == 2)
    {
        card *carte_generated2 = ft_pick_hand_player(deck);
        main->carte = carte_generated;
        main->next->carte = carte_generated2;
        main->next->next = NULL;
    }
    free(deck);
    return (main);
}

void    ft_add_carte_to_hand(hand *player_hand)
{

    while (player_hand)
    {
        if (player_hand->next == NULL)
            player_hand->next = ft_generate_hand(1);
        player_hand = player_hand->next;
    }
}

/*Une main = une liste de cartes.*/

int main(void)
{     
    char decision; 
    char *your_hand = "YOUR HAND";
    char *bank = "BANK";
    int mise = 0;
    hand *new_cart;
    mise = ft_parier();
    printf("%d\t%d\n", ft_get_wallet(), mise);
    //On génére un deck
    //On distribue 1 carte a la banque : il faut un main pour la banque
    hand *hand_bank = ft_generate_hand(1);
    printer_hand(hand_bank, bank);
    hand *hand_player = ft_generate_hand(2);
    //printf("Player : %s of %s \t %s of %s\n", hand_player->carte->value, hand_player->carte->suit, hand_player->next->carte->value, hand_player->next->carte->suit);
    printer_hand(hand_player, your_hand);
    //printf("bank : %d\n", hand_bank->carte->points);
    //printf("player : %d\n", hand_player->carte->points);
    print_score(hand_bank, hand_player);
    decision = demande_decision();
    if (decision == 's')
    {
        if (ft_bank(hand_bank, hand_player, mise) == 1)
            ft_update_wallet(mise * 2);
    }
    else if (decision  == 'c')
    {
        new_cart = ft_generate_hand(1);
        hand_player->next->next = new_cart;
        printer_hand(hand_player, your_hand);
        if (ft_player_score(hand_player) > 21)
        {
            printf("\033[31m💀 -%d 💀 Tu as été trop greedy mon ami...🃏\033[0m\n", mise);
            ft_update_wallet(-mise);
            return (0);
        }
        print_score(hand_bank, hand_player);
        decision = demande_decision();
        if (decision == 'c')
        {
            new_cart = ft_generate_hand(1);
            hand_player->next->next->next = new_cart;
            printer_hand(hand_player, your_hand);
            if (ft_player_score(hand_player) > 21)
            {
                print_score(hand_bank, hand_player);
                printf("\033[31m💀 -%d 💀 Tu as été trop greedy mon ami...🃏\033[0m\n", mise);
                ft_update_wallet(-mise);
                return (0);
            }
            print_score(hand_bank, hand_player);
            decision = demande_decision();
            if (decision == 's')
            {
                if (ft_bank(hand_bank, hand_player, mise) == 1)
                    ft_update_wallet(mise * 2);
            }
        } 
        else if (decision == 's')
        {
            if (ft_bank(hand_bank, hand_player, mise) == 1)
                    ft_update_wallet(mise * 2);
        }
        else if (decision == 'a')
        {
            printf("Dommage, une prochaine fois peut être\n");
            return (1);
        }
    }
    else if (decision == 'a')
    {
        printf("Dommage, une prochaine fois peut être\n");
        return (1);
    }
    // hand *player_hand = malloc(sizeof(hand) * 2);
    //free(deck);
    return (0);
}
