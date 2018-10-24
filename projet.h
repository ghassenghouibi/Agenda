#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#define TAILLE 256
#define couleur(param) printf("\033[%sm",param);

#define BEGIN        '['
#define SEP          ':'
#define BUF_SIZE     10000

#define TAG_TITRE      "titre"
#define TAG_LIEU       "lieu"
#define TAG_JOUR       "jour"
#define TAG_MOIS       "mois"
#define TAG_ANNEE      "annee"
#define TAG_HEUREDEBUT "heuredebut"
#define TAG_HEUREFIN   "heurefin"
#define TAG_TYPE        "type"

/**
 * \struct Creationdecompte
 * \brief Objet compte.
 * Creationdecompte est un objet de gestion de chaînes de caractères dédié 
 * au stockage de nom d'utilisateur ,et un mot de passe
 * stockage obligatoire pour stocker les donnes et y pouvoir accéder 
 * prochainement grace au mot de passe
 */
typedef struct Creationdecompte Creationdecompte;
struct Creationdecompte
{
   char user[TAILLE];
   char password[TAILLE];
   
};
/**
 * \struct Rendez_vous
 * \brief Objet Rendez_vous.
 * Rendez_vous est un objet de gestion de chaînes de caractères dédié 
 * dedié au stockage de données de rendez_vous le titre,lieu,jour,mois,annee,heuredebut,heurefin
 * a traves un type pour determiner un agenda familial ou professionel ou personnel .
 * une liasion entre les rendez_vous a traves une pointeur suivant
 */
typedef struct Rendez_vous Rendez_vous;
struct Rendez_vous{
	char *titre;
	char *lieu;
	char *jour;
	char *mois;
	char *annee;
	char *heuredebut;
	char *heurefin;
	int type;
	Rendez_vous *suivant;
};
/**
 *\enum contact_tags
 * \brief enumération contact_tags contient le titre lieu jour mois annee heuredebut heurefin
*/
typedef enum
{
   TITRE,
   LIEU,
   JOUR,
   MOIS, 
   ANNEE,  
   HEUREDEBUT,
   HEUREFIN,  
   TYPE,        
   NB_TAG
}
contact_tags;
/**
 * \fn init_user(Creationdecompte* utilisateur)
 * \brief Fonction qui permet la creation d'un compte
 * \param utilisateur type qui contient le login et le mot de passe 
 */
void init_user(Creationdecompte* utilisateur);
/**
 * \fn Connexion()
 * \brief la boucle de connexion soit pour creer un compte Agenda ou
 * réutiliser notre ancien compte 
*/
void Connexion();
void rechercheRendez_vous(Rendez_vous *contact);
void Afficherendezvous(Rendez_vous *contact);
void Ajoutrendezvous (Rendez_vous **L);
void enregister(Rendez_vous *l);
Rendez_vous* new_rendez_vous(char *titre,char *lieu,char *jour,char *mois,char *annee,char *heuredebut ,char *heurefin,int type);
void ajout_rendez_vous(Rendez_vous **chaine,Rendez_vous *m);
Rendez_vous* Recuperer();
char *str_dup(const char * str);
void str_finalize (char * str);
void get (Rendez_vous *p,FILE *file,contact_tags tag);
Rendez_vous* recuperer();
void s_sleep(int seconds);
void Agenda();

/*--------Mehdi-----------*/
void supprimerrendezvous(Rendez_vous *l);
void supprimer1(Rendez_vous *l);
void supprimer2(Rendez_vous *l);
void supprimer3(Rendez_vous *l);
void supprimer4(Rendez_vous *l);
void supprimer5(Rendez_vous *l);
/*
tu vas poser la question ça sera quel rendez_vous 
par exemple tu demande si c'est titre ou peut importe
et tu supprime 
*/
/*--------Dyhia----------*/
void trierrendezvous(Rendez_vous *l);
void trierRendezvous();
/*
comme tu peux le choix l'enlever des paramètre
 et demande dans le corps de la fonction
*/