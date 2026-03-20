# 🔁 Repeat

**Repeat** est un jeu de mémoire développé en **Lua** avec **LÖVE2D**.
Le principe est simple : répétez la séquence de chiffres affichée à l’écran —
et voyez jusqu’où vous pouvez aller avant de vous tromper !

---

## 🧩 Fonctionnalités

- Interface graphique avec **grille de 1 à 9**
- Jeu en **solo**
- Séquences de chiffres aléatoires
- Retour visuel avec cellules en surbrillance
- Probabilités d'acceleration du rythme croissante à chaque tours
- Aucun paramètre requis

---

## ⚙️ Installation

Assurez-vous d’avoir **LÖVE** installé sur votre système.
👉 [https://love2d.org/](https://love2d.org/)

### Vérifiez l’installation :
```bash
love --version
```

---

## 🚀 Exécution

Lancez simplement le jeu avec :

```bash
love game/
```

---

## 🎮 Règles du jeu

1. Une **grille de chiffres (1 à 9)** apparaît à l’écran.
2. Le jeu affiche une **séquence de chiffres aléatoires** : les cases correspondantes s’allument brièvement une par une.
3. Une fois la séquence affichée, le joueur doit **reproduire la même séquence** en appuyant sur les touches **1 à 9** du clavier.
4. Si la séquence est correcte :
   * le score augmente 💯
   * la **séquence s'allonge**
   * la **vitesse peut augmenter** (avec une probabilité croissante)
5. Si le joueur se trompe :
   * la partie s’arrête
   * le score final est affiché

---

## 🕹️ Contrôles

| Touche       | Action                         |
| ------------ | ------------------------------ |
| **1 – 9**    | Répéter les chiffres affichés  |
| **Q** ou **Échap** | Quitter le jeu           |

---

## 📊 Exemple de session

1. Le jeu montre la case `5` qui s’allume.
2. Vous tapez `5`.
3. Le jeu montre `5 → 2`.
4. Vous tapez `5`, puis `2`.
5. Le jeu montre `5 → 2 → 8`…

   et ainsi de suite, jusqu’à l’erreur fatale 😅.

---

## 💡 Détails techniques

* Langage : **Lua 5.1+**
* Framework : **LÖVE 11.x+**
* Aucune dépendance externe requise
* Le jeu gère automatiquement :
  * le rythme et la vitesse de séquence
  * la génération aléatoire de nombres
  * la détection des entrées clavier

---

## 💡 Améliorations possibles

* Sons et effets visuels synchronisés avec les chiffres
* Sauvegarde du meilleur score
* Modes de difficulté paramétrables
* Système de combo et multiplicateur de points
* Thèmes graphiques personnalisables
