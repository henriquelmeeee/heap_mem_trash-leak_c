#include <stdio.h>
#include <stdlib.h>

#define NUM_BYTES 48

int main()
{
    while(1) {
        char *buffer = (char *) malloc(NUM_BYTES);
        int able_to_print;
        if (buffer == NULL) {
            printf("Erro ao alocar memória na heap\n");
            break;
        }
        for(int n = 0; n<NUM_BYTES; n++) { // para cada byte (NUM_BYTES bytes)
            for(int n = 0; n<8; n++) { // para cada bit do byte atual; buffer+n -> deslocamento de 1 byte
                if((*(buffer+n)) | 0) {
                    able_to_print = 1;
                    break;
                }
            }
        }
        if(able_to_print) {
            printf("[ %s ]\n", buffer);
        }
        free(buffer); able_to_print = 0;
    }
}
