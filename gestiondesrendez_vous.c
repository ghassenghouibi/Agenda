#include "projet.h"

/** 
    * \fn new_rendez_vous (char* titre,char* lieu, char* jour,char* mois,char* annee, char* heuredebut,char* heurefin)
    * \brief fonction qui cree un rendez_vous grace au information passé en paramètre 
    * \param titre char* 
    * \param lieu char* 
    * \param jour char*
    * \param mois char*
    * \param annee char*
    * \param heuredebut*
    * \param heurefin*
    * \return nouveau de type Rendez_vous           \
 */
Rendez_vous* new_rendez_vous(char *titre,char *lieu,char *jour,char *mois,char *annee,char *heuredebut ,char *heurefin,int type){
   
   Rendez_vous *nouveau;
   nouveau=(Rendez_vous*)malloc(sizeof(Rendez_vous));
   nouveau->titre=malloc(256*sizeof(char));
   nouveau->lieu=malloc(256*sizeof(char));
   nouveau->jour=malloc(256*sizeof(char));
   nouveau->mois=malloc(256*sizeof(char));
   nouveau->annee=malloc(256*sizeof(char));
   nouveau->heuredebut=malloc(256*sizeof(char));
   nouveau->heurefin=malloc(256*sizeof(char));
   assert(nouveau);
   strcpy(nouveau->titre,titre);
   strcpy(nouveau->lieu,lieu);
   strcpy(nouveau->jour,jour);
   strcpy(nouveau->mois,mois);
   strcpy(nouveau->annee,annee);
   strcpy(nouveau->heuredebut,heuredebut);
   strcpy(nouveau->heurefin,heurefin);
   nouveau->type=type;
   nouveau->suivant=NULL;

   return nouveau;
}
/** 
    * \fn ajout_rendez_vous(Rendez_vous **chaine,Rendez_vous *m)
    * \brief fonction qui ajoute le rendez_vous la la liste chainée entête
    * \param **chaine type Rendez_vous 
    * \param *m type Rendez_vous 

 */
void ajout_rendez_vous(Rendez_vous **chaine,Rendez_vous *m){
    
    m->suivant=*chaine;
    *chaine=m;

}
/** 
    * \fn rechercheRendez_vous(Rendez_vous *contact)
    * \brief fonction qui recherche un rendez_vous par titre ou lieu ou jour ou mois
    * ou année et liste les rendez_vous 
    * \param *contact type Rendez_vous 
 */
void rechercheRendez_vous(Rendez_vous *contact){
   	Rendez_vous *courant;
   	char Prompt[TAILLE];
   	int choix;   
   	printf("On vous donne les rendez_vous par quoi \n1->titre\n2->lieu\n3->jour\n4->mois\n5->année\n?");
   	scanf("%d",&choix);
    printf("vous cherchez quel nom de rendez vous svp ? \n");
	  scanf("%s",Prompt);
   	printf("Vos Rendez_vous \n");
   	couleur("45");
   	for(courant=contact;courant!=NULL;courant=courant->suivant){
   		if(strcmp(courant->titre,Prompt)==0&& choix==1){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);
		
  		}
  		else if(strcmp(courant->lieu,Prompt)==0&& choix==2){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

  		}
  		else if(strcmp(courant->jour,Prompt)==0&& choix==3){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

  		}
  		else if(strcmp(courant->mois,Prompt)==0&& choix==4){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

  		}
  		else if(strcmp(courant->annee,Prompt)==0&& choix==5){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

  		}
   }
   couleur("0");

}
/** 
    * \fn Afficherendez_vous(Rendez_vous *contact)
    * \brief fonction qui affiche tous les rendez_vous ou aussi on peut afficher que les rendez_vous Personel
    * ou Professionel ou Famillial
    * \param *contact type Rendez_vous 
 */
void Afficherendezvous(Rendez_vous *contact){
   Rendez_vous *courant;
   int reponse1,reponse2;
   printf("Vous voulez afficher tous les rendez_vous ?\n1->Oui\n2->Non\n");
   scanf("%d",&reponse1);
   if(contact==NULL)
    printf("Désolé vous avez pas de rendez vous \n");
   else{
   if(reponse1==2){
   		printf("Vous voulez afficher les rendez_vous\n1->Personel\n2->Famillial\n3->Professionel\n");
   		scanf("%d",&reponse2);
   		if(reponse2==1){
   			printf("Vos Rendez_vous Personel\n");
   			for(courant=contact;courant!=NULL;courant=courant->suivant){
   				if(courant->type==1){
		     printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

		 		}
   			}
   		}
   		else if(reponse2==2){
   			printf("Vos Rendez_vous Famillial \n");
   			for(courant=contact;courant!=NULL;courant=courant->suivant){
   				if(courant->type==2){
		      printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

		  		}
   			}
   		
   		}
   		else if(reponse2==3){
   			printf("Vos Rendez_vous Professionel\n");
   			for(courant=contact;courant!=NULL;courant=courant->suivant){
   				if(courant->type==3){
		     printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

		  		}
   			}
   		}
    }
   else{
   for(courant=contact;courant!=NULL;courant=courant->suivant){
     printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

   		}
	}
  }
}
/** 
    * \fn Ajoutrendez_vous(Rendez_vous **L)
    * \brief fonction ajoute un rendez_vous a nos rendez_vous précedent avec l'acces au deux fonction
    * qui vont nous aidez a realiser ça ajout_rendez et new_rendez_vous et dans le corps de notre 
    * fonction on trouve la demande au utilisateur avec les scanf 
    * \param **L type Rendez_vous 
 */
void Ajoutrendezvous (Rendez_vous **L){
   
  char titre[TAILLE],lieu[TAILLE],jour[TAILLE],mois[TAILLE],annee[TAILLE],heuredebut[TAILLE],heurefin[TAILLE];
  int type,quitter;

  do{
    printf("-------\n");
    printf("titre: \n");
    scanf("%s",titre);
    printf("lieu: \n");
    scanf("%s",lieu);
    printf("jour ");
    scanf("%s",jour);
    printf("mois  ");
    scanf("%s",mois);
    printf("annee ");
    scanf("%s",annee);
    printf("heuredebut\n");
    scanf("%s",heuredebut);
    printf("heurefin?\n");
    scanf("%s",heurefin);
    printf("Type de rendez_vous ? \n1->Personel\n2->Famillial\n3->Professionel\n");
    scanf("%d",&type);
    ajout_rendez_vous(L,(new_rendez_vous(titre,lieu,jour,mois,annee,heuredebut,heurefin,type)));
    s_sleep(1);
    couleur("32");
    printf("Vos informations sont bien prises en compte\n");
    couleur("0");
    printf("vous voulez inscrire encore \n|1->Oui\n|0->Non\n");
    scanf("%d",&quitter);
  }while(quitter!=0);
}




/*-------Dyhia---------*/
void trierRendezvous(Rendez_vous *contact){
   Rendez_vous *courant;
   int choix;
   char Prompt[235];
     printf("On vous donne les rendez_vous par quoi ?\n1->heure\n2->jour\n3->lesplusrecent\n");
     scanf("%d",&choix);
     if(choix==1){
     printf("vous cherchez les rendez_vous qui commencent a quelle heure? \n");
     scanf("%s",Prompt);
     }
     if(choix==2){
       printf("vous cherchez les rendez_vous de quel jour? \n");
       scanf("%s",Prompt);
     }
  
     printf("Vos Rendez_vous \n");
     for(courant=contact;courant!=NULL;courant=courant->suivant){
   		if(strcmp(courant->heuredebut,Prompt)==0&& choix==1){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);
	   
  		}
  		else if(strcmp(courant->jour,Prompt)==0&& choix==2){
			printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);

  		}
		 else{
		   if(choix==3){
		   	for(courant=contact;courant!=NULL;courant=courant->suivant){
		     printf("|%s à %s le %s/%s/%s de %s jusqu'à %s|\n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin);
		   }
		   }
		 }
     }
     }


/*------------------Doesn't WORK-----------------*/
void trierrendezvous(Rendez_vous *l){
	Rendez_vous* courant;
	Rendez_vous* swap;
	Rendez_vous* save=l->suivant;
	for(courant=l;courant->suivant!=NULL && save->suivant!=NULL;courant=courant->suivant){
		for(courant=l;courant->suivant!=NULL && save->suivant!=NULL;courant=courant->suivant){
			if (courant->titre>save->titre){
				printf("%s %s \n",courant->titre,save->titre);
				swap=courant;
				courant=save;
				save=swap;
			}
		}
	}
}
/*----Mehdi-----*/
void supprimerrendezvous(Rendez_vous *l){
    int choix;

    printf("vous voulez supprimer les rendez_vous par quoi \n1->titre\n2->lieu\n3->jour\n4->mois\n5->année\n?");
    scanf("%d",&choix);
    
       switch(choix){
            case 1:
            supprimer1(l);
                
                break;
            case 2:
            supprimer2(l);
            
                break;
            case 3:
            supprimer3(l);
                
                break;
            case 4:
            supprimer4(l);
                
                break;
            case 5:
            supprimer5(l);
             
                break;
                

            default:
                printf("choix invalide \n");
                break;
        }
    
        
}

void supprimer1(Rendez_vous *l){
    Rendez_vous *courant;
    char Prompt[235];
 	printf("le nom du rendez_vous a supprimer svp ? \n");
    scanf("%s",Prompt);
    if(l->suivant==NULL)
      free(l);

 
    else{
       	
        Rendez_vous *save=l;
        Rendez_vous *save2=l->suivant;
        int x=0;
        int y=0;
        for(courant=l;courant!=NULL && y==0 && save2!=NULL;courant=courant->suivant){
            
            if(strcmp(courant->titre,Prompt)==0){
                if (courant==l){
                    save=courant->suivant;
                    l=save;
                    free(courant);
                }else{
                save->suivant=save2;
                free(courant);
                y=1;
                }

            }
            x++;
            if(x>=2)
                save=save->suivant;
            if(save2->suivant!=NULL) 
            	save2=save2->suivant;
        }
    }
    
}


void supprimer2(Rendez_vous *l){
    Rendez_vous *courant;
    char Prompt[235];
    if(l->suivant==NULL)
      free(l);
    else{
        printf("le lieu du rendez_vous a supprimer svp ? \n");
        scanf("%s",Prompt);
               
        Rendez_vous *save=l;
        Rendez_vous *save2=l->suivant;
        int x=0;
        int y=0;
        for(courant=l;courant!=NULL && y==0 && save2!=NULL;courant=courant->suivant){
            
            if(strcmp(courant->lieu,Prompt)==0){
                save->suivant=save2;
                free(courant);
                y=1;

            }
            x++;
            if(x>=2)
                save=save->suivant;

            save2=save2->suivant;
        }
    }
    
}

void supprimer3(Rendez_vous *l){
    Rendez_vous *courant;
    char Prompt[235];
 

    if(l->suivant==NULL)
      free(l);

    else{
        printf("le jour du rendez_vous a supprimer svp ? \n");
        scanf("%s",Prompt);
               
        Rendez_vous *save=l;
        Rendez_vous *save2=l->suivant;
        int x=0;
        int y=0;
        for(courant=l;courant!=NULL && y==0 && save2!=NULL;courant=courant->suivant){
            
            if(strcmp(courant->jour,Prompt)==0){
                save->suivant=save2;
                free(courant);
                y=1;

            }
            x++;
            if(x>=2)
                save=save->suivant;

            save2=save2->suivant;
        }
    }
    
}


void supprimer4(Rendez_vous *l){
    Rendez_vous *courant;
    char Prompt[235];
 

    if(l->suivant==NULL)
      free(l);

    else{
        printf("le mois du rendez_vous a supprimer svp ? \n");
        scanf("%s",Prompt);
               
        Rendez_vous *save=l;
        Rendez_vous *save2=l->suivant;
        int x=0;
        int y=0;
        for(courant=l;courant!=NULL && y==0 && save2!=NULL;courant=courant->suivant){
            
            if(strcmp(courant->mois,Prompt)==0){
                save->suivant=save2;
                free(courant);
                y=1;

            }
            x++;
            if(x>=2)
                save=save->suivant;

            save2=save2->suivant;
        }
    }
    
}

void supprimer5(Rendez_vous *l){
    Rendez_vous *courant;
    char Prompt[235];
 

    if(l->suivant==NULL)
      free(l);

    else{
        printf("l'anne du rendez_vous a supprimer svp ? \n");
        scanf("%s",Prompt);
               
        Rendez_vous *save=l;
        Rendez_vous *save2=l->suivant;
        int x=0;
        int y=0;
        for(courant=l;courant!=NULL && y==0 && save2!=NULL;courant=courant->suivant){
            
            if(strcmp(courant->annee,Prompt)==0){
                save->suivant=save2;
                free(courant);
                y=1;

            }
            x++;
            if(x>=2)
                save=save->suivant;

            save2=save2->suivant;
        }
    }
    
}
