//Bibliotecas Padrão
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Final Bibliotecas Padrão

//Minhas Bibliotecas
#include "cadastro.h"
//Final Minhas Bibliotecas

int main() {
	//Definir linguagem para portugues
    setlocale(LC_ALL, "portuguese");
	//Declaracao de variaveis
	int verific_inicial;
	char entrada;
	
	//altera o valor para o funcionamento do "DO WHILE"
	verific_inicial = 1;
	
	do{
		menu_principal();
		entrada = getch();
		
		switch(entrada){
			case '1' : //Parte dos Clientes
				printf ("Em constru��o...");
				printf("\n\n");
				break;
			
			case '2' : //Parte dos Servi�os
				printf ("Trabalhando nisso ainda...");
				printf ("\n\n");
				break;
			
			case '3' :
				verific_inicial = 0;
				break;
				
			default :
				printf ("\n		Op��o invalida				");
				printf ("\n	Esolha outra op��o para continuar	");	
				printf ("\n\n")	;
			}
			
	}while (verific_inicial != 0);

    return 0;
}

