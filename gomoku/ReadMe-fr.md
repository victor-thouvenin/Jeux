# ⚫ Gomoku

**Gomoku** est un jeu de stratégie en **C++** jouable dans le terminal.
Un joueur affronte une **intelligence artificielle (IA)**, ou deux joueurs s'affrontent, sur un plateau carré dont la taille est donnée en paramètre.
Le but est d’être le premier à aligner **cinq pions consécutifs** horizontalement, verticalement ou en diagonale.

---

## 🧩 Fonctionnalités

- Jeu **1 joueur contre IA**
- Taille du plateau configurable (passée en paramètre)
- Interface entièrement en **console**
- Trois commandes principales pour interagir avec le jeu :
  - `commence` : laisse l’IA commencer la partie
  - `où [x y]` : montre l'emplacement de la case aux coordonnées données
  - `stop` (ou `Ctrl+D`) : termine la partie
- Choix de la langue (à l'exécution ou pendant la partie)

---

## ⚙️ Compilation

Assurez-vous d’avoir un compilateur **g++ 20** ou supérieur.

Pour compiler le programme, exécutez simplement :

```bash
make
```

Cela génère un exécutable nommé :

```bash
./gomoku
```

---

## 🚀 Exécution

Lancez le programme avec la commande :

```bash
./gomoku [taille]
```

### Exemples :

```bash
./gomoku 15
```

→ Lance une partie sur une grille **15×15**

```bash
./gomoku 20
```

→ Lance une partie sur une grille **20×20**

```bash
./gomoku 15 -multi
```

→ Lance une partie à deux joueurs sur une grille 15×15

```bash
./gomoku 15 -lang=fr
```

→ Lance une partie sur une grille **15×15** en français *(le français est la langue par défaut du jeu)*

---

## 🎮 Commandes en jeu

| Commande              | Arguments                                 | Description                                                   |
| --------------------- | ----------------------------------------- | ------------------------------------------------------------- |
| `commence`            | *(aucun)*                                 | Laisse l’IA commencer la partie *(mode solo uniquement)*      |
| `[x y]`               | coordonnées de la case (ex : `7 8`)       | joue à l'emplacement demandé                                  |
| `où [x y]`            | coordonnées de la case (ex : `où 7 8`)    | Indique l'emplacement de la case demandée sur la grille *(n'est pas compté comme une action)* |
| `stop` ou `Ctrl+D`    | *(aucun)*                                 | Termine la partie proprement                                  |
| `[langue]`            | langue (ex : `fr`)                        | change la langue du jeu *(n'est pas compté comme une action)* |
| `langue`              | *(aucun)*                                 | liste les langues disponibles *(n'est pas compté comme une action)* |

Les autres actions (gestion des tours, affichage du plateau, détection de victoire) sont automatiques.

---

## 🗺️ Exemple de session

```
$ ./gomoku 15
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
tour du joueur > fr
le jeu est déjà en français
tour du joueur > commence
l'IA a joué 8,8
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
tour du joueur > 8 9
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o . . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
tour de l'IA > 9 8
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o o . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+

[...]

tour de l'IA > 10 9
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
tour du joueur > où 8 7
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . X . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
tour du joueur > 8 7
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+

[...]

```

---

## 🧠 Règles du jeu

* Le premier à aligner **5 pions consécutifs** (horizontalement, verticalement ou en diagonale) gagne la partie.
* Le joueur et l’IA jouent chacun leur tour.
* Si la grille est remplie sans vainqueur, la partie est déclarée **nulle**.
* La commande `stop` (ou `Ctrl+D`) permet d’interrompre la partie à tout moment.

---

## 💡 Améliorations possibles

* IA plus avancée (Minimax, élagage alpha-bêta, heuristiques)

---

Projet **Gomoku** — Réaliser en groupe

---
