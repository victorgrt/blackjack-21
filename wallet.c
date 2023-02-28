/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:58:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/02/28 13:39:16 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_get_wallet()
{
	int wallet = 100; // Montant initial du porte-monnaie
    FILE *fp;

    // Lire le montant du fichier
    fp = fopen("wallet.txt", "r");
    if (fp != NULL) 
	{
        fscanf(fp, "%d", &wallet);
        fclose(fp);
    }
	return (wallet);
}

void printer_wallet()
{
	int wallet = ft_get_wallet();
	printf("\n        ████████████                                                \n    ██████      ████████    \n  ████              ████    \n  ██            ██    ████  \n████            ██    ████  \n██              ██      ████\n██              ██      ████\n██     %d    	██      ████\n██              ██      ████\n██              ██      ████\n████            ██    ████  \n  ██      ████████    ████  \n  ████              ████    \n    ██████      ████████    \n        ████████████", wallet);        
}

int ft_update_wallet(int mise)
{
	FILE *fp;
	int wallet = ft_get_wallet() + mise;
	
    fp = fopen("wallet.txt", "w");
    if (fp != NULL) 
	{
        fprintf(fp, "%d", wallet);
        fclose(fp);
    }
	return (wallet);
}

// int main() 
// {
// 	printer_wallet();
// 	//printf("%d\n", ft_get_wallet());
// 	ft_update_wallet(100);
// 	//printf("%d\n", ft_get_wallet());
// 	printer_wallet();
//     return 0;
// }