#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* klartext, char* key){
    int key_size = strlen(key);
    int text_size = strlen(klartext);

    int index_key = 0;


    for(int i = 0; i<text_size; i++){
        char c = klartext[i];
        
        if(index_key == key_size){
            index_key = 0;
        }

        if(c >= 'a' && c <= 'z'){
            c = ((c - 'a') + (key[index_key] - 'a')) % 26 + 'a';
        }else if(isupper(c)){
            if(islower(key[index_key])){
                c = ((c - 'A') + (toupper(key[index_key]) - 'A')) % 26 + 'A';
            }else{
                c = ((c - 'A') + (key[index_key] - 'A')) % 26 + 'A';
            }
        }

        klartext[i] = c;
        index_key++;
       
    }

    return klartext;
}


char * decrypt(char * klartext, char* key){
    int key_size = strlen(key);
    int text_size = strlen(klartext);

    int index_key = 0;


    for(int i = 0; i<text_size; i++){
        char c = klartext[i];
        if(index_key == key_size){
            index_key = 0;
        }

        if(c >= 'a' && c <= 'z'){
            c = ((c - 'a') + ('z' - key[index_key]+1)) % 26 + 'a';
            
        }else if(isupper(c)){
            if(islower(key[index_key])){
                c = ((c - 'A') + ('Z' - toupper(key[index_key])+1)) % 26 + 'A';
            }else{
                c = ((c - 'A') + ('Z' - key[index_key]+1)) % 26 + 'A';
            }
        }

        klartext[i] = c;
        index_key++;
       
    }
    return klartext;    
}


char* getKey(char * key){
    
    int size = strlen(key);
    

    for(int i = 0; i<size-3; i++){
        key[i] = key[i+3];
    }

    for(int i = size-3; i<size;i++){
        key[i] = '\0';
    }
    return key;

}


char* getText(char * text){
    
    int size = strlen(text);

    for(int i = 0; i<size-3; i++){
        text[i] = text[i+3];
    }
    for(int i = size-3; i<size;i++){
        text[i] = '\0';
    }
    return text;
    
}

void help(){
    printf("\nHelp Menu\n\n");
    printf("---------modes-----------\n\n");
    printf("-e                | encrypt \n");
    printf("-d                | decrypt \n");
    printf("-h                | help \n\n\n");
    printf("---------params----------\n\n");
    printf("-p=['password']   | password \n");
    printf("-m=['message']    | message \n\n\n");
    printf("\n\nyou have to define mode as first.\n");
    printf("password(optional) as second. Default value = 'caesar'\n");
    printf("message as third.\n\n");
}

void error(){
    printf("\n\n\nFalse Syntax: For Help type caesar -h\n\n\n");
}