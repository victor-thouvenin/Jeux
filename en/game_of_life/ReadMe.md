# 🧬 Conway’s Game of Life

**Conway’s Game of Life** is a cellular automaton implemented in **OCaml**.  
It simulates the evolution of a grid of cells over discrete time steps according to simple rules, resulting in complex and emergent behavior.

The initial grid is provided as a parameter, and the simulation advances one generation at a time when the user presses **Enter**.

---

## 🧩 Features

- Terminal-based implementation
- Written in **OCaml**
- Initial grid loaded from a file
- Step-by-step simulation controlled by the user
- Faithful implementation of Conway’s original rules
- Console interface

---

## ⚙️ Requirements

- **OCaml** (version 4.x or newer recommended)

Check your installation:

```bash
ocaml -version
```

---

## 🚀 Execution

```bash
ocaml game_of_life.ml <grid_file>
```

Example:

```bash
ocaml game_of_life.ml grid.txt
```

* `grid.txt` must contain the initial grid configuration
* Each line represents a row of the grid
* Spaces represent dead cells, other characters represent living cells.
If no file or an invalid file is provided, the program displays an error and exits.

---

### Characters used:

* ` ` — dead cell
* `@` — alive cell

Each line represents a row of the grid.

### Example (`grid.txt`):

```
.@..@
...@.
@@@..
.....
```

* The example above represents a 5x4 grid with some living cells (here the spaces are replaced by dots)

---

## 🎮 Controls

| Key        | Action                         |
| ---------- | ------------------------------ |
| `Enter`    | Advance to the next generation |
| `Q then Enter` or `Ctrl + D` | Quit the simulation |

---
