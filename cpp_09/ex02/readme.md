Complexité des opérations d'insertion et de suppression :

std::vector : 
			Les opérations d'insertion et de suppression en milieu de vecteur sont coûteuses car elles nécessitent le décalage des éléments suivants. Cependant, les opérations en fin de vecteur sont généralement rapides car elles peuvent être effectuées en temps constant.
std::list : 
			Les opérations d'insertion et de suppression sont plus efficaces car elles ne nécessitent que des modifications locales des pointeurs de nœuds. Cependant, l'accès séquentiel peut être plus lent en raison de l'absence de localité des données.
---------------------------------------------------------------------------------------------
Accès aléatoire :

std::vector : 
			Les accès aléatoires sont rapides car les éléments sont stockés de manière contiguë en mémoire. Cela est particulièrement important pour les algorithmes de tri comme Merge Sort qui effectuent fréquemment des accès aléatoires.
std::list : 
			Les accès aléatoires sont inefficaces car ils nécessitent un parcours séquentiel des nœuds.
---------------------------------------------------------------------------------------------
Localité des données :

std::vector : 
			Les éléments sont stockés de manière contiguë en mémoire, ce qui favorise une meilleure utilisation du cache et peut améliorer les performances en raison de la localité des données.
std::list : 
			Les éléments sont dispersés dans la mémoire, ce qui peut entraîner une utilisation inefficace du cache et des performances plus faibles en raison du manque de localité des données.