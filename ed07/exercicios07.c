/** exercicios0700 - ed07
 * aluna: Izadora Galarza Alves
 */
#include<stdio.h>
#include<stdlib.h>
#include "io.h"
#include<time.h>

/** 01.) Incluir um método (0711) para 
ler um valor inteiro do teclado e  
gravar essa quantidade em múltiplos de 4, pares, em ordem crescente, começando em 4. 
 
Exemplo: n = 5 => { 4, 8, 12, 16, 20 } */


void exe0711 ()
{

    FILE* arquivo = fopen("RESULTADO0711.TXT", "wt");
    int y=0;
    int x=0; //quantidade
    IO_id("Exercicio0711 - ed07");
    x = IO_readint("Entre com uma quantidade: ");

    for (y=1; y <= x; y= y+1)
    {
        fprintf(arquivo,"%d\n", y*4);
    }

    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar.");
}

/** 02.) Incluir um método (0712) para 
ler um valor inteiro do teclado e  
gravar essa quantidade em múltiplos de 15, pares, em ordem decrescente encerrando em 30. 
 
Exemplo: n = 5 => { 150, 120, 90, 60, 30 } */

void exe0712 ()
{
    FILE* arquivo = fopen("RESULTADO0712.TXT", "wt");
    int n=0; // quantidade
    int x=0; //cotrole
    IO_id("Exercicio0712 - ed07");
    n = IO_readint("Entre com uma quantidade: ");
    for( x = 2*n; x > 1; x=x-1) // ter o dobro aumenta aumentara o numero de quantidade, mantendo assim o valor 
    {
        if(x*15 % 2 == 0)
        {
        IO_fprintf(arquivo, "%d\n", x*15);
        }
      
    }

    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar.");

}

/** Incluir um método (0713) para 
ler um valor inteiro do teclado e  
gravar essa quantidade em valores da sequência: 1 3 9 27 81 ... 
 
Exemplo: n = 5 => { 1, 3, 9, 27, 81 } */
void exe0713 ()
{
    FILE*arquivo = fopen("RESULTADO0713.TXT","wt");
    int n = 0; // quantidade
    int x=1; // controle
    int y=1; // valor
    IO_id("Exercicio0713 - ed07");
    n = IO_readint("Entre com uma quantidade: ");
    fprintf(arquivo,"%d\n", 1); //mostrar primeiro valor
    while(x<n)
    {
        y= y*3;
        IO_fprintf(arquivo,"%d\n",y);
        x=x+1;
    }
    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar.");
}

/** Incluir um método (0714) para 
ler um valor inteiro do teclado e  
gravar essa quantidade em valores decrescentes da sequência: ... 1/81 1/27 1/9 1/3 1. 
 
Exemplo: n = 5 => { 1/81, 1/27, 1/9, 1/3, 1 */


void exe0714 ()
{
    FILE*arquivo = fopen("RESULTADO0714.TXT","wt");
    int n = 0; // quantidade
    int x=1; // controle
    int y=1; // valor
    IO_id("Exercicio0714 - ed07");
    n = IO_readint("Entre com uma quantidade: ");
    for(x=n; x>1; x=x-1)
    {
        y=y*3;
    }

    while(x<n)    
    {
        fprintf(arquivo, "1/%d\n", y);
        y = y / 3;
        x=x+1;
    }
    fprintf(arquivo,"%d\n", 1); //mostrar o ultimo valro
    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar.");
}

/** Incluir um método (0715) para 
ler um valor inteiro do teclado (n) e outro valor real (x),  
gravar essa quantidade (n) em valores reais da sequência: 1 1/x3 1/x5  1/x7... 
DICA: Usar pow ( x, y ) da biblioteca <math.h> para calcular a potência. 
 
Exemplo: n = 5 => { 1, 1/x3, 1/x5, 1/x7, 1/x9 }  */

void exe0715 ()
{
    FILE* arquivo = fopen ("RESULTADO0715.TXT","wt");
    int n= 0; // quantidade
    double x= 0.0; // valor real
    int c= 0; // controle
    int y=2; // potencia
    IO_id("Exercicio0715 - ed07");

    n= IO_readint("Entre com uma quantidade: ");
    x = IO_readdouble("Entre com um valor real: ");
    IO_fprintf(arquivo,"%d\n",1); //imprimir primeiro valor
    for (c=1; c<n; c=c+1)
    {
        IO_fprintf(arquivo,"%lf\n",1/ pow(x,2*y-1));
        y=y+1;
    }
    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar.");
    
}

/**  Incluir um método e uma função (0716) para 
ler um valor inteiro do teclado para representar certa quantidade de valores  
a serem somados dentre os primeiros gravados no exercício anterior (0715). 
Testar essa função para quantidades diferentes.  
Gravar em outro arquivo ("RESULTADO06.TXT") cada quantidade e seu resultado.
*/

void somarArq (chars fileName, int n)
{
    FILE* entrada = fopen(fileName, "rt");
    FILE* saida = fopen ("RESULTADO06.TXT","a");
    int contador =0;
    double soma=0.0;
    double valor=0.0;

    
    //repetir enquando houver dados
    while (contador < n && !feof(entrada))
    {
        fscanf (entrada, "%lf", &valor);
        fprintf(saida, "%lf\n", valor);
        soma = soma + valor;
        contador = contador +1;
    }
    fprintf(saida, "A soma dos %d valores = %lf", n , soma);
    fclose(entrada);
    fclose(saida);
}


void exe0716 ()
{
    int n= 0; // quantidade
    n = IO_readint("Entre com uma quantidade: ");
    somarArq("RESULTADO0715.TXT", n);
    IO_pause("Apertar ENTER para continuar.");
}

/** Incluir um método e uma função (Exemplo0717) para 
ler um valor inteiro do teclado, e até essa quantidade, um valor por vez, 
calcular a soma dos inversos das potências do exercício (0714). 
Gravar em outro arquivo ("RESULTADO07.TXT") cada quantidade e seu resultado. 
 
Exemplo: n = 5 => { 1/81 + 1/27 + 1/9 + 1/3 + 1 } 
 */

int somaInversos (chars fileName, int n)
{
    FILE* arquivo = fopen(fileName, "a");
    int x=1; // controle
    double soma=0.0;
    for(x=n; x>1; x=x-1)
    {
        soma = soma + 1.0/ pow(3.0,x);
        fprintf(arquivo, "%lf\n",soma);
    }
    fprintf(arquivo, "soma dos %d valores = %lf\n", n, soma);
    fclose(arquivo);
    return(soma);
}
void exe0717 ()
{
    IO_id("exercicio0717 - ed07");
    int n= 0; // quantidade
    double somar=0.0;
    n = IO_readint("Entre com uma quantidade: ");
    
    somar = somaInversos("RESULTADO07.TXT", n);
    
    IO_pause("Apertar ENTER para continuar.");
}


int somaInversosb (chars fileName, int n)
{
    FILE* arquivo = fopen(fileName, "a");
    int x=1; // controle
    int soma=1;
    int y=1;
    fprintf(arquivo,"1");
    for(x=n; x>1; x=x-1)
    {
        y=y*3;
        printf("%d\n",y);
        soma = soma + y;
        fprintf(arquivo, "1/%d\n",y);
    }
    fprintf(arquivo, "soma dos %d valores = 1/%d\n", n, soma);
    fclose(arquivo);
    return(soma);
}

void exe0717b ()
{
    IO_id("exercicio0717b - ed07");
    int n= 0; // quantidade
    int somar=0;
    n = IO_readint("Entre com uma quantidade: ");
    somar = somaInversosb("RESULTADO07b.TXT", n);
    IO_printf("Soma = 1/%d\n", somar );
    IO_pause("Apertar ENTER para continuar.");
}


/** Incluir um método e uma função (0718) para 
ler um valor inteiro do teclado, e até atingir essa quantidade, um valor por vez, 
gravar o valor correspondente aos primeiros termos pares da série de Fibonacci. 
Gravar em outro arquivo ("RESULTADO08.TXT") cada quantidade e seu resultado. 
DICA: Separar o gerador de Fibonacci do mapeamento de pares. 
 
Exemplo: n = 5 => { 2, 8, 34, 144, 610 } */
int fibonacci (int x)
{
    int resposta = 0;

    if (x == 1 || x == 2)
    {
        resposta = 1;
    }
    else if (x > 2)
    {
        resposta = fibonacci(x - 1) + fibonacci(x - 2);
    }

    return resposta;
}
void exe0718 ()
{
    FILE*arquivo = fopen("RESULTADOS08.TXT","wt");
    int n=0; // quantidades
    int controle=0;
    int contador=1;
    int termo=0;

    n = IO_readint("Entre com uma quantidade:");
    while( controle < n)
    {
        termo = fibonacci(contador);

        if(termo % 2 ==0)
        {
            fprintf(arquivo, "%d\n", termo);
            printf("%d\n",termo);
            controle = controle +1;
        }

        contador = contador +1;
    }

    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar");
    
}

/** Incluir um método e uma função (0719) para 
para calcular a quantidade de maiúsculas em cadeia de caracteres de um arquivo texto. 
Gravar em outro arquivo ("RESULTADO09.TXT") cada cadeia de caracteres e seus resultados. 
Testar essa função com cadeias de tamanhos diferentes. 
 
Exemplo: PaReDe de TiJoLoS AmaRElOs */

int minuscula (chars fileName, chars palavra)
{
    FILE *arquivo  = fopen (fileName, "wt");
    
    int m = 0;
    int controle=0;
    int tamanho = 0;
    char a = '_';
    tamanho = strlen(palavra);
    
    for(controle=0; controle<= tamanho; controle= controle +1)
    {
        a = palavra[controle];
        if('a' <= a && a <= 'z')
        {
            fprintf(arquivo, "%c\t", a);
            printf("%c\n", a);
            fprintf(arquivo,"\n");
            m = m+1;
        }

    }
    fprintf(arquivo,"Total de caracteres minusculos = %d", m);

    fclose(arquivo);
    return (m);
    
}
void exe0719 ()
{
    chars palavras = IO_new_chars(STR_SIZE);
    int result= 0;
    
    palavras = IO_readln("Entre com a cadeia de caracteres: ");
    result = minuscula("RESULTADO09.TXT", palavras);
    printf("O total de minusculas e' %d\n", result);
    IO_pause("Apertar ENTER para continuar.");
}

int tres (chars fileName, chars palavra)
{
    FILE *arquivo  = fopen (fileName, "wt");
    
    int t = 0;
    int controle=0;
    int tamanho = 0;
    char a = '_';
    tamanho = strlen(palavra);
    
    for(controle=0; controle<= tamanho; controle= controle +1)
    {
        a = palavra[controle];

        if('0' <= a && a <= '9' && (a >= '3') )
        {
            fprintf(arquivo, "%c\t", a);
            printf("%c\n", a);
            fprintf(arquivo,"\n");
            t = t+1;
        }

    }
    fprintf(arquivo,"Total de caracteres minusculos = %d", t);

    fclose(arquivo);
    return (t);
}
void exe0720 ()
{
    chars palavras = IO_new_chars(STR_SIZE);
    int result= 0;
    
    palavras = IO_readln("Entre com a cadeia de caracteres: ");
    result = tres("RESULTADO10.TXT", palavras);
    printf("O total de digitos maiores de 3 e' %d\n", result);
    IO_pause("Apertar ENTER para continuar.");
}

/**  Incluir um método (07E1) para 
programa ler um valor inteiro do teclado, e 
gravar em arquivo os seus divisores ímpares em ordem decrescente. */

void divisor (chars fileName, int x)
{
    FILE* arquivo = fopen(fileName,"wt");
    int n =0; //controle
    int valor=0;
    for (int n = x; n >= 1; n--)
    {
        if (x % n == 0 && n % 2 != 0)
        {
            fprintf(arquivo, "%d\n", n);
        }
    }

    fclose(arquivo);
}

void ex07E1()
{
    int x = 0;
    x = IO_readint("Entre com um valor: ");
    divisor("EXTRA1.TXT", x);
    IO_pause("Apertar ENTER para continuar.");
}

/** 
E2.) Incluir um método e uma função (07E2) para 
ler palavras de um arquivo, uma por linha, e 
contar quantas começam com a letra 'c' (ou 'C') e tenham, no máximo, 12 caracteres. 
 
  */


  void gravarPalavras (chars fileName)
  {
    FILE *arquivo = fopen(fileName, "wt");
    chars palavra = IO_new_chars(STR_SIZE);
  
    if (arquivo != NULL)
    {
        palavra = IO_readln("Digite uma palavra (fim para terminar): ");
  
        while (strcmp(palavra, "fim") != 0)
        {
            fprintf(arquivo, "%s\n", palavra);
            palavra = IO_readln("Digite uma palavra (fim para terminar): ");
        }
  
        fclose(arquivo);
    }
    }
  
  int contarPalavrasC (chars fileName)
  {
    FILE *arquivo = fopen(fileName, "rt");
    int contador = 0;
    chars palavra = IO_new_chars(STR_SIZE);
    int tamanho = 0;
  
    if (arquivo != NULL)
    {
        palavra = IO_freadln(arquivo);
  
        while (!feof(arquivo))
        {
            if (palavra != NULL && palavra[0] != '\0')
            {
                tamanho = strlen(palavra);
                if ((palavra[0] == 'c' || palavra[0] == 'C') && tamanho <= 12)
                {
                    contador = contador + 1;
                }
            }
            palavra = IO_freadln(arquivo);
        }
  
        fclose(arquivo);
    }
      
  
    return (contador);
  }
  
  void ex07E2()
  {
      int resultado = 0;
  
      gravarPalavras("EXTRA2.TXT");
      resultado = contarPalavrasC("EXTRA2.TXT");
  
      printf("Total de palavras comecando com 'c' ou 'C' e com ate 12 caracteres: %d\n", resultado);
      IO_pause("Apertar ENTER para continuar.");
  }
  


int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED05 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exercicio 0711");
        IO_println("2 - Exercicio 0712");
        IO_println("3 - Exercicio 0713");
        IO_println("4 - Exercicio 0714");
        IO_println("5 - Exercicio 0715");
        IO_println("6 - Exercicio 0716");
        IO_println("7 - Exercicio 0717");
        IO_println("71 - Exercicio 0717");
        IO_println("8 - Exercicio 0718");
        IO_println("9 - Exercicio 0719");
        IO_println("10 - Exercicio 0720");
        IO_println("11 - Exercicio 07E1");
        IO_println("12 - Exercicio 07E2");

        
        op = IO_readint("Escolha um exemplo: ");
        

        //testar valor 
        switch(op)
        {
            case 0 : break;
            case 1 : exe0711(); break;
            case 2 : exe0712();break;
            case 3 : exe0713(); break;
            case 4 : exe0714();break;
            case 5 : exe0715(); break;
            case 6 : exe0716();break;
            case 7 : exe0717(); break;
            case 71 : exe0717b(); break;
            case 8 : exe0718();break;
            case 9 : exe0719(); break;
            case 10 : exe0720(); break;
            case 11 : ex07E1(); break;
            case 12 : ex07E2(); break;

            

            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}