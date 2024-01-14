#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()// Função por cadastrar os usuarios nosistema 
{
	//inicio criação da variaveis /string
	char arquivo [40];
	char cpf[40];
	char nome[400];
	char sobrenome[40];
	char cargo[40];
	//final da  criação da variaveis /string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informaçõa do usuario
	scanf("%s", cpf);//salvando as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file;//cria o arquivo
	file =fopen(arquivo, "w");// cria o arquivo e o "w" siganifica estcrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
	while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	fclose(file);
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");	
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("/nCPF não cadastrado!\n\n");
	}
	
	remove(cpf);
	
	if(file!=NULL)
	{
		printf("\nUsuario deletado com sucesso!\n\n");
		system("pause");
	}
	
	fclose(file);
	
}


int main()
{
	int opcao=0;//Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem
	
		printf("### Cartório da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejadado menu:\n\n");
		printf("\t1-Registar Nomes\n");
		printf("\t2-Consultar Nomes\n");
		printf("\t3-Deletar Nomes\n\n");
		printf("Opção: ");//Fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usuario
		
		system("cls");	// responsavel por deletar a tela 
		
		switch(opcao)//inicio daseleção do menu
		{
			case 1:
			registro(); //chamada da função registro
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break; 
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
						
				
		}
	
	}
}
