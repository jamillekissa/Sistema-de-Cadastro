#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USER 100

//Estrutura de dados
typedef struct{
	int id;
    char email[50];
    char nome[50];
    char profissao[50];
    int idade;
    int cel;
    int cep;
    int num_casa;
    char rua[50];
    char bairro[50];
    char complemento[50];
    int qtde_pessoas;
    double renda;
    char nome_user[50];
    char senha[50];
}Users;

//Função para cadastrar usuário
void cadastrar_user(Users users[], int *num_user){
	char conf_senha[50];
	
	if(*num_user == MAX_USER){
		printf("Limite maximo de usuarios atingido");
		return;
	}
	
	printf("Nome: ");
    scanf("%s", users[*num_user].nome);
    printf("Idade: ");
    scanf("%d", &users[*num_user].idade);
    printf("Email: ");
    scanf("%s", &users[*num_user].email);
    printf("Profissao: ");
    scanf("%s", users[*num_user].profissao);
    printf("Celular: ");
    scanf("%d", &users[*num_user].cel);
    printf("Renda mensal: ");
    scanf("%lf", &users[*num_user].renda);
    printf("Quantidade de pessoas que moram com você (incluindo você): ");
    scanf("%d", &users[*num_user].qtde_pessoas);
    printf("CEP: ");
    scanf("%d", &users[*num_user].cep);
    printf("Rua: ");
    scanf("%s", &users[*num_user].rua);
    printf("Bairro: ");
    scanf("%s", &users[*num_user].bairro);
    printf("Número da casa/apartamento: ");
    scanf("%d", &users[*num_user].num_casa);
    printf("Complemento: ");
    scanf("%s", &users[*num_user].complemento);
    printf("Nome de usuário: ");
    scanf("%s", &users[*num_user].nome_user);
    printf("Senha: ");
    scanf("%s", &users[*num_user].senha);
    printf("Confirmar senha: ");
    scanf("%s", &conf_senha);
	
	if(strcmp(users[*num_user].senha, conf_senha) != 0) {
        printf("\nAs senhas não coincidem!\n");
        return;
    }
	
	(*num_user)++;
	printf("Usuario cadastro com sucesso");
}


//Função para realizar login
void login(Users users[], int num_user){
	char login[50], senha[50];
	int i;
	printf("Nome de usuario: ");
	scanf("%s", &login);
	printf("Senha: ");
	scanf("%s", &senha);
	
	for (i = 0; i < num_user; i++) {
        if (strcmp(users[i].nome_user, login) == 0 && strcmp(users[i].senha, senha) == 0) {
            printf("\nLogin bem-sucedido! Bem-vindo, %s!\n", users[i].nome_user);
            return;
        }
    }
}

//Recuperar senha
void recuperar_senha(Users users[], int num_user){
	char nome[50], email[50];
	int op, cel, i;
	int user_encontrado;
	
	
	printf("Insira seu nome: ");
	scanf("%s", &nome);
	for(i = 0; i < num_user; i++){
		if(strcmp(users[i].nome, nome) == 0){
			user_encontrado = 1;
		}
		else{
			printf("Usuario não cadastrado no sistema");
		}
	}
	
	printf("Informe qual opcao deseja?: ");
	printf("\n1. Email");
	printf("\n2. Celular");
	printf("\nOpcao: ");
	scanf("%d", &op);
	if(op == 1){
		printf("\nInforme seu email: ");
		scanf("%s", &email);
		
		for(i = 0; i < num_user; i++){
			if (strcmp(users[i].nome, nome) == 0 && strcmp(users[i].email, email) == 0) {
                printf("\nSua senha é: %s\n", users[i].senha);
                return;
            }
            else{
            	printf("\nEmail nao cadastrado");
			}
		}
		
	} 
	else if(op == 2){
		printf("\nInforme seu celular: ");
		scanf("%d", &cel);
	
		for (int i = 0; i < num_user; i++) {
            if (strcmp(users[i].nome, nome) == 0 && users[i].cel == cel) {
                printf("\nSua senha é: %s\n", users[i].senha);
                return;
            }
            else{
            	printf("\nCelular nao cadastrado");
			}
        }
	}
	else{
		printf("\nOpcao invalida!");
	}
}


int main(){
	int num_user = 0;
	int opcao;
	Users users[MAX_USER];
	
	do{
		printf("------- Menu -------");
		printf("\n1. Realizar cadastro");
		printf("\n2. Realizar login");
		printf("\n3. Recuperar senha");
		printf("\n4. Editar dados");
		printf("\n5. Listar cadastros");
		printf("\n6. Sair");
		printf("-------------------");
		printf("\nDigite sua opcao: ");
		scanf("%d", &opcao);
		
		while(opcao > 6 || opcao < 1){
			printf("\nDigite sua opcao novamente: ");
			scanf("%d", &opcao);
		}
		
		switch(opcao){
			case 1:
				cadastrar_user(users, &num_user);
				system("cls");
				break;
			case 2:
				login(users, num_user);
				system("cls");
				break;
			case 3:
				recuperar_senha(users, num_user);
				system("cls");
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				printf("\nDigite uma opcao valida!");
		}
	} while(opcao >= 1 || opcao <= 6);

	return 0;
}
