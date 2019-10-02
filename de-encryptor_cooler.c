#include <stdio.h>

int xNew;
int xSum = 0;
char message[140];
char secretMessage[140];

int deencryptionAlg(char n1, char n2);

int main(void){
    //gets a message for encryption
    printf("What is the message you would like to de-encrypt?");
    printf("\n\nPaste Message:");
    
    scanf("%s",secretMessage);
    int n = strlen(secretMessage);//length of message
    
    message[0] = secretMessage[0];//first value is the same
    
    for(int i = 1; i < n; i++){
        message[i] = deencryptionAlg(secretMessage[i],secretMessage[i-1]);
    }
    
    printf("\noutput:");
    for(int i = 0; i < n; i++){
        printf("%c", message[i]);
    }
    
    printf("\n\n");
    return 0;
}

int deencryptionAlg(char n1,char n0){
    
    xNew =  (n1-n0-32);//before the mod function, this is what can be reversed
    while(xNew < 32){
        xNew += 94;//this reverses the mod funtion
    }
    
    return xNew;
}
