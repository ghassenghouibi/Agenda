#include "projet.h"
/**
  * \fn void enregister(Rendez_vous *l)
  * \brief fonction qui permet de sauvegarder tous nos rendez_vous dans un fichier grace a notre login
  * \param *l type Rendez_vous 
*/
void enregister(Rendez_vous *l){
  FILE* fichier = NULL;
  Rendez_vous *courant;
  char deco[TAILLE];
  char chaine[TAILLE]="fichierde";
  couleur("35");
  printf("votre login svp \n");
  couleur("0");
  scanf("%s",deco);
  strcat(chaine,deco);
  fichier = fopen(chaine, "w+");
  for(courant=l;courant!=NULL;courant=courant->suivant){
  fprintf(fichier, "[\n\ttitre:%s\n\tlieu:%s\n\tjour:%s\n\tmois:%s\n\tannee:%s\n\theuredebut:%s\n\theurefin:%s\n\ttype:%d\n] \n",courant->titre,courant->lieu,courant->jour,courant->mois,courant->annee,courant->heuredebut,courant->heurefin,courant->type);
  }

  fclose(fichier);
}


/**
  * \fn char* str_dup(const char *str)
  * \brief fonction permet de copier une chaine de caractère même fonctionnement du strdup classique
  * \return dup type chaine de caractere
*/
char *str_dup(const char * str){
   
   char *dup=NULL;
   if (str!=NULL){
      size_t size=strlen(str)+1;
      dup=malloc(size);
      if(dup!=NULL)
         memcpy(dup,str,size);
   }
   return dup;
}
/**
  * \fn str_finalize(char* str)
  * \brief fonction qui cherche le saut de ligne
  * \param str chaine de caractère
*/
void str_finalize (char * str){
   char *p=strchr(str,'\n');

   if (p!=NULL)
      *p=0;
   
}
/**
  * \fn get (Rendez_vous *p,FILE *file,contact_tags tag)
  * \brief fonction qui va remplir notre liste chainée d'aprés des valeurs sauvedgarder dans notre fichier
  * \param *p type Rendez_vous
  * \param *file type FILE
  * \param tag type contact_tags
*/
void get(Rendez_vous *p,FILE *file,contact_tags tag){

   char buff [BUF_SIZE];
   char *s=NULL;
   fgets(buff,BUF_SIZE,file);
   s=strchr(buff,SEP);
   if (s != NULL){
      s++;
      str_finalize(s);
      switch (tag)
      {
         case TYPE:
            p->type=strtol(s, NULL, 10);
         
         break;
         case TITRE:
            p->titre=str_dup(s);
         break;

         case LIEU:
            p->lieu=str_dup(s);
         break;
         case JOUR:
            p->jour=str_dup(s);
         break;
         case MOIS:
            p->mois=str_dup(s);
         break;
         case ANNEE:
            p->annee=str_dup(s);
         break;
         case HEUREDEBUT:
            p->heuredebut=str_dup(s);
         break;
         case HEUREFIN:
            p->heurefin=str_dup(s);
         break;

         default:
            break;
      }
   }
}
/**	
  *\fn Rendez_vous* recuperer()
  *\brief fonction qui nous permet d'extraire de texte de notre fichier et consuitre notre liste et la renvoie
  *\return rdv qui est notre liste de rendez_vous 
*/
Rendez_vous* recuperer(){
  Rendez_vous *rdv;
  Rendez_vous  *ret;
  FILE *file=NULL;
  char buff[BUF_SIZE];
  char deco[TAILLE];
  char chaine[TAILLE]="fichierde";
  couleur("32");
  printf("retappez votre login svp \n");
  couleur("0");
  scanf("%s",deco);
  strcat(chaine,deco);
  file=fopen(chaine, "r");
  if (file != NULL){
    while ((fgets (buff, BUF_SIZE, file) != NULL)){  
      if (buff[0] == BEGIN ){
        ret = malloc (sizeof (* ret));
        if (ret != NULL){
          get(ret,file,TITRE);
          get(ret,file,LIEU);
          get(ret,file,JOUR);
          get(ret,file,MOIS);
          get(ret,file,ANNEE);
          get(ret,file,HEUREDEBUT);
          get(ret,file,HEUREFIN);
          get(ret,file,TYPE);
        }
        ret->suivant=rdv;
        rdv=ret;
      } 
    }
  }
  fclose (file);

  return rdv;
}
/*-----------------------------------------------------------*/