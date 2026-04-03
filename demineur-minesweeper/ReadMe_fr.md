# 💣 Démineur

**Démineur** est un jeu classique développé en **Java**, basé sur le jeu de démineur classique.
Le but est de révéler toutes les cases sans déclencher de mine.

---

## 🧩 Fonctionnalités

- Déplacement du **curseur** à l’aide des flèches du clavier
- **Révélation** des cases et **pose de drapeaux** pour marquer les mines
- Possibilité de **recommencer une partie** sans relancer le programme
- Paramètres personnalisables :
  - Taille de la grille (par défaut `10x10`)
  - Nombre de mines

---

## ⚙️ Prérequis

- Assurez-vous d’avoir **Java JDK 8 ou supérieur** installé

Vérifier la version avec :

```bash
java --version
```

## ⚙️ Compilation

Compiler le projet à l’aide de `javac` :

```bash
javac Demineur.java
```

Cela génère les fichiers `.class` nécessaires à l’exécution du programme.

---

## 🚀 Exécution

Lancer le programme avec :

```bash
java Demineur [taille] [nombre_de_mines] [langue]
```

### Paramètres :

* `taille` *(optionnel)* : taille de la grille (par défaut `10`)
* `nombre_de_mines` *(optionnel)* : nombre total de mines (le nombre par défaut dépend de la taille)
* `langue` *(optionnel)* : langue du jeu (par défaut `fr`)

Vous pouvez taper `-` pour utiliser les valeur par défaut

### Exemples :

```bash
# Grille 10x10 avec nombre de mines par défaut en français
java Demineur

# Grille 15x15 avec 30 mines en français
java Demineur 15 30

# Grille 10X10 avec 15 mines en français
java Demineur - 15

# Grille 10x10 avec nombre de mines par défaut en français
java Demineur - - fr

# Grille 15x15 avec 30 mines en anglais
java Demineur 15 30 en
```

---

## 🚀 Exécution par script

Un script, `launch.sh` avec les même paramètres que l'exécutable, est disponible pour la compilation (si nécessaire) et l'exécution

```bash
./launch.sh [paramètres]
```

---

## 🎮 Commandes en jeu

| Touche     | Action                          |
| ---------- | ------------------------------- |
| 🡅🡇🡄🡆    | Déplacer le curseur             |
| **Entrée** | Révéler la case sélectionnée    |
| **F**      | Poser ou retirer un drapeau     |
| **R**      | Recommencer une nouvelle partie |
| **Q**      | Quitter le jeu                  |
| **G**      | Révéler toute la grille (quand tous les drapeau sont placés) |

---

## 🕹️ Règles du jeu

* Si vous révélez une mine 💥 → **c'est perdu**
* Si vous révélez toutes les cases sûres et marquez toute les mines → **Victoire 🎉**
* Utilisez un drapeau 🚩 pour marquer une case suspecte
* Les chiffres indiquent combien de mines se trouvent **dans les 8 cases voisines**.

---
