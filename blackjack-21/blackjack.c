/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:28:16 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 20:45:14 by victor           ###   ########.fr       */
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

/*Une main = une liste de cartes.*/

int main(void)
{     
    //On génére un deck
    //On distribue 1 carte a la banque : il faut un main pour la banque
    hand *hand_bank = ft_generate_hand(1);
    printer_hand(hand_bank);
    hand *hand_player = ft_generate_hand(2);
    printf("Player : %s of %s \t %s of %s\n", hand_player->carte->value, hand_player->carte->suit, hand_player->next->carte->value, hand_player->next->carte->suit);
    printer_hand(hand_player);
    //printf("bank : %d\n", hand_bank->carte->points);
    //printf("player : %d\n", hand_player->carte->points);
    print_score(hand_bank, hand_player);
    // hand *player_hand = malloc(sizeof(hand) * 2);

    // card *deck = ft_generate_deck();
    // int random = random_generator(1, 52);
    // card *carte_banque = ft_pick_hand_bank(deck, random);
    // printer_card(carte_banque);
    // card *carte_player1 = ft_pick_hand_player(deck, random);
    // card *carte_player2 = ft_pick_hand_player(deck, random);
    // player_hand->   = carte_player1;
    // player_hand->next_card = carte_player2;
    
    // printer_card(carte_player1);
    // printer_card(carte_player2);
    //printf("Carte banque : %s of %s\n", carte_banque->value, carte_banque->suit);
    //printf("Carte player : %s of %s\n", carte_player->value, carte_player->suit);
    // for (int i = 0; i < 52; i++)
    // {
    //     printf("%s of %s\n", deck[i].value, deck[i].color);
    // }
    //free(deck);
    return (0);
}
