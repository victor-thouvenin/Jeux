# ❌⬜⭕ Tic-Tac-Toe

This project contains **three implementations of the classic Tic-Tac-Toe game**, each written in a different **esoteric programming language**:

- **Brainfuck**
- **AsciiDots**
- **Whenever**

Despite the unusual languages, all versions follow the **classic Tic-Tac-Toe rules** and provide a playable experience on terminal.

---

## 🎮 Gameplay Rules

- Classic **3×3 Tic-Tac-Toe**
- Two players take turns.
- Players place their symbol on an empty cell (`X` for first player and `O` for second player).
- The first player to align **three symbols** Horizontally, Vertically, Diagonally wins.
- If all cells are filled with no winner, the game ends in a draw.

---

## 🧩 Features

- No command-line parameters
- Terminal-based interaction
- One executable per language

---

## ⌨️ Controls

During the game, players input a **number between 1 and 9** to choose a cell:

```
1|2|3
4|5|6
7|8|9
```

- Only valid and empty cells are accepted.
- Invalid inputs are rejected.

---

## 🚀 Execution

Each version is run according to the conventions of its language.
make you have an interpreter for each one

### Brainfuck

```bash
bf tic_tac_toe.bf
```

⚠️ Only first caracter of input is read, the rest is ignored

### AsciiDots

```bash
asciidots tic_tac_toe.dots
```

### Whenever

```bash
whenever tic_tac_toe.we
```

⚠️ Interpreter names may differ from the examples.

---
