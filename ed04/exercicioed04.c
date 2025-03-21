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
bool intervalo (double x, double inferior, double superior)
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
    quantidade= IO_readint("Entre com uma quantidade: ");
    inf= IO_readdouble("Entre com um valor para o intervalo inferior: ");
    sup= IO_readdouble("Entre com um valor para o intervalo superior: ");


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
    IO_printf("%s : %d\n","Valores dentro do intervalo: ", contadorD);
    IO_printf("%s : %d","Valores fora do intervalo: ", contadorF);
    IO_pause("Apertar ENTER para continuar.");

}


/* Incluir um método (0412) para:
- ler uma sequência de caracteres do teclado;
- contar e mostrar a quantidade de letras minúsculas maiores que 'c' e menores que 'p'.
DICA: Definir uma função para determinar se um caractere é letra maiúscula. **/

bool minuscula2 (char x)
{
    bool result =false;
    if ('A' <=x && x<= 'Z')
    {
        result= true;
    }
    return (result);
}

void exe0412 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho=0;
    int posicao=0;
    char simbolo= '_';
    int contador =0;

    IO_id("Exercicio0412 -ED04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    tamanho= strlen(palavra);
    for(posicao=0;posicao < tamanho; posicao= posicao+1)
    {
        simbolo= palavra [posicao]; //isolar simbolo
        if (!(minuscula2(simbolo)) && simbolo >'c' && simbolo < 'p' )
        {
            IO_printf("%c\n",simbolo);
            contador= contador +1;
        }
    }
    IO_printf("%s: %d\n","Minusculas maiores que 'c e menores que 'p'", contador);
    IO_pause("Apertar ENTER para continuar.");

}

/*I ncluir um método (0413) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras minúsculas maiores que 'c' e menores que 'p',
- definir e usar uma função para receber uma cadeia de caracteres como parâmetro
e contar a quantidade desejada*/
int minuscula3 (chars palavras)
{
    int posicao=0;
    int tamanho=0;
    int contador = 0;
    char simbolo= '_';
    tamanho= strlen(palavras);
    
    for(posicao=0;posicao < tamanho; posicao= posicao+1)
    {
        simbolo= palavras [posicao]; 
         if  (simbolo > 'c' && simbolo < 'p') 
        {
            contador= contador +1;
        }
    }
    return  (contador);
}

void exe0413 ()
{
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio0413 -ED04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    IO_printf("%s: %d\n","Minusculas maiores que 'c e menores que 'p' :", minuscula3(palavra) );
    IO_pause("Apertar ENTER para continuar.");
    
}


/*Incluir um método (0414) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras minúsculas maiores que 'c' e menores que 'p',
- definir e usar uma função para receber uma cadeia de caracteres como parâmetro
e separar em outra cadeia de caracteres os símbolos desejados*/
int minuscula4 (chars palavras)
{
    int posicao=0;
    int tamanho=0;
    int contador = 0;
    char simbolo= '_';
    tamanho= strlen(palavras);
    
    for(posicao=0;posicao < tamanho; posicao= posicao+1)
    {
        simbolo= palavras [posicao]; 
         if  (simbolo > 'c' && simbolo < 'p') 
        {
            IO_printf("%c\n",simbolo);
            contador= contador +1;
        }
    }
    return  (contador);
}

void exe0414 ()
{
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio0414 -ED04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    IO_printf("%s: %d\n","Minusculas maiores que 'c' e menores que 'p'", minuscula4(palavra));
    IO_pause("Apertar ENTER para continuar.");
    
}


/* ncluir um método (0415) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas)
maiores que 'c' ou 'C' e menores que 'P' ou 'p'
contadas por uma função definida para receber uma cadeia de caracteres como parâmetro */
int intervalocp (chars palavras)
{
    int posicao=0;
    int tamanho=0;
    int contador = 0;
    char simbolo= '_';
    tamanho= strlen(palavras);
    
    for(posicao=0;posicao < tamanho; posicao= posicao+1)
    {
        simbolo= palavras [posicao]; 
         if  ((simbolo > 'c' && simbolo < 'p') || (simbolo > 'C' && simbolo < 'P') ) 
        {
            contador= contador +1;
        }
    }
    return  (contador);
}

void exe0415 ()
{
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio0415 -ED04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    IO_printf("%s: %d\n","Letras maiores que 'c'/'C' e menores que 'p'/'P': ", intervalocp(palavra));
    IO_pause("Apertar ENTER para continuar.");
    
}


/* Incluir um método (0416) para:
- ler uma sequência de caracteres do teclado;
- mostrar as letras (tanto maiúsculas, quanto minúsculas)
maiores que 'c' ou 'C' e menores que 'P' ou 'p'
separadas por uma função definida para receber uma cadeia de caracteres como parâmetro */
int intervalocp2 (chars palavras)
{
    int posicao=0;
    int tamanho=0;
    int contador = 0;
    char simbolo= '_';
    tamanho= strlen(palavras);
    
    for(posicao=0;posicao < tamanho; posicao= posicao+1)
    {
        simbolo= palavras [posicao]; 
         if  ((simbolo > 'c' && simbolo < 'p') || (simbolo > 'C' && simbolo < 'P') ) 
        {
            IO_printf("%c",simbolo);
            contador= contador +1;
        }
    }
    return  (contador);
}

void exe0416 ()
{
    chars palavra = IO_new_chars(STR_SIZE);

    IO_id("Exercicio0416 -ED04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    IO_printf("%s\n","Letras maiores que 'c'/'C' e menores  que 'p'/'P': ");
    intervalocp2(palavra);
    IO_pause("Apertar ENTER para continuar.");
    
}


/* Incluir um método (0417) para:
- ler uma sequência de caracteres do teclado;
- mostrar a quantidade de dígitos pares em uma cadeia de caracteres contados por uma função
definida para receber uma cadeia de caracteres como parâmetro.
DICA: Considerar o valor inteiro do código equivalente (type casting) para teste.*/

int pares (chars x) 
{
    int posicao=0;
    char simbolo='_';
    int contador=0;
    int tamanho=0;

    tamanho= strlen(x);
    for(posicao=0; posicao < tamanho; posicao=posicao+1)
    {
    simbolo = x[posicao];
    if(('0'<= simbolo && simbolo <='9') && simbolo%2==0)
    {
        IO_printf("[%c]\n", simbolo);
        contador= contador+1;
    }
    
    }
    IO_printf("O total de digitos pares e' = %d",contador);
    int result=contador;
    return(contador);


}
void exe0417 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    IO_id("Exercicio0417 - ed04 -Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra:");
    (int)pares(palavra);
    IO_pause("Apertar ENTER para continuar.");


    
}

/* Incluir um método (0418) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos não alfanuméricos (letras e dígitos) em uma cadeia de caracteres
separados por meio de uma função.
DICA: Usar negação*/
bool AlfaN ( char x)
{
    bool result = false;
    if ( ('a' <= x && x <='z') || ('A' <= x && x <='Z')  || ( '0'<=x && x<='9') )
    {
        result= true;
    }
    return(result);
}
void exe0418 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho=0;
    int simbolo='_';
    int posicao=0;

    IO_id("Exemplo0418 -ed04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra: ");
    tamanho = strlen(palavra);
    for (posicao=0; posicao < tamanho; posicao= posicao+1)
    {
        simbolo=palavra[posicao];
        if(!(AlfaN(simbolo)))
        {
            IO_printf("[%c]\n",simbolo);
        }
        
    }
    IO_pause("Apertar ENTER para continuar.");
    
}

/*Incluir um método (0419) para:
- ler uma sequência de caracteres do teclado;
- mostrar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres
separados por meio de uma função.
DICA: Usar conjunção de duas outras funções.*/

bool letra (char x)
{
    bool result=false;
    if (('A'<= x && x<='Z') || ('a' <= x &&  x <= 'z') )
    {
        result=true;
    }  
    return(result);
}

bool numero (char x)
{
    bool result=false;
    if ('0'<= x && x<='9')
    {
        result=true;
    }  
    return(result);
}
void exe0419 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho=0;
    int simbolo='_';
    int posicao=0;

    IO_id("Exemplo0419 -ed04 - Izadora Galarza Alves");
    palavra = IO_readstring("Entre com uma palavra: ");
    tamanho = strlen(palavra);
    for (posicao=0; posicao < tamanho; posicao= posicao+1)
    {
        simbolo=palavra[posicao];
        if(!(letra(simbolo)) && !(numero(simbolo)))
        {
            IO_printf("[%c]\n",simbolo);
        }
    }
    IO_pause("Apertar ENTER para continuar.");
    
}

/*Incluir um método (0420) para:
- ler certa quantidade de cadeias de caracteres do teclado, uma por vez;
- mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra,
por meio de uma função, e calcular o total acumulado de todas as palavras*/

bool AlfaNumerico ( char x)
{
    bool result = false;
    if ( ('a' <= x && x <='z') || ('A' <= x && x <='Z')  || ( '0'<=x && x<='9') )
    {
        result= true;
    }
    return(result);
}

void exe0420 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho=0;
    int simbolo='_';
    int posicao=0;
    int contador=0;

    IO_id("Exemplo0420 -ed04 - Izadora Galarza Alves");
    palavra = IO_readln("Entre com uma palavra: ");
    tamanho = strlen(palavra);
    for (posicao=0; posicao < tamanho; posicao= posicao+1)
    {
        simbolo=palavra[posicao];
        if(AlfaNumerico(simbolo))
        {
            IO_printf("%d :[%c]\n",contador,simbolo);
            contador=contador+1;
            
        }
        
    }
    IO_printf("Total de numeros e letras: %d", contador);
    IO_pause("Apertar ENTER para continuar.");
    
}

/** 
 * Incluir um método (04E1) para:
- ler certa quantidade de cadeias de caracteres do teclado;
- contar a quantidade de símbolos alfanuméricos, incluindo espaços em branco, em cada palavra,
e calcular o total de todas as palavras com mais de três símbolos, por meio de uma função.
OBS.: Para a leitura incluir espaços em branco, usar
IO_readln( ) ou fgets( ).
 */
void exe04E1 ()
{

}

/** Incluir um método (04E2) para:
- ler duas cadeias de caracteres do teclado;
- calcular qual das duas sequências possui a maior quantidade de dígitos,
por meio de uma função.*/

int digito (chars x)
{
    int posicao=0;
    char simbolo='_';
    int contador=0;
    int tamanho=0;

    tamanho= strlen(x);
    for(posicao=0; posicao < tamanho; posicao=posicao+1)
    {
    simbolo= x[posicao];
    if(('0'<= simbolo && simbolo <='9') && !('a'<= simbolo && simbolo <='z' ||'A'<= simbolo && simbolo <='Z'  ))
    {
        contador= contador+1;
    }
    }
    return(contador);
    
}
void exe04E2 ()
{
    chars palavra1 = IO_new_chars(STR_SIZE);
    chars palavra2 = IO_new_chars(STR_SIZE);
    int contador1=0;
    int contador2=0;

    palavra1=IO_readln("Entre com uma palavra:");
    palavra2= IO_readln("Entre com uma segunda palavra: ");
    contador1=digito(palavra1);
    contador2=digito(palavra2);

    if(contador1>contador2)
    {
        IO_printf("Primeira palavra tem mais digitos que a segunda [%d]>[%d]",contador1,contador2);
    }
    else if (contador2>contador1)
    {
        IO_printf("Segunda palavra tem mais digitos que a primeira [%d]>[%d]",contador2,contador1);

    }
    else
    {
        IO_printf("Primeira palavra e segunda possuem a mesma quantidade de digitos [%d]=[%d]",contador1,contador2);

    }

    IO_pause("Apertar ENTER para continuar.");


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
        IO_println("11 - Exercicio 04E1");
        IO_println("12 - Exercicio 04E2");




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
            case 11 : exe04E1(); break;
            case 12 : exe04E2(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}