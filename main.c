//Bibliotecas Padrao
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
//Final Bibliotecas Padrao

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
				menu_clientes();
				printf("\n\n");
				break;
			
			case '2' : //Parte dos Servicos
				printf ("Trabalhando nisso ainda...");
				printf ("\n\n");
				break;
			
			case (char)27 : //Saida do programa
				verific_inicial = 0;
				break;
				
			default :
				printf ("\n		Opção invalida				");
				printf ("\n	Esolha outra opção para continuar	");	
				printf ("\n\n")	;
			}
			
	}while (verific_inicial != 0);

    return 0;
}

