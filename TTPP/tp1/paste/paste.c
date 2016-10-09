/*Por ejemplo, dado el siguiente par de archivos:

$ cat anios.txt
1996
2007
2013
2016
2016

$ cat ciudades.txt
Bogotá
La Boca
Lanús
Nuñez
Avellaneda
Al invocar el programa, su salida deberá ser la siguiente:

$ ./paste anios.txt ciudades.txt
1996  Bogotá
2007  La Boca
2013  Lanús
2016  Nuñez
2016  Avellaneda*/
#include <stdio.h>;
#include <string.h>;
#define SPEARADOR '\t'

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int main(int argc, char const *argv[]) {

    if(argc != 2){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !")
        return 1;
    }

    char single_line_1[150];
    char single_line_2[150];
    FILE * file_1 = fopen(argv[1],'r');
    FILE * file_2 = fopen(argv[2],'r');

    while(!feof(file_1) || !feof(file_2)){
        getline(&single_line_2,150,file_1);
        getline(&single_line_1,150,file_2);
        fprintf(stout, "%s\n",single_line_1);
        fprintf(stout, "%s\n",single_line_2);
        free(single_line_1);
        free(single_line_2);
    }

    return 0;
}
