# 🔁 Repeat

**Repeat** is a memory game developed in **Lua** using the **LÖVE (Love2D)** framework.  
The player must watch and reproduce an increasing sequence of numbers.

The sequence is displayed visually on a **3×3 grid**, and the rhythm speeds up as the game progresses.

---

## 🧩 Features

- Graphical interface using **LÖVE**
- **Solo** game
- Sequence of random digits
- Visual feedback with highlighted cells
- Chances of rythm acceleration increasing after each turn
- No parameters required

---

## ⚙️ Requirements

- **LÖVE (Love2D)** installed
👉 [https://love2d.org/](https://love2d.org/)

```bash
love --version
```

---

## 🚀 Execution

```bash
love game/
```

---

## 🎮 Rules

1. A **grid of numbers (1 to 9)** appears on the screen.
2. The game displays a **sequence of random numbers**: the corresponding squares light up briefly one by one.
3. Once the sequence is displayed, the player must **reproduce the same sequence** by pressing the keyboard **1 to 9** keys.
4. If the sequence is correct:
   * The score increases 💯
   * The **sequence lengthens**
   * The **speed can increase** (with increasing probability)
5. If the player makes a mistake:
   * The game ends
   * The final score is displayed

---

## 🕹️ Controls

| Key     | Action                  |
| ------- | ----------------------- |
| `1 – 9` | Repeat the sequence     |
| `Q` or `Esc` | Quit               |

---

## 📊 Example session

1. The game displays the number `5`, which lights up.
2. You type `5`.
3. The game displays `5 → 2`.
4. You type `5`, then `2`.
5. The game displays `5 → 2 → 8`…

   and so on, until the fatal mistake 😅.

---

## 💡 Technical Details

* Language: **Lua 5.1+**
* Framework: **LÖVE 11.x+**
* No external dependencies required
* The game automatically manages:
   * the rhythm and sequence speed
   * random number generation
   * keyboard input detection

---

## 💡 Possible Improvements

* Sounds and visual effects synchronized with the numbers
* High score saving
* Customizable difficulty modes
* Combo system and score multiplier
* Customizable graphic themes