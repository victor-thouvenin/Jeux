# 🧩 Taquin

**Taquin** est une implémentation du célèbre jeu de glissement de tuiles en **C#**, jouable dans le terminal.
Le joueur doit **réordonner les nombres** en déplaçant les cases à l’aide des **flèches du clavier**, jusqu’à reordoner la grille dans l’ordre croissant.

---

## 🧩 Fonctionnalités

- Jeu entièrement en **console**
- Taille de la grille **personnalisable** au lancement
- Déplacement à l’aide des flèches du clavier
- Mélange initial aléatoire mais **toujours résoluble**
- Affichage clair de la grille et du nombre de coups joués
- Détection automatique de **victoire** lorsque la grille est réordonée

---

## 🚀 Compilation & Exécution

### ⚙️ Prérequis

- Assurez-vous d’avoir **.NET 8.0 ou supérieur** installé

```bash
dotnet --version
```

---

### Compilation

```bash
dotnet build
```

---

### Exécution

```bash
dotnet run [taille]
```

* `taille` (optionnel) : taille de la grille (par défaut 4)
  La grille sera de taille `[taille]×[taille]`.

#### Exemples

```bash
dotnet run
```

→ Lance le jeu avec la taille par défaut (i.e. 4×4)

```bash
dotnet run 5
```

→ Lance le jeu avec une grille **5×5**

---

## 🎮 Contrôles

| Touche            | Action                                         |
| ----------------- | ---------------------------------------------- |
| Flèches (↑ ↓ ← →) | Déplace la case vide dans la direction choisie |
| `Q`               | Quitte la partie                               |

---

## 🧠 Règles du jeu

* Dans un plateau de taille **N** chaque tuile est représentée par ses coordonnées `[ligne][colonne]` de `00` à `[N-1][N-1]` en hexadécimal (i.e. les lettres `A` à `F` représentent les nombres de 10 à 15), et la **case vide** (`[N-1][N-1]`) est représentée par ` `(espace).
* Le but est de **réorganiser les tuiles dans l’ordre croissant**.

### Exemple de grille :

* Dans cet exemple la case vide est représentée par `//`.

```
###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############
```

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

* Mode chronomètre
* Interface graphique
* Animation légère des déplacements
* Sauvegarde des meilleurs temps / scores
