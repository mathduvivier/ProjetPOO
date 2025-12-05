Documentation utilisateur 
1.1Présentation générale 
Ce programme implémente une version personnalisée du « Jeu de la Vie » de 
John Conway. 
Il permet de : 
• Charger une grille initiale à partir d’un fichier texte  
• Simuler son évolution selon les règles du jeu  
• Visualiser la simulation de manière graphique ou textuelle  
• Enregistrer chaque itération dans des fichiers  
• Consulter une itération donnée sous forme de fichier  
• Exécuter des tests unitaires internes validant la cohérence du moteur 
Fonctionnement de notre jeu  
Le fonctionnement du programme repose sur un menu interactif composé de 
cinq modes. 
1.2. Format du fichier d’entrée 
L’utilisateur doit fournir un fichier texte contenant : 
1. Deux entiers : hauteur et largeur de la grille ; 
2. Une matrice de dimensions hauteur × largeur composée de valeurs : 
o 0 : cellule morte en bleu  
o 1 : cellule vivante en vert 
o 2 : obstacle vivant en magenta 
o 3 : obstacle mort en rouge 
14 
Exemple de fichier valide : 
10 9 
1 0 0 0 1 1 1 0 0 
0 2 1 1 3 0 0 3 0 
3 1 3 0 0 0 2 0 0 
0 2 2 1 2 0 1 0 0 
0 0 1 1 1 0 1 1 1 
3 1 3 0 0 0 0 0 0 
0 2 2 1 2 0 1 2 1 
0 0 1 1 1 0 0 0 0 
3 1 3 0 0 0 0 0 0 
3 1 3 0 0 0 0 0 0 
1.3. Déroulement de l’utilisation 
Étape 1 : Chargement initial 
Le programme demande d’abord : 
• Le nom du fichier d’entrée  
• Le nombre d’itérations à exécuter 
Le nombre d’itérations est contrôlé automatiquement : 
seules les valeurs entières strictement positives sont acceptées sinon il 
renvoie un message d’erreur. 
Étape 2 : Menu principal 
À chaque boucle, le programme affiche : 
15 
L’utilisateur choisit l’un des cinq modes décrits ci-après. 
1.4. Description des modes 
Mode 1 : Mode graphique (SFML) 
Ce mode ouvre une fenêtre graphique permettant de visualiser l’évolution de 
la grille en temps réel. 
Caractéristiques : 
• La fenêtre s’adapte à la taille de la grille (1 carré par cellule). 
• Les cellules sont représentées par des couleurs distinctes : 
o bleu : cellule morte  
o vert : cellule vivante  
o rouge : obstacle mort  
o magenta : obstacle vivant 
• Une mise à jour est effectuée toutes les secondes. 
• La simulation s’arrête lorsque le nombre d’itération demandé par 
l’utilisateur est atteint. 
Ce mode n’écrit aucun fichier sur le disque. 
Mode 2 : Mode console (génération des fichiers iteration_X) 
Ce mode exécute la simulation dans la console et génère automatiquement un 
fichier texte pour chaque itération : 
iteration_0.txt 
iteration_1.txt 
16 
... 
iteration_N.txt 
Chaque fichier contient : 
• la hauteur et la largeur ; 
• la grille de cellules à cet instant. 
Ce mode doit avoir été exécuté au moins une fois avant d’utiliser le Mode 3. 
Mode 3 : Affichage d’un fichier iteration_X 
Ce mode permet de consulter à l’écran un fichier d’itération généré par le 
mode console. 
Fonctionnement : 
• Le programme demande un numéro X ; 
• Il ouvre iteration_X.txt et en affiche le contenu dans la console. 
Si aucun fichier iteration_X n’a encore été généré, un message d’erreur 
informe l’utilisateur. 
Mode 4 : Tests unitaires internes 
Ce mode exécute une batterie de tests automatiques. 
Les tests portent notamment sur : 
• Le calcul des voisins (calcCellNeighbors) ; 
• La mise à jour de la grille (update) ; 
Les tests sont implémentés avec assert() et affichent les résultats dans la 
console. 
Mode 5 : Quitter le programme 
Met fin à l’exécution du programme. 
17
Environnement de développement opérationnel 
Le développement du projet a été réalisé dans un environnement Linux, avec 
une organisation professionnelle basée sur le contrôle de version et 
l’utilisation d’outils dédiés à la compilation, aux tests et à la gestion du code. 
1. Système d’exploitation 
L’intégralité du projet a été développée et testée sous Linux . 
Ce choix garantit : - un environnement stable et adapté à la compilation en C++ ; - une compatibilité optimale avec les outils Makefile ; - une gestion facilitée des dépendances comme SFML. 
2. Gestion de version : Git et GitHub 
Le suivi du code source a été assuré via Git, avec un dépôt hébergé sur GitHub. 
Avantages : - Suivi précis des modifications et historique complet du développement. - Collaboration facilitée grâce aux branches, commits et pull requests. - Hébergement sécurisé et sauvegarde distante du projet. 
Structure du dépôt : - src/ : fichiers sources (.cpp) - include/ : headers (.h/.hpp) - tests/ : tests unitaires - Makefile : script de compilation - README.md : instructions/sujet 
18 
3. Outils de compilation 
Le Makefile permet : - la compilation complète du projet, - la génération des exécutables console et graphique, - le nettoyage automatique via `make clean`. 
4. Langage et bibliothèques 
Langage : - C++  
Bibliothèque graphique : - SFML pour la gestion de fenêtre, l'affichage graphique et les événements 
utilisateur 
5. Organisation du développement - Commits réguliers sur GitHub - Compilation et tests en ligne de commande sous Linux - Architecture modulaire orientée objet 
