# 🔴🟡 Puissance 4

Un jeu Puissance 4 implémenté en Ruby, jouable en local ou sur réseau local.

- Joueur 1 : `O`
- Joueur 2 : `@`

---

## 🧩 Fonctionnalités

- Multijoueur en local (à deux joueurs sur la même machine)
- En réseau local (LAN) grâce à deux scripts :  
  - `puissance4_server.rb` (serveur → Joueur 1 / `O`)  
  - `puissance4_client.rb` (client → Joueur 2 / `@`)

Le but reste classique : aligner **4 pions identiques** horizontalement, verticalement ou en diagonale.

---

## 🧠 Règles du jeu

- La grille est de **7 colonnes × 6 lignes**
- Les joueurs entrent le **numéro d'une colonne (1–7)** pour y déposer leur pion
  - Joueur 1 : `O`
  - Joueur 2 : `@`
- Le premier joueur qui aligne **4 pions** (horizontalement, verticalement ou diagonalement) gagne la partie !
- Si le plateau est plein : **égalité**
- Le jeu signale :
  - les coups invalides (colonne pleine ou numéro incorrect)
  - la victoire
  - l'égalité

---

## 🚀 Exécution

### 🕹️ 1. Mode local (deux joueurs, même machine)

Aucun paramètre n'est requis :

```bash
ruby puissance4_server.rb
```

Les joueurs entrent simplement le numéro de colonne à leur tour.

---

### 🌐 2. Mode réseau (LAN, deux machines différentes)

#### 📡 1. Lancer le serveur (Joueur 1)

```bash
ruby puissance4_server.rb --LAN [port]
```

Exemple :

```bash
ruby puissance4_server.rb --LAN 5000
```

Le serveur attendra la connexion du joueur 2.

---

#### 🖧 2. Lancer le client (Joueur 2)

```bash
ruby puissance4_client.rb [ip_joueur1] [port]
```

Exemple :

```bash
ruby puissance4_client.rb 192.168.1.42 5000
```

Le client se connecte alors au serveur et la partie peut commencer.

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

tour du joueur 1 : 1
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
|O| | | | | | |
---------------

tour du joueur 2 : 5
 1 2 3 4 5 6 7
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
|O| | | |@| | |
---------------

tour du joueur 1 : 5
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

## 🕹️ Contrôles

| Entrée | Action                           |
| ------ | -------------------------------- |
| `1–7`  | Déposer un pion dans la colonne  |

---

## ⚠️ Notes réseau

* Les ports utilisés doivent être **ouverts** sur les firewalls locaux
* Le mode réseau fonctionne uniquement sur **réseau local (LAN)**
* Le serveur doit être lancé **avant** le client

---

## 💡 Améliorations possibles

* Gestion de reconnexion en cas de coupure
* IA pour jouer en solo
* Mode spectateur
* Interface graphique

---
