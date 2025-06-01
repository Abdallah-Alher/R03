# 💻 Mini Shell – Rush-9 (Compatible Windows)

Ce projet est le résultat du **dernier Rush** de la piscine Codeloccol 2025.  
Nous avons développé un **mini shell** en langage C, capable de lire, analyser, et exécuter des commandes système, 
comme un terminal simplifié, compatible avec Windows (via `system()`).

---

##  Objectifs pédagogiques

- Appliquer les compétences en **langage C** acquises pendant la piscine
- Travailler en équipe sur un projet modulaire
- Utiliser des pointeurs, des tableaux de chaînes et la mémoire dynamique
- Structurer un programme avec plusieurs fichiers `.c` / `.h`
- Exécuter des commandes système avec `system()`

---

##  Fonctionnalités du Mini Shell

- ✅ Affiche un **prompt personnalisé** : `mini-shell_rush-9> `
- ✅ Lit une ligne de commande entrée par l'utilisateur
- ✅ Supprime les espaces en début et fin de ligne (`trim_whitespace`)
- ✅ Découpe la commande en **tokens** (mots)
- ✅ Recompose la commande puis l’exécute avec `system()`
- ✅ Gère la commande spéciale `exit` pour quitter
- ✅ Nettoie correctement la mémoire utilisée

---

## Structure du projet

mini-shell/
── main.c # Point d’entrée du programme
── parser.c # Découpage de la commande en tokens
── parser.h
── executor.c # Recomposition et exécution de la commande
── executor.h
── utils.c # Suppression des espaces inutiles
── utils.h
── README.md # Documentation du projet


---

##  Répartition de l'équipe Rush-9

| Membre         | Rôle                                                    |
|----------------|----------------------------------------------------------|
| **Ismael_K**   |  `main.c` – boucle principale, intégration et coordination |
| **ABDALLAH_AM**|  `parser.c` & `parser.h` et README.md – découpage des commandes en tokens |
| **Oudou_M**    |  `executor.c` & `executor.h` – exécution via `system()` |
| **Yacine_A**   |  `utils.c` & `utils.h` – nettoyage des chaînes (espaces) |

---

##  Compilation

> 📌 Pré-requis : avoir installé [MinGW](https://www.mingw-w64.org/) ou un compilateur GCC pour Windows.

Dans un terminal (cmd, Git Bash, PowerShell...) :

```bash
gcc main.c parser.c executor.c utils.c -o minishell
./minishell.exe


## Exemple d’utilisation

mini-shell_rush-9>     echo    Hello World
Hello World

mini-shell_rush-9> dir
[Affiche les fichiers du dossier courant]

mini-shell_rush-9>     exit
Au revoir !
