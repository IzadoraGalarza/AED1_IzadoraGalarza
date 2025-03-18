/*
Exercicios0310 - v0.0. - 16 / 03 / 2025
Author: Izadora Galarza Alves
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include "io.h"
#include<ctype.h>

void method_00 (void)
{
    //method vazio
    

} // fim do method00
/* 01.) Incluir um método (0311) para:
- ler uma palavra do teclado;
- mostrar as letras maiúsculas maiores que 'K'.
DICA: Definir um teste para determinar se um caractere é letra maiúscula.
Comparar os símbolos e não seus códigos numéricos equivalentes.
Exemplo: palavra = "PaLaVrA"*/
void ex0311(void)
{
    int x =0;
    int tamanho =0;
    char palavra [STR_SIZE];

    IO_id("Exercicio0311 - ED03 - Izadora Galarza Alves");

    IO_printf("Entre com uma palavra:");
    scanf("%s",palavra);

    tamanho= strlen(palavra);

    for(x=0; x < tamanho; x=x+1)
    {
        if( palavra[x] >= 'A' && palavra[x]<= 'Z' && palavra[x]>'K')
        {
            IO_printf("%c\n",palavra[x]);
        }
        
    }
    
    IO_pause ( "Apertar ENTER para continuar" );
}

/*02.) Incluir um método (0312) para:
- ler uma palavra do teclado;
- contar e mostrar apenas as letras minúsculas menor que 'k'.
DICA: Definir um teste para determinar se um caractere é letra minúscula.
Comparar os símbolos e não seus códigos numéricos equivalentes.
Exemplo: palavra = "PaLaVrA"*/
void ex0312(void) 
{
    int x =0;
    int y =0;
    int tamanho =0;
    char palavra [STR_SIZE];

    IO_id("Exercicio0312 - ED03 - Izadora Galarza Alves");

    IO_printf("Entre com uma palavra:");
    scanf("%s",palavra);

    tamanho= strlen(palavra);

    for(x=0; x < tamanho; x=x+1)
    { 
        if( palavra[x] >= 'a' && palavra[x]<'k')
        {
            IO_printf("%d:[%c]\n",y,palavra[x]);
            y=y+1;
        }
        
    }
    
    IO_pause ( "Apertar ENTER para continuar" );


}
/*03.) Incluir um método (0313) para:
- ler uma palavra do teclado;
- contar e mostrar as letras minúsculas maiores que 'K', percorrendo do fim para o início da palavra.
Exemplo: palavra = "PaLaVrA"*/
void ex0313(void)
{
    int x =0;
    int y=0;
    int tamanho =0;
    char palavra [STR_SIZE];

    IO_id("Exercicio0313- ED03 - Izadora Galarza Alves");

    IO_printf("Entre com uma palavra:");
    scanf("%s",palavra);

    tamanho= strlen(palavra) - 1;
    
    for(x=tamanho; x > 0; x=x-1)
    { 
        if( palavra[x] > 'k' && palavra[x]<='z')
        {
            IO_printf("%d: [%c]\n",y, palavra[x]);
            y=y+1;
            
        }
        
    }
    
    IO_pause ( "Apertar ENTER para continuar" );

}

/** Fiz dois testes nessa questao, uma utilizando o contador de acordo com a posicao da letra(caractere) 
 * e a outra utilizando uma contagem mesmo.
*/

/*04.) Incluir um método (0314) para:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.
Exemplo: palavra = "P4LaVr@"*/
void ex0314(void)
{
    int x =0;
    int y=0;
    char palavra[STR_SIZE];
    int tamanho=0;

    IO_id("Exercicio0314 - ED03 - Izadora Galarza Alves");
    IO_printf("Entre com uma cadeia de caracteres:");
    scanf("%s",palavra);

    tamanho= strlen(palavra);

    for(x=0; x < tamanho; x=x+1)
    {
        if(palavra[x] >= 'A' && palavra[x] <= 'Z')
        {
            IO_printf("%d. %c (letra Maiuscula)\n",y,palavra[x]);
        }
        else if(palavra[x] >= 'a' && palavra[x] <= 'z')
        {
            IO_printf("%d. %c (letra minuscula)\n",y,palavra[x]);
                
        }
        else
        {
            IO_printf("%d. %c (Diferente de letra)\n",y,palavra[x]);
            
        }
        y=y+1;
            
    }

    IO_pause ( "Apertar ENTER para continuar" );

}
/*05.) Incluir um método (0315) para:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos os dígitos pares, percorrendo do fim para o início da cadeia de caracteres.
Exemplo: palavra = "P4LaVr@1"*/    
void ex0315(void)
{
    int x =0;
    int y=0;
    int tamanho =0;
    char palavra [STR_SIZE];
    
    IO_id("Exercicio0315 - ED03 - Izadora Galarza Alves");
    
    IO_printf("Entre com uma palavra:");
    scanf("%s",palavra);
    
    tamanho= strlen(palavra) - 1;
    

        
    for(x=tamanho; x >= 0; x=x-1)
    { 
        
        if( y%2==0 )
        {
        IO_printf("%d. %c\n", y,palavra[x]);
        }
        else{
            IO_printf("\n");

        }
        y=y+1;
    }
        
    IO_pause ( "Apertar ENTER para continuar" );
    
}
    

/*06.) Incluir um método (0316) para:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar tudo o que não for dígito ímpar e também não for letra.
Exemplo: palavra = "P4LaVr@O!"*/

void ex0316(){
    
    int x =0;
    int y=0;
    int tamanho =0;
    char palavra [STR_SIZE];
    
    IO_id("Exercicio0316 - ED03 - Izadora Galarza Alves");
    
    IO_printf("Entre com uma palavra:");
    scanf("%s",palavra);
    
    tamanho= strlen(palavra) ;
    

    for(x=0; x < tamanho; x=x+1)    
    { 
        
        if( y%2==0 && !(palavra[x] >= 'A' && palavra[x] <= 'Z') && !( palavra[x] >= 'a' && palavra[x] <= 'z') )
        {
        IO_printf("%d. %c\n", y,palavra[x]);
        }
        else
        {
        
        }
        y=y+1;
    }
        
    IO_pause ( "Apertar ENTER para continuar" );
    
}

/** Fiz alguns testes mudando variaveis e todos deram certo */
   
/*07.) Incluir um método (0317) para:
- ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b]; ok
- ler uma quantidade (n) de valores inteiros a serem testados; 
- repetir a leitura de outros tantos valores, quantos os indicados pela quantidade, um (x) por vez;
- contar e mostrar quantos dentre esses valores lidos (x)
os que forem múltiplos de 3, e pertençam ao intervalo [a:b].
Exemplo: [ 20: 50 ], e n = 7, com { 10, 20, 30, 42, 54, 60, 84 }*/
void ex0317(void)
{
    int a=0;
    int b=0;
    int n=0;
    int x=0;
    int m=0; //contador

    IO_id("Exercicio0317 - ED3- Izadora Galarza Alves");

    IO_printf("Entre com um valor inteiro para o intevalo inferior:");
    scanf("%d",&a);
    IO_printf("Entre com um valor inteiro para o intevalo superior:");
    scanf("%d",&b);
    IO_printf("Quantas vezes vai ser testado?");
    scanf("%d",&n);

    for(int y=0;y<n;y=y+1)
    {
        scanf("%d",&x);

        if(x % 3 ==0  && (x>=a && x<=b))
        {

            m=m+1;
        }
        
    }
    IO_printf("Quantidade de valores multiplos de 3 e dentro do intervalo [%d:%d] = %d",a,b,m);

    IO_pause ( "Apertar ENTER para continuar" );


}

/*08.) Incluir um método (0318) para:
- ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
- ler uma quantidade (n) de valores inteiros a serem testados;
- ler outros tantos valores quantos os indicados pela quantidade, um (x) por vez;
- contar e mostrar quantos dentre esses valores lidos (x)
os que forem múltiplos de 4, que não forem também múltiplos de 3,
e pertençam ao intervalo [a:b].
Exemplo: [ 15: 55 ], e n = 7, com { 10, 20, 30, 48, 52, 60, 84 }*/
void ex0318(void)
{

    int a=0;
    int b=0;
    int n=0;
    int x=0;
    int m=0; //contador
    IO_id("Exercicio0318 - ED3- Izadora Galarza Alves");
    IO_printf("Entre com um valor inteiro para o intevalo inferior:");
    scanf("%d",&a);
    IO_printf("Entre com um valor inteiro para o intevalo superior:");
    scanf("%d",&b);
    IO_printf("Quantas vezes vai ser testado?");
    scanf("%d",&n);

    for(int y=0;y<n;y=y+1)
    {
        scanf("%d",&x);

        if(x % 4 == 0 && x % 3 !=0 && x>=a && x<=b)
        {

            m=m+1;
        }
        
    }
    IO_printf("Quantidade de valores multiplos de 4 , nao multiplos de 3, e dentro do intervalo [%d:%d] = %s",a,b,m);

    IO_pause ( "Apertar ENTER para continuar" );



}

/*09.) Incluir um método (0319) para:
- ler dois valores reais (a e b), o primeiro (a) menor que o segundo (b), confirmadamente,
para definirem um intervalo aberto (a:b); OK
- ler a quantidade (n) de valores reais a serem testados, e
ler outros tantos valores (x) quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos, pertencentes ao do intervalo,
cujas partes inteiras forem pares e menores que 5.
DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
antes de testar se é par (ver 0110).
Exemplo: ( 1.5: 8.1 ), e n = 7, com { 1.0, 2.4, 3.3, 4.1, 5.5, 6.3, 8.6 }*/
void ex0319(void)
{
    double a=0.0;
    double b=0.0;
    int n=0;
    double x=0;
    int m=0;

    IO_id("Exercicio0319 - ED3- Izadora Galarza Alves");

    IO_printf("Entre com um valor inteiro para o intevalo inferior:");
    scanf("%lf",&a);
    IO_printf("Entre com um valor inteiro para o intevalo superior:");
    scanf("%lf",&b);
    
    IO_printf("Quantas vezes vai ser testado?");
    scanf("%d",&n);

    for(int y=0;y<n;y=y+1)
    {   
        IO_printf("Digite valor real: ");
        scanf("%lf",&x);
        if( (int)x< 5 && (int)x%2==0 && (x>a && x<b))
        {
            IO_printf("%lf dentro das condicoes.\n",x);
            m++;
        }
        else
        {
            IO_printf("\n");
        }
        
    }
    
    IO_pause ( "Apertar ENTER para continuar" );

}

/*10.) Incluir um método (0320) para:
- ler dois valores reais (a e b), maiores que 0 e menores que 1, confirmadamente,
para definirem um intervalo aberto (a:b);
- ler uma quantidade (n) de valores reais a serem testados, e
ler outros tantos valores quantos os indicados por essa quantidade;
- contar e mostrar todos os valores lidos
que tenham suas partes fracionárias dentro do intervalo ]a:b[.
DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),
e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.
Exemplo: ( 0.25: 0.50 ), e n = 7, com { 1.0, 2.8, 3.3, 4.1, 5.5, 6.9, 8.4 }*/
void ex0320(void)
{
    double a=0.0;
    double b=0.0;
    int n=0;
    double x=0;
    double fp=0.0;
    int m =1;


    IO_id("Exercicio0319 - ED3- Izadora Galarza Alves");
    do{
        IO_printf("Entre com um valor inteiro para o intevalo inferior:");
        scanf("%lf",&a);
        IO_printf("Entre com um valor inteiro para o intevalo superior:");
        scanf("%lf",&b);
    
        if(!(0 < a && a < 1 && 0 < b && b < 1 && a < b))
        {
            IO_printf("Os valores devem estar no intervalo (0,1) e 'a'' deve ser menor que 'b'.");
        }
    }while(!(0 < a && a < 1 && 0 < b && b < 1 && a < b));

    IO_printf("Quantas vezes vai ser testado?");
    scanf("%d",&n);

    for(int y=0;y<n;y=y+1)
    {
        IO_printf("Digite %d valor real:", m);
        scanf(" %lf",&x);
        fp= x - (int)x;
        if(fp>a &&fp<b)
        {
            IO_printf(" %lf (Dentro do intervalo)\n",x);
            

        }
        m++;
    }
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
        IO_println("1 - Exercicio 01");
        IO_println("2 - Exercicio 02");
        IO_println("3 - Exercicio 03");
        IO_println("4 - Exercicio 04");
        IO_println("5 - Exercicio 05");
        IO_println("6 - Exercicio 06");
        IO_println("7 - Exercicio 07");
        IO_println("8 - Exercicio 08");
        IO_println("9 - Exercicio 09");
        IO_println("10 - Exercicio 10");


        op = IO_readint("Escolha um exemplo: ");

        //testar valor 
        switch(op)
        {
            case 0 : method_00(); break;
            case 1 : ex0311(); break;
            case 2 : ex0312();break;
            case 3 : ex0313(); break;
            case 4 : ex0314();break;
            case 5 : ex0315(); break;
            case 6 : ex0316();break;
            case 7 : ex0317(); break;
            case 8 : ex0318();break;
            case 9 : ex0319(); break;
            case 10 : ex0320(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}