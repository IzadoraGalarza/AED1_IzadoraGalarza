/*
Exemplo0300 - v0.0. - 16 / 03 / 2025
Author: Izadora Galarza Alves
*/


//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"io.h"
#include<string.h>


/** Method_00 -- nao faz nada */

void method_00 (void)
{
    //method vazio
    

} // fim do method00

/** Method_01 -- Repeticao com teste no inicio */

void method_01 (void)
{
    //definir dado (variavel)
    int x =0;

    //identificacao

    IO_id("Exemplo0301 - ED03 - Izadora Galarza Alves");
    x= IO_readint("Entre com um quantidade inteira: ");

    //repeticao while
    while(x > 0)
    {
        IO_println(IO_toString_d(x));

        //passar ao proximo valor
        x=x-1;
    }

    IO_pause("Apertar ENTER para continuar");
} // fim method_01

////////////////////////////////////////////////////////////////////////////////////////////////////////


/** Method_02 -- repeticao com teste no inicio */

void method_02 (void)
{
    int x=0;
    int y=0;

    IO_id("Exemplo0302 - ED3 - Izadora Galarza Alves");
    x= IO_readint("Entre com uma quantidade inteira: ");

    // repetir x vezes

    y=x; // melhor usar uma variavel para copiar o valor de entrada
    while ( y>0)
    {
        IO_println(IO_toString_d(y));
        y = y - 1;
    }

    IO_pause("Apertar ENTER para continuar");

} // fim do method02

////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Method_03 -- repeticao com teste no inicio */

void method_03 (void)
{
    int x=0;
    int y=0;

    IO_id("Exemplo03 -ED03 - Izadora Galarza Alves");
    x = IO_readint("Entre com uma quantidade inteira:");
    y=1; // o x vai ser preservado e y sera usado como parada

    while(y<=x)
    {
        IO_printf("%d\n",y);
        y=y+1;
    }
    IO_pause ( "Apertar ENTER para continuar" );

} // fim do method00

////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 4 -- repeticao com teste no inicio e variacao */

void method_04 (void)
{
    int x=0;
    int y=0;
    int z=0;

    IO_id("Exemplo04 -ED03 - Izadora Galarza Alves");
    x = IO_readint("Entre com uma quantidade inteira:");

    for( y=1; y<=x; y=y+1)
    {
        z= IO_readint("Valor=");
        IO_printf("%d. %d\n", y,z);
    }
    IO_pause ( "Apertar ENTER para continuar" );
} // fim do method00

////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Method_05 -- Repeticao com teste no inicio e variacao */

void method_05 (void)
{
    int x=0;
    int y=0;
    int z=0;

    IO_id("Exemplo05 -ED03 - Izadora Galarza Alves");
    x = IO_readint("Entre com uma quantidade inteira:");

    for( y=x; y>=1; y=y-1)
    {
        z= IO_readint("Valor=");
        IO_printf("%d. %d\n", y,z);
    }
    IO_pause ( "Apertar ENTER para continuar" );

} // fim do method00

////////////////////////////////////////////////////////////////////////////////////////////////////////


/** Method_06 -- Repeticao sobre cadeia de caracateres */

void method_06 (void)
{
    int x=0;
    int y=0;

    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho=0;

    IO_id("Exemplo06 - ED03 - Izadora Galarza Alves");

    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen (palavra) -1;

    for (y= tamanho; y >=0; y= y-1)
    {
        IO_printf("%d: [%c]\n",y, palavra[y]);
    }
    IO_pause ( "Apertar ENTER para continuar" );

} // fim do method00


////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Method_07 -- Repeticao sobre cadeia de caracateres */

void method_07 (void)
{
    int x=0;
    int y=0;

    chars palavra = IO_new_chars (STR_SIZE);
    int tamanho=0;

    IO_id("Exemplo07 - ED03 - Izadora Galarza Alves");

    IO_printf("Entrar com uma palavra:");
    scanf("%s",palavra); // a cadeia de caractere dispensa a indicacao de endereco na leitura
    getchar();
    tamanho = strlen (palavra);

    for (y= 0; y < tamanho; y= y+1)
    {
        IO_printf("%d: [%c]\n",y, palavra[y]);
    }
    IO_pause ( "Apertar ENTER para continuar" );

} // fim do method00


////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Method_08 -- repeticao com intervalos */

void method_08 (void)
{
    int superior =0;
    int inferior =0;
    int x= 0;

    IO_id("Exemplo0308 - ED03 - Izadora Galarza Alves");

    inferior = IO_readint("Limite inferior do intervalo:");
    superior = IO_readint("Limite superior do intervalo:");

    for(x= inferior; x <= superior; x=x+1)
    {
        IO_printf("%d\n",x);
    }

    IO_pause ( "Apertar ENTER para continuar" );


} // fim do method00

////////////////////////////////////////////////////////////////////////////////////////////////////////


/** Method_09 -- Repeticao com intervalos */

void method_09 (void)
{
    double superior =0.0;
    double inferior =0.0;
    double passo =0.0;
    double x= 0.0;

    IO_id("Exemplo0309 - ED03 - Izadora Galarza Alves");

    inferior = IO_readdouble("Limite inferior do intervalo:");
    superior = IO_readdouble("Limite superior do intervalo:");
    passo = IO_readdouble("Variacao no intervalo (passo):");

    for(x= superior; x >= inferior; x=x-passo)
    {
        IO_printf("%lf\n",x);
    }

    IO_pause ( "Apertar ENTER para continuar" );
} // fim do method00
////////////////////////////////////////////////////////////////////////////////////////////////////////


/** Method_10 -- Repeticao com confirmacao */

void method_10 (void)
{
    double superior =0.0;
    double inferior =0.0;
    double passo =0.0;
    double x= 0.0;

    IO_id("Exemplo0310 - ED03 - Izadora Galarza Alves");

    inferior = IO_readdouble("Limite inferior do intervalo:");

    do
    {
        superior = IO_readdouble("Limite superior do intervalo:");

    } while(inferior >=superior);

    do
    {
        passo = IO_readdouble("Variacao no intervalo (passo):");

    } while(passo <= 0.0);

    for(x=inferior; x <= superior; x=x+passo)
    {
        IO_printf("%lf\n",x);
    }
    
    IO_pause ( "Apertar ENTER para continuar" );

    

} // fim do method00

////////////////////////////////////////////////////////////////////////////////////////////////////////



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
            case 0 : method_00(); break;
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
