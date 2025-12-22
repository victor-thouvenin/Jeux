# 🕹️ Collection de Jeux — Multi-langages & Multi-interfaces  

Une compilation de jeux programmés dans une variété de langages (C, C++, C#, Java, Ruby, Python, Lua, OCaml…).
Ce dépôt rassemble plusieurs petits jeux classiques (et certains moins classiques), jouables en terminal ou avec interface graphique.

---

## 📦 **Contenu du dépôt**

| Jeu                     | Langage         | Interface      |
| ----------------------- | --------------- | -------------- |
| Navy (Bataille navale)  | C               | Terminal       |
| Démineur                | Java            | Terminal       |
| Conway’s Game of Life   | OCaml           | Terminal       |
| Gomoku                  | C++             | Terminal       |
| Nim                     | C               | Terminal       |
| Repeat                  | Lua / LÖVE      | Graphique      |
| Snake                   | Python / Pygame | Graphique      |
| Sokoban                 | C / ncurses     | Terminal       |
| Sudoku                  | C#              | Terminal       |
| Taquin                  | C#              | Terminal       |
| Morpion ×3              | Brainfuck, Asciidots, Whenever | Terminal       |
| Puissance 4             | Ruby            | Terminal + LAN |

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
├── demineur/
├── game_of_life/
├── gomoku/
├── morpion/
├── navy/
├── nim/
├── puissance4/
├── repeat/
├── snake/
├── sokoban/
├── sudoku/
└── taquin/
```

Chaque dossier contient le code source et un `README.md` individuel.

---

## 🧰 **Technologies utilisées**

* **C / C++** : ncurses, signaux Unix
* **Java** : I/O, gestion clavier
* **Python** : Pygame
* **Lua** : LÖVE framework
* **OCaml**
* **C#**
* **Ruby** : sockets TCP pour mode LAN
* **Brainfuck / Asciidots / Whenever**

---

## 🛠️ Compilation & Exécution (exemple)

### C / C++

```bash
make
./jeu
```

### Java

```bash
javac jeu.java
java jeu
```

### Python

```bash
python3 snake.py
```

### Lua (LÖVE)

```bash
love repeat/
```

### Ruby

```bash
ruby puissance4.rb
```

---

Compilation de jeux -- ancients projets d'études retravaillés comme projets personnels.