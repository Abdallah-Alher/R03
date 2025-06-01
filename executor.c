#include <stdio.h>      // Pour les fonctions d'entrée/sortie, notamment perror()
#include <stdlib.h>     // Pour la fonction system() et d'autres utilitaires
#include <string.h>     // Pour les fonctions de manipulation de chaînes comme strncat() et strlen()
#include "executor.h"   // Inclusion du header déclarant la fonction execute_command()

// Fonction auxiliaire pour joindre les tokens en une seule chaîne
// Cette fonction parcourt le tableau de tokens et les concatène dans 'buffer', 
// en séparant chaque token par un espace, jusqu'à atteindre la taille maximale spécifiée.
static void join_tokens(char **tokens, char *buffer, size_t size) {
    buffer[0] = '\0'; // Initialise le buffer à une chaîne vide.
    int i = 0;
    while (tokens[i] != NULL) { // Parcourt chaque token du tableau tant qu'il n'est pas NULL.
        // Ajoute le token courant dans 'buffer' en s'assurant de ne pas dépasser la taille du buffer.
        strncat(buffer, tokens[i], size - strlen(buffer) - 1);
        // Si le token courant n'est pas le dernier, ajoute un espace pour séparer les tokens.
        if (tokens[i + 1] != NULL) {
            strncat(buffer, " ", size - strlen(buffer) - 1);
        }
        i++; // Passe au token suivant.
    }
}

// Fonction : execute_command
// But : Composer la commande complète à partir du tableau de tokens et l'exécuter.
// La commande est exécutée en utilisant la fonction system() adaptée pour Windows.
void execute_command(char **tokens) {
    char command[1024]; // Déclaration d'un buffer suffisamment grand pour assembler la commande.
    
    // Concatène tous les tokens en une seule chaîne représentant la commande complète.
    join_tokens(tokens, command, sizeof(command));

    // Exécute la commande reconstituée via system(), qui lance l'interpréteur de commandes du système.
    int result = system(command);
    if (result == -1) { // En cas d'erreur lors de l'exécution de la commande,
        perror("Erreur lors de l'exécution de la commande avec system()"); // affiche le message d'erreur correspondant.
    }
}