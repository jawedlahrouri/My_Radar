[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Graphics: CSFML](https://img.shields.io/badge/GUI-CSFML-brightgreen.svg?style=for-the-badge)](https://www.sfml-dev.org/)
[![Module](https://img.shields.io/badge/Module-B--MUL--100-informational?style=for-the-badge)](#)

# ✈️ MyRadar — Simulateur 2D de Contrôle Aérien & Détection de Collisions

**MyRadar** est un simulateur de trafic aérien en temps réel développé en langage C avec la bibliothèque multimédia **CSFML**. Le programme modélise le vol d'avions entre différentes coordonnées cartésiennes, la surveillance par des tours de contrôle et la gestion dynamique des zones de collision.

---

## 🕹️ Systèmes & Mécaniques de Simulation

- **Avions de Ligne (`A`)** :
  - Déplacement vectoriel fluide du point de départ $(x_1, y_1)$ vers la destination $(x_2, y_2)$.
  - Vitesse paramétrable ($px/s$) et délai de décollage individuel ($s$).
  - Disparition automatique dès l'arrivée à destination ou destruction en cas de crash.
- **Tours de Contrôle (`T`)** :
  - Rayon de couverture radar circulaire paramétrable autour de leurs coordonnées.
  - **Zone de Sécurité** : Les aéronefs situés dans la zone de couverture d'une tour ne peuvent entrer en collision avec d'autres appareils.
- **Détection des Collisions** :
  - Algorithme d'intersection géométrique entre les boîtes englobantes (*Hitboxes*) des avions hors des zones protégées par les tours de contrôle.
  - Deux avions en collision sont instantanément détruits et retirés de la simulation.

---

## ⌨️ Raccourcis Clavier & Contrôles

- **`L`** : Afficher / Masquer les boîtes de collision (hitboxes) et les cercles de couverture des tours.
- **`S`** : Afficher / Masquer les sprites graphiques des avions et des tours.
- **`Échap`** : Quitter la simulation.

---

## 📄 Format des Scripts de Vol

Le programme prend en paramètre un fichier script texte décrivant les entités de la simulation :

```text
# Avions : A [x_dep] [y_dep] [x_arr] [y_arr] [vitesse] [délai_décollage]
A 800 400 200 100 5 0
A 150 200 800 800 2 3

# Tours : T [x] [y] [rayon_couverture]
T 500 500 150
```

---

## 🛠️ Compilation & Lancement

```bash
make        # Génère l'exécutable 'my_radar'
make clean  # Nettoie les fichiers objets
make fclean # Supprime les fichiers objets et le binaire
make re     # Recompile le simulateur

./my_radar scripts/scenario.txt
```
