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

* Le plateau contient les nombres de **1** à `N×N - 1` en hexadécimal, et une **case vide**.
* Le but est de **réorganiser les tuiles dans l’ordre croissant**.

### Exemple pour une grille :

```
###########
# 1 2 3 4 #
# 5 6 7 8 #
# 9 A B C #
# D E F / #
###########
```

* la case vide est représentée par ` `(espace) en jeu, et `/` dans cet exemple.
* Le jeu se termine automatiquement quand la grille est en ordre croissant.

---

## 🧾 Exemple de session

```
taile : 4X4
###########
# 1 2 3 4 #
# 5 6 7 8 #
# 9 A B C #
# D E F / #
###########
###########
# 2 8 3 1 #
# 9 6 7 A #
# / F B 5 #
# 4 E C D #
###########
[le joueur appuie sur ↓]
###########
# 2 8 3 1 #
# 9 6 7 A #
# 4 F B 5 #
# / E C D #
###########
Coup : 1
[...]
###########
# 1 2 3 4 #
# 5 6 7 8 #
# 9 A B C #
# D E F / #
###########
Vous avez gagné en 86 coups.
```

---

## 💡 Améliorations possibles

* Mode **chronomètre** ou **limite de coups**
* Interface graphique
* Animation légère des déplacements
* Sauvegarde des **meilleurs temps / scores**
