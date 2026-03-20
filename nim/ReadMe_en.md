# 🔥 Nim

**Nim** is a classic strategy game implemented in **C**, playable in the terminal.  
Matches are arranged in a **pyramid (triangle)** shape, and players take turns removing them.

⚠️ The goal is **NOT** to take the last match.  
The player who takes the last match **loses** the game.

---

## 🧩 Features

- Terminal-based gameplay
- Written in **C**
- Matches arranged in a **pyramid shape**
- Play **against an AI** (default) or in **multiplayer mode**
- Up to **9 players**
- Optional limit on the number of matches removed per turn
- Input validation with automatic retry
- Command `end` or `Ctrl+D` to **quit the game at any time**
- Language selection in game (at launch or runtime)

---

## ⚙️ Compilation

The project includes a **Makefile**.

```bash
make
```

This generates the executable:

```bash
./nim
```

---

## 🚀 Execution

```bash
./nim [lines] [max_removal] [players]
```

### Parameters

| Parameter     | Description                             | Default   |
| ------------- | --------------------------------------- | --------- |
| `lines`       | Number of lines (height of the pyramid) | required  |
| `max_removal` | Maximum matches removable per turn (or `-` for default value) | unlimited |
| `players`     | Number of players (2–9) or 1 for AI     | 1         |

---

### Examples

```bash
./nim 4
```

→ 4-line pyramid, no removal limit, vs AI

```bash
./nim 5 3
```

→ 5 lines, max 3 matches per turn, vs AI

```bash
./nim 3 2 4
```

→ 4 players, 3 lines, max 2 matches per turn

```bash
./nim 3 - 4
```

→ 4 players, 3 lines, no removal limit

---

### Language selection at launch

```bash
./nim [parameters] -lang=[language]
```

Example:
With `-lang=en`, the game will start in english *(start in french by default)*

---

### Language selection at runtime

Select the the language when input is requested 

Example:

```bash
Your turn:
Line: fr
langue changée en français
Ligne : en
changing language to english
[...]
```

Use the command `lang` to list the available languages

Example:

```bash
Your turn:
Line: lang
fr, en
```

---

## 🎮 Gameplay

* The program displays the **matchstick pyramid**
  * Each line is in the format `[l][content][n]` where:
    * `l` is the line number
    * `content` is the line content
    * `n` is the number of remaining matches in the line

Example:

```
 *********
 1   |   1
 2  |||  3
 3 ||||| 5
 4|||||||7
 *********
```

### Turn flow

1. Choose a **line number**
2. Choose how many **matches to remove**
3. The game validates the move
4. Next player’s turn

If input is invalid, both values are requested again.

---

## 🧠 Rules

* Players take turns removing matches from **one line only**
* At least **one match must be removed**
* A player **loses** if they take the **last match**
* The last remaining player wins 🎉
* The game ends immediately if a player types:

  * `end`
  * or sends **EOF (Ctrl+D)**

---

## 🧾 Example Session

```
$ ./nim 4
 *********
 1   |   1
 2  |||  3
 3 ||||| 5
 4|||||||7
 *********

Tour du joueur :
Ligne : en
changing language to english
Line: 3
Matches: 2
 *********
 1   |   1
 2  |||  3
 3 |||   3
 4|||||||7
 *********
player removed 2 match(es) from line 3

AI's turn...
 *********
 1   |   1
 2  |||  3
 3 |||   3
 4|      1
 *********
AI removed 6 match(es) from line 4

[...]
```

---

## 💡 Possible Improvements

* Smarter AI (optimal Nim strategy using XOR)
* Save and load system
* Graphical interface (ncurses / SDL)
