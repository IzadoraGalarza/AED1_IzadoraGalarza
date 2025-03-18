// 866053_Izadora Galarza Alves
// Exemplo_0001

#include <stdio.h>
#include<stdlib.h>
#include "io.h"
#include<math.h>

//primeiro testa se é difente ou igual a 0 usando apenas if
void method_01 (void)
{
	int x =0;
	IO_id("866053_AED1 - Exemplo0201");
	x= IO_readint("Entrar com um valor inteiro:");

	if( x == 0 )
	{
		IO_printf("%s (%d)\n","Valor igual a zero",x);
	}
	if ( x !=0)
	{
		IO_printf("%s (%d)\n","Valor diferente de zero",x);
	}
	

	IO_pause("Apertar ENTER para terminar.");
}

//testa se é igual ou diferente a 0 usando if e else
void method_02 (void)
{
	int x =0;
	IO_id("866053_AED1 - Exemplo0202");
	x= IO_readint("Entrar com um valor inteiro:");

	if( x == 0 )
	{
		IO_printf("%s (%d)\n","Valor igual a zero",x);
	}
	else
	{
		IO_printf("%s (%d)\n","Valor diferente de zero",x);
	}
	
	IO_pause("Apertar ENTER para terminar.");
}

// testa se é igual a zero, ou diferente e se diferente, se e maior ou menor, usando if e else
void method_03 (void)
{
	int x =0;
	IO_id("866053_AED1 - Exemplo0203");
	x= IO_readint("Entrar com um valor inteiro:");

	if( x == 0 )
	{
		IO_printf("%s (%d)\n","Valor igual a zero",x);
	}
	else
	{
		IO_printf("%s (%d)\n","Valor diferente de zero",x);
		if( x > 0 )
		{
			IO_printf("%s (%d)\n", "Valor maior que zero", x);
		}
		else
		{
			IO_printf("%s (%d)\n", "Valor menor que zero", x);
		}
	}
	
	IO_pause("Apertar ENTER para terminar.");
}

//usando intervalo e numero real
void method_04 (void)
{
	double x = 0.0;
	
	IO_id("866053_AED1 - Exemplo0204");
	x = IO_readdouble ("Entrar com valor real:");

	if (1.0 <= x && x <= 10.0)
	{
		IO_printf("%s (%lf)\n", "Valor dentro do intervalo [1:10]",x);
	}
	else 
	{
		IO_printf("%s(%lf)\n","Valor fora do intervalo [1:10]",x);
		if(x<1.0)
		{
			IO_printf("%s(%lf)\n","Valor abaixo do intervalo [1:10]",x);
		}
		else
		{
			IO_printf("%s(%lf)\n","Valor acima do intervalo [1:10]",x);
		}
	}
	IO_pause("Apertar ENTER para terminar.");
}
//verifica se e' maiuscula ou minuscula, E se nao, se e algarismo ou diferente
void method_05 (void)
{
	char x = '_';
	
	IO_id("866053_AED1 - Exemplo0205");
	x = IO_readchar ("Entrar com um caractere:");

	if (('a' <= x) && (x <= 'z'))
	{
		IO_printf("%s (%c)\n", "Letra minuscula",x);
	}
	else 
	{
		IO_printf("%s(%c)\n","Valor diferente de minuscula",x);
		if(('A' <= x) && (x <= 'Z'))
		{
			IO_printf("%s(%c)\n","Letra Maiuscula",x);
		}
		else
		{
			if(('0' <= x) && (x<='9'))
			{
			IO_printf("%s(%c)\n","Algarismo",x);
			}
			else
			{
				IO_printf("%s(%c)\n","Valor diferente de algarismo",x);
			}
		}
	}
	IO_pause("Apertar ENTER para terminar.");
}

//verifica se e letra
void method_06 (void)
{
	char x = '_';
	
	IO_id("866053_AED1 - Exemplo0206");
	x = IO_readchar ("Entrar com um caractere:");
	if( ('a'<= x && x<='z') ||
		('A'<= x && x<= 'Z'))
	{
		IO_printf("%s(%c)\n","Letra",x);
	}
	else
	{
		IO_printf("%s(%c)\n","Valor diferente de letra",x);
	}
	IO_pause("Apertar ENTER para terminar.");
}

//verifica se NAO e' letra
void method_07 (void)
{
	char x = '_';
	
	IO_id("866053_AED1 - Exemplo0207");
	x = IO_readchar ("Entrar com um caractere:");
	if(! (('a'<= x && x<='z') ||
		('A'<= x && x<= 'Z')))
	{
		IO_printf("%s(%c)\n","Valor diferente de letra",x);
	}
	else
	{
		IO_printf("%s(%c)\n","Letra",x);
	}
	IO_pause("Apertar ENTER para terminar.");
}

//verifica se esta entre as opcoes e mostra o valor em ascii
void method_08 (void)
{
	char x = '_';
	
	IO_id("866053_AED1 - Exemplo0208");
	x = IO_readchar ("Entrar com um caractere['0','A','a']:");
	switch (x)
		{
			case '0': 
				IO_printf("%s(%c=%d)\n","Valor igual do simbolo zero",x,x);
				break;
			case 'A' : 
				IO_printf("%s(%c=%d)\n","Valor igual a letra 'A'",x,x);
				break;
			case 'a': 
				IO_printf("%s(%c=%d)\n","Valor igual a letra 'a'",x,x);
				break;
			default: 
				IO_printf("%s(%c=%d)\n", "Valor diferente das opcoes ['0','A','a']",x,x);
		}
		IO_pause("Apertar ENTER para continuar");
}

//verifica se esta entre as opcoes de inteiros
void method_09 (void)
{
	int x = 0;
	
	IO_id("866053_AED1 - Exemplo0209");
	x = IO_readint ("Entrar com um valor inteiro[0,1,2,3]:");
	switch (x)
		{
			case 0: 
				IO_printf("%s(%d)\n","Valor igual a zero",x);
				break;
			case 1 : 
				IO_printf("%s(%d)\n","Valor igual a um",x);
				break;
			case 2: 
				IO_printf("%s(%d)\n","Valor igual a dois",x);
				break;
			case 3: 
				IO_printf("%s(%d)\n","Valor igual a tres",x);
				break;
			default: 
				IO_printf("%s(%c=%d)\n", "Valor diferente das opcoes [0,1,2,3]",x,x);
		}
		IO_pause("Apertar ENTER para continuar");
}

// verifica se esta entre as opcoes com biblioteca IO
void method_10 (void)
{
	int x = 0;
	
	IO_id("866053_AED1 - Exemplo0210");
	x = IO_readint ("Entrar com um valor inteiro[0,1,2,3]:");
	switch (x)
		{
			case 0: 
				IO_println (IO_concat ("Valor igual a zero(",
					                    IO_concat(IO_toString_d(x),")\n")));
				break;
			case 1 : 
				IO_println (IO_concat ("Valor igual a um(",
					                    IO_concat(IO_toString_d(x),")\n")));
				break;
			case 2: 
				IO_println (IO_concat ("Valor igual a dois(",
					                    IO_concat(IO_toString_d(x),")\n")));
				break;
			case 3: 
				IO_println (IO_concat ("Valor igual a tres(",
					                    IO_concat(IO_toString_d(x),")\n")));
				break;
			default: 
				IO_println (IO_concat ("Valor diferente das opcoes [0,1,2,3](",
					                    IO_concat(IO_toString_d(x),")\n")));
		}
		IO_pause("Apertar ENTER para continuar");
}



int main ()
{
	int opcao=0;

	do
		{
	    printf("\n%s\n","Opcoes:");
		printf("%s\n"," 0 - Terminar");
		printf("%s\n"," 1 - Metodo 1");
	    printf("%s\n"," 2 - Metodo 2");
		printf("%s\n"," 3 - Metodo 3");
	    printf("%s\n"," 4 - Metodo 4");
		printf("%s\n"," 5 - Metodo 5");
		printf("%s\n"," 6 - Metodo 6");
		printf("%s\n"," 7 - Metodo 7");
		printf("%s\n"," 8 - Metodo 1");
		printf("%s\n"," 9 - Metodo 8");
		printf("%s\n"," 10 - Metodo 10");
		printf("\n");

		printf("%s","Escolha uma opcao:");
		scanf("%d",&opcao);
		getchar();
			
		printf("%s: %d\n\n","Opcao escolhida",opcao);

				switch(opcao)
				{
					case 0: break;
					case 1: method_01(); 
						    break;
					case 2: method_02(); 
						    break;
					case 3: method_03(); 
						    break;
					case 4: method_04(); 
						    break;
					case 5: method_05(); 
						    break;
					case 6: method_06(); 
					        break;
					case 7: method_07(); 
						    break;
					case 8: method_08(); 
						    break;
					case 9: method_09(); 
						    break;
					case 10: method_10(); 
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
	
