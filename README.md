
# TP0 & TP1 – Primality Testing

Master 1 IL & RSD – Algorithmique avancée et complexité

## Structure du projet
- `data/` : Fichiers CSV des jeux de données (Random100, Random1000, Test-1, Test-2, Test-3)
- `src/` : Code source en C (Algorithmes A1, A2, A3, A4)
- `results/` : Résultats des tests (temps d'exécution, statistiques, speedup)
- `graphs/` : Graphiques et histogrammes
- `report/` : Rapport final

## Répartition des rôles
- **Role 1 (Data)** : Génération des données dans `data/` (CSV)
- **Role 2 (Programming)** : Implémentation des algorithmes dans `src/` (C)
- **Role 3 (Testing)** : Exécution des tests, statistiques dans `results/`, graphiques dans `graphs/`
- **Role 4 (Report)** : Rédaction du rapport dans `report/`

## Consignes Git
- Toujours faire `git pull origin main` avant de commencer à travailler.
- Ne pas commiter les fichiers compilés (.exe, .o, etc.) - déjà géré par .gitignore.
- Faire des commits clairs : `git commit -m "Ajout de Random100.csv"`