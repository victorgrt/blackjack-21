/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:24:57 by victor            #+#    #+#             */
/*   Updated: 2023/02/26 23:43:19 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLACKJACK_H
# define    BLACKJACK_H

typedef struct card {
    char *suit;
    char *value;
    int points;
} card;

typedef struct hand {
    card *carte;
    struct hand *next;
} hand;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int random_generator(int min, int max);
void    printer_hand(hand *hand, char *nom);
void    print_score(hand *bank, hand *player);
void    printer_card(hand *carte);
int ft_get_value(card *carte);
card *ft_pick_hand_player(card *deck);
card *ft_pick_hand_bank(card *deck);
card *ft_generate_deck();
hand *ft_generate_hand(int nb);

int    ft_player_score(hand *player);

void ft_bank(hand *hand_bank, hand *hand_player);

char demande_decision();

#endif