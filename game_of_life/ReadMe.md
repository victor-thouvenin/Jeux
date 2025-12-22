# 🧬 Game of Life

**Conway's Game of Life** est une simulation de l'automate cellulaire de **John Conway**, implémentée en **OCaml**.
Le programme lit une grille initiale depuis un fichier et affiche l’évolution étape par étape dans le terminal.

---

## 🧩 Fonctionnalités

- Simulation du **jeu de la vie** classique
- Grille personnalisable via un fichier d’entrée
- Représentation des cellules :
  - `@` : cellule vivante
  - ` ` (espace) : cellule morte
- Avancement **étape par étape** en appuyant sur **Entrée**
- Affichage en console avec mise à jour dynamique

---

## ⚙️ Compilation

Assurez-vous d’avoir **OCaml** installé (version 4.x ou supérieure).

Pour compiler le programme :

```bash
ocamlc -o game_of_life game_of_life.ml
````

Cela génère un exécutable nommé `game_of_life`.

---

## 🚀 Exécution

Lancez le programme avec la commande :

```bash
./game_of_life <fichier_grille>
```

### Exemple :

```bash
./game_of_life grille.txt
```

* `grille.txt` doit contenir la configuration initiale de la grille
* Chaque ligne représente une rangée de la grille
* `@` pour une cellule vivante, espace pour une cellule morte

---

## 🎮 Commandes en jeu

| Touche     | Action                          |
| ---------- | ------------------------------- |
| **Entrée** | passer à l’étape suivante       |
| **Q**      | quitter la simulation           |

---

## 🗺️ Exemple de grille

```
 @  @
   @ 
@@@  
     
```

* L’exemple ci-dessus représente une grille 5x4 avec quelques cellules vivantes

---
