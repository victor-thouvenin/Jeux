# 📦 Sokoban

**Sokoban** is a **C** implementation using the **ncurses** library of the famous Japanese puzzle game.
The **player** must push **boxes** onto **storage locations** inside a warehouse.
Every move must be carefully considered, because it is impossible to pull the boxes!

---

## ⚠️ Epilepsy warning

This game uses a console display that refreshes after each move.
When moving the player or the boxes quickly, the screen may **flick rapidly** depending on your device or system configuration.
👉 **Playing is not recommended (or should be played slowly) if you are sensitive to bright lights or fast visual effects (photosensitivity/epilepsy).**
To reduce these effects:
- Avoid holding down the movement keys or pressing them too quickly.

---

## 🧩 Features

- Sokoban game on **console** (ncurses)
- Reads the **warehouse map** from a **file passed as a parameter**
- Maps written with ASCII characters:
  - `#`: wall
  - `P`: player
  - `X`: box
  - `O`: storage location
  - ` ` (space): empty space
- Automatic victory verification
- Move the player with the keyboard
- Simple handling of file errors (invalid format / file not found)
- You can quit at any time with `Q` or the `End` key or restart with space bar.

---

## ⚙️ Prerequisites / Compilation

### Dependencies
- **ncurses** (text interface management library)

On Debian/Ubuntu:
```bash
sudo apt install libncurses6 libncurses-dev libncursesw6
```

### Compilation

The project comes with a **Makefile**. To compile:

```bash
make
```

This generates the executable:

```bash
./sokoban
```

---

## 🚀 Execution

```bash
./sokoban <map_file>
```

You can also choose the language with an optional parameter:

```bash
./sokoban <map_file> [language]
```

### Example:

```bash
./sokoban maps/level1.txt
```

Start the game with the map `level1.txt`

and:

```bash
./sokoban maps/level1.txt en
```

Start the game in english with the map `level1.txt`

The game launches in French by default

---

## 🗺️ Symbols

* `#` — wall
* `P` — player position (exactly one per card)
* `X` — box
* `O` — storage
* ` ` (space) — empty space

### Map example:

```
#######
#  O  #
#  X  #
# P   #
#######
```

---

## 🎮 Controls

| Key               | Action                                     |
| ----------------- | ------------------------------------------ |
| Arrows (↑ ↓ ← →)  | Move the player / push a box (if possible) |
| ` ` (Space)       | Restart                                    |
| `Q` or `End` key  | Quit game                                  |

---

## 🧠 Rules

1. You play as player `P` and must push the boxes `X` into their spaces `O`.
2. You **cannot pull** the boxes, only push them. A box can only be pushed if the destination space is free (an empty space or a storage space).
3. When the boxes occupy **all the storage spaces**, you **win**.
4. If you are blocked, you **lose**.

---

## 🧾 Example session

```
#######
#  O  #
#  X  #
# P   #
#######
```

➡️ The player presses the right arrow.

```
#######
#  O  #
#  X  #
#  P  #
#######
```

➡️ The player presses the up arrow to push `X` onto `O`.

```
#######
#  X  #
#  P  #
#     #
#######
```

🎉 You won !

---

## 💡 Possible Improvements

* Support for **multiple chained levels**
* Save/load progress
* Animate the player and boxes
* Undo last move/move history
