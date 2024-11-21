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
	char data_nascimento[11];
	char telefone[15];
	char *notas_enf;
};

//Prototipos
void desativar_cliente(void);
void menu_principal(void);
void menu_clientes(void);
void cadastro0(void);
void desativar_cliente(void);
void excluir_cliente(void);
int valida_cpf(char cpf[11]);
//Fim Protitipos

/*Menu principal*/
void menu_principal(){

    printf("\n           ########## MENU PRINCIPAL ##########           ");
    printf("\n");
    printf("\n  [1] - Clientes                ");
    printf("\n");
    printf("\n  [2] - Servi�os                ");
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
		    	
		    	default:
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
		
		if (valida_cpf(cad.cpf) != 1) {return;};

		cad.ativo = true;

		printf("Digite a data de nascimento (DD/MM/AAAA): ")

		fflush(stdin);
		fgets(cad.data_nascimento, 11, stdin);
		cad.data_nascimento[strcspn(cad.data_nascimento, "\n")] = 0;

		printf("Digite o número de telefone ((XX) XXXXX-XXXX)");

		fflush(stdin);
		fgets(cad.telefone, 15, stdin);
		cad.telefone[strcspn(cad.telefone, "\n")] = 0;

		//Alocação pras notas de enfermagem (como o cliente chegou, consciente/inconsciente, queixas etc.)
		cad.notas_enf = (char*)malloc(256 * sizeof(char));
		if (cad.notas_enf != NULL) {
			printf("Digite as notas de enfermagem: ");
			fflush(stdin);
			fgets(cad.notas_enf, 256, stdin);
			cad.notas_enf[strcspn(cad.notas_enf, "\n")] = 0;
		} else {
			printf("Erro de alocação de memória...");
			return;
		}


		fwrite(&cad, sizeof(CADASTRO), 1, arquivo);
		printf("Cadastro realizado!");

		free(cad.notas_enf);
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

/*Validação do CPF*/
int valida_cpf(char cpf[11]){
	int cpf_numeros[11]; //array que armazena os números inteiros
	int mult = 2, soma = 0, aux, dig1, dig2;
	for (int i = 0; i < 11; i++) {
        cpf_numeros[i] = cpf[i] - 48; //conversão de char para int
    }

	//loop para pegar o primeiro dígito
	for (int i = 8; i >= 0; i--) {
		soma = soma + (mult * cpf_numeros[i]);
		mult++;
	}

	aux = soma % 11;

	if (aux <= 2) {
		dig1 = 0;
	} else if (aux > 2 && aux < 11) {
		dig1 = 11 - aux;
	}

	soma = 0;
	mult = 2;
	aux = 0;
	//loop para pegar o segundo dígito
	for (int i = 9; i >= 0; i--) {
		soma = soma + (mult * cpf_numeros[i]);
		mult++;
	}

	aux = soma % 11;

	if (aux <= 2) {
		dig2 = 0;
	} else if (aux > 2 && aux < 11) {
		dig2 = 11 - aux;
	}	

	//validação
	int valido = 0;

	if (dig1 == cpf_numeros[10]) {valido++;}
	if (dig2 == cpf_numeros[11]) {valido++;}

	if (valido == 2) {
		return 1;
	} else {return 0;}
}