# ⚫⚪ Gomoku

**Gomoku** is a terminal-based implementation of the classic "five in a row" board game, written in **C++**.  
The game can be played **against an AI** or in **multiplayer mode**, and supports different board sizes.

The objective is to be the first player to align **five stones in a row** horizontally, vertically, or diagonally.

---

## 🧩 Features

- Terminal-based Gomoku game
- Written in **C++**
- Play **against an AI** or in **multiplayer mode**
- Customizable board size
- Simple command-based interface
- Makefile provided for easy compilation
- Real-time board analysis commands

---

## ⚙️ Requirements

- **C++ compiler** supporting C++17 or newer
- `make`

```bash
g++ --version
```

---

## 🛠️ Compilation

Compile the project using the provided Makefile:

```bash
make
```

This will generate the executable:

```bash
./gomoku
```

---

## 🚀 Execution

### Standard mode (vs AI)

```bash
./gomoku [board_size]
```

Example:

```bash
./gomoku 15
```

→ Start a game on a **15×15** grid

---

### Multiplayer mode

Use the `-multi` option as the **second parameter**:

```bash
./gomoku [board_size] -multi
```

Example:

```bash
./gomoku 15 -multi
```

→ Start a two-player game on a 15×15 grid

---

## 🎮 Commands

During the game, players interact with the program using text commands:

| Command           | Arguments                                   | Description                                             |
| ----------------- | ------------------------------------------- | ------------------------------------------------------- |
| `begin`           | *(none)*                                    | Let the AI start the game *(single player only)*        |
| `[x y]`           | coordinates of the cell (e.g., `7 8`)       | Play at coordinates `(x, y)`                            |
| `where [x y]`     | coordinates of the cell (e.g., `where 7 8`) | highlight the cell at coordinates `(x, y)` *(not considered an action)* |
| `end` or `Ctrl+D` | *(none)*                                    | Exit the game properly                                  |

---

## 🧾 Example Session

```
$ ./gomoku 15
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
your turn > begin
AI plays 8,8
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
your turn > 8 9
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o . . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
AI's turn > 9 8
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . o o . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+

[...]

AI's turn > 10 9
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
your turn > where 8 7
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . X . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+
your turn > 8 7
+-------------------------------+
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . * . . . . . . . |
| . . . . . . * o o o * . . . . |
| . . . . . . . * * o . . . . . |
| . . . . . . . . o . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
| . . . . . . . . . . . . . . . |
+-------------------------------+

[...]

```

---

## 🧠 Gameplay Rules

* Players take turns placing a stone on the board.
* Stones are placed on empty cells only.
* The first player to align **five stones** wins.
* If the grid is filled with no winner, it's a tie
* The `end` command (or `Ctrl+D`) allows you to interrupt the game at any time.

---

## 💡 Possible Improvements

* Stronger AI (minimax, alpha-beta pruning)

---

Project **Gomoku** — made in Groupe

---
