#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char const *argv[]) {

    if(argc != 3){
        fprintf(stderr, "%s\n", "CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }

    char single_line_1[150];
    char single_line_2[150];
    FILE * file_1 = fopen(argv[1],"r");
    FILE * file_2 = fopen(argv[2],"r");

    while(!feof(file_1) || !feof(file_2)){
        fgets(single_line_1,150,file_1);
        fgets(single_line_2,150,file_2);
        fprintf(stdout,"%s\t%s\n",strtok(single_line_1,"\n"),strtok(single_line_2,"\n"));
    }
    fclose(file_1);
    fclose(file_2);

    return 0;
}
