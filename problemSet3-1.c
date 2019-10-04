#include<stdio.h>
#include <stdlib.h>

char encryptionALG(char m, int key);
int main (void){//ok I have no idea how to get the program to run with command line prompts
    char str[100];
    int key;
    
    printf("\nWord to encrypt:");
    scanf("%s",&str);
    
    printf("\nKey?:");
    scanf("%i",&key);
    
    char cypher[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        cypher[i] = encryptionALG(str[i],key);
    }
    
    printf("\nCypher text: %s\n",cypher);
    
    char solution[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        solution[i] = encryptionALG(cypher[i],key);
    }
    printf("\nDe-encryption: %s\n\n\n",solution);
    return 0;
}

char encryptionALG(char m, int key){
    char m2 = m ^ key;
    return m2;
}
