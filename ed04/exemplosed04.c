/*
Exemplo0400 - v0.0. - 17 / 03 / 2025
Author: Izadora Galarza Alves
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"io.h"
#include<string.h>



void method_00 ()
{

}


void method_01 (void)
{
	int quantidade =0;
	int valor=0;
	int controle=0;

	IO_id("Exemplo0401 - ED04 - Izadora Galarza Alves");

	quantidade = IO_readint("Entrar com quantidade: ");
	//repetir para a quantidade de vezes informada
	controle =1;
	while( controle <=quantidade)
	{
	valor = IO_readint (IO_concat( IO_concat        ("",IO_toString_d(controle)),":"));
	printf("\n%s%d\n","Valor =", valor);
	controle++;
	}
	IO_pause("Apertar ENTER para continuar.");
}


bool positivo (int x)
{
	bool result = false;
	if( x>0)
	{
		result = true;
	}

	return(result);
}

/**
 Method_02 - Ler valores e contar positivos.
*/

void method_02 ()
{
	int quantidade=0;
	int valor =0;
	int controle=0;
	int contador=0;

	IO_id("Exemplo0402 - ED04 - Izadora Galarza Alves");

	quantidade = IO_readint("Entre com uma quantidade:");
	controle= 1;
	while( controle <= quantidade)
	{
    valor=IO_readint(IO_concat
(IO_concat("",IO_toString_d(controle)),":"));
	if(positivo(valor))
	{
		contador++;
	}
		controle++;
	} //fim while
	IO_printf ( "%s%d\n", "Positivos = ", contador );
 IO_pause ( "Apertar ENTER para continuar" );
}


/**
 Funcao para determinar se valor inteiro pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x - valor a ser testado
 @param inferior - limite inferior do intervalo
 @param superior - limite superior do intervalo
*/

bool belongsTo(int x, int inferior, int superior)
{
	bool result= false;

	if (inferior < x && x< superior)
	{
		result= true;
	}
	return(result);
}
/**
 Method_03 - Ler valores e contar positivos menores que 100.
*/
void method_03 ( )
{
	int quantidade=0;
	int valor=0;
	int controle=0;
	int contador=0;

	IO_id("Exemplo0403 - ED04 -Izadora Galarza Alves");
	quantidade = IO_readint("Entre com uma quantidade");
	controle=1;
	while (controle <= quantidade)
		{
			valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );

		if(belongsTo (valor, 0,100))
		{
			contador++;
		}//fim if
		controle++;
		}//fim while
	IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
	IO_pause ( "Apertar ENTER para continuar" );

}

/**
 Funcao para determinar se valor inteiro e' par.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/

bool even (int x)
{
	bool result = false;
	if( x%2==0)
	{
		result= true;
	}
	return(result);
}

/**
 Method_04 - Ler valores e contar positivos menores que 100 e pares.
*/

void method_04 ()
{
	int quantidade=0;
	int valor=0;
	int contador=0;
	int controle=0;

	IO_id("Exemplo0404 - ED04 - Izadora Galarza Alves");
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
    controle = 1;
    while ( controle <= quantidade )
    {
        valor = IO_readint ( IO_concat (
        IO_concat ( "", IO_toString_d ( controle ) ),
        ": " ) );
         if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
        {
            contador = contador + 1;
        } 
        controle++;
    }
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

/**
Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method_05 ( )
{
    int quantidade = 0;
    int valor = 0;
    int controle = 0;
    int contador = 0;
    bool ok = false;

    IO_id("Exemplo0405 - ED04 - Izadora Galarza Alves");
    quantidade = IO_readint ( "Entrar com uma quantidade: " );

    controle++;

    while( controle <= quantidade)
    {
    valor = IO_readint ( IO_concat (
        IO_concat ( "", IO_toString_d ( controle ) ),
        ": " ) );

        ok = belongsTo ( valor, 0, 100 );
        ok = ok && even ( valor );
        if ( ok )
        {
            contador = contador + 1;
        }

        controle++;
    }

    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

/**
Funcao para determinar se caractere e' letra minuscula.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/

bool isLowerCase (char x)
{
    bool result = false;
    if( 'a' <= x && x <= 'z')
    {
        result= true;
    }
    return(result);
}

/**
Method_06 - Ler palavra e contar letras minusculas.
*/
void method_06 ( )
{
    chars palavra = IO_new_chars (STR_SIZE); //estava dando erro, entao eu tentei usar um ponteiro
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;

    IO_id("Exemplo0406 - ED04 - Izadora Galarza Alves");

    palavra= IO_readstring("Entre com uma palavra:");
    tamanho=strlen(palavra);

    for( posicao =0; posicao < tamanho; posicao=posicao +1)
    {
        simbolo = palavra[posicao];
        if (isLowerCase (simbolo))
        {
            IO_printf("%c",simbolo);
            contador++;
        } 
    }
    IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

/**
Method_07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method_07 ( )
{
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    int contador = 0;
    
    IO_id ( "Exemplo0407 - ED04- Izadora Galarza Alves" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen ( palavra );
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
    {
        simbolo = palavra [ posicao ];
        if ( isLowerCase ( simbolo ) )
        {
            IO_printf ( "%c ", simbolo );
            contador = contador + 1;
        } 
    } 
    IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
} 

/**
Method_08 - Ler palavra, contar e mostrar letras minusculas (alternativo).
*/
void method_08 ( )
{
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho=0;
    int posicao=0;
    char simbolo='_';
    int contador=0;
    chars minusculas = IO_new_chars(STR_SIZE);

    strcpy ( minusculas, STR_EMPTY ); 

    IO_id("Exemplo0406 - ED04 - Izadora Galarza Alves");

    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen(palavra);

    for (posicao =0; posicao < tamanho; posicao= posicao+1)
    {
        simbolo = palavra [posicao];
        if (isLowerCase (simbolo))
        {
            minusculas = IO_concat(minusculas,IO_toString_c (simbolo));
            contador++;
        }
    }
    IO_printf("\n%s%d[%s]\n","Minuscula=",contador,minusculas);
    IO_pause("Apertar ENTER para continuar.");
}

/**
Funcao para determinar se caractere e' digito.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/

bool isDigital(char x)
{
    bool result= false;
    if ( '0' <= x && x<='9')
    {
        result=true;
    }
    return(result);
}

/**
Method_09 - Ler palavra e contar os algarismos.
*/
void method_09 ( )
{
    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho =0;
    int posicao =0;
    char simbolo ='_';
    int contador =0;

    IO_id("Exemplo0409 - ED04 - Izadora Galarza Alves");

    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen(palavra);

    for (posicao =0; posicao< tamanho; posicao= posicao+1)
    {
        simbolo = palavra[posicao];
        if (isDigital(simbolo))
        {
            IO_printf("%c",simbolo);
            contador++;
        }
       
    }
    IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
    IO_pause ( "Apertar ENTER para continuar" );
}

/**
Funcao para determinar se caractere e' digito.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool isADigit ( char x )
{
return ( '0' <= x && x <= '9' );
} 

/**Funcao para concatenar 'a cadeia de caracteres mais um digito.
@return cadeia de caracteres acrescida de mais um digito
@param digits - cadeia de caracteres
@param digit - simbolo a ser acrescentado 'a cadeia de caracteres
*/
char* concatADigit ( char* string, char digit )
{
return ( IO_concat ( string, IO_toString_c ( digit ) ) );
}

/**
Method_10.
*/
void method_10 ( )
{
    char* palavra = IO_new_chars ( STR_SIZE );
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    char* digitos = IO_new_chars ( STR_SIZE );
    strcpy ( digitos, STR_EMPTY );

    IO_id("Exemplo0410 - ED04 - Izadora Galarza Alves");

    palavra = IO_readstring ( "Entrar com uma palavra: " );
    tamanho = strlen ( palavra );
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
    {
        simbolo = palavra [ posicao ];
        if ( isADigit ( simbolo ) )
        {
            digitos = concatADigit ( digitos, simbolo );
        }
    }
    IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos );
    IO_pause ( "Apertar ENTER para continuar" );
}

int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED03 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exemplo01");
        IO_println("2 - Exemplo02");
        IO_println("3 - Exemplo03");
        IO_println("4 - Exemplo04");
        IO_println("5 - Exemplo05");
        IO_println("6 - Exemplo06");
        IO_println("7 - Exemplo07");
        IO_println("8 - Exemplo08");
        IO_println("9 - Exemplo09");
        IO_println("10 - Exemplo10");

        op = IO_readint("Escolha um exemplo: ");

        //testar valor 
        switch(op)
        {
            case 0 : method_00();break;
            case 1 : method_01(); break;
            case 2 : method_02();break;
            case 3 : method_03(); break;
            case 4 : method_04();break;
            case 5 : method_05(); break;
            case 6 : method_06();break;
            case 7 : method_07(); break;
            case 8 : method_08();break;
            case 9 : method_09(); break;
            case 10 : method_10(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
}
