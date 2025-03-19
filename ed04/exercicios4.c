/*
Exercicios0400 - v0.0. - 17 / 03 / 2025
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

/** Incluir um método (0411) para:
- ler a quantidade de valores reais; ok
- ler dois valores reais para definir um intervalo fechado; ok
- ler tantos valores reais quanto a quantidade, um de cada vez e
- contar quantos desses valores estão dentro do intervalo, e quantos estão fora dele. */ 
bool intervalo (double x, double superior, double inferior)
{
    bool result= false;
    if (x>=inferior && x<=superior)
    {
        result= true;
    }
    return(result);
}
void exe0411 ()
{
    double valor =0.0;
    double inf=0.0;
    double sup=0.0;
    int quantidade=0;
    int contadorD=0;
    int contadorF=0;
    int controle=0;

    IO_id("Exercicio0411 - ED04 - Izadora Galarza Alves");
    quantidade= IO_readint("Entre com uma quantidade");
    inf= IO_readdouble("Entre com um valor para o intervalo inferior:");
    sup= IO_readdouble("Entre com um valor para o intervalo superior");


    controle=1;
    while(controle<=quantidade)
    {
        valor = IO_readdouble ( IO_concat (
            IO_concat ( "", IO_toString_d ( controle ) ),
            ": " ) );
        if(intervalo(valor,inf,sup))
        {
            contadorD++;
        }
        else
        {
            contadorF++;
        }
        controle++;
    }
    IO_printf("%s : %d\n","Valores dentro do intervalo", contadorD);
    IO_printf("%s : %d","Valores fora do intervalo", contadorF);
    IO_pause("Apertar ENTER para continuar.");

}


/* Incluir um método (0412) para:
- ler uma sequência de caracteres do teclado;
- contar e mostrar a quantidade de letras minúsculas maiores que 'c' e menores que 'p'.
DICA: Definir uma função para determinar se um caractere é letra maiúscula. **/
void exe0412 ()
{
    
}

/*I ncluir um método (0413) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras minúsculas maiores que 'c' e menores que 'p',
- definir e usar uma função para receber uma cadeia de caracteres como parâmetro
e contar a quantidade desejada*/
void exe0413 ()
{
    
}


/*Incluir um método (0414) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras minúsculas maiores que 'c' e menores que 'p',
- definir e usar uma função para receber uma cadeia de caracteres como parâmetro
e separar em outra cadeia de caracteres os símbolos desejados*/
void exe0414 ()
{
    
}


/* ncluir um método (0415) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas)
maiores que 'c' ou 'C' e menores que 'P' ou 'p'
contadas por uma função definida para receber uma cadeia de caracteres como parâmetro */
void exe0415 ()
{
    
}


/* Incluir um método (0416) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras (tanto maiúsculas, quanto minúsculas)
maiores que 'c' ou 'C' e menores que 'P' ou 'p'
separadas por uma função definida para receber uma cadeia de caracteres como parâmetro */
void exe0416 ()
{
    
}

/* Incluir um método (0417) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de dígitos pares em uma cadeia de caracteres contados por uma função
definida para receber uma cadeia de caracteres como parâmetro.
DICA: Considerar o valor inteiro do código equivalente (type casting) para teste.*/
void exe0417 ()
{
    
}

/* Incluir um método (0418) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos não alfanuméricos (letras e dígitos) em uma cadeia de caracteres
separados por meio de uma função.
DICA: Usar negação*/
void exe0418 ()
{
    
}

/*Incluir um método (0419) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres
separados por meio de uma função.
DICA: Usar conjunção de duas outras funções.*/

void exe0419 ()
{
    
}

/*Incluir um método (0420) para:
- ler certa quantidade de cadeias de caracteres do teclado, uma por vez;
- mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra,
por meio de uma função, e calcular o total acumulado de todas as palavras*/

void exe0420 ()
{
    
}



int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED03 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exercicio 0411");
        IO_println("2 - Exercicio 0412");
        IO_println("3 - Exercicio 0413");
        IO_println("4 - Exercicio 0414");
        IO_println("5 - Exercicio 0415");
        IO_println("6 - Exercicio 0416");
        IO_println("7 - Exercicio 0417");
        IO_println("8 - Exercicio 0418");
        IO_println("9 - Exercicio 0419");
        IO_println("10 - Exercicio 0420");


        op = IO_readint("Escolha um exemplo: ");

        //testar valor 
        switch(op)
        {
            case 0 : method_00(); break;
            case 1 : exe0411(); break;
            case 2 : exe0412();break;
            case 3 : exe0413(); break;
            case 4 : exe0414();break;
            case 5 : exe0415(); break;
            case 6 : exe0416();break;
            case 7 : exe0417(); break;
            case 8 : exe0418();break;
            case 9 : exe0419(); break;
            case 10 : exe0420(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}