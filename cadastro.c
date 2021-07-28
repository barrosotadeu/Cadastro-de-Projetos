
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int i = 0;
int j;
struct projeto{
	
		
	int codigo;
	char titulo[10];
	char descricao[100];
	int ano;
	int status;
	char setor[10];
	char gerente[10];
	int complexidade;
	int urgencia;
};
struct projeto lista[200];

void cadastraProjeto(){
	if(i < 200){
		lista[i].codigo = i +1;
		printf("Informe um título para o projeto: \n");
		fflush(stdin);
		gets(lista[i].titulo);
		printf("\nInforme uma desrição para o projeto: \n");
		fflush(stdin);
		gets(lista[i].descricao);
		printf("\nInforme o ano do projeto: \n");
		fflush(stdin);
		scanf("%d", &lista[i].ano);
	
	
		printf("\n Informe o status do projeto (1: A fazer; 2: Fazendo; 3: Concluído: )\n");
		fflush(stdin);
		scanf("%d", &lista[i].status);
		while(lista[i].status != 1 && lista[i].status != 2 && lista[i].status != 3)	{
			printf("Opção inválida! \n");
			printf("\n Informe o status do projeto (1: A fazer; 2: Fazendo; 3: Concluído: )\n");
			fflush(stdin);
			scanf("%d", &lista[i].status);
		}	

	
		printf("Status válido\n");
		printf("\nInforme o nível de complexidade do projeto(1: Simples; 2: Médio; 3: Complexo): \n");
		fflush(stdin);
		scanf("%d", &lista[i].complexidade);
		while(lista[i].complexidade != 1 && lista[i].complexidade != 2 && lista[i].complexidade != 3){
			printf("Opção inválida! \n");
			printf("\nInforme o nível de complexidade do projeto(1: Simples; 2: Médio; 3: Complexo): \n");
			fflush(stdin);
			scanf("%d", &lista[i].complexidade);
		}
		
		printf("Informe o setor responsável pelo projeto: \n");
		fflush(stdin);
		gets(lista[i].setor);
		printf("\nInforme o gerente do projeto:  \n");
		fflush(stdin);
		gets(lista[i].gerente);
		printf("Informe o nível de urgência do projeto (1: Baixa; 2: Média; 3:Alta)\n");
		fflush(stdin);
		scanf("%d", &lista[i].urgencia);
		while(lista[i].urgencia != 1 && lista[i].urgencia != 2 && lista[i].urgencia != 3){
			printf("Opção inválida");
			printf("Informe o nível de urgência do projeto (1: Baixa; 2: Média; 3:Alta)\n");
			fflush(stdin);
			scanf("%d", &lista[i].urgencia);
		}
	
		printf("Projeto %d cadastrado com sucesso!\n\n", lista[i].codigo);
		
		i += 1;

	}else{
		printf("Não foi possível cadastrar um novo projeto: número máximo de projetos alcançado");
	}
		
	
}

void printaProjeto(){
	printf("Código %d \n", lista[j].codigo);
	printf("Título: %s \n", lista[j].titulo);
	printf("Descrição: %s \n", lista[j].descricao);
	printf("Ano: %d \n", lista[j].ano);
	printf("Status: %d \n", lista[j].status);
	printf("Complexidade: %d \n", lista[j].complexidade);
	printf("Setor: %s \n", lista[j].setor);
	printf("Gerente: %s \n", lista[j].gerente);
	printf("Urgência: %d \n", lista[j].urgencia);
	printf("\n");	
}


void printaMenu(){
	int escolhaPrinta;
	int codigo;
	
	printf("\nQual/quais projetos você quer consultar? (1: Todos; 2: A fazer; 3: Fazendo; 4: Concluído; 5: Busca por código)\n");
	fflush(stdin);
	scanf("%d", &escolhaPrinta);
	while(escolhaPrinta != 1 && escolhaPrinta !=2 && escolhaPrinta !=3 && escolhaPrinta !=4 && escolhaPrinta != 5){
		printf("Opção inválida!");
		printf("\nQual/quais projetos você quer consultar? (1: Todos; 2: A fazer; 3: Fazendo; 4: Concluído; 5:Busca por código)\n");
		fflush(stdin);
		scanf("%d", &escolhaPrinta);
	}
	
	switch(escolhaPrinta){
		case 1:
		
		for(j = 0; j < i; j++){
			printaProjeto();			
		}
			
		break;
		
		case 2:
		printf("Projetos com o status 1 (A fazer): \n\n");
		for(j = 0; j < i; j++){
			if(lista[j].status == 1){
				printaProjeto();
				}
			}
		break;
			
		case 3:
		printf("Projetos com o status 2(Fazendo): \n\n");
		for(j = 0; j < i; j++){
			if(lista[j].status == 2){
				printaProjeto();
					}
				}
		break;
			
		case 4:
		printf("Projetos com o status 3(Concluído): \n\n");
		for(j = 0; j < i; j++){
			if(lista[j].status == 3){
				printaProjeto();
			}
		}
		break;
		
		case 5:
		
		printf("Informe o código que você quer buscar: \n\n");
		fflush(stdin);
		scanf("%d", &codigo);
		for(j = 0; j < i; j++){
			if(lista[j].codigo == codigo){
				printaProjeto();
			}
		}
			
		
		}		
		}
	
	



int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int escolha;	
	


		
	
	
	
	printf("Sistema de projetos: \n");
	
	for (;;)
	{
	
		printf("Você deseja criar um novo projeto ou consultar os projetos existentes (1: Novo projeto, 2: projetos existentes)? \n");
		fflush(stdin);
		scanf("%d", &escolha);
		while(escolha != 1 && escolha != 2){
			printf("Opção inválida!\n");
			printf("Você deseja criar um novo projeto ou consultar os projetos existentes (1: Novo projeto, 2: projetos existentes)? \n");
			fflush(stdin);
			scanf("%d", &escolha);
		}
		if (escolha == 1) {
			cadastraProjeto();
		
		}else{
			printaMenu();		
		}
			
		
		
		
    }
}
