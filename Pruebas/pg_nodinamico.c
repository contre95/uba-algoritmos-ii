#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    if (argc == 1){
        return 1;
    }

    int sumas;
    for (int i = 0; i < argc;i++){
        sumas += atoi(argv[i]);
    }
    printf("%i\n",sumas );

    return 0;
}
