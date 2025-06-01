#include <stdio.h>      // Bibliothèque standard d'entrée/sortie (pour perror, etc.)
#include <stdlib.h>     // Bibliothèque standard (malloc, free, etc.)
#include <string.h>     // Pour la manipulation des chaînes (strtok, strdup, strlen, etc.)
#include "parser.h"     // Inclusion du header définissant les fonctions de parsing

// Définition du nombre maximum de tokens pouvant être extraits de la commande
#define MAX_TOKENS 100

// Fonction : parse_command
// But      : Découper une chaîne de caractères (input) en tokens (mots) selon le délimiteur " "
// Paramètre: input - Chaîne de caractères représentant la commande saisie par l'utilisateur
// Retour   : Un tableau de chaînes de caractères (tokens) terminé par NULL
char **parse_command(char *input) {
    // Allocation dynamique d'un tableau de pointeurs sur char pour stocker les tokens
    char **tokens = malloc(MAX_TOKENS * sizeof(char*));
    if (tokens == NULL) {
        // En cas d'échec, affiche un message d'erreur et retourne NULL
        perror("Erreur d'allocation mémoire");
        return NULL;
    }

    int position = 0;  // Variable pour suivre la position dans le tableau de tokens

    // Utilise strtok pour extraire le premier token, avec " " comme délimiteur
    char *token = strtok(input, " ");
    // Boucle sur chaque token tant qu'il existe et que l'on n'a pas dépassé la capacité maximale
    while (token != NULL && position < MAX_TOKENS - 1) {
        // Duplique le token pour l'allouer dynamiquement et le stocker dans le tableau
        tokens[position] = strdup(token);
        if (tokens[position] == NULL) {
            // En cas d'échec de l'allocation pour ce token, affiche une erreur
            perror("Erreur d'allocation mémoire pour le token");
            // Libère tous les tokens déjà alloués pour éviter toute fuite de mémoire
            for (int i = 0; i < position; i++) {
                free(tokens[i]);
            }
            free(tokens); // Libère le tableau lui-même
            return NULL;
        }
        position++;                    // Passe au token suivant dans le tableau
        token = strtok(NULL, " ");     // Récupère le token suivant de la chaîne d'entrée
    }
    tokens[position] = NULL; // Termine le tableau de tokens par un pointeur NULL pour indiquer la fin
    return tokens;         // Retourne le tableau de tokens construit
}

// Fonction : free_tokens
// But      : Libérer la mémoire allouée pour le tableau de tokens et chaque token individuel
// Paramètre: tokens - Le tableau de chaînes de caractères à libérer
void free_tokens(char **tokens) {
    if (tokens == NULL) return; // Si le tableau est NULL, il n'y a rien à libérer
    int i = 0;
    // Parcourt chaque token dans le tableau et le libère
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens); // Libère le tableau de pointeurs lui-même
}