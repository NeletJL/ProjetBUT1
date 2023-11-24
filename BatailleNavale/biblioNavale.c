#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ajoutNavireAleatoire (char tab[][10], char b, int t) {
	int compteur, ligne, colonne, max, verif, ligne_verif, colonne_verif, limite;
	int bateau_placable = 0;
	int horVer = rand() % 2;
	switch (horVer) {		/*Le switch traite si on place le bateau à l'horizontal ou à la vertical*/
		case 0:			/*Le case 0 traite le cas des bateau à l'horizontal*/
		switch (b) {		/*Traite le type du bateau pour avoir sa limite (la derniere case où il est possible de le placer)*/
			case 'A':
				limite = 6;
				break;
			case 'C':
				limite = 7;
				break;
			case 'S':
				limite = 8;
				break;
			case 'M':
				limite = 8;
				break;
			case 'T':
				limite = 9;
				break;
			}
			ligne = rand() % 10;		/*Choisi une ligne au hasard*/
			colonne = rand() % limite;		/*choisi une colonne au hasard en respectant les limites du bateau*/
			while (bateau_placable == 0) {		/*Boucle qui permet de savoir si le bateau a été placé ou non*/
				for (verif = 0; verif < t; verif++) {		/*Boucle qui vérifie la condition ci-dessous*/
					colonne_verif = colonne + verif;		/*Permet de tester chacunes des colonnes pour placer le bateau*/
					if (tab[ligne][colonne_verif] == ' ') {			/*Confition qui vérifie s'il y'a bien un espace*/		
						bateau_placable = 1; 
					} else {		/*S'il n'y a pas d'espace alors on refait un tirage et on recommence*/
						ligne = rand() % 10;
						colonne = rand() % limite;
						bateau_placable = 0;
						break;			/*Utilisation du break car inutile de tester les autres cas s'il n'y'a d'espaces*/
					}
				}
			}
			max = colonne+t;		/*permet d'avoir la taille du bateau et ainsi placer le bon nombre de lettres*/
			for (compteur = colonne; compteur < max; compteur++) {
				tab[ligne][compteur] = b;		/*Permet de placer les lettres qui constituent le bateau*/
			}
			break;
		case 1:			/*le case 1 traite le cas des bateau à la vertical*/
		switch (b) {
			case 'A':
				limite = 6;
				break;
			case 'C':
				limite = 7;
				break;
			case 'S':
				limite = 8;
				break;
			case 'M':
				limite = 8;
				break;
			case 'T':
				limite = 9;
				break;
			}
			ligne = rand() % limite;			/*choisi une ligne au hasard en respectant les limites du bateau*/
			colonne = rand() % 10;			/*Choisi une colonne au hasard*/
			while (bateau_placable == 0) {		/*Boucle qui permet de savoir si le bateau a été placé ou non*/
				for (verif = 0; verif < t; verif++) {		/*Boucle qui vérifie la condition ci-dessous*/
					ligne_verif = ligne + verif;		/*Permet de tester chacunes des colonnes pour placer le bateau*/
					if (tab[ligne_verif][colonne] == ' ') {			/*Confition qui vérifie s'il y'a bien un espace*/	
						bateau_placable = 1; 
					} else {			/*S'il n'y a pas d'espace alors on refait un tirage et on recommence*/
						ligne = rand() % limite;
						colonne = rand() % 10;
						bateau_placable = 0;
						break;			/*Utilisation du break car inutile de tester les autres cas s'il n'y'a d'espaces*/
					}
				}
			}
			max = ligne+t;			/*permet d'avoir la taille du bateau et ainsi placer le bon nombre de lettres*/
			for (compteur = ligne; compteur < max; compteur++) {
				tab[compteur][colonne] = b;			/*Permet de placer les lettres qui constituent le bateau*/
			}
		break;
	}
}


int verif (char tab[][10]) {
	int ligne, colonne;
	int resultat = 0;
	int bordure = 10;		/*Taille du plateau*/
	for (ligne = 0; ligne < bordure; ligne++) {
		for (colonne = 0; colonne <bordure; colonne++) {
			if (tab[ligne][colonne] != ' ') {		/*Compte le nombre de caractères différent d'espace*/
				resultat++;
			}
		}
	} 
	if (resultat == 17) {		/*Lorsque resultat atteint 17, la fonction retourne 1 et signifie que tout les bateaux sont placés*/
		return 1;
	} else {
		return 0;
	}
}


void affiche (char t[][10]) {
	int chiffre, ligne, colonne;
	int bordure = 10;		/*Taille du plateau*/
	printf("_|");
	for (chiffre = 0; chiffre < bordure; chiffre++) {		/*Boucle qui affiche les chiffres de la première ligne*/
		printf("%d|", chiffre);
	}
	printf("\n");
	for (ligne = 0; ligne < bordure; ligne++) {			/*Boucle qui affiche les lettres de la première colonne*/
	printf("%c|", 'A' + ligne);
		for (colonne = 0; colonne < bordure; colonne++) {		/*Boucle qui affiche les navires lorsqu'ils sont placés*/
			printf("%c|", t[ligne][colonne]);
		}
		printf("\n");
	}
	printf("\n");
}


void afficheduo (char t[][10], char p[][10]) {
	int chiffre, ligne, colonne;
	int bordure = 10;
	printf("_|");
	for (chiffre = 0; chiffre < bordure; chiffre++) {		/*Boucle qui affiche les chiffres de la première ligne du joueur 1*/
		printf("%d|", chiffre);
	}
	printf("		");
	printf("_|");
	for (chiffre = 0; chiffre < bordure; chiffre++) {		/*Boucle qui affiche les chiffres de la première ligne du joueur 2*/
		printf("%d|", chiffre);
	}
	printf("\n");
	for (ligne = 0; ligne < bordure; ligne++) {			/*Boucle qui affiche le plateau du joueur 2*/
		printf("%c|", 'A' + ligne);
		for (colonne = 0; colonne < bordure; colonne++ ) {
			if (t[ligne][colonne] == 'X') {			/*Si dans le tableau se trouve un 'X' alors affiche le 'X'*/
				printf("X|");
			} else {
				if (t[ligne][colonne] == '.') {			/*Si dans le tableau se trouve un '.' alors affiche le '.'*/
					printf(".|");
				} else {		/*S'il n'y'a rien alors affiche un espace*/
					printf(" |");
				}
			} 
		}
		printf("		");
		printf("%c|", 'A' + ligne);
		for (colonne = 0; colonne < bordure; colonne++) {		/*Boucle qui affiche le plateau du joueur 2*/
				if (p[ligne][colonne] == 'X') {			/*Si dans le tableau se trouve un 'X' alors affiche le 'X'*/
				printf("X|");
			} else {
				if (p[ligne][colonne] == '.') {			/*Si dans le tableau se trouve un '.' alors affiche le '.'*/
					printf(".|");
				} else {		/*S'il n'y'a rien alors affiche un espace*/
					printf(" |");
				}
			} 
		}
		printf("\n");
	}
	printf("\n");
}


void initPlateau (char plat[][10]) {
	int bordure = 10;		/*Taille de plateau*/
	char choix[100];		/*Tableau qui conserve le choix du joueur en manuel ou aléatoire*/
	int ligne, colonne;
	for (ligne = 0; ligne < bordure; ligne++) {			/*Création du plateau en le mettant a vide*/
		for (colonne = 0; colonne < bordure; colonne++ ) {
			plat[ligne][colonne] = ' ';
		}
	}
	while (choix[0] != 'A' || choix[0] != 'M') {		/*redemmande a l'utilisateur s'il n'y a pas M ou A*/
		printf("Souhaitez-vous placez vos navires à la (M)ain ou (A)léatoirement ?\n");
		scanf("\n%s", &choix);
		if (choix[0] == 'M') {
			printf("Vous devez placer vos navires.\nPour chaque navire, indiquez horizontal (h) ou vertical (v), suivi de la case la plus au nord-ouest (ex : h,E4).\n");
			char tabChar[5] = {'A', 'C', 'S', 'M', 'T'};		/*Tableau contenant les lettres correnspondantes aux bateaux*/
			int tabInt[5] = {5, 4, 3, 3, 2};		/*Tableaux correspondant à la taille des bateaux*/
			char poubelle[100] = {'\n'};		/*Création de la variable poubelle afin de de ne prendre en compte que les valeurs lettre et chiffre afin de ne pas altérer le jeu*/
			for (int i = 0; i < 5; i++) {		/*Boucle qui permet de placer les 5 bateaux*/
				affiche(plat);
				char lettre, horVer;
				int chiffre, lettre_entier;
				printf("Placer votre %c (longueur %d) :\n", tabChar[i], tabInt[i]);
				scanf ("\n%c,%c%d%c", &horVer, &lettre, &chiffre, &poubelle);
				lettre_entier = lettre - 65;		/*Permet de convertir la lettre en un chiffre*/
				int verif, taille, valeur, valeur_test, max, compteur, taille_verif, erreur, valeur_verif;
				switch (tabChar[i]) {			/*Switch qui permet de definir la taille du bateau en fonction du bateau à placer*/
					case 'A':
						taille = 5;
						break;
					case 'C':
						taille = 4;
						break;
					case 'S':
						taille = 3;
						break;
					case 'M':
						taille = 3;
						break;
					case 'T':
						taille = 2;	
						break;
				}
				do {		
					while ((lettre_entier < 0 || lettre_entier > 9) || (chiffre < 0 || chiffre >9) || (poubelle[0] != '\n')) {			/*Redemande a l'utilisateur les coordonnées du bateau si celles-ci n'étaient pas bonnes*/
						printf("Navire sort des limites du plateau.\n");
						affiche(plat);
						printf("Placer votre %c (longueur %d) :\n", tabChar[i], tabInt[i]);
						scanf ("\n%c,%c%d%c", &horVer, &lettre, &chiffre, &poubelle);
						lettre_entier = lettre - 65;
					}
					switch (horVer) {		/*Défini la valeur qui change selon si c'est vertical ou horizontal*/
						case 'h':
							valeur = chiffre;
							break;
						case 'v':
							valeur = lettre_entier;
							break;
					}
					taille_verif = 11 - valeur;			/*Défini la colonne maximale sur laquel peut se placer le bateau pour ne pas dépasser des limites du plateau*/
					erreur = 0;			/*Défini une variable à 0 qui permet de rester ou non dans une boucle*/
					if (taille_verif > taille) {			/*Vérifie que le bateau peut bien être placé dans le plateau*/
						for (verif = 0; verif < taille; verif++) {			/*Boucle qui test chacune des cases pour placer le bateau*/
							valeur_verif = valeur + verif;			
							switch (horVer) {			/*Défini la case que l'on teste selon si c'est vertical ou horizontal*/
								case 'h':
									valeur_test = plat[lettre_entier][valeur_verif];
									break;
								case 'v':
									valeur_test = plat[valeur_verif][chiffre];
									break;
							}
							if (valeur_test != ' ') {			/*Condition qui vérifie si il y a ou non un espace, si non alors redemande des coordonnées et retest*/
								printf("Navire empiète sur un autre navire.\n");
								affiche(plat);
								printf("Placer votre %c (longueur %d) :\n", tabChar[i], tabInt[i]);
								scanf ("\n%c,%c%d%c", &horVer, &lettre, &chiffre, &poubelle);
								lettre_entier = lettre - 65;
								erreur++;			/*Il y a une erreur donc on ajoute +1 pour replacer le bateau*/
								break;			/*Utilisation du break car inutile de tester les autres cas s'il n'y'a d'espaces*/
							}
						}
					} else {			/*Si le bateau ne peut pas être placé sur le plateau redemande à l'utilisateur des coordonées*/
						printf("Nous ne comprennons pas. Pour chaque navire indiquez horizontal (h) ou vertical (v).\n");
						affiche(plat);
						printf("Placer votre %c (longueur %d) :\n", tabChar[i], tabInt[i]);
						scanf ("\n%c,%c%d%c", &horVer, &lettre, &chiffre, &poubelle);
						lettre_entier = lettre - 65;
						erreur++;			/*Il y a une erreur donc on ajoute +1 pour replacer le bateau*/
					}
				} while (erreur > 0);			/*Exécute la boucle si dessous tant qu'il y une erreur dans le plaçage*/
				max = valeur + taille;			/*permet d'avoir la taille du bateau et ainsi placer le bon nombre de lettres*/
				for (compteur = valeur; compteur < max; compteur++) {
					switch (horVer) {
						case 'h':
							plat[lettre_entier][compteur] = tabChar[i];			/*Permet de placer les lettres qui constituent le bateau pour un bateau à l'horizontal*/
							break;
						case 'v':
							plat[compteur][chiffre] = tabChar[i];			/*Permet de placer les lettres qui constituent le bateau pour un bateau à la vertical*/
							break;
					}
				}
			}
			break;			/*Quitte la boucle du choix*/
		}
		if (choix[0] == 'A') {
			while (verif(plat) != 1) {		/*tant que ajoutNavireAleatoire n'a pas placé les 17 cases qui constituent les 5 bateaux alors on relance une éxécution*/
				ajoutNavireAleatoire (plat, 'A', 5);
				ajoutNavireAleatoire (plat, 'C', 4);
				ajoutNavireAleatoire (plat, 'S', 3);
				ajoutNavireAleatoire (plat, 'M', 3);
				ajoutNavireAleatoire (plat, 'T', 2);
			}
			break;		/*Quitte la boucle du choix*/
		}
	}
}


int jouerJoueur (char adv[][10]) {
	int resultat = -2;
	char poubelle[100] = {'\n'};		/*Création de la variable poubelle afin de de ne prendre en compte que les valeurs lettre et chiffre afin de ne pas altérer le jeu*/
	char lettre;
	int chiffre, lettre_entier;
	scanf ("\n%c%d%c", &lettre, &chiffre, &poubelle);
	lettre_entier = lettre - 65;
	if ((lettre_entier < 0 || lettre_entier > 9) || (chiffre < 0 || chiffre >9) || (poubelle[0] != '\n')) {			/*si le if n'est pas respecté alors les coordonnées sont du bon format*/
		resultat = -3;
	} else {
		switch (adv[lettre_entier][chiffre]) {			/*Le switch renvoie la variable résultat selon si un bateau a été touché ou non*/
			case ' ':		/*renvoie -1 car aucun bateau n'a été touché*/
				adv[lettre_entier][chiffre] = '.';
				resultat = -1;
				break;
			case 'A':		/*renvoie 0 si le porte-avion a été touché*/
				adv[lettre_entier][chiffre] = 'X';
				resultat = 0;
				break;
			case 'C':		/*renvoie 1 si le croiseur a été touché*/
				adv[lettre_entier][chiffre] = 'X';
				resultat = 1;
				break;
			case 'S':		/*renvoie 2 si le sous-marin a été touché*/
				adv[lettre_entier][chiffre] = 'X';
				resultat = 2;
				break;
			case 'M':		/*renvoie 3 si le mous-sarin a été touché*/
				adv[lettre_entier][chiffre] = 'X';
				resultat = 3;
				break;
			case 'T':		/*renvoie 4 si le torpilleur a été touché*/
				adv[lettre_entier][chiffre] = 'X';
				resultat = 4;
				break;
			default :		/*renvoie -2 car les caractères n'ont pas été reconnu */
				resultat = -2;
				break;
		}
	}
	return resultat;
}


char* navire (int i) {
	char* Navire;
	switch (i) {
		case 0:
			Navire = "Porte-Avion";
			break;
		case 1:
			Navire = "Croiseur";
			break;
		case 2:
			Navire = "Sous-Marin";
			break;
		case 3:
			Navire = "Mous-Sarin";
			break;
		case 4:
			Navire = "Torpilleur";
			break;
	}
	return Navire;
}
