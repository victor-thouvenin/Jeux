# ❌⬜⭕ Morpion

Le Morpion, est un jeu de société pour deux joueurs qui jouent alternativement en marquant les cases d'un tableau à tour de rôle avec leur symbole (`X` et `O`) sur une grille **3×3**. Le but du jeu est de placer trois symboles identiques en ligne droite, diagonale ou colonne, avant que l'adversaire ne le fasse.

---

## 🧠 Règles du jeu
Les règles du jeu sont simples:

1. Le jeu se joue sur une grille de **3×3 cases numérotées de 1 à 9** :
```
1|2|3
4|5|6
7|8|9
```
2. Le premier joueur joue avec le symbole `X` et le deuxième joueur joue avec le symbole `O`.
3. Les joueurs jouent à tour de rôle, en sélectionnant une case entre 1 et 9.
4. Le premier joueur qui place trois symboles identiques en ligne droite, diagonale ou colonne remporte la partie.
5. Si toutes les cases sont remplies et qu'aucun joueur n'a gagné, la partie se termine en match nul.

---

## 🧩 Implémentations

- Gestion de l’affichage ASCII du plateau
- Prise en entrée d’un chiffre `1–9`
- Vérification des coups et détection de victoire
- 3 implémentations sont disponibles
    - Brainfuck
    - AsciiDots
    - Whenever

Assurez-vous d’avoir les interpréteurs adéquats installés sur votre système.

### 1️⃣ Morpion en **Brainfuck**

* Version minimaliste en Brainfuck

```bash
bf morpion.bf
```

⚠️ un seul caractère par entré est lu reste ignoré

---

### 2️⃣ Morpion en **AsciiDots**

* Version utilisant le langage visuel AsciiDots

```bash
asciidots morpion.dots
```

---

### 3️⃣ Morpion en **Whenever**

* Version utilisant le langage non déterministe “Whenever”

```bash
whenever morpion.we
```

---

⚠️ Le nom d'un l'interpreteur peut être différant de celui dans l'exemple

---

## 🕹️ Contrôles

| Entrée             | Action                                        |
| ------------------ | --------------------------------------------- |
| `1` à `9`          | Placer son symbole sur la case correspondante |

---

## 💡 Idées d’améliorations

* Ajout d’autres versions en d'autres langages ésotériques (pour compléter la collection 😄)

---
