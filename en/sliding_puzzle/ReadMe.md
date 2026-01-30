# 🧩 Sliding Puzzle (Taquin)

**Sliding Puzzle** is a classic puzzle game implemented in **C#**.  
The goal is to reorder the tiles into their correct positions by sliding them into the empty space.

The game is played entirely with the keyboard and supports different grid sizes.

---

## 🧩 Features

- Classic sliding puzzle gameplay
- Terminal-based game
- Customizable grid size
- Keyboard-controlled movements
- The puzzle is generated in a **solvable configuration**

---

## ⚙️ Requirements

- **.NET SDK** (version 8.0 or newer recommended)

Check your installation:

```bash
dotnet --version
```

---

## Compilation

```bash
dotnet build
```

---

## 🚀 Execution

```bash
dotnet run [size]
```

* `size` (optional): size of the grid (default: 4×4)
  The board will be `[size]×[size]`.

### Examples

```bash
dotnet run
```

→ Starts a default puzzle (e.g. 4×4)

```bash
dotnet run 5
```

→ Starts a **5×5** sliding puzzle

---

## 🎮 Controls

| Key        | Action                         |
| ---------- | ------------------------------ |
| Arrow keys | Move the empty tile            |
| `Q`        | Quit the game                  |

Only valid moves are allowed. Tiles slide into the empty space when possible.

---

## 🎯 Objective

* In a board of size **N** each tile is represented by its coordinates `[row][column]` from `00` to `[N-1][N-1]` in hexadecimal (e.g. the letters `A` to `F` represent the numbers from 10 to 15), and the **empty spot** (`[N-1][N-1]`) is represented by ` `(space).
* The goal is to **rearrange the tiles so that they are ordered correctly**

### Grid example :

* In this example the empty box is represented by `//`.

```
###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############
```

---

## 🧾 Example Session

```
size: 4X4

###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############

###############
# 00 11 // 02 #
# 12 03 10 13 #
# 23 21 22 01 #
# 20 30 31 32 #
###############

[the player press ↓]
###############
# 00 11 10 02 #
# 12 03 // 13 #
# 23 21 22 01 #
# 20 30 31 32 #
###############
move: 1
[...]
###############
# 00 01 02 03 #
# 10 11 12 13 #
# 20 21 22 23 #
# 30 31 32 // #
###############
you win in 94 moves
```

---

## 💡 Possible Improvements

* Timer mode
* Graphical interface
* animation
* Save best times/scores

---
