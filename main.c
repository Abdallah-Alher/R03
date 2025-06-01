#include <stdio.h>         // Bibliothèque standard pour les entrées/sorties (printf, fgets, etc.)
#include <stdlib.h>        // Bibliothèque standard pour la gestion de la mémoire et d'autres fonctions (malloc, free, system, etc.)
#include <string.h>        // Bibliothèque pour la manipulation de chaînes (strtok, strdup, strncat, etc.)
#include "parser.h"        // Déclaration des fonctions du module de parsing (découpage de la commande en tokens)
#include "executor.h"      // Déclaration des fonctions du module d'exécution (lancement des commandes)
#include "utils.h"         // Déclaration des fonctions utilitaires (par exemple, trim_whitespace)

// Définition de la taille maximale autorisée pour une commande utilisateur
#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];   // Tableau de caractères pour stocker la commande saisie
    char **tokens;                // Pointeur vers le tableau de tokens généré par le parsing
    
    // Affichage du message de bienvenue et indication de la commande pour quitter
    printf("Bienvenue dans Mini Shell rush-9 ! Tapez \"exit\" pour quitter.\n");

    // Boucle principale du shell pour traiter de manière continue les commandes utilisateur
    while (1) {
        // Affichage du prompt du shell
        printf("mini-shell_rush-9> ");
        
        // Lecture de l'entrée utilisateur depuis stdin (affiche de la console)
        if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL) { 
            break; // Sort de la boucle si fin d'entrée ou erreur (par exemple, Ctrl+D)
        }
        
        // Retrait du saut de ligne ajouté par fgets, en le remplaçant par le caractère nul
        input[strcspn(input, "\n")] = '\0';

        // Nettoyage de la chaîne pour éliminer les espaces superflus en début et fin de ligne
        char *trimmed_input = trim_whitespace(input);
        
        // Vérification si l'utilisateur souhaite quitter le shell
        if(strcmp(trimmed_input, "exit") == 0) {
           break;
        }
        
        // Découpage de la commande saisie en tokens à l'aide du module de parsing
        tokens = parse_command(trimmed_input);
        if(tokens == NULL) { 
            // Affichage d'un message d'erreur en cas d'échec du parsing
            fprintf(stderr, "Erreur lors du parsing.\n");
            continue; // Passe à l'itération suivante de la boucle
        }
        
        // Exécution de la commande reconstituée à partir des tokens via le module d'exécution
        execute_command(tokens);
        
        // Libération de la mémoire allouée pour les tokens afin d'éviter les fuites
        free_tokens(tokens);
    }
    
    // Affichage du message d'au revoir à la sortie du shell
    printf("Au revoir !\n");
    return 0;
}