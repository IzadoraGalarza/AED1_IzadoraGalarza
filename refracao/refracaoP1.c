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

bool is_Multiple_of_7 (int valor)
{
    int result = valor;
    int resto=0, ultimo=0;
    while(result > 0)
    {
        resto =result/10; //o que sobrou apos tirar o ultimo algarismo
        ultimo =result % 10; //ultimo algarismo
        result = resto - 2*ultimo;

    }
   
    return (result);
}
void question_06 ()
{
    int valor=0;
    int x = 0;
    IO_id("Questao 6 - aberta");
    valor = IO_readint ("Entre com um valor: ");
    x = is_Multiple_of_7(valor);
    if(x == 0 || x == -7 || x == -14)
    {
        IO_printf(" Valor %d e' multiplo de 7",valor);
    }
    else
    {
        IO_printf(" Valor %d nao e' multiplo de 7",valor);

    }

    IO_pause("Apertar ENTER para continuar.");

}


void question_07 ()
{


}

void question_08 ()
{


}


int main ()
 {
    int op=0;


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
    scanf("%d", &op);

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
 }
