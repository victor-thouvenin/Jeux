# 🧩 Taquin

**Taquin** est une implémentation du célèbre jeu de glissement de tuiles en **C#**, jouable dans le terminal.
Le joueur doit **réordonner les nombres** en déplaçant les cases à l’aide des **flèches du clavier**, jusqu’à reformer la grille dans l’ordre croissant.

---

## 🧩 Fonctionnalités

- Jeu entièrement en **console**
- Taille de la grille **personnalisable** au lancement (`N x N`)
- **Déplacement fluide** à l’aide des flèches du clavier
- Mélange initial aléatoire mais toujours résolvable
- Affichage clair de la grille et du nombre de coups joués
- Détection automatique de **victoire** lorsque la grille est remise en ordre
- Aucune dépendance externe nécessaire

---

## 🚀 Compilation & Exécution

### ⚙️ Prérequis

- Assurez-vous d’avoir **.NET 8.0 ou supérieur** installé

### Compilation

```bash
dotnet build
```

### Exécution

```bash
dotnet run [taille]
```

> Le paramètre `[taille]` est optionnel (par défaut 4).

---

## 🎮 Contrôles

| Touche            | Action                                         |
| ----------------- | ---------------------------------------------- |
| Flèches (↑ ↓ ← →) | Déplace la case vide dans la direction choisie |
| `Q`               | Quitte la partie                               |

> Les déplacements ne sont autorisés que pour les tuiles adjacentes à la case vide adjacente.

---

## 🧠 Règles du jeu

* Le plateau contient les nombres de **0** à `N-1` en hexadécimal (i.e. les lettres `A` à `F` représentent les nombres de 10 à 15) dans chaque ligne, et une **case vide** représente la case `[N-1][N-1]`.
* Le but est de **réorganiser les tuiles dans l’ordre croissant**.

### Exemple pour une grille :

```
###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############
```

* la case vide est représentée par ` `(espace) en jeu, et `//` dans cet exemple.
* Le jeu se termine automatiquement quand la grille est en ordre croissant.

---

## 🧾 Exemple de session

```
taille : 4X4

###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############

###############
# 00 11 // 02 #
# 12 03 10 13 #
# 23 21 22 01 #
# 20 30 31 32 #
###############

[le joueur appuie sur ↓]
###############
# 00 11 10 02 #
# 12 03 // 13 #
# 23 21 22 01 #
# 20 30 31 32 #
###############
Coup : 1
[...]
###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############
victoire en 94 coups
```

---

## 💡 Améliorations possibles

* Mode **chronomètre** ou **limite de coups**
* Interface graphique
* Animation légère des déplacements
* Sauvegarde des **meilleurs temps / scores**
