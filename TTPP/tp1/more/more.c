#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int main(int argc, char const *argv[]) {

    if(argc != 3){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORRECTA !");
        return 1;
    }

    FILE * file_1 = fopen(argv[1],"r");
    char single_line_1[200];

    for(int i=0; i< argv[2] ; i++){
        fgets(single_line_1,200,file_1);
        fprintf(stdout,"%s",single_line_1);
    }
    whiel(!feof(file_1)){
        if(getchar() != '\n') break;
        fgets(single_line_1,200,file_1);
        fprintf(stdout,"%s",single_line_1);
    }
    return 1;
