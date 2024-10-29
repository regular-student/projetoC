#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu_principal(){

    printf("\n           ########## MENU PRINCIPAL ##########           ");
    printf("\n");
    printf("\n  [1] - Clientes                ");
    printf("\n");
    printf("\n  [2] - Serviços                ");
    printf("\n");
    printf("\n  [3] - SAIR                    ");
    printf("\n\n");
}

void menu_clientes(){
	
	//difinicao de variaveis
	int entra;
	
	printf("\n           ########## MENU CLIENTES ##########            ");
	printf("\n");
    printf("\n  [1] - Cadastrar Cliente ");
    printf("\n");
    printf("\n  [2] - Litar Clientes ");
    printf("\n");
    printf("\n  [3] - Consultar pelo CPF ");
    printf("\n");
    printf("\n  [4] - Desativar Cliente ");
    printf("\n");
    printf("\n  [5] - Excluir Cliente ");
    printf("\n");
    printf("\n  [6] - SAIR ");
    printf("\n\n");
    
    entra = getch();
    switch (entra){
	    	
	    	case '1':
	    		//cadastro();
	    		printf ("\n\n");
	    		break;
	    	
	    	case '2':
	    		printf ("\n           ########## LISTA CLIENTES ##########            ");
	    		printf ("\nEm desenvolvimento...");
	    		printf ("\n\n");
	    		break;
	    	
			case '3':
				printf ("\n           ########## CONSULTA DE CLIENTES ##########            ");	
				printf ("\n\nEm desenvolvimento...");
				printf ("\n\n");
				break;
				
			case '4':
				
				printf("\n\n");
				break;
	    	
	    	defautl :
	    		printf("\n");
	    		break;
		}
}

/*void cadastro(){
	FILE* arquivo;
    arquivo = fopen("clientes.txt", "a+");
    
     if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## CADASTRO DE CLIENTE ##########            ");
	    printf ("\n\nEm desenvolvimento...");
	}
}*/

void desativar_cliente(){
		FILE* arquivo;
    arquivo = fopen("clientes.txt", "a+");
    
     if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## DESATIVAR CLIENTE ##########            ");
	    printf ("\n\nEm desenvolvimento...");
	}
	
}
