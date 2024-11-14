#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct cadastro CADASTRO;
struct cadastro{
	char nome[51];
	char cpf[12]; //o cpf tem 11 numeros mas o gets adiciona um \n no final
	bool ativo;
};

//Prototipos
void desativar_cliente(void);
void menu_principal(void);
void menu_clientes(void);
void cadastro0(void);
void desativar_cliente(void);
void excluir_cliente(void);
//Fim Protitipos

/*Menu principal*/
void menu_principal(){

    printf("\n           ########## MENU PRINCIPAL ##########           ");
    printf("\n");
    printf("\n  [1] - Clientes                ");
    printf("\n");
    printf("\n  [2] - Serviços                ");
    printf("\n");
    printf("\n  [ESC] - SAIR                    ");
    printf("\n\n");
}

/*Menu de clientes*/
void menu_clientes(){
	
	//difinicao de variaveis
	int entra;
	int aux_client;
	
	//altera o valor da variavel auxiliar do menu de clientes
	aux_client = 1;
	
	do{
	
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
	    printf("\n  [ESC] - SAIR ");
	    printf("\n\n");
	    
	    entra = getch();
	    
	    switch (entra){
		    	
		    	case '1':
		    		cadastro0();
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
					desativar_cliente();
					printf("\n\n");
					break;
					
				case '5':
					excluir_cliente();
					printf("\n\n");
					break;
					
				case (char)27:
					aux_client = 0;
					break;		
		    	
		    	defautl :
		    		printf("\n");
		    		break;
			}
	} while (aux_client != 0);
}

/*Cadastro de Clientes*/
void cadastro0(){
	
	/*char nome_cliente[50];
    int cpf_cliente[12];
    bool ativo;*/
   	CADASTRO cad;
	
	FILE* arquivo;
    arquivo = fopen("clientes.txt", "ab");
    
     if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## CADASTRO DE CLIENTE ##########            ");
	    printf ("\n\nDigite o nome do cliente: ");
	    
	    fflush(stdin);
	    fgets (cad.nome, 51, stdin);
	   	cad.nome[strcspn(cad.nome, "\n")] = 0;
	    
	    printf ("Digite o CPF do cliente: ");
	    
	    fflush(stdin);
	   	fgets (cad.cpf, 12, stdin);
	   	cad.cpf[strcspn(cad.cpf, "\n")] = 0;
	   	
		cad.ativo = true;
	}
	
	if (fclose(arquivo) == 0){
		printf ("\n");
	}else{
		printf ("Erro no fechamento do arquivo.\n");
	}
	
}

/*Desativar clientes*/
void desativar_cliente(){
	
	int cpf_cliente;
	int resultado;
	
		FILE* arquivo;
    arquivo = fopen("clientes.txt", "a+");
    
     if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## DESATIVAR CLIENTE ##########            ");
	    printf ("\n\nEm desenvolvimento... ");
	}
	
	if (fclose(arquivo) == 0){
		printf ("\n");
	}else{
		printf ("Erro no fechamento do arquivo.\n");
	}
	
}

/*Excluir Clientes*/
void excluir_cliente(){
	FILE* arquivo;
    arquivo = fopen("clientes.txt", "a+");
    
     if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## EXCLUIR CLIENTE ##########            ");
	    printf ("\n\nEm desenvolvimento...");
	}
	
	if (fclose(arquivo) == 0){
		printf ("\n");
	}else{
		printf ("Erro no fechamento do arquivo.\n");
	}
	
}

