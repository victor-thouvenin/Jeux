# 🧬 Game of Life

"**Conway's Game of Life**" est une simulation de l'automate cellulaire de **John Conway**, implémentée en **OCaml**.
Le programme lit une grille initiale depuis un fichier et affiche l’évolution étape par étape dans le terminal.

---

## 🧩 Fonctionnalités

- Simulation du **jeu de la vie** classique
- Grille personnalisable via un fichier d’entrée
- Représentation des cellules :
  - "`@`" : cellule vivante
  - "` `" (espace) : cellule morte
- Avancement **étape par étape** en appuyant sur **Entrée**
- Affichage en console avec mise à jour dynamique

---

## 🚀 Exécution

Assurez-vous d’avoir **OCaml** installé (version 4.x ou supérieure).

Lancez le programme avec la commande :

```bash
ocaml game_of_life.ml <fichier_grille>
```

### Exemple :

```bash
ocaml game_of_life.ml grille.txt
```

* `grille.txt` doit contenir la configuration initiale de la grille
* Chaque ligne représente une rangée de la grille
* les espaces représentent les cellules mortes, les autres caractères les cellules vivantes
Si aucun fichier ou un fichier invalide est fourni, le programme affiche une erreur et se termine.

---

## 🗺️ Exemple de grille

```
.@..@
...@.
@@@..
.....
```

* L’exemple ci-dessus représente une grille 5x4 avec quelques cellules vivantes (ici les espaces sont remplacés par des poins)

---

## 🎮 Commandes en jeu

| Touche     | Action                          |
| ---------- | ------------------------------- |
| **Entrée** | passer à l’étape suivante       |
| **Q puis Entrée** ou **CTRL + D** | quitter la simulation |

---
