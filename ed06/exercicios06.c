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

 int somar (int x)
 {
    int soma=0;
    soma= soma+ x;
 }

 int numeroNatural (int n)
 {
    int x = 3;
    if (n>1)
    {
        x = numeroNatural(x +2*n-1);
        IO_printf("%d\n",x);
    }
 }
 void exe0615 ()
 {

 }

 void exe0616 ()
 {

 }

 void exe0617 ()
 {

 }

 void exe0618 ()
 {

 }

 void exe0619 ()
 {

 }

 void exe0620 ()
 {

 }

 void exe06E1 ()
 {

 }

 void exe06E2 ()
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
        IO_println("11 - Exercicio 06E1");
        IO_println("12 - Exercicio 06E2");




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
            case 11 : exe06E1(); break;
            case 12 : exe06E2(); break;

            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );

}