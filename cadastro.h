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
	char notas_enf[256];
};

//Prototipos
void desativar_cliente(void);
void menu_principal(void);
void menu_clientes(void);
void cadastro0(void);
void desativar_cliente(void);
void excluir_cliente(void);
int valida_cpf(char cpf[11]);
void consultar(void);
void listar(void);
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
	char entra;
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
		    		listar();
		    		printf ("\n\n");
		    		break;
		    	
				case '3':
					printf ("\n           ########## CONSULTA DE CLIENTES ##########            ");
					consultar();	
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
	    
	    while (getchar() != '\n');
	    fgets (cad.nome, 51, stdin);
	   	cad.nome[strcspn(cad.nome, "\n")] = 0;
	    
		if (strlen(cad.nome) == 0) {
            printf("Nome não pode ser vazio!\n");
            return;
        }

	    printf ("Digite o CPF do cliente: ");
	    
	    fflush(stdin);
	   	fgets (cad.cpf, 12, stdin);
		cad.cpf[strcspn(cad.cpf, "\n")] = 0;
		
		// printf("CPF armazenado: '%s' (tamanho: %lu)\n", cad.cpf, strlen(cad.cpf));
		
		if (valida_cpf(cad.cpf) != 1) {
			printf("O CPF é inválido!");
			return;
		};

		cad.ativo = true;

		printf("Digite a data de nascimento (DD/MM/AAAA): ");

		while (getchar() != '\n');
		fgets(cad.data_nascimento, 11, stdin);
		cad.data_nascimento[strcspn(cad.data_nascimento, "\n")] = 0;

		printf("Digite o número de telefone ((XX) XXXXX-XXXX)");

		while (getchar() != '\n');
		fgets(cad.telefone, 15, stdin);
		cad.telefone[strcspn(cad.telefone, "\n")] = 0;

		//Alocação pras notas de enfermagem (como o cliente chegou, consciente/inconsciente, queixas etc.)
		printf("Digite as notas de enfermagem: ");
		fgets(cad.notas_enf, 256, stdin);
		cad.notas_enf[strcspn(cad.notas_enf, "\n")] = 0;

		fwrite(&cad, sizeof(CADASTRO), 1, arquivo);
		
		printf("Cadastro realizado!");
	}
	
	if (fclose(arquivo) == 0){
		printf ("\n");
	}else{
		printf ("Erro no fechamento do arquivo.\n");
	}
	
}

/*Consultar Cliente*/
void consultar() {
	char auxcpf[11];
	bool encontrado = false;

	fflush(stdin);
	printf("\n\n");
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", auxcpf);

	if (valida_cpf(auxcpf) != 1) {
		printf("O CPF é inválido!");
		return;
	};

	FILE* arquivo;
	CADASTRO cad;

	arquivo = fopen("clientes.txt", "rb");

	if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		}
    else{
    	printf ("\n           ########## CONSULTAR CLIENTE ##########            ");
	    while (fread(&cad, sizeof(CADASTRO), 1, arquivo) == 1) {
			if (strcmp(cad.cpf, auxcpf) == 0) {
				printf("\nCliente encontrado:");
				printf("\nNome: %s", cad.nome);
				printf("\nCPF: %s", cad.cpf);
				printf("\nData de Nascimento: %s", cad.data_nascimento);
				printf("\nTelefone: %s", cad.telefone);
				printf("\nNotas de Enfermagem: %s\n", cad.notas_enf);
				printf("\nStatus do Cliente: ");
				if(cad.ativo == true){
					printf("Ativo");
				} else{
					printf ("Desativado");
				}
				encontrado = true;
				break;
			} 
		}
		if (encontrado != true) {
				printf("\nCliente com o CPF %s não encontrado...\n", auxcpf);
		}

		fclose(arquivo);
	}
	Sleep(2000);
}

/*Listar clientes*/
void listar() {
	setlocale(LC_ALL, "portuguese");
	int i, j;

	FILE* arquivo;
	CADASTRO cad;
	CADASTRO *clientes = NULL;

	int contador = 0;

	arquivo = fopen("clientes.txt", "rb");
	if (arquivo == NULL) {
		printf("Sem usuários cadastrados...");
	} else {
		while(fread(&cad, sizeof(CADASTRO), 1, arquivo) == 1) {
			clientes = realloc(clientes, (contador + 1) * sizeof(CADASTRO));
			if (clientes == NULL) {
				printf("Erro de alocação de memória...\n");
				fclose(arquivo);
				return;
			}
			clientes[contador++] = cad;
		}
		fclose(arquivo);
	}

	for (i = 0; i < contador; i++) {
        for (j = 0; j < contador - i - 1; j++) {
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                // Trocar os clientes
                CADASTRO temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }

	printf("\n           ########## LISTA DE CLIENTES ##########            \n");
    for (i = 0; i < contador; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Data de Nascimento: %s\n", clientes[i].data_nascimento);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Notas de Enfermagem: %s\n", clientes[i].notas_enf);
        printf("Status do cliente: ");
        if(clientes[i].ativo = false){
        	printf("Desativado");
		} else{
			printf("Ativo");
		}
        printf("\n---------------------------------\n");
    }

	free(clientes);
	Sleep(2000);
}

/*Desativar clientes*/
void desativar_cliente(){
	
	char aux1;
	char saida = 1;
	char auxcpf[11];

	fflush(stdin);
	printf("\n\n");
	printf("Digite o CPF que deseja desativar: ");
	scanf("%s", auxcpf);

	if (valida_cpf(auxcpf) != 1) {
		printf("O CPF inválido!");
		return;
	};

	FILE* arquivo;
	CADASTRO cad;

	arquivo = fopen("clientes.txt", "rb");
	
	if(arquivo == NULL){
      	printf ("\n\n ERRO NA ABERTURA DO ARQUIVO \n\n");
		return;
	}

	FILE* auxil;
	auxil = fopen("auxil.txt", "wb");
	if (auxil == NULL) {
		printf("Erro na abertura do arquivo temporário.");
		fclose(auxil);
	} else {
		while(fread(&cad, sizeof(CADASTRO), 1, arquivo) == 1){
        	// auxil = fopen("auxil.txt", "ab");
        	if(strncmp(cad.cpf, auxcpf, 11) == 0){
				do{
					printf("\nNome: %s", cad.nome);
					printf("\nCPF: %s", cad.cpf);
					printf("\nSitua��o: ");
					if (cad.ativo == true){
						printf ("Ativo");
					} else{
						printf ("Desativado");
					}
				
					if (cad.ativo == true){
						printf ("\nDeseja desativar esse cliente? ");
						printf ("\n[s] para alterar [ESC] para sair: ");
						
						aux1 = getch();
						switch(aux1){
							case 's':
								cad.ativo = false;
								printf ("\nDesativado com Sucesso");
								saida = 0;
								break;
								
							case 'S':
								cad.ativo = false;
								printf ("\nDesativado com Sucesso");
								saida = 0;
								break;
							
							case (char)27:
								saida = 0;
								break;
							
							default:
								printf ("\n\nEscolha uma op��o valida");
								break;
						}
					}
				
				}while(saida == 1);
				
			}else{
				printf("erro");
			}
	
			fwrite(&cad, sizeof(CADASTRO), 1, auxil);
		    fclose(auxil);
		}
	}
	fclose(arquivo);
    remove("clientes.txt");
    rename("auxil.txt", "clientes.txt");
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
	int i;
	for (i = 0; i < 11; i++) {
        cpf_numeros[i] = cpf[i] - 48; //conversão de char para int
    }

	//loop para pegar o primeiro dígito
	for (i = 8; i >= 0; i--) {
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
	for (i = 9; i >= 0; i--) {
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

	if (dig1 == cpf_numeros[9]) {valido++;}
	if (dig2 == cpf_numeros[10]) {valido++;}

	if (valido == 2) {
		return 1;
	} else {return 0;}
}
