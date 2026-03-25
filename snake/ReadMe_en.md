# 🟡 Snake - Pac Edition

A **Snake game** developed in **Python** using **Pygame**, inspired by the **Pac-Man** universe.
The snake head is **Pac-Man**, body is made of **ghosts**, and the **Pac-Gums** replace the apples.

---

## 🧩 Features

- **Pygame** graphical interface
- Simple and responsive controls via the **keyboard arrows**
Customized appearance:
  - 🟡 **Pac-Man** for the head
  - 👻 **Ghosts** for the body
  - ⚪ **Pac-Gums** for the apples
- Smooth collision and snake growth
- Real-time score display
- Ability to quit at any time with `Q` or `Esc`
- Sounds and animations inspired by the **Pac-Man** universe

---

## ⚙️ Requirements

### Install the dependencies

**Python 3** and **Pygame**:

```bash
pip install pygame
```

---

## 🚀 Execution

```bash
python snake.py
```

No parameters are required.
A window will automatically open displaying the playing field.

---

## 🎮 Controls

| Key         | Action |
| ----------- | ------ |
| 🡐 🡒 🡑 🡓     | Move   |
| `Q` / `Esc` | Quit   |

---

## 🧠 Rules

* Move **Pac-Man** across the screen to **eat the Pac-Gums** ⚪.
* With each Pac-Gum eaten:
  * The snake grows 👻
  * The score increases 💯
* If Pac-Man hit a wall or the ghosts, the game is over 💥.
* The goal is to **survive as long as possible** and achieving the best score.

---

## 🧾 Example session (simplified visual)

```
Score : 3

👻👻👻🟡⚪
```

```
Score : 4

👻👻👻👻🟡
```

Pac-Man moves forward, eats the Pac-Gum, and a new ghost appears at the back of the line.

---

## 🎨 Graphic Theme

The sprites used are free resources inspired by **Pac-Man**

---

## 💡 Possible improvements

* main menu and gradual speed
