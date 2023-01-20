#include <stdio.h>  // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() 	// Fun��o respons�vel por cadastrar os usu�rios no sistema	
{
    //in�cio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
		
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); 			// %s refere-se a string
	
	strcpy(arquivo, cpf);       // respons�vel por copiar o valor das string
	
	FILE *file;                 // cria um arquivo
	file = fopen(arquivo, "w"); // cria um arquivo e o "w" escreve 
	fprintf(file,cpf);          // salva o valor da vari�vel 
	fclose(file);               // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // abre o aquivo e o "a" est� atualizando 
	fprintf(file,","); 			// adciona um v�rgula 
	fclose(file);				//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");      // mostra ao usu�rio uma informa��o.
	scanf("%s",nome);						       	 // informa que a vari�vel nome ser� o texto inserido do usu�rio
	
	file = fopen(arquivo, "a");					     //abre o arquivo e atualiza 
	fprintf(file,nome);							     // coloca o "nome" inserido no c�digo anterior dentro do arquivo
	fclose(file);							         // fecha o arquivo
	
	file = fopen(arquivo, "a");                      // abre o arquivo e atualiza
	fprintf(file,",");						         // adciona v�rgula 
	fclose(file);									 // fecha o programa
	
	printf("Digite o sobrenome a ser cadastrado: "); // mostra ao usu�rio uma informa��o.
	scanf("%s", sobrenome);							 // informa que a vari�vel sobrenome ser� o texto inserido
	
	file = fopen(arquivo, "a");						 // abre o arquivo e atualiza 
	fprintf(file, sobrenome);					     // coloca o sobrenome dentro da pasta
	fclose(file);									 // fecha o arquivo
	
	file = fopen(arquivo, "a");                      // abre o arquivo para ser atulizado
	fprintf(file,",");								 // adciona v�rgula 
	fclose(file);									 // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");     // mostra ao usu�rio uma informa��o.
	scanf("%s", cargo);                              // pega a resposta do usu�rio e coloca na vari�vel cargo
	
	file = fopen(arquivo, "a");					     // abre um arquivo para ser atualizado
	fprintf(file, cargo);							 // coloca a vari�vel cargo dentro do arquivo
	fclose(file);									 // Fecha o arquivo
	
	system("cls");                                   // limpa a tela
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");                 // informa que o texto ser� em portugues e permite a leitura de acentua��o
	
	char cpf[40];                                    // definido a vari�vel cpf
	char conteudo[200];								 // definido a vari�vel conteudo
	
	printf("Digite o CPF a ser consultado: ");	     // mostra ao usu�rio uma informa��o.
	scanf("%s", cpf);                                // pega a resposta do usu�rio e coloca na vari�vel cpf
	
	FILE *file;										 // abre o arquivo
	file = fopen(cpf, "r");                          // abre o arquivo e o "r" l� o arquivo
	
	if(file == NULL)                                 // se(arquivo for igual nulo)      
	{ 
		printf("\n O arquivo n�o foi localizado no banco de dados! \n\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essa s�o as informa��es do usu�rio: ");  // mostra ao usu�rio uma informa��o, neste caso faz uma afirma��o.
		printf("%s", conteudo);                             // pega a resposta do usu�rio e coloca na vari�vel conteudo
		printf("\n\n");                                     // pular linhas
	}
	
	system("pause");                                        // pausa o sistema at� que o usu�rio saia.
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");					    // informa que o texto ser� em portugues e permite a leitura de acentua��o
	char cpf[40];                                           // cria a vari�vel cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: ");     // mostra ao usu�rio uma informa��o, neste caso faz uma pergunta.
	scanf("%s", cpf);									    // pega a resposta do usu�rio e coloca na vari�vel cpf
	
	remove(cpf);                                            // remove a vari�vel cpf do arquivo
	
	FILE *file;                                             // abre o arquivo
	file = fopen(cpf, "r"); 							    // abre o arquivo e o "r" l� o arquivo
	
	if (file == NULL)                                       // se o arquivo for igual a nulo
	{
		printf("\n O usu�rio n�o se encontra no sistema! \n\n "); // 
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");					    	         // limpa a tela
		
		setlocale(LC_ALL, "Portuguese");                 // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n");         //In�cio do menu 
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n"); 
		printf("\t4 - Sair do sistema \n\n");
		printf("Op��o: ");                               //Final do menu 
	
		scanf("%d", &opcao);                             //Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)                                    // in�cio das sele��es do menu
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es	
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel! \n\n");
			system("pause");
			break;	
		}												 // final das sele��es do menu 			
	}	
}
