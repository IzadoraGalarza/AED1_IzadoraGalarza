/** ED05 - EXERCICIOS
 *  Autora: Izadora Galarza Alves
 *  Data: 19/09/2021
 */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"

/** 
 * Incluir função e método (0511) para: 
para ler uma quantidade inteira (n) do teclado e, mediante um procedimento, 
testar a função para gerar valores múltiplos de 3 em ordem crescente. 
 
Exemplo:  n = 5 => { 3, 6, 9, 12, 15 }
 */

int multiplosTres (int n )
{
    int y =0;
    int multiplo =0;
    for (y =1; y <= n; y= y+1)
    {
        multiplo = y*3;
        IO_printf("%d: [%d]\n", y, multiplo);
    }
}
void exe0511 (void)
{
    int n=0;
    IO_id("Exercicio0511 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    multiplosTres(n);
    IO_pause("Apertar ENTER para continuar");
}


/** 
 * Incluir função e método (0512) para: 
para ler uma quantidade inteira do teclado e, mediante um procedimento, 
testar a função para gerar valores múltiplos de 3 e 5 em ordem crescente. 
 
Exemplo:  n = 5 => { 15, 30, 45, 60, 75 }
 */
void multiplosTresCinco (int n )
{
    int y =0;
    int multiplo =0;
    for (y =1; y <= n; y= y+1)
    {
        multiplo= y*15; //usando o mmc
        if( multiplo%5==0 && multiplo%3==0)
        {
            IO_printf("%d: [%d]\n", y, multiplo);
        }
       
    }
}
void exe0512 (void)
{
    int n=0;
    IO_id("Exercicio0512 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    multiplosTresCinco(n);
    IO_pause("Apertar ENTER para continuar");

}


/**  Incluir função e método (0513) para: 
para ler uma quantidade inteira do teclado e, mediante um procedimento, 
testar a função para gerar potências de 4 em ordem decrescente. 
 
Exemplo:  n = 5 => { 1024, 256, 64, 16, 4 } */
void gerarPotencia4 (int x)
{
    int potencia =0;
    int y=0;
    for (y=x; y>0; y=y-1)
    {
        potencia = pow(4,y);
        IO_printf("%d: [%d]\n", y, potencia);
    }
}
void exe0513 (void)
{
    int n=0;
    IO_id("Exercicio0513 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    gerarPotencia4(n);
    IO_pause("Apertar ENTER para continuar");
}

/**   Incluir função e método (0514) para: 
para ler uma quantidade inteira do teclado e, mediante um procedimento, 
testar a função para gerar valores crescentes nos denominadores  
(sequência dos inversos) múltiplos de 3. 
 
Exemplo:  n = 5 => { 1/3, 1/6, 1/9, 1/12, 1/15 }  */
void denominador3 (int x)
{
    int y=0;
    int denominador =0;
    for(y=1; y <=x; y=y+1)
    {
        denominador= y*3;
        IO_printf("1/%d\n", denominador);
    }
}

void exe0514 (void)
{
    int n=0;
    IO_id("Exercicio0514 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    denominador3(n);
    IO_pause("Apertar ENTER para continuar");
}

/** */
void denominadorpar (double x, int n)
{
    int y=0;
    double denominador =0;
    for (y=0; y <n; y=y+1)
    {
        denominador = pow(x,(y*2));
        IO_printf("1/%.4lf\n", denominador);
    }
}
void exe0515 (void)
{
    int n=0;
    double x=0;
    IO_id("Exercicio0515 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    x = IO_readdouble("Entre com um valor real: ");
    denominadorpar(x,n);
    IO_pause("Apertar ENTER para continuar");
}
/**  Incluir função e método (0516) para 
calcular a soma dos primeiros valores positivos começando no valor 3, 
múltiplos de 3 e não múltiplos de 4. 
Testar essa função para quantidades diferentes e mostrar os resultados em outro método. */

int somaemultiplo (int x)
{
    int y=1;
    int valor=0;
    int soma=0;
    int contador=0;
    while (contador<x)
    { 
        valor= 3*y;
        if(valor%4 !=0)
        {
            IO_printf(" [%d]\n", valor);
            soma = soma+valor;
            contador=contador+1;
            
        }
        y=y+1;
        
    }
    IO_printf("Soma: %d\n",soma);
    
}

void exe0516 (void)
{
    int n=0;
    IO_id("Exercicio0516 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    somaemultiplo(n);
    IO_pause("Apertar ENTER para continuar");
}

/** Incluir função e método (0517) para 
calcular a soma dos inversos (1/x) dos primeiros valores positivos, 
começando no valor 4, múltiplos de 4 e não múltiplos de 5. 
Testar essa função para quantidades diferentes e  
mostrar os resultados em outro método. 
 
Exemplo:  n = 5 => 1/4 + 1/8 + 1/12 + 1/16 + 1/24 */

void inverso4 (int x)
{
    int y=1;
    int valor=0;
    int contador=0;
    for(contador=0; contador<=x; contador=contador+1)
    {
        valor= 4*y;
        if(valor%5 !=0)
        {
            IO_printf("1/%d\n",valor);
        }
        y=y+1;
    }
}

void exe0517 (void)
{
    int n=0;
    IO_id("Exercicio0517 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    inverso4(n);
    IO_pause("Apertar ENTER para continuar");
}

/** Incluir função e método (0518) para 
calcular a soma da adição dos primeiros números naturais começando no valor 5. 
Testar essa função para quantidades diferentes de valores e  
mostrar os resultados em outro método. 
 
Exemplo:  n = 5 => 5 + 6 + 8 + 11 + 15 */

void somanaturais (int x)
{
    int y=0;
    int valor=5;
    int soma=0;
    int contador=0;
    int adicional=1;
    while(contador<x)
    {
        valor=valor+y;
        IO_printf("%d\n",valor);
        soma= soma+valor;
        contador=contador+1;
        y=y+adicional;
    }
    IO_printf("Soma: %d\n",soma);
}


void exe0518 (void)
{
    int n=0;
    IO_id("Exercicio0518 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    somanaturais(n);
    IO_pause("Apertar ENTER para continuar");
}

/** 
 *  Incluir função e método (0519) para  
calcular a soma dos quadrados dos números naturais começando no valor 25. 
Testar essa função para quantidades diferentes de valores e 
e mostrar os resultados em outro método. 
 
Exemplo:  n = 5 => 25 + 36 + 49 + 64 + 81
*/

void quadrados (int x)
{
    int y=0;
    int valor=5;
    int contador=0;
    int soma=0;

    while (contador<x)
    {
        valor=pow(5+y,2);
        IO_printf("%d\n",valor);
        soma=soma+valor;
        contador=contador+1;
        y=y+1;
    }
    IO_printf("Soma= %d\n",soma);
}
void exe0519 (void)
{
    int n=0;
    IO_id("Exercicio0519 - ED05 - Izadora Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    quadrados(n);
    IO_pause("Apertar ENTER para continuar");
}

/** 
 * Incluir função e método (Exemplo0520) para  
calcular a soma dos inversos (1/x) das adições de números naturais terminando no valor 3. 
Testar essa função para quantidades diferentes de valores 
e mostrar os resultados em outro método. 
 
Exemplo:  n = 5 => 1/13 + 1/9 + 1/6 + 1/4 + 1/3
 */

 

void exe0520 (void)
{
    int n=0;
    IO_id("Exercicio0520 - ED05 - Izadoraa Galarza Alves");
    n = IO_readint("Entre com uma quantidade: ");
    imprimir(n);
    IO_pause("Apertar ENTER para continuar");
}

void exe05E1 (void)
{  

    
}

void exe05E2 (void)
{
    
}


int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED05 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exercicio 0511");
        IO_println("2 - Exercicio 0512");
        IO_println("3 - Exercicio 0513");
        IO_println("4 - Exercicio 0514");
        IO_println("5 - Exercicio 0515");
        IO_println("6 - Exercicio 0516");
        IO_println("7 - Exercicio 0517");
        IO_println("8 - Exercicio 0518");
        IO_println("9 - Exercicio 0519");
        IO_println("10 - Exercicio 0520");
        IO_println("11 - Exercicio 05E1");
        IO_println("12 - Exercicio 05E2");




        op = IO_readint("Escolha um exemplo: ");
        

        //testar valor 
        switch(op)
        {
            case 0 : break;
            case 1 : exe0511(); break;
            case 2 : exe0512();break;
            case 3 : exe0513(); break;
            case 4 : exe0514();break;
            case 5 : exe0515(); break;
            case 6 : exe0516();break;
            case 7 : exe0517(); break;
            case 8 : exe0518();break;
            case 9 : exe0519(); break;
            case 10 : exe0520(); break;
            case 11 : exe05E1(); break;
            case 12 : exe05E2(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}