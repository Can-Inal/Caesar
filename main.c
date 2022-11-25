#include "caesar.h"


int main (int argc, char *argv[]) {
    

    char *mode = argv[1];
    char *message = getText(argv[3]);
    char *key = getKey(argv[2]);


    printf("Mode: %s\n\n", mode);
    printf("Key: %s\n\n", key);
    printf("Klartext: %s\n\n", message);

    if(mode[1] == 'e'){
        printf("Geheimtext: %s\n", encrypt(message,key));
    }
    else if(mode[1] == 'd'){
        printf("Klartext: %s\n", decrypt(message,key));
    }
    
    
    return 0;
}