#include<stdio.h>
#include <stdlib.h>

char encryptionALG(char m, int key,int keySum);
int main (int argc, char* argv[]){
    if(argc < 3){
        printf("no");
        return 1;
    }

    char* str;//for some reason, the program won't compile with str[100]
    str = argv[1];
    int key = atoi(argv[2]);  
    int keySum = 0;/*this is disabled at the moment,
    but if you remove the // in the code below,
    you'll have a continuosly shifting ceasar cypher */
    
    for(int i = 0; str[i]; i++){// converts to lower case
        str[i] = tolower(str[i]);
    }
    printf("\n\nplaintext: %s",str);
    char cypher[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        cypher[i] = encryptionALG(str[i],key,keySum);
        //keySum += key;
        
        //^^this will contiuously shift it over!
    }
    
    keySum = 0;
    printf("\nCypher text: %s\n",cypher);
    
    char solution[100];
    
    for (int i = 0, n = strlen(str); i < n; i++){
        solution[i] = encryptionALG(cypher[i],-(key),keySum);
        
        //keySum -= key;
    }
    printf("De-encryption: %s\n\n\n",solution);
    return 0;
}

char encryptionALG(char m, int key, int keySum){
    char m2 = m + key + keySum;
    if(m2 < 97){
        m2+=26;
    }
    if(m2 > 122){
        m2-=26;
    }
    return m2;
}


