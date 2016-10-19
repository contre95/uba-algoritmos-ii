#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(char *message){
    fprintf(stderr, "%s\n", message);
}

int main(int argc, char const *argv[]) {

    if(argc != 3){
        error("CANTIDAD DE ARCHIVOS NO ES LA CORR=CTA !");
        return 1;
    }

    FILE * file_1 = fopen(argv[1],"r");
    char single_line_1[1000];

    for(int i=0; i < atoi(argv[2]) ; i++){
        fgets(single_line_1,1000,file_1);
        fprintf(stdout,"%s",single_line_1);
    }
    char single_line_2[200];
    while(getchar() == '\n' && !feof(file_1)){
        fgets(single_line_2,1000,file_1);
        fprintf(stdout,"%s",strtok(single_line_2,"\n"));
    }
    fclose(file_1);
    return 0;
}
