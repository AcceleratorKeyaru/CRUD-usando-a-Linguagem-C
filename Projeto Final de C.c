// PEDRO VINÍCIUS MORAES ALVES


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100


enum X{
	
	VI=0
	
}REF2;

typedef struct { 

char nome[MAX];
int idade;
char descricao[MAX];

}Lab_Members;

Lab_Members CAD[MAX];
unsigned int cadastrar();
unsigned int contador();
void editar();
void excluir();
void pesquisar();
void listar();
int cont=VI;
FILE *arq;


int main(){
arq=fopen("CONT.txt","r");
fscanf(arq,"%i\n",&cont);
fclose(arq);
setlocale(LC_ALL, "Portuguese");	
int OP;
int I;	
char sair=1;
arq=fopen("LAB_MEMBERS.txt","r");
for(I=0;I<cont;I++){
	
	
	fscanf(arq,"%s", &CAD[I].nome);
	fscanf(arq,"%i", &CAD[I].idade);
	fscanf(arq,"%s", &CAD[I].descricao);
	
}
fclose(arq);

do {

system("cls");

printf("***********************************************************************************************************************\nCadastro Lab_Members \nEscolha uma das opções:\n1-Cadastrar\t2-Editar\t3-Excluir\t4-Pesquisar\t5-Listar Ordenado\t6-Sair\n***********************************************************************************************************************\n\n"); // Menu
scanf("%i",&OP);
switch (OP){

	case 1: cadastrar();
			contador();
			break;
	case 2: editar();
			break;
	case 3: excluir();
			contador();
			break;
	case 4: pesquisar();
			break;
	case 5: listar();	
			break;
	case 6: sair=0;
			break;

	default:
			 printf("\nERROR!!\n");
			 system("pause"); 
			 break;
}


}while(sair!=0);





}


unsigned int cadastrar(){
	
	
	system("cls");
	int sair=1;
	char saida;
	arq=fopen("LAB_MEMBERS.txt","a+");
	do{
		printf("\nCADASTRO DO LAB_MEMBER %03i",cont+1);
		printf("\nDigite o nome do Novo Membro:");
		fflush(stdin);
		gets(CAD[cont].nome);
		fprintf(arq,"%s\n",CAD[cont].nome);
		printf("\nDigite a idade do Novo Membro:");
		scanf("%i",&CAD[cont].idade);
		fprintf(arq,"%i",CAD[cont].idade);
		printf("\nDigite uma descrição para o Novo Membro:");
		fflush(stdin);
		gets(CAD[cont].descricao);
		fprintf(arq,"\n%s\n",CAD[cont].descricao);
		cont++;
		printf("\nDeseja Cadastrar Outro Usuario?(S ou N)\n");
		scanf("%c",&saida);
		if(saida=='N'||saida=='n'){
			sair=0;
			system("cls");
		}
		else if(saida=='S'||saida=='s'){
			system("cls");
		}
		else{
			
			printf("\nDigito Invalido!!!\nSAINDO DO CADASTRO...\n");
			sair=0;
			system("pause");
			system("cls");
		}
	}while(sair!=0);
	fclose(arq);			
	system("cls");
	return(cont);
}

unsigned int contador(){
	
	arq=fopen("CONT.txt","w+");
	fprintf(arq,"%i",cont);
	fclose(arq);
	
}

void listar(){
	
	int Listar;
	system("cls");
	for(Listar=0;Listar<cont;Listar++){
		
		printf("\nLab Member%03i:",Listar+1);
		printf("%s\n\n",CAD[Listar].nome);
		printf("Idade:%i\n\n",CAD[Listar].idade);
		printf("Descricao do Lab Member:\n\n%s\n",CAD[Listar].descricao);		
	}
	system("pause");
	system("cls");
}

void editar(){
	
	int sair2=1;
	char saida2;
	int CAC;
	do{
	
	system("cls");
	
	printf("Digite o Numero(ID) do LAB_MEMBER:");
	scanf("%i",&CAC);
	if(CAC==0){
		CAC++;
	}
	else{
	}
	CAC=CAC-1;
	if(CAC>=cont||cont==0){
		printf("\n Usuario nao cadastrado!!");
	}
	else{
		
		printf("\nDigite as modificacoes do Membro %03i\nNome:",CAC+1);
		fflush(stdin);
		gets(CAD[CAC].nome);
		printf("\nIdade:");
		scanf("%i",&CAD[CAC].idade);
		printf("\nDescricao:");
		fflush(stdin);
		gets(CAD[CAC].descricao);
		
	}
	printf("\nDeseja Editar Outro Usuario?(S ou N)\n");
		fflush(stdin);
		scanf("%c",&saida2);
		if(saida2=='N'||saida2=='n'){
			sair2=0;
			system("cls");
		}
		else if(saida2=='S'||saida2=='s'){
			system("cls");
		}
		else{
			
			printf("\nDigito Invalido!!!\nSAINDO DA EDICAO...\n");
			sair2=0;
			system("pause");
			system("cls");
		}
	}while(sair2!=0);
	
	arq=fopen("LAB_MEMBERS.txt","w+");
	
	for(CAC=0;CAC<cont;CAC++){

	fprintf(arq,"%s\n",CAD[CAC].nome);		
	fprintf(arq,"%i",CAD[CAC].idade);		
	fprintf(arq,"\n%s\n",CAD[CAC].descricao);			
	
	}
	fclose(arq);
}




void pesquisar(){
	
	int sair3=1;
	char saida3;
	int CAC2;
	do{
	
	system("cls");
	
	printf("Digite o Numero(ID) do LAB_MEMBER:");
	scanf("%i",&CAC2);
	if(CAC2==0){
		CAC2++;
	}
	else{
	}
	CAC2=CAC2-1;
	if(CAC2>=cont||cont==0){
		printf("\n Usuario nao cadastrado!!");
	}
	else{
	
		printf("\nLab Member%03i:",CAC2+1);
		printf("%s\n\n",CAD[CAC2].nome);
		printf("Idade:%i\n\n",CAD[CAC2].idade);
		printf("Descricao do Lab Member:\n\n%s\n",CAD[CAC2].descricao);	
	
	}
	
	printf("\nDeseja Pesquisar Outro Usuario?(S ou N)\n");
		fflush(stdin);
		scanf("%c",&saida3);
		if(saida3=='N'||saida3=='n'){
			sair3=0;
			system("cls");
		}
		else if(saida3=='S'||saida3=='s'){
			system("cls");
		}
		else{
			
			printf("\nDigito Invalido!!!\nSAINDO DA PESQUISA...\n");
			sair3=0;
			system("pause");
			system("cls");
		}
	}while(sair3!=0);
	

}


void excluir(){

	int sair4=1;
	char saida4;
	int CAC4;
	arq=fopen("VAZIO.txt","a");
	fprintf(arq,"NULL");
	fprintf(arq,"\nNULL");
	do{
	
	system("cls");
	
	printf("Digite o Numero(ID) do LAB_MEMBER:");
	scanf("%i",&CAC4);
	if(CAC4==0){
		CAC4++;
	}
	else{
	}
	CAC4=CAC4-1;
	if(CAC4>=cont||cont==0){
		printf("\n Usuario nao cadastrado!!");
	}
	else{	
	
	fscanf(arq,"%s",CAD[CAC4].nome);
	CAD[CAC4].idade=0;
	fscanf(arq,"%s",CAD[CAC4].descricao);
	
	
	}
	
	printf("\nDeseja EXCLUIR Outro Usuario?(S ou N)\n");
		fflush(stdin);
		scanf("%c",&saida4);
		if(saida4=='N'||saida4=='n'){
			sair4=0;
			system("cls");
		}
		else if(saida4=='S'||saida4=='s'){
			system("cls");
		}
		else{
			
			printf("\nDigito Invalido!!!\nSAINDO DA PESQUISA...\n");
			sair4=0;
			system("pause");
			system("cls");
		}
		fclose(arq);
	}while(sair4!=0);
	arq=fopen("LAB_MEMBERS.txt","w+");
	
	for(CAC4=0;CAC4<cont;CAC4++){

	fprintf(arq,"%s\n",CAD[CAC4].nome);		
	fprintf(arq,"%i",CAD[CAC4].idade);		
	fprintf(arq,"\n%s\n",CAD[CAC4].descricao);			
	
	}
	fclose(arq);
}
	
	

