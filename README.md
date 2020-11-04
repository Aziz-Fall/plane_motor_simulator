# Similateur de fonctionnement d'un système carburant d'un avion

Le système carburant d'un avion alimente ses moteurs en carburant. Il est composé en général de plusieurs réservoirs, d'un système de pompes, de vannes et de tuyaux permettant d'acheminer le carburant aux moteurs. Comme tout système, le système carburant peut avoir des pannes, par exemple, la panne d'une pompe pendant le vol, un réservoir qui se vide, une vanne qui se bloque, etc. Pour assurer l'acheminement du carburant à tous les moteurs pendant le vol, il est possible de reconfigurer le système pour mettre en marche une pompe de secours ou alimenter un moteur par un autre réservoir. À tout moment pendant le vol, le pilote peut voir l'état du système carburant et agir sur ce dernier. Il peut notamment mettre en marche les pompes de secours, ouvrir ou fermer les vannes pour changer l'acheminement du carburant. Pour éviter les erreurs au cours d'un vol, le pilote a besoin de s'entraîner. Pour cela l'interface graphique ci-dessous a été conçu pour le pilote.

## Système de Carburant
Le système de carburant simplifié d'un avion de chasse est représenté sur la Figure ci-dessous. 
[Système de carburant](img/systemeDeCarburant.png)
Il est composé de 3 réservoirs indépendants: Tank1, Tank2, Tank3. Avec un fonctionnement normal du système, chaque réservoir alimente son moteur: Tank1 alimente le moteur M1, Tank2 alimente le moteur M2 et Tank3 alimente le moteur M3. Il faut noter que les réservoirs Tank1 et Tank3 ont une plus grande capacité que le réservoir Tank2. Le carburant est acheminé aux moteurs à l'aide d'un système de pompes. Pour chaque réservoir il existe 2 pompes, une pompe primaire et une pompe de secours. Dans le fonctionnement normal, les pompes de secours sont arrêtées.
Pendant le vol, des événements imprévus peuvent survenir. Nous pouvons considérer le cas d'un réservoir qui se vide ou le cas d'une pompe qui tombe en panne. Pour remédier à ses pannes deux systèmes de reconfigurations sont prévus:
    * Les trois réservoirs sont reliés par des tuyaux pour équilibrer le niveau de carburant dans chaque réservoir. Si les vannes   VT12 et VT23 sont fermées, le carburant peut circuler d'un réservoir à l'autre. Si l'un des réservoirs se vide, le pilote peut fermer les vannes VT12 et/ou VT23 pour remplir le réservoir vide avec le carburant provenant des autres réservoirs.

    * Chaque pompe peut alimenter n'importe lequel des trois moteurs. Chaque moteur a besoin d'une seule pompe pour être alimenté. Si l'une des pompes tombe en panne, le pilote peut démarrer la pompe secondaire. Si les 2 pompes sont en pannes, il est possible d'acheminer le carburant au moteur depuis un autre réservoir. Il suffit que le pilote démarre la pompe secondaire et ferme la vanne correspondante (V13, V12 ou V23).
## Tableau de bord du pilote
[Interface de connection](img/connexion.png)
    * L'interface de connection permet d'identifier le pilote par son ID et son mot de passe.
[Tableau de bord](img/tableauDeBord.png)
    Le tableau de bord est composée de deux parties:
        * une partie qui affiche l'état du système
        * et une partie pour inter-agir avec le pilote.
    La partie d'interaction est composée de trois colonnes, chaque colonne est constituée:
        - un bouton `VT` qui permet d'équiliber le carburant entre deux réservoir, 
        - un bouton `V` qui permet vider le carburant d'un réservoir à un autre.
        - Une barre de progression représentant le niveau du carburant, 
        - un bouton `Draining` qui vide le reservoir 
        - et un bouton `B_P` qui permet de mettre les pompes de secours en pannes.
    * les boutons `VT`, `V`, `B_P` sont suivis par le numéro des réservoirs qu'ils relient.

## Fonctionalités
Le pilote peut effectuer les actions suivantes :
    * ouverture et fermeture des vannes;
    * démarrage et arrêt des pompes.
    * déclencher une panne des pompes;
    * vider des réservoirs.

## Execution
Pour utiliser le projet il faut juste avoir Qt creator, cloner le projet, compliler le projet avec qmake et appuyer sur le bouton d'exécution. Qt creator [Lien d'installation de Qt créator](https://www.qt.io/download) necessite de paramétrage selon le système d'exploitation utilisé.