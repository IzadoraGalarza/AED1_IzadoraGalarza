/** ED06 - exercicios0600
 * Autora : Izadora Galarza Alves - 866053
 * Professor: Theldo Cruz
 */

 //Bibliotecas
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #include"io.h"


 int trescrescente (int n)
 {
    int x=3;

    if(n>1)
    {
        
        trescrescente(n-1);
        IO_printf("%d: %d\n", n, x*n);
    }
    else
    {
        IO_printf("%d: %d\n",1,x);
    }
    
 }

 void exe0611 ()
 {
    int quantidade=0;
    IO_id("Exercicio0611 - 01");
    quantidade = IO_readint("Entre com uma quantidade:");
    trescrescente(quantidade);
    IO_pause("Apertar ENTER para continuar");
 }
 
 int tresdecrescente (int n)
 {
    int c= 0;
    int x =3;
    int y =n;
    

    for (c=n; c>0; c=c-1)
    {
        IO_printf("%d: %d\n", c, x*y);
        y = y - 1;
    }
 }

 
 void exe0612 ()
 {
    int quantidade=0;
    IO_id("Exercicio0612 - 02");
    quantidade = IO_readint("Entre com uma quantidade:");
    tresdecrescente(quantidade);
    IO_pause("Apertar ENTER para continuar");
 }

int fracao1 (int n)
{
    int x=3;
    if(n>1)
    {
        fracao1(n-1);
        IO_printf("1/%d\n",x*(n-1));
        
    }   
    else
    {
        IO_printf("1/%d\n",1);
    }
}

 void exe0613 ()
 {
    int quantidade=0;
    IO_id("Exercicio0613 - 03");
    quantidade = IO_readint("Entre com uma quantidade:");
    fracao1(quantidade);
    IO_pause("Apertar ENTER para continuar");
 
 }

 int fracao2 (int n)
 {
    int x=3;
    
    if(n-1>0)
    {
    
        IO_printf("1/%d\n",x*(n-1));
        fracao2(n-1);
        
    }   
    else
    {
        IO_printf("1/%d\n",1);
    }

 }
 void exe0614 ()
 {

    int quantidade=0;
    IO_id("Exercicio0614 - 04");
    quantidade = IO_readint("Entre com uma quantidade:");
    fracao2(quantidade);
    IO_pause("Apertar ENTER para continuar");
 }

 
    int impar (int x)
 {
    return(2*x-1);
 }

 int numeroNatural (int n)
 {
        int y =0;

     if(n>0)
    {   
        if( n == 1)
        {
            y=3;
        
        }
        else
        {
           y= numeroNatural(n-1) + impar(n-1);
           
        }
        
    }
    return(y);
 }
 void exe0615 ()
 {
    int quantidade=0;
    int soma=0;
    int x=0;
    IO_id("Exercicio0615 - 05");
    quantidade = IO_readint("Entre com uma quantidade:");
    for(int w=1; w<=quantidade; w=w+1)
    {
        x = numeroNatural(w);
        IO_printf("%d\n",x);
        soma= soma + x;
    }
    IO_printf("Soma = %d", soma);
    IO_pause("Apertar ENTER para continuar");

 }

 
 /** 
  *  Incluir uma função recursiva (0616) para 
calcular a soma dos inversos (1/x) dos primeiros valores ímpares positivos múltiplos do valor 3. 
Testar essa função para quantidades diferentes. 
 
Exemplo: valor = 5 => 1/3 + 1/9 + 1/15 + 1/21 + 1/27
  */
 int tresImpar( int n)
{
    int x=3;
    int soma =0;
    if (n >0)
    {
        soma = (tresImpar (n-1));
        int denominador = x * (n-1);
        if(denominador % 2 != 0 && denominador % 3 == 0)
        {
            IO_printf("1/%d\n",denominador);
            soma = soma + denominador;

        }
    }
return(soma);
}

 void exe0616 ()
 {
    int quantidade=0;
    int w =0; //controle
    int z = 0; // contador
    IO_id("Exercicio0616 - 06");
    quantidade = IO_readint("Entre com uma quantidade:");
    for( z=0; z<= quantidade; z=z+1)
    {
        if((3*z % 2 != 0) && 3*z %3 ==0)
        {
            
            w=w+1;
        }
        else
        {
            quantidade= quantidade +1;
        }
        
    }
    int soma = tresImpar(quantidade);
    IO_printf("Soma = 1/%d", soma );
    IO_pause("Apertar ENTER para continuar");
 }

 /**
  *  Incluir um método recursivo (0617) para 
ler uma cadeia de caracteres e chamar procedimento recursivo para 
mostrar cada símbolo separadamente, de trás para frente, um por linha. 
 
Exemplo: sequência = "abcde" 
 
  */
 void separarLetras (int t, chars palavras)
 {
    
    if(t >= 0)
    {
        IO_printf("%c\n",palavras[t]);
        separarLetras(t-1, palavras);

    }
 }

 void exe0617 ()
 {
    chars palavra =IO_new_chars(STR_SIZE);
    int tamanho =0;
    IO_id("Exercicio0617 - 07");
    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen(palavra);
    separarLetras(tamanho - 1,palavra);
    IO_pause("Apertar ENTER para continuar");

 }

 int letrasPares (int t, chars palavras)
 {
    int m = strlen(palavras);
    int contador=0;
    char simbolo = palavras[t];
    if(t < m )
    {
        if((simbolo >= '0' && simbolo <= '9') && simbolo%2==0)
        {
        IO_printf("%c\n",palavras[t]);
        contador = 1;
        }

     contador = contador + letrasPares(t+1, palavras);

    }
    return(contador);
 }
 void exe0618 ()
 {
    chars palavra =IO_new_chars(STR_SIZE);
    int tamanho =0;
    IO_id("Exercicio0618 - 08");
    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen(palavra);
    int valor = letrasPares(0 ,palavra);
    IO_printf("Quantidade de digitos com valores pares: %d", valor);
    IO_pause("Apertar ENTER para continuar");
 }

 int cp (int t, chars palavras)
 {
    int m = strlen(palavras);
    int contador=0;
    char simbolo = palavras[t];
    if(t < m )
    {
        if((simbolo > 'C' && simbolo < 'P') && !('a' <= simbolo && simbolo <= 'z'))
        {
        IO_printf("%c\n",palavras[t]);
        contador = 1;
        }

     contador = contador + cp(t+1, palavras);

    }
    return(contador);
 }
 void exe0619 ()
 {
    chars palavra =IO_new_chars(STR_SIZE);
    int tamanho =0;
    IO_id("Exercicio0619 - 09");
    palavra = IO_readstring("Entre com uma palavra:");
    tamanho = strlen(palavra);
    int valor = cp(0 ,palavra);
    IO_printf("Quantidade de maiusculas maiores que 'C' e menores que 'P': %d", valor);
    IO_pause("Apertar ENTER para continuar");
 }

 int fibonacci(int x)
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

void exe0620()
{
    int k = 0;
    int y = 1;
    int soma = 0;
    int pares = 0;
    int termo = 0;

    IO_id("Exercicio0620 - 10");
    k = IO_readint("Entre com uma quantidade:");

    while (pares < k)
    {
        termo = fibonacci(y);

        if (termo % 2 == 0)
        {
            IO_printf("%d\n", termo);
            soma = soma + termo;
            pares= pares +1;
        }

        y=y +1;
    }

    IO_printf("A soma dos %d primeiros termos pares de Fibonacci e: %d\n", k, soma);
    IO_pause("Apertar ENTER para continuar");
}


 

 


 int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED05 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exercicio 0611");
        IO_println("2 - Exercicio 0612");
        IO_println("3 - Exercicio 0613");
        IO_println("4 - Exercicio 0614");
        IO_println("5 - Exercicio 0615");
        IO_println("6 - Exercicio 0616");
        IO_println("7 - Exercicio 0617");
        IO_println("8 - Exercicio 0618");
        IO_println("9 - Exercicio 0619");
        IO_println("10 - Exercicio 0620");
        
        




        op = IO_readint("Escolha um exemplo: ");
        

        //testar valor 
        switch(op)
        {
            case 0 : break;
            case 1 : exe0611(); break;
            case 2 : exe0612();break;
            case 3 : exe0613(); break;
            case 4 : exe0614();break;
            case 5 : exe0615(); break;
            case 6 : exe0616();break;
            case 7 : exe0617(); break;
            case 8 : exe0618();break;
            case 9 : exe0619(); break;
            case 10 : exe0620(); break;
            

            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}