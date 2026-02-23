# 🚢 Navy (Battleship)

**Battleship** is a terminal-based implementation of the classic game, written in **C**.  
Two players run the program in **separate terminals** and play against each other using **UNIX process communication**.

Each player provides a file describing their fleet, and the second player connects to the first using its **process ID (PID)**.

---

## 🧩 Features

- Classic Battleship gameplay
- Written in **C**
- Two-player mode only
- Players run the game in **separate terminals**
- Communication between processes using **UNIX signals**
- Fleet configuration loaded from a file
- Turn-based gameplay with attack coordinates

---

## ⚙️ Requirements

- UNIX-compatible system (Linux, macOS)
- C compiler (`gcc`, `clang`, etc.)

Check your compiler:

```bash
gcc --version
```

---

## 🛠️ Compilation

Compile the project using the provided Makefile:

```bash
make
```

This generates the executable:

```bash
./battleship
```

---

## 🚀 Execution

### 1️⃣ Player 1

Launch the first instance of the game **with the positions file**:

```bash
./battleship positions_player1.txt
```

The program displays the **PID** that Player 2 must use to connect.

### 2️⃣ Player 2

Launch the second instance of the game **specifying the PID of player 1** and its own positions file:

```bash
./battleship <pid_player1> positions_player2.txt
```

---

## 🗺️ Fleet Configuration File

Each player provides a file describing the size and position of their ships.

### Format

```
[size]:[coordinate1]:[coordinate2]
```

* `size` — length of the ship (from 2 to 5)
* `coordinate1` — starting coordinate
* `coordinate2` — ending coordinate

Ships must be placed **in a straight line**, either horizontally or vertically.

---

### Example:

```
2:C1:C2
3:D4:F4
4:A6:D6
5:H1:H5
```

---

## 🚢 Fleet Rules

* The fleet contains **4 ships**, one of each size:

  * 2
  * 3
  * 4
  * 5
* Ships cannot overlap
* Ships must stay within the board boundaries
* Diagonal placement is not allowed

---

## 🎮 Gameplay

* Players take turns attacking by entering coordinates (e.g. `B4`)
* The game reports:

  * **hit**
  * **miss**
* The boards are displayed after each turn:

  * Your fleet
  * Enemy hits and misses
* The game ends when one player has **all ships sunk**

---

## 🧾 Example Session

### 1️⃣ Player 1

```bash
> ./battleship positions_player1.txt
PID: 5644
waiting for enemy connection...

enemy connected

my boats:
 |A B C D E F G H
-+---------------
1|. . . . . . . 5
2|. . 2 . . . . 5
3|. . 2 . . . . 5
4|. . . 3 3 3 . 5
5|. . . . . . . 5
6|. 4 4 4 4 . . .
7|. . . . . . . .
8|. . . . . . . .

enemy's boats:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack:
```

### 2️⃣ Joueur 2

```bash
> ./battleship 5644 positions_player2.txt
PID: 5654
successfully connected

my boats:
 |A B C D E F G H
-+---------------
1|. 2 2 . . . . .
2|. . . 3 . . . .
3|. . . 3 . . . .
4|. . . 3 . . . .
5|. . 4 4 4 4 . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . 5 5 5 5 5

enemy's boats:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy's attack...
```

---

## 💡 Possible Improvements

* Network-based multiplayer (via sockets)
