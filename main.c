#include "caesar.h"


int main (int argc, char *argv[]) {
    

    char *mode = argv[1];
    char *message = getText(argv[3]);
    char *key = getKey(argv[2]);

    if(mode[1] == 'e'){
        printf("encrypted: %s\n", encrypt(message,key));
    }
    else if(mode[1] == 'd'){
        printf("decrypted: %s\n", decrypt(message,key));
    }
    
    
    return 0;
}