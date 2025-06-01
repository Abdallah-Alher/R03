#ifndef EXECUTOR_H        // Inclusion guard : empêche l'inclusion multiple du même header
#define EXECUTOR_H

//----------------------------------------------------------------------------------
// Fichier : executor.h
// But     : Déclaration de l'interface du module d'exécution.
//           Ce module est chargé d'exécuter la commande représentée par un
//           tableau de tokens. La fonction déclarée ici permettra de lancer
//           la commande en utilisant la méthode d'exécution adaptée à l'environnement.
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Fonction : execute_command
// But      : Exécuter une commande système en se basant sur un tableau de tokens.
//            Elle prend en compte le fait que la commande et ses arguments sont déjà
//            séparés et s'occupe de reconstituer la commande complète pour son exécution.
// Paramètre :
//            tokens - Un tableau de chaînes de caractères (terminé par NULL)
//                     qui représente la commande et ses paramètres.
// Note     : Dans une version Unix, cette fonction pourrait créer un processus
//            enfant via fork() suivi de exec(), mais ici, elle s'adapte aux spécificités
//            de l'environnement (par exemple, en utilisant system() sur Windows).
//----------------------------------------------------------------------------------
void execute_command(char **tokens);

#endif /* EXECUTOR_H */