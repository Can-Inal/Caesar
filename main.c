#include "caesar.h"


int main (int argc, char *argv[]) {
    

    

    if (argc >= 4){
        char *mode = argv[1];
        if(mode[1] == 'e'){

            char *message = getText(argv[3]);
            char *key = getKey(argv[2]);
            printf("encrypted: %s\n", encrypt(message,key));
        
        }
        else if(mode[1] == 'd'){
    
            char *message = getText(argv[3]);
            char *key = getKey(argv[2]);
            printf("decrypted: %s\n", decrypt(message,key));
    
        }else if(mode[1] == 'h'){
            help();
        }else{
            error();    
        }
    }
    
    else if(argc < 4){
        char *mode = argv[1];
    
        if(mode[1] == 'e'){
    
            char *message = getText(argv[2]);
            char *key = "caesar";
            printf("encrypted: %s\n", encrypt(message, key));
    
        }else if(mode[1] == 'd'){
    
            char *message = getText(argv[2]);
            char *key = "caesar";
            printf("decrypted: %s\n", decrypt(message, key));
    
        }else if(mode[1] == 'h'){
            help();
        }
        else{
            error();
        }
    }else{
        error();
    }
    return 0;
}