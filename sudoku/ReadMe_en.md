# 🔢 Sudoku

A classic **Sudoku** game implemented in **C#**, playable in the terminal.
The game generates a 9x9 grid according to the classic Sudoku rules.
The player fills in the squares by entering their coordinates followed by the number to be placed.

---

## 🧩 Features

- 9x9 grid respecting the standard Sudoku rules
- Input using coordinates: `[row] [column] [number]`
- Possibility of **removing** a number with `0` or `X`
- Input validation
- `Q` command to quit at any time
- Clear and responsive text interface

---

## ⚙️ Compilation

- Make sure you have **.NET 8.0 or higher** installed

```bash
dotnet --version
```

Then, build the project by using:

```bash
dotnet build
```

---

## 🚀 Execution

```bash
dotnet run
```

---

## 🧠 Rules

* The goal is to **fill the 9×9 grid** with numbers from **1 to 9**:
* No duplicates in:
  * rows
  * columns
  * 3×3 squares

---

## 🎮 Controls

| Input            | Action                                     |
| ---------------- | ------------------------------------------ |
| `row col number` | Place the number in the given position (1 to 9) (ex: `1 1 5` = places a 5 in the top left corner) |
| `row col 0/X`    | Remove the number in the given position    |
| `Q`              | Displays the solution and quit             |

---

## 🧾 Example session

```
 ------- ------- -------
| _ _ _ | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 2
 ------- ------- -------
| _ _ 2 | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 5
 ------- ------- -------
| _ _ 5 | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
> 1 3 X
 ------- ------- -------
| _ _ _ | _ _ 8 | _ 1 _ |
| 3 _ _ | 9 _ _ | _ _ _ |
| _ _ 1 | _ _ _ | _ _ 7 |
 ------- ------- -------
| 9 _ _ | 3 _ _ | _ _ _ |
| _ _ _ | _ 7 _ | _ _ _ |
| _ _ _ | _ _ 1 | _ 9 _ |
 ------- ------- -------
| 7 _ _ | _ _ _ | 3 _ _ |
| _ _ _ | _ _ 5 | _ _ 9 |
| _ 4 _ | _ 8 _ | _ _ _ |
 ------- ------- -------
[...]
```

---

## 🧩 Automatic validation

* If a predefined number is already in the chosen cell, an error is displayed.
* Otherwise, the grid is updated.
* The game automatically detects a **win** when the grid is complete and correct.

---

## 💡 Possible improvements

* Adjustable difficulty levels
* timer and recording of **resolution time**
* Help/Hints Mode
* Save and Load Game
* Graphical Interface
