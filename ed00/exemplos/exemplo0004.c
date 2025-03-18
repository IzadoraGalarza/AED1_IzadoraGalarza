/*
 Exemplo0004 - v0.4 - 10 / 02 / 2025
 Author: Izadora Galarza Alves
*/
#include <stdio.h>
#include <stdlib.h> 
/**
Metodo 01.
*/
void method_01 ( void )
{
// identificar
printf ( "%s\n", "Metodo 01" );
// encerrar
printf ( "\nApertar ENTER para continuar.\n" );
getchar ( );
} // end method_01 ( )
int main (int argc, char* argv[])
{
	int opcao =0;

	printf("%s\n","4 - Programa = v0.4");
	printf("%s\n","Autor:Izadora Galarza Alves");
	printf("\n");


	//mostrar opcoes
	printf ( "\n%s\n", "Opcoes:" );
	printf ( "\n%s" , "0 - Terminar" );
	printf ( "\n%s" , "1 - Metodo 01" );
	printf ( "\n" );
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
			case 1: method_01(); 
				    break;
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
0.3 03. ( OK )
0.4 04. ( OK )

*/