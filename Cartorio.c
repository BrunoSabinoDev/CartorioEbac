#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o 
#include <string.h> //Biblioteca respons�vel por cuidar dos string

int registrar() //Fun��o responsavel por cadastrar os usu�rios no sistema / "int' Vari�vel do tipo n�mero inteiro
{
	//Inicio da cria��o da string/variavel
	char arquivo[40]; //Respons�vel por criar a string arquivo / "char' Representa os caracteres
	char cpf[40]; //Respons�vel por criar a string cpf / "char' Representa os caracteres
	char nome[40]; //Respons�vel por criar a string nome / "char' Representa os caracteres
	char sobrenome[40]; //Respons�vel por criar a string sobrenome / "char' Representa os caracteres
	char cargo[40]; //Respons�vel por criar a string cargo / "char' Representa os caracteres
	//Final da cia��o da string/variavel
	
	printf("Digite o CPF para ser cadastrado:"); //Pede para que o usu�rio coloque suas infom��es
	scanf("%s", cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo criado / o "w' cria e escreve o arquivo
	fprintf(file, "CPF: "); //O fprintf � igual o printf s� que � escrito no sistema
	fprintf(file,cpf); //O fprintf � igual o printf s� que � escrito no sistema, e nesse caso escreve a string cpf
	fprintf(file, "  "); //O fprintf � igual o printf s� que � escrito no sistema
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome para ser cadastrado: "); //Pede para que o usu�rio coloque suas infom��es
	scanf("%s", nome); //"%s" Salva dentro de uma string, no caso a string nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo j� criado
	fprintf(file, "Nome: "); //O fprintf � igual o printf s� que � escrito no sistema
	fprintf(file,nome); //O fprintf � igual o printf s� que � escrito no sistema, e nesse caso escreve a string nome
	fprintf(file, "  "); //O fprintf � igual o printf s� que � escrito no sistema
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome para ser cadastrado: "); //Pede para que o usu�rio coloque suas infom��es
	scanf("%s", sobrenome); //"%s' Salva dentro de uma string, no caso a string sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo j� criado
	fprintf(file, "Sobrenome: "); //O fprintf � igual o printf s� que � escrito no sistema
	fprintf(file,sobrenome); //O fprintf � igual o printf s� que � escrito no sistema, e nesse caso escreve a string sobrenome
	fprintf(file, "  "); //O fprintf � igual o printf s� que � escrito no sistema
	fclose(file); //Fecha o arquivo

	printf ("Digite o cargo para ser cadastrado: "); //Pede para que o usu�rio coloque suas infom��es
	scanf("%s", cargo); //"%s' Salva dentro de uma string, no caso a string cargo
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo j� criado
	fprintf(file, "Cargo: "); //O fprintf � igual o printf s� que � escrito no sistema
	fprintf(file,cargo); //O fprintf � igual o printf s� que � escrito no sistema, e nesse caso escreve a string cargo
	fprintf(file, "  "); //O fprintf � igual o printf s� que � escrito no sistema
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Mant�m as inform��es na tela
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema / "int' Vari�vel do tipo n�mero inteiro
{
	setlocale(LC_ALL, "Portuguese"); //L�ngua escolhida para aloca��o do texto
	
	char cpf[40]; //String respons�vel pelo cpf / "char" Representa os caracteres
	char conteudo[200]; //Repons�vel por todo o conte�do que vai aparecer para o usuario / "char' Representa os caracteres
	
	printf("\n"); //Respons�vel por pular linha
	printf("Digite o CPF a ser consultado: "); //Pergunta feita para poder consultar o usu�rio
	scanf("%s",cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	FILE *file;  //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo criado / o "r' l� o arquivo
	
	if(file == NULL) //"if' op��o de escolha, consiste na compara��o de dois ou mais valores, e ent�o a instru��o
	{
		printf("\n\n"); //Respons�vel por pular linha
		printf("N�o foi possivel localizar o arquivo!"); //Aviso dado ao usu�rio
		printf("\n\n"); //Respons�vel por pular linha
	}
	
	while(fgets(conteudo, 200, file) != NULL)//L� os arquivos criados
	{
		printf("\nEssa s�o as inform��es do usuario:\n\n"); //Aviso adado ao usu�rio
		printf("%s", conteudo); //"%s' Salva dentro de uma string, no caso a string conteudo
		printf("\n\n"); //Respons�vel por pular linha
	}
	
	system("pause"); //Mant�m as inform��es na tela
	fclose(file); //Fecha o arquivo
}

int deletar() //Respons�vel por deletar os usu�rios do sistema / "int' Vari�vel do tipo n�mero inteiro
{
	setlocale(LC_ALL, "Portuguese"); //L�ngua escolhida para aloca��o do texto
	
	char cpf[40]; //String respons�vel pelo cpf / "char" Representa os caracteres
	
	printf("\n"); //Respons�vel por pular linha
	printf("Digite o CPF que ser� deletado: "); //Pede para o usu�rio informar o cpf que ser� deletado
	scanf("%s", cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo / "r' l� o arquivo
	
	if(file != NULL) //Significa "se', ou seja, se o pedido da frente for correspondido ele ser� rodado / "!=' Significa diferente
	{
		fclose(file); //Fecha o arquivo
		remove(cpf); //Exclu� a string cpf do sistema
		printf("\n"); //Respons�vel por pular linha
		printf("CPF deletado com sucesso!\n\n"); //Aviso dado ao usu�rio
		system("pause"); //Mant�m as informa��es na tela 
	}
	
	else //Tamb�m significa "se", ou seja, se o "if' n�o rodar ela ser� rodada OBS: O "else' N�O PRECISA DE UM PEDIDO COMO O "if'
	{
		printf("\n"); //Respons�vel por pular linha
		printf("CPF n�o localizado no sistema\n\n"); //Informa que o cpf n�o foi enontrado
		system("pause"); //Mant�m as informa��es na tela
	}
}

int main() //Fun��o principal do sistema
{
	int opcao=0; //"opcao' � a variavel que salva as fun��es / O "=0' � muito importante pois � ele que diz que aquela variavel n�o esta dispon�vel
	int x=1; //� a repeti��o feita pelo "for'
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("*** Cart�rio da EBAC ***\n\n");
	printf("Login de Administrador!\n\n");
	printf("Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(x=1;x=1;) //"for' Faz uma reti��o o quantas vezes for pedido, nesse caso o "x=1;x=1;' cria um loop e sempre ser� repetido
		{
	
	
    		setlocale(LC_ALL, "Portuguese"); //L�ngua escolhida para aloca��o do texto

			printf("*** Cart�rio da EBAC ***\n\n"); //Inicio do menu
    		printf("Ecolha seu menu:\n\n"); //Pede para o usu�rio escolher uma das op��es abaixo
    		printf("\t1 - Registrar Nomes\n"); //Primeira op��o / O "\t1 -' cria um n�mero da frente na op��o
			printf("\t2 - Consultar Nomes\n"); //Segunda op��o / O "\t2 -' cria o n�mero da frente na op��o
    		printf("\t3 - Deletar Nomes\n"); //Terceira op��o / O "\t2 -' cria o n�mero da frente na op��o
	    	printf("\t4 - Sair do Sistema\n\n");
	        printf("Op��o:  "); //Final do menu
	
    		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    		system("cls"); //Respons�vel por limpar a tela 
    	
    		switch(opcao) //Inicio da sele��o do menu
    		{
    			case 1: //Op��o que ser� escolhida / Nesse caso o n�mero � o mesmo das op��es de cima e serve para puxar a fun�ao int ""
		        registrar(); //Chamada de fun��es // Puxa a fun��o int registrar
    			break; //Pausa a fun��o puxada para que n�o seja um loop eterno
    		
    			case 2: //Op��o que ser� escolhida / Nesse caso o n�mero � o mesmo das op��es de cima e serve para puxar a fun�ao int ""
    				consultar(); //Chamada de fun��es
    		    break; //Pausa a fun��o puxada para que n�o seja um loop eterno
    	    
    		    case 3: //Op��o que ser� escolhida / Nesse caso o n�mero � o mesmo das op��es de cima e serve para puxar a fun�ao int ""
    		    	deletar(); //Chamada de fun��es
			    break; //Pausa a fun��o puxada para que n�o seja um loop eterno
			    
		 		case 4:
					printf("Obrigado por ultilizar o sistema!\n"); //Mensagem de agradecimento ao fechar o sistema
			    	return 0; //Retorna para o status inicial, ou seja, fecha o sistema
			    break; //Pausa o comando para que o sistema n�o seja aberto novamnete
		    	
			    default: //Op��o que ser� escolhida / Nesse caso � a op��o inexistente, ou seja, qualquer op��o que n�o seja nenhuma das acima 
			    	printf("Essa op��o n�o existe\n\n"); //Informa o usu�rio
			        system("pause"); //Mant�m as informa��es na tela
			    break; //Pausa a fun��o puxada para que n�o seja um loop eterno
			} //Final da sele��o
		}
	}
	else
		system("cls");
		printf("\n");
		printf("Senha Incorreta!\n");
}
