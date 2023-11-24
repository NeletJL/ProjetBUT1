#include <stdio.h>
#include <stdlib.h>
#include "biblioNavale.c"

int main(int argc, char const *argv[]) {
	srand(time(NULL));				/*srand permet de rendre aléatoire le placement des bateaux.*/
	char joueur1[10][10];			/*variable qui détermine le joueur 1.*/
	char joueur2[10][10];			/*variable qui détermine le joueur 2.*/

	printf("Joueur 1 :\n");
	initPlateau(joueur1);			/*Fonction permettant d'initialiser le plateau du joueur 1 de maniere aléatoire ou a la main.*/

	printf("Joueur 2 :\n");
	initPlateau(joueur2);			/*Fonction permettant d'initialiser le plateau du joueur 2 de maniere aléatoire ou a la main.*/
	
	if(verif(joueur1)==0 || verif(joueur2)==0) {
		return 1;
		}			/*Permet de vérifier s'il y a tout les navires sur chaque plateau, s'il n'y a pas 17 cases contenant un caractere different de l'espace, alors le programme s'arrête.*/

	afficheduo(joueur1,joueur2);			/*Fonction qui permet d'afficher côte à côte les grilles de bataille navale du joueur1 et du joueur2.*/

	printf("Le joueur 1 joue.\n");
	int TourDuJoueur=0; 			/*On détermine le tour du joueur, soit le joueur1 soit le joueur2*/
	int compteurJ1=0, compteurJ2=0;				/*Compteur qui compte le nombre de coup touché, s'il atteint 17 alors le joueur du compteur associé l'emporte.*/
	int compteurA1=0, compteurC1=0, compteurS1=0, compteurM1=0, compteurT1=0;			/*Compteur qui compte si un bateau est coulé ou non, pour le joueur1 qui joue le plateau 2.*/
	int compteurA2=0, compteurC2=0, compteurS2=0, compteurM2=0, compteurT2=0;			/*Compteur qui compte si un bateau est coulé ou non, pour le joueur2 qui joue le plateau 1.*/
	while (compteurJ1<17 || compteurJ2<17) {			/*On continue le programme tant que le compteur de victoire n'arrive pas à 17, c'est-à-dire tant qu'aucun des joueurs n'a gagné.*/
		if (TourDuJoueur==0) {				/*Si TourDuJoueur = 0, alors le joueur 1 joue*/
			int J1=jouerJoueur(joueur2);			/*On stocke le résultat de la variable jouerJoueur dans J1*/
	
		if (J1==-1) {			/*Si le coup joué par le joueur1 est raté, alors on entre dans cette condition*/
			printf("A l'eau !\n");
			afficheduo(joueur1,joueur2);
			printf("Le joueur 2 joue.\n");
			TourDuJoueur=1;				/*Le coup est raté donc on donne la main au joueur2.*/
		}
		if (J1==0 || J1==1 || J1==2 || J1==3 || J1==4) {			/*Si le coup joué par le joueur1 est réussi, alors on entre dans cette condition*/
			if (J1==0) {			/*Si le coup touche le Porte-Avion, on entre dans cette condition.*/
				compteurA1++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Porte-Avion est touchée.*/
				if (compteurA1==5) {			/*Lorsque les cinq cases du Porte-Avion sont touchées alors la condition pour afficher que le Porte-Avion est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(0));
				}
			}
			if (J1==1) {			/*Si le coup touche le Croiseur, on entre dans cette condition.*/
				compteurC1++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Croiseur est touchée.*/
				if (compteurC1==4) {			/*Lorsque les quatre cases du Croiseur sont touchées alors la condition pour afficher que le Croiseur est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(1));
				}
			}
			if (J1==2) {			/*Si le coup touche le Sous-Marin, on entre dans cette condition.*/
				compteurS1++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Sous-Marin est touchée.*/
				if (compteurS1==3) {			/*Lorsque les trois cases du Sous-Marin sont touchées alors la condition pour afficher que le Sous-Marin est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(2));
				}
			}
			if (J1==3) {			/*Si le coup touche le Mous-Sarin, on entre dans cette condition.*/
				compteurM1++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Mous-Sarin est touchée.*/
				if (compteurM1==3) {			/*Lorsque les trois cases du Mous-Sarin sont touchées alors la condition pour afficher que le Mous-Sarin est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(3));
				}	
			}	
			if (J1==4) {			/*Si le coup touche le Torpilleur, on entre dans cette condition.*/
				compteurT1++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Torpilleur est touchée.*/
				if (compteurT1==2) {			/*Lorsque les deux cases du Torpilleur sont touchées alors la condition pour afficher que le Torpilleur est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(4));
				}
			}
			compteurJ1++;			/*On ajoute 1 au compteur à chaque fois qu'une case contenant un navire est touchée, au joueur1.*/
			printf("Touché !\n");
			afficheduo(joueur1,joueur2);
			if (compteurJ1==17) {			/*Condition qui permet de savoir lorsque le joueur1 remporte la victoire.*/
				printf("Le joueur 1 remporte la partie !\n");
				break;				/*On utilsie break pour finir la boucle et ainsi finir la partie car le joueur1 remporte la victoire.*/ 
			} else {
				printf("Le joueur 1 joue.\n");
			}
		}
		if (J1==-2 || J1==-3) {				/*Si le coup joué par le joueur1 n'est pas conforme ou hors plateau, alors on entre dans cette condition*/
			printf("Mauvais coup, rejouez.\n");
			afficheduo(joueur1,joueur2);
			printf("Le joueur 1 joue.\n");
		}
		}

		if (TourDuJoueur==1) {			/*Si TourDuJoueur = 1, alors le joueur 2 joue.*/
			int J2=jouerJoueur(joueur1);			/*On stocke le résultat de la variable jouerJoueur dans J2.*/
	
		if (J2==-1) {			/*Si le coup joué par le joueur2 est raté, alors on entre dans cette condition.*/		
			printf("A l'eau !\n");
			afficheduo(joueur1,joueur2);
			printf("Le joueur 1 joue.\n");
			TourDuJoueur=0;				/*Le coup est raté donc on donne la main au joueur1.*/
		}
		if (J2==0 || J2==1 || J2==2 || J2==3 || J2==4) {			/*Si le coup joué par le joueur1 est réussi, alors on entre dans cette condition*/
			if (J2==0) {			/*Si le coup touche le Porte-Avion, on entre dans cette condition.*/
				compteurA2++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Porte-Avion est touchée.*/
				if (compteurA2==5) {			/*Lorsque les deux cases du Porte-Avion sont touchées alors la condition pour afficher que le Porte-Avion est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(0));
				}
			}
			if (J2==1) {			/*Si le coup touche le Croiseur, on entre dans cette condition.*/
				compteurC2++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Croiseur est touchée.*/
				if (compteurC2==4) {			/*Lorsque les deux cases du Croiseur sont touchées alors la condition pour afficher que le Croiseur est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(1));
				}
			}
			if (J2==2) {			/*Si le coup touche le Sous-marin, on entre dans cette condition.*/
				compteurS2++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Sous-Marin est touchée.*/
				if (compteurS2==3) {			/*Lorsque les deux cases du Sous-Marin sont touchées alors la condition pour afficher que le Sous-Sarin est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(2));
				}
			}
			if (J2==3) {			/*Si le coup touche le Mous-Sarin, on entre dans cette condition.*/
				compteurM2++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Mous-Sarin est touchée.*/
				if (compteurM2==3) {			/*Lorsque les deux cases du Mous-Sarin sont touchées alors la condition pour afficher que le Mous-Sarin est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(3));
				}
			}
			if (J2==4) {			/*Si le coup touche le Torpilleur, on entre dans cette condition.*/
				compteurT2++;			/*On ajoute 1 au compteur à chaque fois qu'une case du Torpilleur est touchée.*/
				if (compteurT2==2) {			/*Lorsque les deux cases du Torpilleur sont touchées alors la condition pour afficher que le Torpilleur est coulé s'active.*/
					printf("Vous avez coulé le %s !\n", navire(4));
				}
			}
			compteurJ2++;			/*On ajoute 1 au compteur à chaque fois qu'une case contenant un navire est touchée, au joueur2.*/
			printf("Touché !\n");
			afficheduo(joueur1,joueur2);
			if (compteurJ2==17) {			/*Condition qui permet de savoir lorsque le joueur2 remporte la victoire.*/	
				printf("Le joueur 2 remporte la partie !\n");		
				break;				/*On utilsie break pour finir la boucle et ainsi finir la partie car le joueur1 remporte la victoire.*/ 
			} else {
			printf("Le joueur 2 joue.\n");
			}
		}
		if (J2==-2 || J2==-3) {				/*Si le coup joué par le joueur2 n'est pas conforme ou hors plateau, alors on entre dans cette condition*/
			printf("Mauvais coup, rejouez.\n");
			afficheduo(joueur1,joueur2);
			printf("Le joueur 2 joue.\n");
		}
	}
}
	return 0;
}
