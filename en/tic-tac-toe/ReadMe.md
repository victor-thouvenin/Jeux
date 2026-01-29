# ❌⭕ Tic-Tac-Toe

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
- Only first caracter of input is read, the rest is ignored
- Invalid inputs are rejected.

---

## 🚀 Execution

Each version is run according to the conventions of its language.

### Brainfuck

make you have brainfuck interpreter on your system

```bash
bf tic_tac_toe.bf
```

### AsciiDots

make you have asciidots interpreter on your system

```bash
asciidots tic_tac_toe.ad
```

### Whenever

make you have whenever interpreter on your system

```bash
whenever tic_tac_toe.whn
```

⚠️ Interpreter names may differ from the examples.

---
