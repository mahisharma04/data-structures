#include <stdio.h>
#include <math.h>

int HexadecimalToDecimal(){
    printf("Enter your hexadecimal number: ");
    char hexa[100];
    scanf("%99s", hexa);

    //calculating the lenght
    int len = 0;
    for(int i = 0; hexa[i] != '\0'; i++){
        len++;
    }
    int i = 0;
    int summation = 0;
    int digitscore = 0;
    for(int j = len-1; j>= 0; j--){
        switch(hexa[j]){
            case 'A':
                digitscore = 10;
                break;
            case 'B':
                digitscore = 11;
                break;
            case 'C':
                digitscore = 12;
                break;
            case 'D':
                digitscore = 13;
                break;
            case 'E':
                digitscore = 14;
                break;
            case 'F':
                digitscore = 15;
                break;
            default:
                digitscore = hexa[j] - '0';
                break;

        }
        summation = summation + (int)pow(16, i) * digitscore;
        i++;
    }
    return summation;
}
void DecimalToHexadecimal(){
    printf("Enter your decimal number: ");
    int num;
    scanf("%d", &num);

    int hexa[100];
    int i = 0;
    while(num>0){
        int remainder = 0;
        remainder = num % 16;
        num = num/16;

        if(remainder < 10){
            hexa[i] = remainder + 48;
        }
        else{
            hexa[i] = remainder + 55;
        }
        i++;
    }
    for(int j = i-1; j>=0; j--){
        printf("%c", hexa[j]);
    }
}
int main(){
    DecimalToHexadecimal();
}