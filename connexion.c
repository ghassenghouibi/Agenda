#include "projet.h"
/*-----------------------------------------------------------*/
/** 
    * \fn void init_user(Creationdecompte* utilisateur)
    * \brief fonction qui permet la creation d'un compte avec un motdepasse et un login
    * \param utilisateur de type Creationdecompte
 */
void init_user(Creationdecompte* utilisateur){

   FILE *compte = NULL;
   char login[TAILLE];
   char motdepasse[TAILLE];
   char chaine[145]="fichierde";
   couleur("35");
   printf("\nchoissir un login\n");
   couleur("0");
   scanf("%s",login);
   strcat(chaine,login);
   FILE *x=fopen(chaine,"a+");
   fclose(x);
   compte =fopen(login, "a+"); 
   couleur("35");
   printf("\ntappez un mot de passe :\n");
   couleur("0");
   scanf("%s",motdepasse);
   strcpy(utilisateur->user,login); 
   strcpy(utilisateur->password,motdepasse);
   fprintf(compte,"%s\n",motdepasse);
   fclose(compte); 

}
/** 
    * \fn void Connexion()
    * \brief fonction qui vas nous demandé si jamais on a un compte et demande 
    * le motpasse et vérifer si il est bon fonction utile au début du programme pour nous permettre de 
    * recuperer les rendez_vous a traves le nom d'utilisateur et son motdepasse
 */
/*-----------------------------------------------------------*/
void Connexion(){
   int reponse;
   Creationdecompte utilisateur;
   char login[TAILLE];

   printf("Vous avez déjà un compte ?? \n");
   printf("1/Yes or 0/No ?\n");
   scanf("%d",&reponse);
   if (reponse==0){
      init_user(&utilisateur);
      couleur("31");
      printf("\nVotre compte est crée ! merci \n\n");
      couleur("0");
      printf("%s Bienvenue Parmis nous \n\n",utilisateur.user);
      Agenda();
   }
   else {
      char motdepasse[TAILLE],chaine[TAILLE];
      couleur("35");
      printf("Saisir votre login\n\n");
      couleur("0");
      scanf("%s",login);
      FILE* fichier = NULL;
      fichier = fopen(login, "r");
      if (fichier != NULL )
      {
         printf("\n\nContent de vous revoir %s\n",login);
         couleur("35");
         printf("\n\nTappez votre motdepasse svp\n\n");
         couleur("0");
         scanf("%s",motdepasse);
         int y=strlen(motdepasse);
         while (fgets(chaine,y+1, fichier) != NULL){
            if(strcmp(chaine,motdepasse)==0){
               couleur("34");
               printf("motdepasse correct !!\n\n\n");
               couleur("0");
               Agenda();
            }     
            else{
               printf("motdepasse incorrect !!\n");
               Connexion();
            }
         }
      }
      else{
         printf("le login n'exsite pas\n");
         Connexion();
      }
   }
}