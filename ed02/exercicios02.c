/* Aluna: Izadora Galarza Alves 
Professor : Theldo Cruz
Guia_02
*/


#include <stdio.h>
#include<stdlib.h>
#include "io.h"
#include<math.h>


/*0211: 
- ler um valor inteiro do teclado e
- dizer se é par e positivo, ou ímpar e negativo.*/

void exercicio_01 (void)
{
    int x=0;
	IO_id("866053 -  exerciciocicio0211");
	x = IO_readint("Entre com um valor inteiro:");

	if((x>=0) && (x%2==0))
    {
		IO_printf("%s(%d)\n","Valor par e positivo",x);
	}
	else 
	{
		if((x<0) && ( x%2 !=0))
		{
		IO_printf("%s(%d)\n","Valor impar e negativo",x);
	    }
	     else 
		{ 
			IO_printf("%s(%d)\n", "Valor nao e' nem par positivo, nem impar negativo",x);
		}
	}
	IO_pause("Apertar ENTER para continuar");
}

/*0212:
- ler um valor inteiro do teclado e
- dizer se é par e menor que -25, ou ímpar e maior que 25.
 */
void exercicio_02 (void)
{
	int x =0;

    IO_id("866053 - exerciciocicio0212");
    x = IO_readint("Entre com um valor inteiro:");

    if((x<-25) && (x%2==0))
    {
        IO_printf("%s(%d)\n", "Valor e' par e menor que -25",x);
    }
    else
    {
        if((x>25) && (x%2!=0))
        {
            IO_printf("%s(%d)\n","Valor impar e maior que 25",x);
        }
        else
        {
            IO_printf("%s(%d)\n","Valor nao entre nos criterios: Impar maior que 25 e Par menor que -25",x);
        }
    }
    IO_pause("Apertar ENTER para continuar");
}

/*0213:
- ler um valor inteiro do teclado e
- dizer se pertence ao intervalo aberto entre (20:55).
*/
void exercicio_03 (void)
{
    int x=0;

    IO_id("866053 - exerciciocicio0213");
    x= IO_readint("Entre com um valor inteiro:");

	if((x>20) && (x<55))
    {
        IO_printf("%s(%d)\n","Valor dentro do intervalo (20:55)",x);
    }
    else
    {
        IO_printf("%s(%d)\n","Valor fora do intervalo aberto (20:55)",x);
    }
	IO_pause("Apertar ENTER para terminar.");
}

/*0214:
- ler um valor inteiro do teclado e
- dizer se pertence ao intervalo fechado entre [20:55]
*/
void exercicio_04 (void)
{
	int x=0;

    IO_id("866053 - exerciciocicio0214");
    x= IO_readint("Entre com um valor inteiro:");

	if((x>=20) && (x<=55))
    {
        IO_printf("%s(%d)\n","Valor dentro do intervalo [20:55]",x);
    }
    else
    {
        IO_printf("%s(%d)\n","Valor fora do intervalo fechado [20:55]",x);
    }
	IO_pause("Apertar ENTER para terminar.");
}
void exercicio_05 (void)
{
	int x =0;

    IO_id("866053 - exerciciocicio0215");
    x= IO_readint("Entre com um valor inteiro:");

    if( (x>20) && (x<=30)) 
	{
		IO_printf("%s(%d)\n","Valor esta dentro da intersecao de [10:30] e (20:40)",x);
	} 
	else 
	{
		if((x>=10) && (x<=30)) 
		{
			IO_printf("%s(%d)\n", "Valor dentro apenas do intervalo [10:30]",x);
		} 
		else 
		{
			if((x>20) && (x<40))
			{
			IO_printf("%s(%d)\n", "Valor dentro apenas do intervalo (20:40)",x);
			}
			else  
			{
			IO_printf("%s(%d)\n", "Nao pertence a nenhum intervalo",x);
			}
		}
	}//fim do else principal
    IO_pause("Aperte ENTER para continuar.");
}// fim exerciciocicio0215


void exercicio_06 (void)
{
	int a=0;
	int b=0;

	IO_id("866053_AED1 - exerciciocicio0216");

	a = IO_readint("Entre com um valor inteiro:");
	b = IO_readint("Entre com um segundo valor inteiro:");

	if ((a%2==0) && (b%2 != 0))
	{
		IO_printf("%s(%d,%d)\n","O primeiro valor e' par e o segundo e' impar",a,b);
	}
	else 
	{
	  if(a%2 != 0)
	    {
			IO_printf("%s(%d)\n","Primeiro valor nao e' par",a);
		}
		else
		{
			if(b%2==0)
			{
				IO_printf("%s(%d)\n","Segundo valor nao e' impar",b);
			}
			
		}
	}
	IO_pause("\n\nApertar ENTER para terminar.");
	
}
void exercicio_07 (void)
{

	int a=0;
	int b=0;

	IO_id("866053_AED1 - exerciciocicio0217");
	a= IO_readint("Entre com um valor inteiro:");
	b= IO_readint("Entre com um segundo valor inteiro:");

	if (((a<0) && (a%2==0)) && ((b>=0) && (b%2 !=0)) )
	{
		IO_printf("%s(%d)\n","Primeiro e' negativo e par",a);
		IO_printf("%s(%d)\n","Segundo e' impar e positivo",b);
	}
	else
	{
		if(((a>0) || (a%2!=0)) && ((b<=0) || (b%2 ==0)))
		{
			IO_printf("%s(%d,%d)\n","Nao esta de acordo com os requisitos (primeiro par negativo e segundo impar  positivo)",a,b);
		}
	}

	IO_pause("\n\nApertar ENTER para terminar.");
	
}
void exercicio_08 (void)
{
	double a=0.0;
	double b=0.0;
	IO_id("866053_AED1 - exerciciocicio0218");
	a= IO_readdouble("Entre com o primeiro valor: ");
	b= IO_readdouble("Entre com o segundo valor:");

	b= b/4;

	if( a > b)
	{
	 IO_printf("%s(%lf,%lf)\n","Primeiro valor e' maior que 1/4 do segundo",a,b);
	}
	else
	{
		if(a<b)
		{
			IO_printf("%s(%lf,%lf)\n","Primeiro valor e' menor que 1/4 do segundo",a,b);
		}
		else
		{
			if(a==b)
			{
				IO_printf("%s(%lf,%lf)\n","Primeiro valor e' igual que 1/4 do segundo",a,b);

			}
		}
	}

	IO_pause("\n\nApertar ENTER para terminar.");

}
void exercicio_09 (void)
{
	double a,b,c; 
	IO_id("866053_AED1 - exerciciocicio0219");
	a = IO_readdouble("Entre com o primeiro valor real:");
	b = IO_readdouble("Entre com o segundo valor real:");
	c = IO_readdouble("Entre com o terceiro valor real:");

	if ( ((a != b) && (a != c) && (b != c)) &&  (a<b && b<c) )
	{
		IO_printf("%s(%lf,%lf,%lf)\n", "O segundo valor esta entre o primeiro e o terceiro",a,b,c);
	}
	else
	{	
		if(b<a || b> c)
		{
			IO_printf("%s(%lf,%lf,%lf)\n","O segundo nao esta entre o primeiro e o terceiro",a,b,c);
		}
		else if (a == b || a== c || b == c)
		{
			
				IO_printf("%s(%lf,%lf,%lf)\n","Valores semelhantes",a,b,c);
			
		}	
	}
	IO_pause("\n\nApertar ENTER para terminar.");
	
}
void exercicio_10 (void)
{
	double a,b,c; 
	IO_id("866053_AED1 - exerciciocicio0220");
	a = IO_readdouble("Entre com o primeiro valor real:");
	b = IO_readdouble("Entre com o segundo valor real:");
	c = IO_readdouble("Entre com o terceiro valor real:");

	if ( ((a != b) && (a != c) && (b != c)) &&  (b<a || b> c))
	{
		IO_printf("%s(%lf,%lf,%lf)\n","O segundo nao esta entre o primeiro e o terceiro",a,b,c);

	}
	else
	{	
		if(b<a || b> c)
		{
			IO_printf("%s(%lf,%lf,%lf)\n", "Nao cumpre os requisitos",a,b,c);
		}
		else if (a == b || a== c || b == c)
		{
			
				IO_printf("%s(%lf,%lf,%lf)\n","Valores semelhantes",a,b,c);
			
		}	
	}
	IO_pause("\n\nApertar ENTER para terminar.");
}

void exercicio_11 (void)
{
	char a,b,c; 
	IO_id("866053_AED1 - 02E1");
	a = IO_readchar("Entre com o primeiro caractere:");
	b = IO_readchar("Entre com o segundo caractere:");
	c = IO_readchar("Entre com o terceiro caractere:");

	if( (a> b && b<c) || a<b && a>c)
	{
	  IO_printf("%s(%c,%c,%c)\n", "Primeiro caractere esta entre os outros dois",a,b,c);
	}
	else
	{
		if (a == b || a == c)
		{
			IO_printf("%s(%c, %c, %c)\n", "O primeiro valor e' igual a um dos outros dois", a, b, c);
		}
		else
		{
			IO_printf("%s(%c, %c, %c)\n", "O primeiro valor nao e' igual e nem esta entre os outros dois", a, b, c);
		}
	}
IO_pause("Apertar ENTER para continuar");
}

void exercicio_12(void) {
    char a, b, c;

    IO_id("866053_AED1 - Exercicio02E2");
    a = IO_readchar("Entre com o primeiro caractere: ");
    b = IO_readchar("Entre com o segundo caractere: ");
    c = IO_readchar("Entre com o terceiro caractere: ");

    if (a != b && a != c && b != c) 
	{
        if (a < b && a < c) 
		{
            IO_printf("%s(%c, %c, %c)\n", "O primeiro valor esta fora do intervalo dos outros dois", a, b, c);
        } 
		else if (a > b && a > c) 
			{
            IO_printf("%s(%c, %c, %c)\n", "O primeiro valor esta fora do intervalo dos outros dois", a, b, c);
            } 
			else 
			{
            IO_printf("%s(%c, %c, %c)\n", "O primeiro valor esta dentro do intervalo dos outros dois", a, b, c);
             }
        } 
	    else 
		{
        IO_printf("%s(%c, %c, %c)\n", "Os valores nao sao todos diferentes", a, b, c);

    }

    IO_pause("\n\nApertar ENTER para terminar.");
}


int main ()
{
	int opcao=0;

	do
		{
	    printf("\n%s\n","Opcoes:");
		printf("%s\n"," 0 - Terminar");
		printf("%s\n"," 1 - exercicio 1");
	    printf("%s\n"," 2 - exercicio 2");
		printf("%s\n"," 3 - exercicio 3");
	    printf("%s\n"," 4 - exercicio 4");
		printf("%s\n"," 5 - exercicio 5");
		printf("%s\n"," 6 - exercicio 6");
		printf("%s\n"," 7 - exercicio 7");
		printf("%s\n"," 8 - exercicio 1");
		printf("%s\n"," 9 - exercicio 8");
		printf("%s\n"," 10 - exercicio 10");
		printf("%s\n"," 11 - Extra 1");
		printf("%s\n"," 12 - Extra 2");

		printf("\n");

		printf("%s","Escolha uma opcao:");
		scanf("%d",&opcao);
		getchar();
			
		printf("%s: %d\n\n","Opcao escolhida",opcao);

				switch(opcao)
				{
					case 0: break;
					case 1: exercicio_01(); 
						    break;
					case 2: exercicio_02(); 
						    break;
					case 3: exercicio_03(); 
						    break;
					case 4: exercicio_04(); 
						    break;
					case 5: exercicio_05(); 
						    break;
					case 6: exercicio_06(); 
					        break;
					case 7: exercicio_07(); 
						    break;
					case 8: exercicio_08(); 
						    break;
					case 9: exercicio_09(); 
						    break;
					case 10: exercicio_10(); 
						    break;
					case 11: exercicio_11(); 
						    break;
					case 12: exercicio_12(); 
						    break;
				
					default: printf("\nERRO: Opcao invalida.\n");
                             break;
		        }
	      }
		  while (opcao!=0);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return(0);
}
	
