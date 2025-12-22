# 🔥 Jeu de Nim

**Nim** est un jeu de stratégie développé en **C**, jouable dans le terminal.
Le but est **de ne pas prendre la dernière allumette** : le joueur qui la retire **perd la partie**.

---

## 🧩 Fonctionnalités

- Mode **1 joueur contre IA** *(par défaut)*
- Mode **multijoueur local** (jusqu’à **9 joueurs**)
- Nombre de **lignes** et **règles personnalisables**
- Commande **`end`** (ou **Ctrl+D**) pour **abandonner la partie**
- Gestion des erreurs d’entrée avec répétition automatique
- Interface **texte claire et intuitive**

---

## ⚙️ Compilation

Assurez-vous d’avoir un compilateur **C18** ou supérieur.

Le projet est fourni avec un **Makefile**.
Pour compiler le programme, exécutez simplement :

```bash
make
````

Cela génère un exécutable nommé :

```bash
./nim
```

---

## 🚀 Exécution

Lancez le programme avec :

```bash
./nim [nombre_de_lignes] [max_retrait] [joueurs]
```

### Paramètres

| Paramètre            | Description                                                | Valeur par défaut |
| -------------------- | ---------------------------------------------------------- | ----------------- |
| **nombre_de_lignes** | Nombre de lignes d’allumettes                              | *(obligatoire)*   |
| **max_retrait**      | Nombre maximum d’allumettes que l’on peut retirer par tour | Aucune limite     |
| **joueurs**          | Nombre de joueurs (2 à 9) ou 1 pour jouer contre l’IA      | 1                 |

### Exemples

```bash
./nim 4
```

→ Partie contre l’IA avec **4 lignes** et **aucune limite** de retrait.

```bash
./nim 5 3
```

→ Partie contre l’IA avec **5 lignes** et un maximum de **3 allumettes par tour**.

```bash
./nim 3 2 4
```

→ Partie **à 4 joueurs humains**, **3 lignes**, maximum **2 allumettes** retirables par tour.

---

## 🎮 Déroulement du jeu

* Le programme affiche la **pyramide d’allumettes**, par exemple :

  ```
      |
     |||
    |||||
   |||||||
  ```
* À chaque tour :
  1. Le joueur choisit le **numéro de la ligne**.
  2. Puis il indique le **nombre d’allumettes à retirer**.
* Si une entrée est invalide (ligne vide, nombre trop grand, etc.), le programme redemande la saisie.
* Le jeu continue jusqu’à ce qu’il ne reste **plus d’allumettes**.

---

## 🧠 Règles du jeu

* Les joueurs jouent à tour de rôle.
* On peut retirer **au moins une allumette** d’une seule ligne à chaque tour.
* Le joueur qui prend **la dernière allumette perd**.
* Le dernier joueur encore en jeu **gagne la partie** 🎉.

---

## 💡 Améliorations possibles

* IA plus stratégique (calcul XOR, stratégie gagnante du Nim parfait)
* Historique des tours et rejouabilité
