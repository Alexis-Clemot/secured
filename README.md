# Secured - Elementary Programming in C

## Description
"Secured" est un projet du module **Elementary Programming in C** d'Epitech. Ce projet a pour objectif de vous familiariser avec les **tables de hachage** en développant votre propre bibliothèque en C, qui inclut des fonctions de hachage et de gestion de données sécurisées. Le contexte de ce projet est d'assurer la protection des plans de robots dans une arène compétitive.

---

## Objectifs du Projet
1. Développer une **fonction de hachage** personnalisée.
2. Créer une **table de hachage** pour stocker et gérer des données.
3. Manipuler des concepts avancés en C, tels que :
   - **Tableaux multidimensionnels**
   - **Listes chaînées**
   - **Gestion de fichiers**
   - **Pointeurs sur fonctions**
   - **Algorithmes de tri et dynamiques**

---

## Fonctionnalités Clés
- **Fonction de Hachage :**  
  Une fonction respectant les 4 critères suivants :
  1. Déterminisme basé sur les données hachées.
  2. Utilisation de toutes les données d'entrée.
  3. Différenciation nette entre des entrées similaires.
  4. Répartition uniforme des données dans la table de hachage.

- **Gestion de la Table de Hachage :**  
  - Création et suppression de la table.
  - Insertion, suppression, et recherche de données.
  - Gestion des collisions via un chaînage séparé.

---

## Fonctions Principales
1. `int hash(char *key, int len)` : Fonction de hachage.
2. `hashtable_t *new_hashtable(int (*hash)(char *, int), int len)` : Crée une nouvelle table de hachage.
3. `void delete_hashtable(hashtable_t *ht)` : Supprime une table de hachage.
4. `int ht_insert(hashtable_t *ht, char *key, char *value)` : Insère une paire clé-valeur.
5. `int ht_delete(hashtable_t *ht, char *key)` : Supprime une clé de la table.
6. `char *ht_search(hashtable_t *ht, char *key)` : Recherche une valeur par clé.
7. `void ht_dump(hashtable_t *ht)` : Affiche le contenu de la table de hachage.

---

## Compilation et Exécution
### Prérequis
- **Langage :** C
- **Compilation :** Makefile, avec les règles suivantes :
  - `make` : Compile le projet.
  - `make clean` : Supprime les fichiers objets.
  - `make fclean` : Supprime les binaires et fichiers objets.
  - `make re` : Reconstruit le projet.

### Instructions
1. Cloner ce dépôt :
   ```bash
   git clone <URL_DU_DEPOT>
   cd <NOM_DU_DEPOT>
2. Compiler le dépôt :
  - `make`
3. Lancer le projet :
   ```bash
   gcc -o my_program main.c -L. -lhashtable
   ./my_program