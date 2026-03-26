# 🟡 Snake - Pac Edition

**Snake - Pac Edition** est une réinterprétation du classique **Snake**, développée en **Python** avec **Pygame**, sur le thème de **Pac-Man**.
Le joueur contrôle un serpent dont la tête est **Pac-Man**, le corps est composé des **fantômes**, et les **Pac-Gums** remplacent les pommes.

---

## 🧩 Fonctionnalités

- Interface graphique réalisée avec **Pygame**
- Commandes simples et réactives via les **flèches du clavier**
- Apparence personnalisée :
  - 🟡 **Pac-Man** pour la tête
  - 👻 **Fantômes** pour le corps
  - ⚪ **Pac-Gums** pour les pommes
- Gestion fluide des collisions et de la croissance du serpent
- Score affiché en temps réel
- Possibilité de quitter à tout moment avec `Q` ou `échap`
- Sons et animations inspirés de l’univers **Pac-Man**

---

## ⚙️ Prérequis

### Installer les dépendances

Assurez-vous d’avoir **Python 3** installé, puis installez **Pygame** :

```bash
pip install pygame
```

---

## 🚀 Exécution

Lancez simplement le jeu avec :

```bash
python snake.py
```

Une fenêtre s’ouvre automatiquement avec le terrain de jeu.

Vous pouvez choisir la langue avec un paramètre optionnel :

```bash
python snake.py [langue]
```

Exemple :

```bash
python snake.py fr
```

Le jeu se lance en français par défaut

---

## 🎮 Contrôles

| Touche      | Action              |
| ----------- | ------------------- |
| 🡐 🡒 🡑 🡓     | Déplacer le serpent |
| **Q** ou **Échap** | Quitter la partie   |

---

## 🧠 Règles du jeu

* Déplacez **Pac-Man** à travers l’écran pour **manger les Pac-Gums** ⚪.
* À chaque Pac-Gum avalée :
  * Le serpent grandit 👻
  * Le score augmente 💯
* Si Pac-Man touche un mur ou les fantômes, la partie est terminée 💥.
* Le but est de **survivre le plus longtemps possible** en obtenant le meilleur score.

---

## 🧾 Exemple de partie (visuel simplifié)

```
Score : 3

👻👻👻🟡⚪
```

```
Score : 4

👻👻👻👻🟡
```

Pac-Man avance, mange la Pac-Gum, et un nouveau fantôme apparaît à l’arrière de la file.

---

## 🎨 Thème graphique

Les sprites utilisés sont des ressources libres inspirées de **Pac-Man**

---

## 💡 Améliorations possibles

* menu principal et vitesse progressive
