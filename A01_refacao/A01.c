#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"io.h"

void question_01 ()
{
    int n=5, x=4,y=n,z=0;
    while(z<y)
    {
        x=x+4*z+1;
        if(x%7==0)
        {
            y=y+1;
        }
        else
        {
            printf("%d\n",x);
        }
        z=z+1;
    }
}

//resposta correta: d) 95

void question_02 ()
{
    char s[] = "a+2*3-D45+(b+c)/e;";
    int x=0;
    for(x = strlen(s)/2; x <strlen(s);x=x+1)
    {
        if('A'<= s[x] && s[x] <= 'Z')
        {
            printf("%c",s[x]);
            x=x+2;
        }
    }

}

//Resposta correta = e) Justificativa (Nao aparece nada)
int f_03 (int x)
{
    int y= x;
    if(x%2 ==0)
    {
        y=f_03(x-1);
    }
    else if (x>2)
    {
        y= y+f_03(x-2);
    }
    return (y);
}

void question_03 ()
{
    printf("f_03(%d) = %d\n",9,f_03(9));
    IO_pause("Apertar ENTER para continuar.");
}

// resposta correta: b)25

void question_04 ()
{
    int n= 9876789, x=0, y=0 ,z=0 ,p=1;
    while(p <= n)
    {
        p= p *10;
        z=z+1;
    }

    p=p/10;
    z=z/2;

    while(x<z)
    {
        if(n/p == n%10)
        {
        y=y+1;
        n=n%p/10;
        p=p/100;
        x=x+1;
        }
        else
        {
            x=z;
        }
    }
    printf("%s %d\n","y= ", y);
    printf("%s %d", "z= ", z);

}

//Resposta correta : a) y=3 e z=3

void question_05 ()
{
    int n=5, y=3, x=1, impar=1;
    printf("%d\t%d\n",x,y);
    x=x+1; // (I)
    while( x<=n)
    {
        y = y+ impar; 
        printf("%d\t%d\n",x,y);
        impar = 2 * x -1;
        x = x+1; // (III)
    }

}

//Resposta correta: c) (I)x=x+1;  (II)(x <=0)  (III)x=x+1;

#include <stdio.h>
#include <stdbool.h>

bool is_Multiple_of_7(int valor) {
    
    if (valor == -14 || valor == -7 || valor == 0) {
        return true;
    } 
    else if (valor > 0) {
        return is_Multiple_of_7((valor / 10) - (valor % 10 * 2));
    }
    
    return false;
}

void question_06() 
{
    int valor=0;
    
    printf("Questao 6 - aberta\n");
    printf("Entre com um valor: ");
    scanf("%d", &valor);
    
    if (is_Multiple_of_7(valor)) { 
        printf("Valor %d e' multiplo de 7.\n", valor);
    } else { 
        printf("Valor %d nao e' multiplo de 7.\n", valor);
    }
}

double sum (int n)
{
    double result = 0.0;
    double ante= 0.0;
    double diff =0.0;
    int x=0;

    for(x=1; x<=n+1; x=x+1)
    {
        ante = result;
        if(x%2 == 0)
        {
            result = result - (1.0/x) ;
        }
        else
        {
            result = result + (1.0/x) ;

        }

        diff = ante - result;
        if (diff < 0)
        {
        diff = -diff;
        }
        

       printf("O termo %d = %.4lf e a diferenca entre ele e o proximo %.4lf \n", x, result,diff);
    }

    return result;
}




void question_07 ()
{
    int n=0;
    double x=0;
    double soma=0.0;
    IO_printf("Questao 7 - aberta\n");
    n = IO_readint("Entre com uma quantidade:");
    x= sum(n);
    soma = x;
    printf("Soma total com %d termos: %.6lf\n", n, soma);

}

bool parequema (chars palavra1, chars palavra2)
{
    int t1 = strlen(palavra1);
    int t2 = strlen(palavra2);
    bool result= false;
    int x = t1;
    int y=0;
    
        if(t1 >= 1 && t2 >= 1)
        {
            if (palavra1[t1 - 1] == palavra2[0])
            {
            IO_printf("%c e %c são ....", palavra1, palavra2);
            result= true;
            }
        }

        if (t1 >= 2 && t2 >= 2)
        {
        if (palavra1[t1 - 2] == palavra2[0] &&
            palavra1[t1 - 1] == palavra2[1])
        {
            IO_printf("2 letras repetem: %c%c\n", palavra1[t1 - 2], palavra1[t1 - 1]);
            result = true;
        }
        }
    
    return result;
}

void question_08 ()
{
    chars palavra1 = IO_new_chars(STR_SIZE);

    palavra1 = IO_readln("Entre com a primeira palavra: ");
    IO_printf("\n");
    chars palavra2 = IO_new_chars(STR_SIZE);
    palavra2 = IO_readln("Entre com a segunda palavra: ");

    if (parequema(palavra1, palavra2))
    {
        IO_printf("\nSao parequema (silabas iguais)\n");
    }
    else
    {
        IO_printf("\nNao sao parequema\n");
    }
}


int main ()
 {
    int op=0;


    do
    {
    printf("0 - Terminar\n");
    printf("1 - question_01\n");
    printf("2 - question_02\n");
    printf("3 - question_03\n");
    printf("4 - question_04\n");
    printf("5 - question_05\n");
    printf("6 - question_06\n");
    printf("7 - question_07\n");
    printf("8 - question_08\n");
   

    printf("%s\n","Qual a opcao?");
    scanf("%d", &op); getchar();

    switch (op)
    {
    case 1 : question_01();
     break;
     case 2 : question_02();
     break;
     case 3 : question_03();
     break;
     case 4 : question_04();
     break;
     case 5 : question_05();
     break;
     case 6 : question_06();
     break;
     case 7 : question_07();
     break;
     case 8 : question_08();
     break;
    default:
        break;
    }
}while(op != 0);
 }
