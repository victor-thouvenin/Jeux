# 🔢 Sudoku

**Sudoku** est une implémentation du célèbre jeu de logique en **C#**, jouable directement dans le **terminal**.
Le jeu génère une grille **9×9** selon les règles classiques du Sudoku.
Le joueur remplit les cases en entrant leurs coordonnées suivies du chiffre à placer.

---

## 🧩 Fonctionnalités

- Grille 9x9 respectant les règles standard du Sudoku
- Entrée simple : `[ligne] [colonne] [nombre]`
- Possibilité de **retirer** un nombre avec `0` ou `X`
- Vérification automatique des entrés
- Commande `Q` pour quitter à tout moment
- Interface texte claire et réactive

---

## ⚙️ Compilation

- Assurez-vous d’avoir **.NET 8.0 ou supérieur** installé

```bash
dotnet --version
```

Pour compiler, exécutez la commande : 

```bash
dotnet build
```

---

## 🚀 Exécution

```bash
dotnet run
```

---

## 🧠 Règles du jeu

* Le but est de **remplir la grille 9×9** avec des chiffres de **1 à 9** :
* Chaque ligne, colonne ou bloc **3×3** doit contenir **tous les chiffres de 1 à 9** sans doublon.

---

## 🎮 Commandes

| Entrée                       | Action                                       |
| ---------------------------- | -------------------------------------------- |
| `[ligne] [colonne] [nombre]` | Place le nombre à la position donnée (1 à 9) (ex : `1 1 5` = place un 5 en haut à gauche) |
| `[ligne] [colonne] [0 ou X]` | Supprime le nombre de la case                |
| `Q`                          | Affiche la solution et quitte la partie      |

---

## 🧾 Exemple de session

```
 ------- ------- -------
| _ _ _ | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 2
 ------- ------- -------
| _ _ 2 | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 5
 ------- ------- -------
| _ _ 5 | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 X
 ------- ------- -------
| _ _ _ | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
[...]
```

---

## 🧩 Validation automatique

* Si un nombre prédéfini est déjà dans la case choisie, une erreur est affichée.
* Sinon, la grille est mise à jour.
* Le jeu détecte automatiquement la **victoire** quand la grille est complète et correcte.

---

## 💡 Améliorations possibles

* Niveaux de difficulté paramétrable
* Chronomètre et enregistrement du **temps de résolution**
* Mode **aide / indices**
* Sauvegarde et chargement de partie
* Interface graphique
