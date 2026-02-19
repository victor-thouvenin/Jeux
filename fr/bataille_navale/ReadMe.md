# 🛳️ Bataille navale

**Bataille navale** est un jeu classique en C jouable à deux joueurs via le terminal.
Chaque joueur place ses bateaux sur une grille et tente de couler ceux de l’adversaire.
La communication entre les deux joueurs se fait via les **signaux UNIX** (`kill`, `SIGUSR1`, `SIGUSR2`).

---

## 🧩 Fonctionnalités

- Jeu de bataille navale en **1 contre 1** via le terminal
- Gestion des signaux entre deux processus
- Placement de **4 bateaux** :
  - 1 bateau de 2 cases
  - 1 bateau de 3 cases
  - 1 bateau de 4 cases
  - 1 bateau de 5 cases
- Affichage des cartes :
  - Carte personnelle (vos bateaux et les coups reçus)
  - Carte ennemie (les coups tentés et leurs résultats)
- Vérification automatique des tirs : touché / manqué
- Fin de partie lorsque tous les bateaux d’un joueur sont coulés

---

## ⚙️ Compilation

Assurez-vous d’avoir un système Unix et un compilateur **C18** ou supérieur.

Utiliser le `Makefile` fourni :

```bash
make
```

Cela génère un exécutable nommé :

```bash
./bataille_navale
```

---

## 🚀 Lancement du jeu

Le jeu se joue à **deux joueurs**, chacun sur un terminal séparé.

### 1️⃣ Joueur 1

Lancer la première instance du jeu **avec le fichier de positions** :

```bash
./bataille_navale positions_player1.txt
```

Le programme affichera le **PID** du joueur 1 (à communiquer au joueur 2).

### 2️⃣ Joueur 2

Lancer la deuxième instance du jeu **en précisant le PID du joueur 1** et son propre fichier de positions :

```bash
./bataille_navale <pid_joueur1> positions_player2.txt
```

---

## 🗺️ Format du fichier de positions

Chaque ligne correspond à un bateau avec le format suivant :

```
[taille]:[coordonnée_de_début]:[coordonnée_de_fin]
```

### Exemple :

```
2:C1:C2
3:D4:F4
4:B5:E5
5:H1:H5
```

* Les coordonnées sont exprimées au format `[Lettre][Chiffre]`
* Les bateaux doivent être **en ligne droite** (horizontalement ou verticalement)
* Aucun chevauchement n’est autorisé

---

## 🎮 Commandes en jeu

* À votre tour, entrez une **coordonnée de tir** (ex : `B4`)
  * ⚠️ les lettres des coordonnées (fichier de positions ou attaque) doivent être en majuscule
* Le programme indique si le tir est **touché** ou **manqué**
* Attendez ensuite le tir de l’adversaire
* Le jeu continue jusqu’à ce que l’un des deux joueurs ait coulé tous les bateaux ennemis

---

## 🗺️ Exemple de session

### 1️⃣ Joueur 1

```bash
> ./bataille_navale positions_player1.txt
PID: 51644
En attente de l'ennemi...

enemi connecté

mes bateaux :
 |A B C D E F G H
-+---------------
1|. . . . . . . 5
2|. . 2 . . . . 5
3|. . 2 . . . . 5
4|. . . 3 3 3 . 5
5|. . . . . . . 5
6|. 4 4 4 4 . . .
7|. . . . . . . .
8|. . . . . . . .

bateaux enemis :
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attaque :
```

### 2️⃣ Joueur 2

```bash
> ./bataille_navale 51644 positions_player2.txt
PID: 52654
connecté

mes bateaux :
 |A B C D E F G H
-+---------------
1|. 2 2 . . . . .
2|. . . 3 . . . .
3|. . . 3 . . . .
4|. . . 3 . . . .
5|. . 4 4 4 4 . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . 5 5 5 5 5

bateaux enemis :
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

en attente de l'attaque de l'ennemie...
```

---

## 💡 Améliorations possibles

* multijoueur en réseau (via socket)
