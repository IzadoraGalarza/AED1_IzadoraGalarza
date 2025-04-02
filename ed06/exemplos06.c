/** ED06 - exemplos0600
 * Autora : Izadora Galarza Alves - 866053
 * Professor: Theldo Cruz
 */

 //Bibliotecas
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #include"io.h"

 /** 
   Method_01a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

void method_01a (int x)
{
    if(x > 0)
    {
        IO_printf("%s%d\n","Valor = ", x);
        method_01a(x-1);
    }
}

void method_01()
{
    int quantidade =0; //inutil nesse method
    int valor=0; // inutil nesse method
    int contador=0; //inutil nesse method

    IO_id("Method_01 -  Exemplos0601");
    method_01a(5);
    IO_pause("Apertar ENTER para continuar.");
}

// saida : 5,4,3,2,1 (ordem decrescente)

/** 
   Method_02a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

void method_02a (int x)
{
    if (x>0)
    {
        method_02a(x-1);
        IO_printf("%s%d\n","Valor = ",x);
    }
}

void method_02 ()
{   
    IO_id("Method_02 - exemplo0602");
    method_02a(5);
    IO_pause("Apertar ENTER para continuar.");
}

//saida: 1,2,3,4,5 (ordem crescente)

/** 
   Method_03a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */ 


void method_03a (int x)
{
 if(x>1)
 {
    method_03a(x-1);
    IO_printf("%s%d\n", "Valor= ",x);
 }   
 else
 {
    IO_printf("%s\n","Valor = 1"); //mostrar o ultimo
 }
}

void method_03 ()
{
    IO_id("Method_03 - exemplo0603");
    method_03a(5);
    IO_pause("Apertar ENTER para continuar.");
}

// saida: 1,2,3,4,5

/** 
   Method_04a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */ 

void method_04a(int x)
{
    if(x>1)
 {
    method_04a(x-1);
    IO_printf("%s%d\n", "Valor= ",2*(x-1));
 }   
 else
 {
    IO_printf("%s\n","Valor = 1"); //mostrar o ultimo
 }
}

//saida : 1,2,4,6,8

void method_04 ()
{
    IO_id("Method_04 - exemplo0604");
    method_04a(5);
    IO_pause("Apertar ENTER para continuar.");   
}

/** Acrescentar outro método para mostrar valores de parcelas do somatório: 
1 + 2/3 + 4/5 + 6/7 + 8/9 ... 

Method_05a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

 void method_05a (int x)
 {
    if (x>1)
    {
        method_05a( x-1);
        IO_printf( "%d : %d/%d\n", x, (2*(x-1)), (2*(x-1)+1));
    }
    else
    {
        IO_printf("%d: %d\n",x,1);
    }
 }
void method_05 ()
{
    IO_id("Method_05 - exemplo0605");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar.");     
}

/** Acrescentar uma função para calcular o somatório: 1 + 2/3 + 4/5 + 6/7 +
 * somarFracoes - Somar certa quantidade de fracoes recursivamente. 
   @return soma de valores 
   @param x - quantidade de valores a serem mostrados
 */

void method_06 ()
{
    
}

void method_07 ()
{
    
}

void method_08 ()
{
    
}

void method_09 ()
{
    
}

void method_10 ()
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
