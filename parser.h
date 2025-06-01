#ifndef PARSER_H
#define PARSER_H

//----------------------------------------------------------------------------------
// Ce fichier d'en-tête déclare les fonctions utilisées pour le parsing
// c'est-à-dire pour découper la commande utilisateur en tokens.
// L'inclusion de ce fichier dans d'autres fichiers source permet d'accéder
// aux fonctions de découpage et à la gestion de la mémoire associée.
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Fonction : parse_command
// But      : Découpe la commande saisie par l'utilisateur en tokens (c'est-à-dire
//            en sous-chaînes) et renvoie un tableau de chaînes de caractères.
// Paramètre : input - Chaîne de caractères contenant la commande saisie.
// Retour    : Un tableau de pointeurs sur char, terminé par NULL, représentant
//             les différents tokens. Ce tableau est alloué dynamiquement, il
//             faudra donc libérer la mémoire une fois utilisé.
//----------------------------------------------------------------------------------
char **parse_command(char *input);


//----------------------------------------------------------------------------------
// Fonction : free_tokens
// But      : Libère la mémoire allouée pour le tableau de tokens généré par 
//            la fonction parse_command.
// Paramètre : tokens - Tableau de chaînes de caractères à libérer.
//----------------------------------------------------------------------------------
void free_tokens(char **tokens);

#endif /* PARSER_H */