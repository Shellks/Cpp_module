/-----------------------------/
currentIndex += insertionAreaSize;
---
Met à jour l'index de la position d'insertion pour la prochaine itération en ajoutant la taille de la zone d'insertion.
Cela garantit que les prochaines insertions seront effectuées à des intervalles de puissances de 2, comme requis par l'algorithme.
---

/-----------------------------/
insertionAreaSize = (insertionAreaSize << 1) - 1 :
---
Met à jour la taille de la zone d'insertion. 
Elle est ajustée pour être une puissance de 2 moins 1. 
Cela garantit que la taille de la zone d'insertion est un nombre de la forme 2^n - 1, 
comme spécifié dans l'algorithme de Ford-Johnson.
---