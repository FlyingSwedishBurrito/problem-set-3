#include<stdio.h>
#include <stdlib.h>

char encryptionALG(char m, int key);

int main (int argc, char* argv[]){
    if(argc < 3){
        printf("need more arguments");
        return(0);
    }
    
    char* str;
    str = argv[1];
    int key = atoi(argv[2]);  
    char cypher[100];
    
    printf("\nplaintext: %s",str);
    
    for (int i = 0, n = strlen(str); i < n; i++){
        cypher[i] = encryptionALG(str[i],key);
    }
    
    printf("\nCypher text: %s\n",cypher);
    
    char solution[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        solution[i] = encryptionALG(cypher[i],key);
    }
    printf("De-encryption: %s\n\n\n",solution);
    return 0;
}

char encryptionALG(char m, int key){
    char m2 = m ^ key;
    return m2;
}
