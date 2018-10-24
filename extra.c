#include <time.h>

/*-----------------------------------------------------------*/
/** 
    * \fn void s_sleep(int seconds) 
    * \brief fonction qui permet de mettre le programme en attente
    * \param seconds de type int c'est le nombre de secondes qu'il faut attendre
 */
void s_sleep(int seconds) {
    time_t start_time = 0;
    time_t current_time = 0;
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}