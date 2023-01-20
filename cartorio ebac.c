#include <stdio.h>  // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() 	// Função responsável por cadastrar os usuários no sistema	
{
    //início da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
		
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); 			// %s refere-se a string
	
	strcpy(arquivo, cpf);       // responsável por copiar o valor das string
	
	FILE *file;                 // cria um arquivo
	file = fopen(arquivo, "w"); // cria um arquivo e o "w" escreve 
	fprintf(file,cpf);          // salva o valor da variável 
	fclose(file);               // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // abre o aquivo e o "a" está atualizando 
	fprintf(file,","); 			// adciona um vírgula 
	fclose(file);				//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");      // mostra ao usuário uma informação.
	scanf("%s",nome);						       	 // informa que a variável nome será o texto inserido do usuário
	
	file = fopen(arquivo, "a");					     //abre o arquivo e atualiza 
	fprintf(file,nome);							     // coloca o "nome" inserido no código anterior dentro do arquivo
	fclose(file);							         // fecha o arquivo
	
	file = fopen(arquivo, "a");                      // abre o arquivo e atualiza
	fprintf(file,",");						         // adciona vírgula 
	fclose(file);									 // fecha o programa
	
	printf("Digite o sobrenome a ser cadastrado: "); // mostra ao usuário uma informação.
	scanf("%s", sobrenome);							 // informa que a variável sobrenome será o texto inserido
	
	file = fopen(arquivo, "a");						 // abre o arquivo e atualiza 
	fprintf(file, sobrenome);					     // coloca o sobrenome dentro da pasta
	fclose(file);									 // fecha o arquivo
	
	file = fopen(arquivo, "a");                      // abre o arquivo para ser atulizado
	fprintf(file,",");								 // adciona vírgula 
	fclose(file);									 // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");     // mostra ao usuário uma informação.
	scanf("%s", cargo);                              // pega a resposta do usuário e coloca na variável cargo
	
	file = fopen(arquivo, "a");					     // abre um arquivo para ser atualizado
	fprintf(file, cargo);							 // coloca a variável cargo dentro do arquivo
	fclose(file);									 // Fecha o arquivo
	
	system("cls");                                   // limpa a tela
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");                 // informa que o texto será em portugues e permite a leitura de acentuação
	
	char cpf[40];                                    // definido a variável cpf
	char conteudo[200];								 // definido a variável conteudo
	
	printf("Digite o CPF a ser consultado: ");	     // mostra ao usuário uma informação.
	scanf("%s", cpf);                                // pega a resposta do usuário e coloca na variável cpf
	
	FILE *file;										 // abre o arquivo
	file = fopen(cpf, "r");                          // abre o arquivo e o "r" lê o arquivo
	
	if(file == NULL)                                 // se(arquivo for igual nulo)      
	{ 
		printf("\n O arquivo não foi localizado no banco de dados! \n\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essa são as informações do usuário: ");  // mostra ao usuário uma informação, neste caso faz uma afirmação.
		printf("%s", conteudo);                             // pega a resposta do usuário e coloca na variável conteudo
		printf("\n\n");                                     // pular linhas
	}
	
	system("pause");                                        // pausa o sistema até que o usuário saia.
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");					    // informa que o texto será em portugues e permite a leitura de acentuação
	char cpf[40];                                           // cria a variável cpf
	
	printf("Digite o CPF do usuário a ser deletado: ");     // mostra ao usuário uma informação, neste caso faz uma pergunta.
	scanf("%s", cpf);									    // pega a resposta do usuário e coloca na variável cpf
	
	remove(cpf);                                            // remove a variável cpf do arquivo
	
	FILE *file;                                             // abre o arquivo
	file = fopen(cpf, "r"); 							    // abre o arquivo e o "r" lê o arquivo
	
	if (file == NULL)                                       // se o arquivo for igual a nulo
	{
		printf("\n O usuário não se encontra no sistema! \n\n "); // 
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");					    	         // limpa a tela
		
		setlocale(LC_ALL, "Portuguese");                 // Definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n");         //Início do menu 
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n"); 
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: ");                               //Final do menu 
	
		scanf("%d", &opcao);                             //Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)                                    // início das seleções do menu
		{
			case 1: 
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções	
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel! \n\n");
			system("pause");
			break;	
		}												 // final das seleções do menu 			
	}	
}
