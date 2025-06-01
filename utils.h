#ifndef UTILS_H       // Inclusion guard : empêche l'inclusion multiple du même header
#define UTILS_H

//----------------------------------------------------------------------------------
// Fonction : trim_whitespace
// But      : Supprime les espaces en début et fin d'une chaîne de caractères.
//            Cette fonction permet d'éliminer les espaces inutiles au début et à la 
//            fin d'une chaîne, afin d'obtenir une version "nettoyée" de l'entrée.
// Paramètre: str - La chaîne de caractères à nettoyer.
// Retour   : Un pointeur vers la chaîne de caractères modifiée, où les espaces superflus
//            ont été retirés.
// Remarque : Il est possible que la chaîne retournée soit la même que celle d'entrée, 
//            modifiée in situ. Ce comportement doit être pris en compte lors de l'utilisation.
//----------------------------------------------------------------------------------
char *trim_whitespace(char *str);

#endif /* UTILS_H */