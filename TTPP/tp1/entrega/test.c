#include "strutil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
    if(argc <= 1){
        fprintf(stderr, "%s\n", "CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }

    char **array = split(argv[1],' ');
    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        printf("%s : %i\n",array[i],(int)strlen(array[i]));
    }
    char * stringg = join(array,' ');
    printf("%s\n",stringg);
    free(stringg);
    free_strv(array);

    return 0;
}
