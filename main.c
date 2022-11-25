#include "caesar.h"


int main (int argc, char *argv[]) {
    

    

    if (argc == 4){
        char *mode = argv[1];
        if(mode[1] == 'e'){
            if(argv[2][1] == 'p' && argv[3][1] == 'm'){
                char *key = getKey(argv[2]);
                char *message = getText(argv[3]);
                printf("\n\nencrypted: %s\n\n", encrypt(message, key));
            }else{
                error();
            }
        }
        else if(mode[1] == 'd'){
            if(argv[2][1] == 'p' && argv[3][1] == 'm'){
                char *key = getKey(argv[2]);
                char *message = getText(argv[3]);
                printf("\n\ndecrypted: %s\n\n", decrypt(message, key));
            }else{
                error();
            }

        }else if(mode[1] == 'h'){
            help();
        }else{
            error();
        }
    }
    
    else if(argc < 4){
        char *mode = argv[1];
    
        if(mode[1] == 'e'){
            if(argv[2][1] == 'm'){
                char *message = argv[2];
                char *key = "caesar";
                printf("\n\nencrypted: %s\n\n", encrypt(message, key));
            }else{
                error();
            }
        }else if(mode[1] == 'd'){
    
            if(argv[2][1] == 'm'){
                char *message = argv[2];
                char *key = "caesar";
                printf("\n\ndecrypted: %s\n\n", decrypt(message, key));
            }else{
                error();
            }

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