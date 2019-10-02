#include <stdio.h>

int xNew;
int xSum = 0;
char message[140];
char secretMessage[140];

int encryptionAlg(char n1, char n2);

int main(void){
    //gets a message for encryption
    printf("What is the message you would like to encrypt?");
    printf("\n\nEnter Message(140 character max, put - for space):");
    
    scanf("%s", message);
    int n = strlen(message);
    
    secretMessage[0] = message[0];
    
    for(int i = 1; i < n; i++){
        secretMessage[i] = encryptionAlg(message[i],secretMessage[i-1]);
    }
    
    printf("\noutput:");
    
    for(int i = 0; i < n; i++){
        printf("%c", secretMessage[i]);
    }
    
    printf("\n\n");
    return 0;
}

int encryptionAlg(char n1, char n0){//takes values from previous and current
    xNew = ((n1 + n0)%94)+32;//since ascii values 0-31 are control commands, and values need to be charaters
    
    return xNew;
}
