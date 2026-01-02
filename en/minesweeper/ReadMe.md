# 💣 Minesweeper

**Minesweeper** is a terminal-based implementation of the classic logic game, written in **Java**.  
The goal is to reveal all safe cells without triggering any mines.

---

## 🧩 Features

- Text-based interface (terminal)
- Default grid size: **10×10**
- Two optional parameters:
  - Grid size
  - Number of mines
- Keyboard-controlled cursor movement
- Flagging system
- Restart and quit commands
- Automatic win and loss detection

---

## ⚙️ Requirements

- **Java JDK 8** or newer

Check your Java version:

```bash
java --version
```

---

## 🚀 Compilation & Execution

### Compile

```bash
javac Minesweeper.java
```

### Run

```bash
java Minesweeper [size] [number_of_mines]
```

### Parameters:

* `size` *(optional)* : grid size (**10** by default)
* `number_of_mines` *(optional)* : total number of mines (default depends on the size)

### Examples:

```bash
# Grid 10x10 with default number of mines
java Minesweeper

# Grid 15x15 with 30 mines
java Minesweeper 15 30
```

If invalid parameters are provided, the game will fall back to default values.

---

## 🎮 Controls

| Key        | Action                   |
| ---------- | ------------------------ |
| Arrow keys | Move the cursor          |
| `Enter`    | Reveal the selected cell |
| `F`        | Place / remove a flag    |
| `R`        | Restart the game         |
| `Q`        | Quit the game            |

---

## 🧠 Game Rules

* Revealing a mine ends the game immediately.
* The player wins when all non-mined cells are revealed and all mined cells are marked.
* Revealing a safe cell shows the number of adjacent mines.
* Flags are used to mark suspected mine locations.

---
