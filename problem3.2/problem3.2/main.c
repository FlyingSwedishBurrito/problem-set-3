#include<stdio.h>
#include <stdlib.h>

char encryptionALG(char m, int key,int keySum);
int main (void){//ok I have no idea how to get the program to run with command line prompts
    char str[100];
    int key;
    int keySum = 0;
    
    
    /*most of this is the same code; the magic happens in the changes
     to the encryption algorithm down bellow*/
    printf("\nWord to encrypt:");
    scanf("%s",&str);
    
    printf("\nKey? (this key will determine how much each letter is shifted by):");
    scanf("%i",&key);
    
    char cypher[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        cypher[i] = encryptionALG(str[i],key,keySum);
        //keySum += key;
        
        //this will contiuously shift it over! check it out, its pretty cool!
    }
    
    keySum = 0;
    printf("\nCypher text: %s\n",cypher);
    
    char solution[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        solution[i] = encryptionALG(cypher[i],-(key),keySum);
        
        //keySum -= key;
    }
    printf("\nDe-encryption: %s\n\n\n",solution);
    return 0;
}

char encryptionALG(char m, int key, int keySum){
    char m2 = m + key + keySum;
    return m2;
}
