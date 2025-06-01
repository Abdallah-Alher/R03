#include <ctype.h>    // Pour la fonction isspace(), qui teste si un caractère est un espace
#include <string.h>   // Pour les fonctions strlen() qui calcule la longueur d'une chaîne
#include "utils.h"    // Inclusion du header déclarant la fonction trim_whitespace()

// Fonction : trim_whitespace
// But      : Supprimer les espaces en début et en fin de la chaîne passée en paramètre
// Paramètre: str - La chaîne de caractères à nettoyer
// Retour   : Un pointeur sur la chaîne "nettoyée". Si la chaîne est vide ou contient uniquement des espaces,
//            le même pointeur sera retourné.
char *trim_whitespace(char *str) {
    char *end; // Pointeur qui sera utilisé pour localiser la fin de la chaîne après avoir retiré les espaces

    // Boucle pour avancer dans la chaîne tant que le caractère courant est un espace
    while (isspace((unsigned char)*str)) {
        str++;  // Passe au caractère suivant
    }

    // Si la chaîne est vide (après suppression des espaces en début), retourne la chaîne
    if (*str == 0)
        return str; // Cas d'une chaîne vide ou d'une chaîne ne contenant que des espaces

    // Initialise le pointeur 'end' pour qu'il pointe sur le dernier caractère de la chaîne
    end = str + strlen(str) - 1;
    
    // Boucle pour reculer dans la chaîne tant que le caractère pointé par 'end' est un espace et que 'end' est
    // toujours après le début de la chaîne
    while (end > str && isspace((unsigned char)*end)) {
        end--; // Recule sur le caractère précédent
    }

    // Place un caractère nul juste après le dernier caractère non-espace
    // Ceci marque la fin de la chaîne "nettoyée"
    *(end + 1) = '\0';

    // Retourne le pointeur vers la chaîne nettoyée
    return str;
}