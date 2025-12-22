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

## ⚙️ Compilation

Compiler le projet à l’aide de `javac` :

```bash
javac Demineur.java
````

Cela génère les fichiers `.class` nécessaires à l’exécution du programme.

---

## 🚀 Exécution

Lancer le programme avec :

```bash
java Demineur [taille] [nombre_de_mines]
```

### Paramètres :

* `taille` *(optionnel)* : taille de la grille (par défaut **10**)
* `nombre_de_mines` *(optionnel)* : nombre total de mines (par défaut adapté à la taille)

### Exemples :

```bash
# Grille 10x10 avec nombre de mines par défaut
java Demineur

# Grille 15x15 avec 30 mines
java Demineur 15 30
```

---

## 🎮 Commandes en jeu

| Touche     | Action                          |
| ---------- | ------------------------------- |
| 🡅🡇🡄🡆   | Déplacer le curseur             |
| **Entrée** | Révéler la case sélectionnée    |
| **F**      | Poser ou retirer un drapeau     |
| **R**      | Recommencer une nouvelle partie |
| **Q**      | Quitter le jeu                  |

---

## 🕹️ Règles du jeu

* Le but est de **révéler toutes les cases non minées**.
* Si vous révélez une mine 💥 → **Game Over**
* Si vous révélez toutes les cases sûres → **Victoire 🎉**
* Les chiffres indiquent combien de mines se trouvent **dans les 8 cases voisines**.
* Utilisez un drapeau 🚩 pour marquer une case suspecte

---
