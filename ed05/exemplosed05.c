/*
Exemplo0400 - v0.0. - 17 / 03 / 2025
Author: Izadora Galarza Alves
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"io.h"
#include<string.h>
#include<stdbool.h>

/** 
   Method_01a - Mostrar certa quantidade de valores. 
   @param x - quantidade de valores a serem mostrados 
 */ 



void method_01a (int x)
{
    int y=1; 
    while ( y<= x)
    {
        IO_printf("%s%d\n","Valor=",y);
        y=y+1;
    }
}

 void method_01 (void)
{
    IO_print("Exemplo0501 - ED05 - Izadora Galarza Alves\n");
    method_01a(5);
    IO_pause("Apertar ENTER para continuar.");
}

 /** 
  Resultados        TESTE
  1,2,3,4,5          1.0
  */



  /** 
   Method_02a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */

 void method_02a (int x)
{
    int y= 1;
    int z=2;

    while (y <= x)
    {
        IO_printf("%d: [%d]\n",y,z);
        z=z+2; //passar pro proximo par
        y=y+1; //contador
    }
}

  void method_02 ()
{
    IO_id("Exemplo0502 - ED05 - Izadora Galarza Alves");
    method_02a(5);
    IO_pause("Apertar ENTER para continuar");
  
}

  /** 
  Resultados        TESTE
  1: 2               1.0
  2: 4
  3: 6
  4: 8
  5: 10  
  -------------------------        
  */

 void method_03a(int x)
{
    int y=1;
    int z=0;
    while (y<=x)
    {
        z=2*y;
        IO_printf("%d: [%d]\n",y,z);
        y=y+1;
    }
}
  void method_03 ()
{
    IO_id("Exemplo0503 - ED05 - Izadora Galarza Alves");
    method_03a(5);
    IO_pause("Apertar ENTER para continuar");
}
 
/** 
  Resultados        TESTE
  1: 2               1.0
  2: 4
  3: 6
  4: 8
  5: 10  
  -------------------------        
*/

/** 
   Method_04a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */

 void method_04a(int x )
{
    int y = x;
    int z= 0;

    while(y>0)
    {
        z=2*y;
        IO_printf("%d: [%d]\n",y,z);
        y=y-1;
    }
}
void method_04 ()
{
    IO_id("Exemplo0504 - ED05 - Izadora Galarza Alves");
    method_04a(5);
    IO_pause("Apertar ENTER para continuar");
}

/** 
  Resultados        TESTE
  5 : [10]           1.0
  4 : [8]
  3 : [6]
  2 : [4]
  1 : [2]
  -------------------------        
*/

/** 
   Method_05a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */

 void method_05a( int x)
 {
    int y= 0;

    for( y=x; y > 0; y=y-1)
    {
        IO_printf("%d: [%d]\n", y, (y*2));
    }
 }
void method_05 ()
{
    IO_id("Exemplo0505 - ED05 - Izadora Galarza Alves");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar");
}

/** 
  Resultados        TESTE
  5 : [10]           1.0
  4 : [8]
  3 : [6]
  2 : [4]
  1 : [2]
  -------------------------        
*/

/** 
   somarValores - funcao para somar certa quantidade de pares. 
    @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
*/

int somarValores(int x)
{
    int soma =1;
    int y=0;

    for (y=1;y <= (x-1); y=y+1)
    {
        IO_printf("%d: [%d]\n", y, (y*2));
        soma = soma +  (2*y);
    }
    return(soma);

}
void method_06 ()
{
    int soma=0;
    IO_id("Exemplo0505 - ED05 - Izadora Galarza Alves");
    soma = somarValores(5);
    IO_printf("A soma dos valores pares e'= %d", soma);
    IO_pause("Apertar ENTER para continuar");
}
/** 
  Resultados        TESTE
  1: [2]             1.0
  2: [4]
  3: [6]
  4: [8]
  A soma dos valores e'= 21
  -------------------------        
*/


/** 
   somarFracao1 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */

 double somarFracao1(int x)
 {
    double soma =1.0;
    double numerador=0.0;
    double denominador =0.0;
    int y=0;

    for(y=1; y<=(x-1); y=y+1)
    {
        numerador=1.0;
        denominador= 2.0*y;
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y,numerador, denominador, (numerador/denominador));
        soma = soma + (1.0)/(2.0*y);
        }
        return(soma);
 }
void method_07 ()
{
    double soma=0.0;
    IO_id("Exemplo0507 - ED05 - Izadora Galarza Alves");
    soma = somarFracao1(5);
    IO_printf("A soma de fracoes e'= %lf\n", soma);
    IO_pause("Apertar ENTER para continuar");}


/** 
   somarFracao2 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
*/

double somarFracoes2 (int x)
{
    double soma =1.0;
    double numerador =0.0;
    double denominador =0.0;
    int y=0;

    IO_printf("%d: %7.4lf/%7.4lf\n",1,1.0, soma);
    for(y=1;y <=(x-1); y=y+1)
    {
        numerador = 2.0*y-1;
        denominador =2.0 * y;
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n", y, numerador, denominador, (numerador/denominador));
        soma = soma + numerador/denominador;
    }
    return(soma);
}
void method_08 ()
{
    double soma =0.0;
    IO_id ( "Exemplo0508 - ED05 - Izadora Galarza Alves" );
    soma= somarFracoes2(5);
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
    IO_pause ( "Apertar ENTER para continuar" ); 

}

/** 
   somarFracao3 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */ 
double somarFracoes3 (int x)
{
    double soma = 1.0; 
    int y=  0;  

    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
    for ( y = 1; y < x; y = y+1 ) 
    { 
        IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n", 
        y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) );

        soma = soma + (2.0*y)/(2.0*y+1); 
    }
    return(soma);
}
void method_09()
{
    double soma = 0.0; 
 
    IO_id ( "Exemplo0509 - ed05 - Izadora Galarza Alves" ); 
    soma = somarFracoes3 ( 5 ); 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
    IO_pause ( "Apertar ENTER para continuar" );
}

/** 
   multiplicarValores - funcao para multiplicar certa quantidade de valores impares. 
   @return produto de valores 
   @param x - quantidade de valores 
 */

int multiplicarValores (int x)
{
    int produto =1;
    int y=0;

    for (y=1; y<= x; y=y+1)
    {
        IO_printf("%d: %d\n",y,(2*y-1));
        produto = produto * (2*y-1);
    }
    return(produto);
}

void method_10 ()
{
    IO_id ( "Exemplo0510 - ed05 - Izadora Galarza Alves" ); 
    IO_printf ( "produto = %d\n", multiplicarValores(5) ); 
    IO_pause ( "Apertar ENTER para continuar" );

}
int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED05 - Izadora Galarza Alves");

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
            case 0 :  break;
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
