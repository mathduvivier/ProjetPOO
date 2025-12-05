ProjePROJET POO : le jeu de la vie
Énoncé
Le jeu de la vie désigne un automate cellulaire proposé par le mathématicien John Conway. Il décrit l’évolution d’une population de cellules sur un intervalle de temps discret. Les cellules placées dans une grille rectangulaire deux dimensionnelle sont caractérisées par deux états ; elles sont soit vivantes, soit mortes. A l’exclusion des bordures, le voisinage d’une cellule est formé par 8 autres cellules directement adjacentes. Pour passer de l’itération 
t à l’itération t+1, l’état des cellules dans la grille est actualisé selon les règles suivantes :

Une cellule morte possédant exactement trois voisines vivantes devient vivante.
Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.
Vous proposerez une implémentation en C++ du jeu de la vie en vous reposant sur les concepts de la programmation orientée objet. En entrée, votre programme consommera un fichier dont la première ligne permettra de spécifier la taille de la grille. Suivra une matrice de booléens, décrivant l’état initial, vivant (1) ou mort (0) des cellules. Par exemple :

5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
Pour aboutir vous formerez des groupes de 2 étudiants. L’utilisation de GIT par tous les membres du projet sera indispensable. L’évaluation portera sur les éléments suivants :

la réponse au besoin
la qualité du code
la robustesse du programme
la mise en oeuvre des concepts de POO
le niveau d’aboutissement
la maitrîse du programme par le groupe
Ce projet sera le fruit d’un travail limité aux membres d’un groupe. Toute tentative de plagiat, toute ressemblance entre les codes livrés, toute incapacité à décrire le programme et le code fourni seront sanctionnées.

Spécifications techniques
Implémenter votre programme de sorte à faire au maximum usage des concepts de la POO en C++. L’objectif n’est pas d’aboutir à un programme procédural. Le respect des principes SOLID sera déterminant, par exemple il s’agira d’appliquer les contraintes suivantes :
Le jeu, la grille et les cellules seront implémentés sous forme de classes.
L’état des cellules sera représenté à l’aide d’une hiérarchie de classes et exploitera le polymorphisme d’héritage.
Les règles de calcul de l’état d’une cellule, dont le comportement pourra être redéfini à l’avenir, seront implémentées dans une hiérarchie de classes indépendante.
Il faudra bien séparer les responsabilités : la partie visuelle (GUI) sera découplée de la partie logique métier (fonctionnement du jeu de la vie).
Lors de la phase de conception, modéliser votre programme avec les diagrammes suivants :
Diagramme de classes.
Diagramme d’activité.
Diagramme de séquence.
Développer votre programme en C++ standard.
S’appuyer sur la bibliothèque standard C++ STL.
Utilisation de la bibliothèque graphique SFML pour le développement de votre interface graphique.
Le programme doit être implémenté de manière efficace.
Spécifications fonctionnelles
L’utilisateur lance le programme et fournit le chemin du fichier contenant l’état initial des cellules en paramètre.
Le programme consomme le fichier avec le format précédemment décrit et génère l’ensemble des objets du programme (grille, cellules).
À chaque itération les cellules changent d’état selon les règles énoncées plus haut.
L’exécution se termine lorsque l’automate n’évolue plus ou après un nombre d’itération fixé arbitrairement.
Deux modes de fonctionnement seront implémentés :
Le premier, en mode console, fournira les états des n premières itérations de votre jeu de la vie. À chaque itération le programme écrit l’état des cellules dans un fichier selon le format décrit précédemment. Ces résultats sont stockés dans des dossiers nommés <nom_du_fichier_dentree>_out et utilisés pour correction.
Le second, en mode graphique, affiche la grille et l’état des cellules sur une interface graphique. Pour aboutir, vous disposez d’un exemple de code capable d’afficher une fenêtre graphique et une grille de cellules. Celui-ci devra être adapté en une version orientée objet. La simulation démarre au lancement du programme. La durée entre deux itérations est contrôlable.
L’application contiendra impérativement une ou plusieurs fonctions de tests unitaires capables de vérifier l’état de la grille après un nombre arbitraire d’itérations. Elle sera ainsi paramétrée par la grille attendue et un nombre d’itérations.
Extensions (points bonus)
Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes ; en d’autres termes les cellules en colonne 0 sont voisines des cellules en colonne N−1, avec N le nombre de colonnes. Le principe est similaire en ligne.
Introduction de cellules obstacles. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de base.
Placement de constructions pré-programmées sur la grille. Utilisez les touches du clavier pour intégrer de nouveaux motifs sur la grille lors de l’exécution.
Paralléliser la génération des cellules. Modifiez votre algorithme pour paralléliser le traitement requis pour mettre à jour l’état des cellules sur la grille.
