/*
 Exemplo0003 - v0.2. - 10 / 02 / 2025
 Author: Izadora Galarza Alves
*/

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char* argv[])
{
	int opcao =0;

	printf("%s\n","Exemplo0003 - Programa = v0.3");
	printf("%s\n","Autor:Izadora Galarza Alves");
	printf("\n");

	 //ler opcao de teclado

	printf("%s\n","Escolha uma opcao: ");
	scanf("%d",&opcao);
	getchar(); //limpar a entrada de dados

	//mostrar a entrada de dado
	printf("%s = %d\n","Opcao escolhida:",opcao);


	//OPCOES

	switch(opcao)
		{
			case 0: break;
			default: printf("\nERRO: Opcao invalida.\n");
					 break;
		}

	//finalizar

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return(0);
}

/*
(NENHUM) documentacao complementar
(NENHUM) notas / observacoes / comentarios
Feitos imediatamente apos final da escrita - previsao de testes
a.) 5
b.) -5
c.) 123456789

---------------------------------------------- historico
Versao Data Modificacao
Nao houve
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK )
0.1 01. ( OK )
0.2 02. ( OK )
*/