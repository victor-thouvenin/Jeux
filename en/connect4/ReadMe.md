# 🔴🟡 Connect Four

A Connect Four game implemented in Ruby, playable locally or over LAN.

- Player 1: `O`
- Player 2: `@`

---

## 🧩 Features

- Local multiplayer (on the same system)
- LAN multiplayer using two scripts:
  - `puissance4_server.rb` (server → Player 1 / `O`)
  - `puissance4_client.rb` (client → Player 2 / `@`)

The goal remains classic: to align **4 identical pawns** horizontally, vertically or diagonally.

---

## 🧠 Rules

- The grid is **7 columns × 6 rows**
- Players enter a **number from a column (1–7)** to place their pawn.
  - Player 1: `O`
  - Player 2: `@`
- The first player to align **4 pieces** (horizontally, vertically, or diagonally) wins the game!
- If the board is full: **tie**
- The game indicates:
  - Invalid moves (full column or incorrect number)
  - Win
  - Tie

## 🚀 Execution

### 🕹️ 1. Local Mode (two players, same computer)

No parameters are required:

```bash
ruby puissance4.rb
```

Players simply enter the column number.

---

### 🌐 2. Online Mode (LAN, two different computer)

#### 📡 1. Server (Player 1)

```bash
ruby puissance4.rb --LAN [port]
```

Example :

```bash
ruby puissance4_server.rb --LAN 5000
```

The server will wait for player 2 to connect.

#### 🖧 2. Client (Player 2)

```bash
ruby puissance4_client.rb [player1_ip] [port]
```

Example :

```bash
ruby puissance4_client.rb 192.168.1.42 5000
```

The client then connects to the server and the game can begin.

---

## 🧾 Exemple de partie

```
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
---------------

player 1's turn: 1
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
|O| | | | | | |
---------------

player 2's turn: 5
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
|O| | | |@| | |
---------------

player 1's turn: 5
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | |O| | |
|O| | | |@| | |
---------------

[...]
```

---

## 🕹️ Controls

| Input | Action      |
| ----- | ----------- |
| `1–7` | Drop a pawn |

---

## ⚠️ Network Notes

* The ports used must be **open** on local firewalls.
* Network mode only works on **local area network (LAN)**.
* The server must be started **before** the client.

---

## 💡 Possible Improvements

* Reconnection management in case of disconnection
* AI for single-player mode
* Spectator mode
* Graphical interface

---