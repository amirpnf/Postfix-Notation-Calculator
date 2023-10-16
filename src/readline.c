#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "readline.h"


/* Nous allons définir quelques règles ici pour la fonction cases.
   Si :
   input est numérique -> la fonction retourne 0
   si l'utilisateur a rentré :
   1) p -> on imprime le sommet de la pile
   2) q -> on ferme le progrmme
   3) a -> on imprime tous les éléments de la pile
*/

int cases(char* input) {
    if(isNumerical(input)) {
        return IS_A_NUMBER;
    }
    else if(strlen(input) == 1){
        switch (input[0])
        {
        case 'p':
            return PRINT_TOP;
            
        case 'a':
            return PRINT_ALL;

        case 'q':
            return QUIT;
        }
    }   
}


