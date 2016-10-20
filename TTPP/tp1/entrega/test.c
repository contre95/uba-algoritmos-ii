#include "strutil.h"


int main(int argc, char const *argv[]){
    if(argc <= 1){
        error("CANTIDAD DE PARAMETROS INVALIDOS !");
        return 1;
    }

    char **array = split(argv[1],' ');
    for(int i = 0; i < cant_palabras(argv[1],' ')  ; i++){
        printf("%s : %i\n",array[i],strlen(array[i]));
    }
    char * stringg = join(array,'');
    printf("%s\n",stringg);
    free(stringg);
    free_strv(array);

    return 0;
