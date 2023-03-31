#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região 
#include <string.h> //Biblioteca responsável por cuidar dos string

int registrar() //Função responsavel por cadastrar os usuários no sistema / "int' Variável do tipo número inteiro
{
	//Inicio da criação da string/variavel
	char arquivo[40]; //Responsável por criar a string arquivo / "char' Representa os caracteres
	char cpf[40]; //Responsável por criar a string cpf / "char' Representa os caracteres
	char nome[40]; //Responsável por criar a string nome / "char' Representa os caracteres
	char sobrenome[40]; //Responsável por criar a string sobrenome / "char' Representa os caracteres
	char cargo[40]; //Responsável por criar a string cargo / "char' Representa os caracteres
	//Final da ciação da string/variavel
	
	printf("Digite o CPF para ser cadastrado:"); //Pede para que o usuário coloque suas infomções
	scanf("%s", cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo criado / o "w' cria e escreve o arquivo
	fprintf(file, "CPF: "); //O fprintf é igual o printf só que é escrito no sistema
	fprintf(file,cpf); //O fprintf é igual o printf só que é escrito no sistema, e nesse caso escreve a string cpf
	fprintf(file, "  "); //O fprintf é igual o printf só que é escrito no sistema
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome para ser cadastrado: "); //Pede para que o usuário coloque suas infomções
	scanf("%s", nome); //"%s" Salva dentro de uma string, no caso a string nome
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo já criado
	fprintf(file, "Nome: "); //O fprintf é igual o printf só que é escrito no sistema
	fprintf(file,nome); //O fprintf é igual o printf só que é escrito no sistema, e nesse caso escreve a string nome
	fprintf(file, "  "); //O fprintf é igual o printf só que é escrito no sistema
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome para ser cadastrado: "); //Pede para que o usuário coloque suas infomções
	scanf("%s", sobrenome); //"%s' Salva dentro de uma string, no caso a string sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo já criado
	fprintf(file, "Sobrenome: "); //O fprintf é igual o printf só que é escrito no sistema
	fprintf(file,sobrenome); //O fprintf é igual o printf só que é escrito no sistema, e nesse caso escreve a string sobrenome
	fprintf(file, "  "); //O fprintf é igual o printf só que é escrito no sistema
	fclose(file); //Fecha o arquivo

	printf ("Digite o cargo para ser cadastrado: "); //Pede para que o usuário coloque suas infomções
	scanf("%s", cargo); //"%s' Salva dentro de uma string, no caso a string cargo
	
	file = fopen(arquivo, "a"); //Abre o arquivo criado / o "a' atualiza o arquivo já criado
	fprintf(file, "Cargo: "); //O fprintf é igual o printf só que é escrito no sistema
	fprintf(file,cargo); //O fprintf é igual o printf só que é escrito no sistema, e nesse caso escreve a string cargo
	fprintf(file, "  "); //O fprintf é igual o printf só que é escrito no sistema
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Mantém as informções na tela
}

int consultar() //Função responsável por consultar os usuários no sistema / "int' Variável do tipo número inteiro
{
	setlocale(LC_ALL, "Portuguese"); //Língua escolhida para alocação do texto
	
	char cpf[40]; //String responsável pelo cpf / "char" Representa os caracteres
	char conteudo[200]; //Reponsável por todo o conteúdo que vai aparecer para o usuario / "char' Representa os caracteres
	
	printf("\n"); //Responsável por pular linha
	printf("Digite o CPF a ser consultado: "); //Pergunta feita para poder consultar o usuário
	scanf("%s",cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	FILE *file;  //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo criado / o "r' lê o arquivo
	
	if(file == NULL) //"if' opção de escolha, consiste na comparação de dois ou mais valores, e então a instrução
	{
		printf("\n\n"); //Responsável por pular linha
		printf("Não foi possivel localizar o arquivo!"); //Aviso dado ao usuário
		printf("\n\n"); //Responsável por pular linha
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Lê os arquivos criados
	{
		printf("\nEssa são as informções do usuario:\n\n"); //Aviso adado ao usuário
		printf("%s", conteudo); //"%s' Salva dentro de uma string, no caso a string conteudo
		printf("\n\n"); //Responsável por pular linha
	}
	
	system("pause"); //Mantém as informções na tela
	fclose(file); //Fecha o arquivo
}

int deletar() //Responsável por deletar os usuários do sistema / "int' Variável do tipo número inteiro
{
	setlocale(LC_ALL, "Portuguese"); //Língua escolhida para alocação do texto
	
	char cpf[40]; //String responsável pelo cpf / "char" Representa os caracteres
	
	printf("\n"); //Responsável por pular linha
	printf("Digite o CPF que será deletado: "); //Pede para o usuário informar o cpf que será deletado
	scanf("%s", cpf); //"%s' Salva dentro de uma string, no caso a string cpf
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo / "r' lê o arquivo
	
	if(file != NULL) //Significa "se', ou seja, se o pedido da frente for correspondido ele será rodado / "!=' Significa diferente
	{
		fclose(file); //Fecha o arquivo
		remove(cpf); //Excluí a string cpf do sistema
		printf("\n"); //Responsável por pular linha
		printf("CPF deletado com sucesso!\n\n"); //Aviso dado ao usuário
		system("pause"); //Mantém as informações na tela 
	}
	
	else //Também significa "se", ou seja, se o "if' não rodar ela será rodada OBS: O "else' NÃO PRECISA DE UM PEDIDO COMO O "if'
	{
		printf("\n"); //Responsável por pular linha
		printf("CPF não localizado no sistema\n\n"); //Informa que o cpf não foi enontrado
		system("pause"); //Mantém as informações na tela
	}
}

int main() //Função principal do sistema
{
	int opcao=0; //"opcao' É a variavel que salva as funções / O "=0' é muito importante pois é ele que diz que aquela variavel não esta disponível
	int x=1; //É a repetição feita pelo "for'
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("*** Cartório da EBAC ***\n\n");
	printf("Login de Administrador!\n\n");
	printf("Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(x=1;x=1;) //"for' Faz uma retição o quantas vezes for pedido, nesse caso o "x=1;x=1;' cria um loop e sempre será repetido
		{
	
	
    		setlocale(LC_ALL, "Portuguese"); //Língua escolhida para alocação do texto

			printf("*** Cartório da EBAC ***\n\n"); //Inicio do menu
    		printf("Ecolha seu menu:\n\n"); //Pede para o usuário escolher uma das opções abaixo
    		printf("\t1 - Registrar Nomes\n"); //Primeira opção / O "\t1 -' cria um número da frente na opção
			printf("\t2 - Consultar Nomes\n"); //Segunda opção / O "\t2 -' cria o número da frente na opção
    		printf("\t3 - Deletar Nomes\n"); //Terceira opção / O "\t2 -' cria o número da frente na opção
	    	printf("\t4 - Sair do Sistema\n\n");
	        printf("Opção:  "); //Final do menu
	
    		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    		system("cls"); //Responsável por limpar a tela 
    	
    		switch(opcao) //Inicio da seleção do menu
    		{
    			case 1: //Opção que será escolhida / Nesse caso o número é o mesmo das opções de cima e serve para puxar a funçao int ""
		        registrar(); //Chamada de funções // Puxa a função int registrar
    			break; //Pausa a função puxada para que não seja um loop eterno
    		
    			case 2: //Opção que será escolhida / Nesse caso o número é o mesmo das opções de cima e serve para puxar a funçao int ""
    				consultar(); //Chamada de funções
    		    break; //Pausa a função puxada para que não seja um loop eterno
    	    
    		    case 3: //Opção que será escolhida / Nesse caso o número é o mesmo das opções de cima e serve para puxar a funçao int ""
    		    	deletar(); //Chamada de funções
			    break; //Pausa a função puxada para que não seja um loop eterno
			    
		 		case 4:
					printf("Obrigado por ultilizar o sistema!\n"); //Mensagem de agradecimento ao fechar o sistema
			    	return 0; //Retorna para o status inicial, ou seja, fecha o sistema
			    break; //Pausa o comando para que o sistema não seja aberto novamnete
		    	
			    default: //Opção que será escolhida / Nesse caso é a opção inexistente, ou seja, qualquer opção que não seja nenhuma das acima 
			    	printf("Essa opção não existe\n\n"); //Informa o usuário
			        system("pause"); //Mantém as informações na tela
			    break; //Pausa a função puxada para que não seja um loop eterno
			} //Final da seleção
		}
	}
	else
		system("cls");
		printf("\n");
		printf("Senha Incorreta!\n");
}
