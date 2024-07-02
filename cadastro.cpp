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
    printf("Renda mensal (Digite com ponto como separador): ");
    scanf("%lf", &users[*num_user].renda);
    printf("Quantidade de pessoas que moram com você (incluindo você): ");
    scanf("%d", &users[*num_user].qtde_pessoas);
    printf("CEP: ");
    scanf("%d", &users[*num_user].cep);
    printf("Rua: ");
    scanf("%s", &users[*num_user].rua);
    printf("Bairro: ");
    scanf("%s", &users[*num_user].bairro);
    printf("Numero da casa/apartamento: ");
    scanf("%d", &users[*num_user].num_casa);
    printf("Complemento: ");
    scanf("%s", &users[*num_user].complemento);
    printf("Nome de usuario: ");
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

void editar_dados(Users users[], int num_user){
	char nome_user[50];
    int i, opcao;

    printf("Informe o nome de usuário que deseja editar: ");
    scanf("%s", nome_user);

    for (i = 0; i < num_user; i++) {
        if (strcmp(users[i].nome_user, nome_user) == 0) {
            printf("\nUsuário encontrado. Escolha o que deseja editar:");
            printf("\n1. Nome");
            printf("\n2. Idade");
            printf("\n3. Email");
            printf("\n4. Profissão");
            printf("\n5. Celular");
            printf("\n6. Renda mensal");
            printf("\n7. Quantidade de pessoas");
            printf("\n8. CEP");
            printf("\n9. Rua");
            printf("\n10. Bairro");
            printf("\n11. Número da casa/apartamento");
            printf("\n12. Complemento");
            printf("\n13. Senha");
            printf("\nOpção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Nome atual: %s\n", users[i].nome);
                    printf("Novo nome: ");
                    scanf("%s", users[i].nome);
                    break;
                case 2:
                    printf("Idade atual: %d\n", users[i].idade);
                    printf("Nova idade: ");
                    scanf("%d", &users[i].idade);
                    break;
                case 3:
                    printf("Email atual: %s\n", users[i].email);
                    printf("Novo email: ");
                    scanf("%s", users[i].email);
                    break;
                case 4:
                    printf("Profissão atual: %s\n", users[i].profissao);
                    printf("Nova profissão: ");
                    scanf("%s", users[i].profissao);
                    break;
                case 5:
                    printf("Celular atual: %d\n", users[i].cel);
                    printf("Novo celular: ");
                    scanf("%d", &users[i].cel);
                    break;
                case 6:
                    printf("Renda mensal atual: %.2lf\n", users[i].renda);
                    printf("Nova renda mensal: ");
                    scanf("%lf", &users[i].renda);
                    break;
                case 7:
                    printf("Quantidade de pessoas atual: %d\n", users[i].qtde_pessoas);
                    printf("Nova quantidade de pessoas: ");
                    scanf("%d", &users[i].qtde_pessoas);
                    break;
                case 8:
                    printf("CEP atual: %d\n", users[i].cep);
                    printf("Novo CEP: ");
                    scanf("%d", &users[i].cep);
                    break;
                case 9:
                    printf("Rua atual: %s\n", users[i].rua);
                    printf("Nova rua: ");
                    scanf("%s", users[i].rua);
                    break;
                case 10:
                    printf("Bairro atual: %s\n", users[i].bairro);
                    printf("Novo bairro: ");
                    scanf("%s", users[i].bairro);
                    break;
                case 11:
                    printf("Número da casa/apartamento atual: %d\n", users[i].num_casa);
                    printf("Novo número da casa/apartamento: ");
                    scanf("%d", &users[i].num_casa);
                    break;
                case 12:
                    printf("Complemento atual: %s\n", users[i].complemento);
                    printf("Novo complemento: ");
                    scanf("%s", users[i].complemento);
                    break;
                case 13:
                    printf("Senha atual: %s\n", users[i].senha);
                    printf("Nova senha: ");
                    scanf("%s", users[i].senha);
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
            }
            printf("Dados atualizados com sucesso!\n");
            return;
		}	
	}
}

void listar_cadastro(Users users[], int num_user){
	int i;
    for (i = 0; i < num_user; i++) {
        printf("\nID: %d", users[i].id);
        printf("\nNome: %s", users[i].nome);
        printf("\nIdade: %d", users[i].idade);
        printf("\nEmail: %s", users[i].email);
        printf("\nProfissão: %s", users[i].profissao);
        printf("\nCelular: %d", users[i].cel);
        printf("\nRenda mensal: %.2lf", users[i].renda);
        printf("\nQuantidade de pessoas que moram com você (incluindo você): %d", users[i].qtde_pessoas);
        printf("\nCEP: %d", users[i].cep);
        printf("\nRua: %s", users[i].rua);
        printf("\nBairro: %s", users[i].bairro);
        printf("\nNúmero da casa/apartamento: %d", users[i].num_casa);
        printf("\nComplemento: %s", users[i].complemento);
        printf("\nNome de usuário: %s\n", users[i].nome_user);
    }
}

void salvar_txt(Users users[], int num_user){
	int i;
	FILE *arquivo = fopen("usuario.txt", "w");
	
	if(arquivo == NULL){
		printf("Arquivo não encontrado!");
	}
	else {
		for(i = 0; i <= num_user; i++){
			fprintf(arquivo, "ID: %d\n", users[i].id);
        	fprintf(arquivo, "Nome: %s\n", users[i].nome);
        	fprintf(arquivo, "Idade: %d\n", users[i].idade);
        	fprintf(arquivo, "Email: %s\n", users[i].email);
        	fprintf(arquivo, "Profissão: %s\n", users[i].profissao);
        	fprintf(arquivo, "Celular: %d\n", users[i].cel);
        	fprintf(arquivo, "Renda mensal: %.2lf\n", users[i].renda);
        	fprintf(arquivo, "Quantidade de pessoas: %d\n", users[i].qtde_pessoas);
        	fprintf(arquivo, "CEP: %d\n", users[i].cep);
        	fprintf(arquivo, "Rua: %s\n", users[i].rua);
        	fprintf(arquivo, "Bairro: %s\n", users[i].bairro);
        	fprintf(arquivo, "Número da casa/apartamento: %d\n", users[i].num_casa);
        	fprintf(arquivo, "Complemento: %s\n", users[i].complemento);
        	fprintf(arquivo, "Nome de usuário: %s\n", users[i].nome_user);
        	fprintf(arquivo, "Senha: %s\n", users[i].senha);
        	fprintf(arquivo, "-------------------\n");
		}
		fclose(arquivo);
		printf("Dados cadastrados com sucesso!");
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
		printf("\n6. Salvar em um arquivo txt");
		printf("\n7. Sair");
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
				editar_dados(users, num_user);
				break;
			case 5:
				listar_cadastro(users, num_user);
				break;
			case 6:
				salvar_txt(users, num_user);
				break;
			case 7:
				break;
			default:
				printf("\nDigite uma opcao valida!");
		}
	} while(opcao >= 1 || opcao <= 6);

	return 0;
}
