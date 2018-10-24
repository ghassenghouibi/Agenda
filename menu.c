#include "projet.h"

/** 
    * \fn void Agenda()
    * \brief fonction qui presente le menu du programme qui comporte toute les fonctions 
    * ajouter,afficher,rechercher,supprimer et trier des rendez_vous
*/
void Agenda(){
	int choix;
	Rendez_vous *L=NULL;
	L=recuperer();
	do{
    	
		printf("______________________________________________\n");
		printf("|___________________Agenda___________________|\n");
		printf("|_________________0->About___________________|\n");
		printf("|_________________1->AjoutRendez_vous________|\n");
		printf("|_________________2->AfficheRendez_vous______|\n");
		printf("|_________________3->Rechercherendez_vous____|\n");
		printf("|_________________4->SupprimerRendez_vous____|\n");
		printf("|_________________5->TrierRendez_vous________|\n");
		printf("|_________________6->Quitter_________________|\n");
		printf("|____________________________________________|\n");
		
		printf("choissiez \n");
		scanf("%d",&choix);
		switch(choix){
			case 0:
				couleur("33");
				printf("\n\nC'est un agenda vous pouvez creer un rendez_vous l'ajouter a votre liste\n\nsupprimer  et aussi trier vos rendez vos rendez_vous sans à la fin recuperer dans un fichier et au lancement du programme \non recuperer tous ces rendez_vous vous allez naviger dans les options de menu faire des modifications etc ...\n et apres votre ancien fichier sera ecrasé et on va recreer un autre c à dire vos données sont tous le temps mis à jour  \npeut être dans le future on va améliorer et faire des envoies mail\nou peut etre faire du cryptage \nMerci !!!\n");
				couleur("0");
				break;
			case 1:
				Ajoutrendezvous(&L);
				break;
			case 2:
				Afficherendezvous(L);
				break;
			case 3:
				rechercheRendez_vous(L);
				break;
			case 4:
				supprimerrendezvous(L);
				break;
			case 5:
				trierRendezvous(L);
				break;
			case 6:
				couleur("31");
				printf("Deconnexion en cours ##### \n");
        		couleur("0");
        		enregister(L);
        		s_sleep(2);
				printf("Bye Bye \n");
				exit(EXIT_SUCCESS);
				break;

			default:
				printf("Sorry i did'nt understood your choice \n");
				break;
		}
	}while (choix!=6);
}