# 🛳️ Navy

**Navy** est un jeu de bataille navale en C jouable à deux joueurs via le terminal.
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
- Vérification automatique des tirs : touché / manqué / coulé
- Fin de partie lorsque tous les bateaux d’un joueur sont coulés

---

## ⚙️ Compilation

Assurez-vous d’avoir un compilateur **C18** ou supérieur.

Utiliser le `Makefile` fourni :

```bash
make
````

Cela génère un exécutable nommé :

```bash
./navy
```

---

## 🚀 Lancement du jeu

Le jeu se joue à **deux joueurs**, chacun sur un terminal séparé.

### 1️⃣ Joueur 1

Lancer la première instance du jeu **avec uniquement le fichier de positions** :

```bash
./navy positions_player1.txt
```

Le programme affichera le **PID** du joueur 1 (à communiquer au joueur 2).

### 2️⃣ Joueur 2

Lancer la deuxième instance du jeu **en précisant le PID du joueur 1** et son propre fichier de positions :

```bash
./navy <pid_joueur1> positions_player2.txt
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
* Le programme indique si le tir est **touché** ou **manqué**
* Attendez ensuite le tir de l’adversaire
* Le jeu continue jusqu’à ce que l’un des deux joueurs ait coulé tous les bateaux ennemis

---
