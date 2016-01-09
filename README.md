# VaisseauAsteroide

L'arborescenece du Rendu est la suivante 

Moulayeely Yezide:
		src: les fichiers .cpp
		include: les fichiers .h
		doc: repport + readme + digramme UML
		VaisseauAsteroide : c'est le projet Visual Studio (netoyé) , sans les .exe ni les .obj


Pour lancer le projet il vous faut inclure le dossier libWin dansl le dossier VaisseauAsteroide:
			VaisseauAsteroide:
			-----------------------libWin/
			-----------------------include/
Ensuite il suffit d’importer  le projet “VaisseauAsteroide“ puis le lancez. 
NB : vérifiez que vous êtes en mode release avant de lancer le projet. 

le dossier libWin/ j'ai pas pu l'envoyer par mail car il contient des fichiers avec des extension non autorisées a être envoyer par mail ;
(engine.lib, glut32.lib).

Le projet VaisseauAseroide contient tous les fichiers nécessaire pour lancer le projet:
		include/ : pour importer les fichiers Engine,GraphicEngin,.....
		libWin/ : pour importer la bibliothèque
		Release/ : contient que le fichier glut32.dll (pas de .exe)
		VaisseauAsteroide/ : les fichiers du code
		VaisseauAsteroide.sln : c'est le fichier projet qui sera importer

vous n'etes pas obligé de refaire la config du projet (include et la bibliothèque), il suffit juste juste de rajouter le dossier libWin/ "contenant les fichiers / glut32.lib ,engine.lib , glut32.dll etc..." dans le dossier projet
