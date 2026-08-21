# 🕹️ Collection de Jeux — Multi-langages & Multi-interfaces  

Une compilation de jeux programmés dans une variété de langages (C, C++, C#, Java, Ruby, Python, Lua, OCaml…).
Ce dépôt rassemble plusieurs petits jeux classiques (et certains moins classiques), jouables en terminal ou avec interface graphique.

---

## 📦 **Contenu du dépôt**

| Jeu              | Langage         | Interface   |
| ---------------- | --------------- | ----------- |
| Bataille navale  | C               | Terminal    |
| Démineur         | Java            | Terminal    |
| Jeu de la vie (Conway’s Game of Life) | OCaml | Terminal    |
| Gomoku           | C++             | Terminal    |
| Nim              | C               | Terminal    |
| Repeat           | Lua / LÖVE      | Graphique   |
| Snake            | Python / Pygame | Graphique   |
| Sokoban          | C / ncurses     | Terminal    |
| Sudoku           | C#              | Terminal    |
| Taquin           | C#              | Terminal    |
| Morpion ×3       | Brainfuck, Asciidots, Whenever | Terminal    |
| Puissance 4      | Ruby            | Terminal + LAN |
| Blue-jam (en cours) | Unity/C#     | Graphique   |

---

## 🖼️ **Aperçu général**

### 🎮 Jeux en terminal (C, C++, C#, Java)

* Interaction clavier simple
* Affichages ASCII
* Logique algorithmique classique
* Communication entre processus (Navy)
* Tour par tour, IA, parsing d’input…

### 🎨 Jeux graphiques (Lua, Python)

* Pygame pour Snake
* LÖVE (Love2D) pour Repeat
* Animations, événements clavier, logique temps réel

---

## 📁 **Structure du dépôt**

```
/
├── blue-jam/
├── demineur/
├── fr/
│   ├── Bataille_navale/
│   ├── game_of_life/
│   ├── morpion/
│   ├── puissance4/
│   ├── repeat/
│   └── taquin/
├── gomoku/
├── nim/
├── snake/
├── sokoban/
└── sudoku/
```

Chaque dossier contient le code source et un `README.md` individuel avec les instructions de compilation et d'exécution.

---

## 🧰 **Technologies utilisées**

* **C** : ncurses, signaux Unix
* **Java** : I/O, gestion clavier
* **Python** : Pygame
* **Lua** : LÖVE framework
* **Ruby** : sockets TCP pour mode LAN

---

Compilation de jeux -- ancients projets d'études retravaillés ou projets personnels.
