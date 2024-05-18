# Calcul des Bulletins de Paie en C

Ce programme est basé sur les connaissances que j'ai acquises après avoir suivi le cours de législation du travail, dispensé dans le cadre du module d'environnement économique  et juridique (EEJ). Son objectif est de faciliter le calcul des bulletins de paie des employés en fonction de leurs salaires, de leur ancienneté et d'autres facteurs. Toutes les opérations effectuées dans ce programme sont inspirées des concepts étudiés dans le cadre de ce cours.

## Contexte et Paramètres Utilisés

Ce programme utilise les paramètres suivants pour le calcul des bulletins de paie :
- **Salaire Brut :** Le salaire brut de l'employé avant les déductions.
- **Ancienneté :** Le nombre d'années de service de l'employé.
- **Prime :** Prime basée sur l'ancienneté de l'employé et le salaire brut.
- **AMO (Assurance Maladie Obligatoire) :** Cotisation pour l'assurance maladie.
- **CNSS (Caisse Nationale de Sécurité Sociale) :** Cotisation pour la sécurité sociale.
- **Impôt sur le Revenu (IR) :** Impôt sur le revenu à payer par l'employé.
- **Salaire Net :** Le salaire net de l'employé après déduction des cotisations et de l'impôt sur le revenu et l'ajout du prime d'Ancienneté.

Lors du calcul des cotisations CNSS, un plafond de 6000 est appliqué sur le salaire brut. Si le salaire brut dépasse ce plafond, les cotisations CNSS sont calculées sur la base du plafond de 6000.

Le processus de calcul de la prime est basé sur les années d'exercice de l'employé :
- Moins de 2 ans d'ancienneté : Pas de prime.
- De 2 à 5 ans : Prime équivalente à 5% du salaire brut.
- De 5 à 12 ans : Prime équivalente à 10% du salaire brut.
- De 12 à 25 ans : Prime équivalente à 15% du salaire brut.
- Plus de 25 ans : Prime équivalente à 25% du salaire brut.

**N.B :** Les données des employés sont stockées dans un fichier texte nommé "employes.txt".
