# ✈️ MyRadar — 2D Air Traffic Control Simulation

[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Module](https://img.shields.io/badge/Module-B--MUL--100-informational?style=for-the-badge)](#)
[![Technology](https://img.shields.io/badge/Technology-CSFML%20%2F%20C-2496ED?style=for-the-badge)](#)

## 📘 Description
**MyRadar** est un simulateur de trafic aérien 2D interactif développé en C avec la bibliothèque graphique CSFML. Le programme charge un script décrivant la position initiale d'avions et de tours de contrôle radar, et simule en temps réel le déplacement des aéronefs avec détection de collisions et zones protégées.

## ⚙️ Fonctionnalités
- Moteur de simulation à 60 FPS avec gestion d'entités vectorielles.
- Hitbox circulaires pour les zones de couverture des tours et rectangulaires pour les avions.
- Système de collision : deux avions entrant en contact explosent sauf s'ils se trouvent dans une zone radar.
- Raccourcis clavier : basculement de l'affichage des sprites (`S`) et des hitboxes (`L`).

## 🔨 Compilation & Utilisation
```bash
make
./my_radar assets/scenario.rdr
```
