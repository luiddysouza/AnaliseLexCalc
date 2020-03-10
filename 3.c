#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char stringInteiro[] = "^[0-9]*$";
char stringReal[] = "^[0-9]+\\.[0-9]+$";
char stringSimbolo[] = "^[\\+|-|/|*|(|)|\\]*$";

void main(){

    char stringOriginal[] ="( 2 + 6 ) - 7 * 7 / 35 + + 1..1";
    char * stringSeparada;
    stringSeparada = strtok (stringOriginal," ");

	regex_t regexInteiro;
    regex_t regexReal;
    regex_t regexSimbolo;

    regcomp(&regexInteiro, stringInteiro, REG_EXTENDED);
    regcomp(&regexReal, stringReal, REG_EXTENDED);
    regcomp(&regexSimbolo, stringSimbolo, REG_EXTENDED);

    printf ("%s\n",stringOriginal);

    while (stringSeparada != NULL){
        printf ("%s ->     \t",stringSeparada);
        if(regexec(&regexInteiro, stringSeparada, 0, NULL, 0) == 0)
		    printf("Numero Inteiro\n");
	    else if(regexec(&regexReal, stringSeparada, 0, NULL, 0) == 0)
		        printf("Numero Real\n");
        else if(regexec(&regexSimbolo, stringSeparada, 0, NULL, 0) == 0)
		        printf("Operação\n");
        else
            printf("Erro\n");
        stringSeparada = strtok (NULL, " ");
    }
}