# 📦 Sokoban

**Sokoban** est une implémentation en **C** avec la bibliothèque **ncurses** du célèbre jeu de réflexion japonais.
Le **joueur** doit pousser des **boîtes** sur les **emplacements de stockage** à l’intérieur d’un entrepôt.
Chaque déplacement doit être réfléchi, car il est impossible de tirer les boîtes !

---

## ⚠️ Avertissement épilepsie

Ce jeu utilise un affichage en console rafraîchi après chaque action.
Lorsqu’on déplace rapidement le joueur ou les boîtes, l’écran peut **clignoter à haute fréquence** selon la configuration du terminal ou du système.
👉 **Il est déconseillé de jouer (ou conseillé de jouer lentement) si vous êtes sensible aux lumières ou aux effets visuels rapides (photosensibilité / épilepsie).**
Pour réduire les effets :
- Évitez de maintenir les touches de déplacement appuyées ou d'appuyer trop rapidement dessus

---

## 🧩 Fonctionnalités

- Jeu de Sokoban en **console** (ncurses)
- Lecture de la **carte de l'entrepôt** depuis un **fichier passé en paramètre**
- Cartes écrites avec des caractères ASCII :
  - `#` : mur
  - `P` : joueur
  - `X` : boîte
  - `O` : emplacement de stockage
  - ` ` (espace) : case vide
- Vérification automatique de la victoire
- Commandes clavier pour déplacer le joueur
- Gestion simple des erreurs de fichier (format invalide / fichier introuvable)
- Vous pouvez quitter à tout moment avec `Q` ou la touche `Fin` ou recommencer avec ` ` (Espace).

---

## ⚙️ Prérequis / Compilation

### Dépendances
- **ncurses** (bibliothèque de gestion de l’interface texte)

Sur Debian/Ubuntu :
```bash
sudo apt-get install libncurses6 libncurses-dev libncursesw6
```

### Compilation

Le projet est fourni avec un **Makefile**. Pour compiler :

```bash
make
```

Cela génère l’exécutable :

```bash
./sokoban
```

---

## 🚀 Exécution

Lancez le jeu avec un **fichier de carte** en paramètre :

```bash
./sokoban <map.txt>
```

### Exemple :

```bash
./sokoban levels/level1.txt
```

---

## 🗺️ Format du fichier de carte

La carte est un fichier texte où chaque caractère représente une case. Les lignes peuvent avoir des longueurs identiques ou variables ; les espaces sont significatifs.

### Symboles autorisés :

* `#` — mur
* `P` — position du joueur (exactement un par carte)
* `X` — boîte
* `O` — emplacement de stockage
* ` ` (espace) — case vide

### Exemple de carte :

```
#######
#  O  #
#  X  #
# P   #
#######
```

---

## 🎮 Contrôles

| Touche              | Action                                               |
| ------------------- | ---------------------------------------------------- |
| Flèches (↑ ↓ ← →)   | Déplacer le joueur / pousser une boîte (si possible) |
| ` ` (Espace)        | Recommencer le niveau                                |
| Touche `Fin` ou `Q` | Quitter le jeu                                       |

---

## 🧠 Règles du jeu

1. Vous incarnez le joueur `P` et devez pousser les boîtes `X` vers les emplacements `O`.
2. Vous **ne pouvez pas tirer** les boîtes, seulement les pousser, une boîte ne peut être poussée que si la case de destination est libre (case vide ou emplacement de stockage).
3. lorsque les boîtes occupent **tout les emplacement de stockage**, la partie est **gagnée**.
4. Si vous êtes bloqué, la partie est **perdu**.

---

## 🧾 Exemple de partie

```
#######
#  O  #
#  X  #
# P   #
#######
```

➡️ Le joueur appuie sur la flèche de droite.

```
#######
#  O  #
#  X  #
#  P  #
#######
```

➡️ Le joueur appuie sur la flèche du haut pour pousser `X` sur `O`.

```
#######
#  X  #
#  P  #
#     #
#######
```

🎉 Niveau réussi !

---

## 💡 Améliorations possibles

* Support de **plusieurs niveaux** en chaîne
* Sauvegarde / chargement de la progression
* Animation du joueur et des boîtes
* annuler le dernier coup / historique des mouvements

---
