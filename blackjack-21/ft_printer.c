/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:18:29 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 20:45:35 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blackjack.h"

void    print_score(hand *bank, hand *player)
{
    int bank_score = 0;
    int player_score = 0;
    
    while (bank)
    {
        bank_score += bank->carte->points;
        bank = bank->next;
    }
    while (player)
    {
        player_score += player->carte->points;
        player = player->next;
    }
    printf("La banque a %d.\nTu as %d.\n", bank_score, player_score);
}

void    printer_hand(hand *hand)
{
    if (hand->next == NULL)
    {
        printer_card(hand);
        return ;
    }  
    while (hand)
    {
        printer_card(hand);
        hand = hand->next;
    }    
    
}

void    printer_card(hand *hand)
{
    char *valeur = hand->carte->value;
    //printf("%s of %s\n", hand->carte->value, hand->carte->suit);
    char *couleur = hand->carte->suit;

    if (strcmp(couleur, "Spades") == 0)
    {
        couleur = "♠♠♠";
    }
    else if (strcmp(couleur, "Hearts") == 0)
    {
        couleur = "❤❤❤";
    }
    else if (strcmp(couleur, "Diamonds") == 0)
    {
        couleur = "♦♦♦";
    }
    else if (strcmp(couleur, "Clubs") == 0)
    {
        couleur = "♣♣♣";
    }
    if (strcmp(valeur, "10") == 0)
    {
        valeur = "10";
         printf("  ______\n |*%s *|\n |      |\n |  %s  |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
        return ;
    }
    else if (strcmp(valeur, "King") == 0)
    {
        valeur = "KING\0";
         printf("  ______\n |*%s *|\n |      |\n | %s |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
        return ;
    }
    else if (strcmp(valeur, "Ace") == 0)
    {
        valeur = "ACE\0";
        printf("  ______\n |*%s *|\n |      |\n | %s  |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
        return ;
    }
    else if (strcmp(valeur, "Queen") == 0)
    {
        valeur = "QUEEN\0";
        printf("  ______\n |*%s *|\n |      |\n |%s |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
        return ;
    }
    else if (strcmp(valeur, "Jack") == 0)
    {
        valeur = "JACK\0";
        printf("  ______\n |*%s *|\n |      |\n | %s |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
    }
    else   
        printf("  ______\n |*%s *|\n |      |\n |  %s   |\n |      |\n |*%s *|\n  ~~~~~~\n", couleur, valeur, couleur);
}

// int main(void)
// {
//     card *deck = ft_generate_deck();
//     int random = random_generator(1, 52);
//     card *carte_banque = ft_pick_hand_bank(deck, random);
//    // card *carte_player = ft_pick_hand_player(deck, random);
//     printer_card(carte_banque);
//     return (0);
// }