/*
Exemplo0100 - v0.0. - 18/02/2025
Author:Izadora Galarza Alves
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include<string.h>
#include <math.h>

void method_01 ( void )
{
    int x = 0;

    printf ( "\n%s\n", "Method_01 - Programa = v0.0" );
    printf ( "\n%s%d\n", "x = ", x );
    printf ( "&%s%p\n" , "x = ", &x );

    printf ( "Entrar com um valor inteiro: " );
    scanf ( "%d", &x );
    getchar ( );

    printf ( "%s%i\n", "x = ", x );

    printf ( "\n\nApertar ENTER para continuar." );
    getchar();
	return;

}


/**
Method_02
*/

void method_02 ( void )
{
    double x = 0.0;

    printf ( "\n%s\n", "Method_02 - Programa - v0.0" );
    printf ( "\n%s%lf\n", "x = ", x );

    printf ( "Entrar com um valor real: " );
    scanf ( "%lf", &x );
    getchar ( );

    printf ( "%s%lf\n", "x = ", x );

    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar();
	return;
}

/**
Method_03
*/

void method_03 ( void )
{
    char x = 'A';

    printf ( "\n%s\n", "Method_03 - Programa - v0.0" );
    printf ( "\n%s%c\n", "x = ", x );

    printf ( "Entrar com um caractere: " );
    scanf ( "%c", &x );
    getchar ( );

    printf ( "%s%c\n", "x = ", x );

    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar();
	return;
}

/**
Method_04
*/

void method_04 ( void )
{
    bool x = false;
    int y = 0;

    printf ( "\n%s\n", "EXEMPLO0104 - Programa - v0.0" );
    printf ( "\n%s%d\n", "x = ", x );

    printf ( "Entrar com um valor logico: " );
    scanf ( "%d", &y );
    getchar ( );

    x = (y != 0);

    printf ( "%s%d\n", "x = ", x );

    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar();
	return;
}


/**
Method_05
*/

void method_05 ( void )
{
    char x[80] = "abc";
    char *px = &x[0];

    printf ( "\n%s\n", "Method_05 - Programa - v0.0" );
    printf ( "\n%s%s\n", "x = ", x );

    printf ( "Entrar com uma cadeia de caracteres: " );
    scanf ( "%s", x );
    getchar ( );

    printf ( "%s%s\n", "x = ", x );

    printf ( "Entrar com outra cadeia de caracteres: " );
    scanf ( "%s", px );
    getchar ( );

    printf ( "%s%s\n", "x = ", px );

    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar();
	return;
}



/**
Method_06
*/

void method_06 ( void )
{
    int x = 0;
    int y = 0;
    int z = 0;
    int *py = &y;

    printf ( "\n%s\n", "Method_06 - Programa - v0.0" );
    printf ( "%s%d\n", "x = ", x );
    printf ( "%s%i\n" , "y = ", y );

    printf ( "Entrar com um valor inteiro: " );
    scanf ( "%d", &x );
    getchar ( );

    printf ( "Entrar com outro valor inteiro: " );
    scanf ( "%i", py );
    getchar ( );

    z = x * y;

    printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );

    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar();
	return;
}


/**
Method_07
*/

#include <stdio.h>
#include <string.h>

void method_07 ( void )
{
    // definir dados
    char x[80] = "abc"; 
    char y[80] = "def"; 
    char z[80];         

    strcpy(z, ""); // copiar para (z) a representação de vazio

    
    printf ( "\n%s\n", "Method_07 - Programa - v0.0" );

    
    printf ( "%s%s (%d)\n", "x = ", x, (int)strlen(x) );
    printf ( "%s%s (%d)\n", "y = ", y, (int)strlen(y) );
    

    // ler do teclado
    printf ( "Entrar com caracteres: " );
    scanf ( "%s", x );
    getchar(); 

    printf ( "Entrar com outros caracteres: " );
    scanf ( "%s", y );
    getchar(); 

    // operar valores
    strcpy(z, x); // copiar (x) para (z)
    strcat(z, y); // concatenar (juntar) (y) a (z)

    // mostrar valor resultante
    printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );

    // operar valores (forma alternativa)
    strcpy(z, strcat(strdup(x), y));
    // copiar para (z) o resultado de concatenar a cópia de (x) com (y)
    // OBS.: Se não duplicar, o valor (x) será alterado.

    // mostrar valor resultante
    printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );

    // encerrar
    printf ( "\n\nApertar ENTER para continuar.\n" );
    getchar(); 
	return;
}


/**
Method_08
*/

void method_08 ( void )
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    printf("\n%s\n", "Method_08 - Programa - v0.0");

    printf("%s%lf\n", "x = ", x);
    printf("%s%lf\n", "y = ", y);

    printf("Entrar com um valor real: ");
    scanf("%lf", &x);
    getchar();
    
    printf("Entrar com outro valor real: ");
    scanf("%lf", &y);
    getchar();

    z = pow(x, y);
    printf("%s(%lf) elevado a (%lf) = (%lf)\n", "z = ", x, y, z);

    x = pow(z, 1.0 / y);
    printf("%s(%lf) elevado a (1/%lf) = (%lf)\n", "z = ", z, y, x);

    z = sqrt(x);
    printf("%sraiz(%lf) = (%lf)\n", "z = ", x, z);

    printf("\n\nApertar ENTER para continuar.\n");
    getchar();
}


/**
Method_09
*/

void method_09 ( void )
{
    int x = 0;
    double y = 3.5;
    char z = 'A';
    bool w = false;
    char s[80] = "";

    printf("\n%s\n", "Method_09 - Programa - v0.0");

    printf("01. %s%d\n", "x = ", x);
    printf("02. %s%lf\n", "y = ", y);
    printf("03. %s%c\n", "z = ", z);

    x = (int)z;
    printf("04. %s%d -> %c\n", "x = ", x, z);

    x = (int)y;
    printf("05. %s%d -> %lf\n", "x = ", x, y);

    x = 97;
    z = (char)x;
    printf("06. %s%c -> %d\n", "z = ", z, x);

    x = (int)'0';
    z = (char)x;
    printf("07. %s%c -> %d\n", "z = ", z, x);

    x = w;
    printf("08. %s%d -> %d\n", "x = ", x, w);

    w = true;
    x = w;
    printf("09. %s%d -> %d\n", "x = ", x, w);

    x = (w == false);
    printf("10. %s%d -> %d\n", "x = ", x, w);

    x = !(w == false);
    printf("11. %s%d -> %d\n", "x = ", x, w);

    x = (w != false);
    printf("12. %s%d -> %d\n", "x = ", x, w);

    w = (x == 0);
    printf("13. %s%d == %d = %d\n", "w = ", x, 0, w);

    w = (x != 0);
    printf("14. %s%d != %d = %d\n", "w = ", x, 0, w);

    w = (x < y);
    printf("15. %s%d < %lf = %d\n", "w = ", x, y, w);

    w = (x <= y);
    printf("16. %s%d <= %lf = %d\n", "w = ", x, y, w);

    w = (y > x);
    printf("17. %s%lf > %d = %d\n", "w = ", y, x, w);

    w = (y >= x);
    printf("18. %s%lf >= %d = %d\n", "w = ", y, x, w);

    x = 4;
    w = (x % 2 == 0);
    printf("19. %s (%d%%2) ? %d\n", "e' par ", x, w);

    x = 4;
    w = (x % 2 != 0);
    printf("20. %s (%d%%2) ? %d\n", "e' impar ", x, w);

    z = '5';
    w = ('0' <= z && z <= '9');
    printf("21. %s (%c) ? %d\n", "e' digito", z, w);

    z = 'x';
    w = ('a' <= z && z <= 'z');
    printf("22. %s (%c) ? %d\n", "e' minuscula ", z, w);

    z = 'X';
    w = (!( 'a' <= z && z <= 'z' ));
    printf("23. %s (%c) ? %d\n", "nao e' minuscula ", z, w);

    z = 'x';
    w = ('A' <= z && z <= 'Z');
    printf("24. %s (%c) ? %d\n", "e' maiuscula ", z, w);

    z = 'X';
    w = ((z < 'A') || ('Z' < z));
    printf("25. %s (%c) ? %d\n", "nao e' maiuscula ", z, w);

    z = '0';
    w = ('0' == z || '1' == z);
    printf("26. %s (%c) ? %d\n", "e' 0 ou 1 ", z, w);

    strcpy(s, "zero");
    printf("27. palavra = %s\n", s);

    w = (strcmp("zero", s) == 0);
    printf("28. palavra == %s ? %d\n", s, w);

    strcpy(s, "um e dois");
    printf("29. palavras = %s\n", s);

    w = (strcmp("zero", s) != 0);
    printf("30. palavra == %s ? %d\n", s, w);

    printf("\n\nApertar ENTER para continuar.");
    getchar(); // aguardar por ENTER
}

/**
Method_10
*/

void method_10 ( void )
{
    int x = 5;
    double y = 3.5;
    char z = 'A';
    bool w = TRUE;
    chars a = IO_new_chars(STR_SIZE);
    chars b = IO_new_chars(STR_SIZE);
    chars c = IO_new_chars(STR_SIZE);

    IO_id("Method 10 - Programa - v0.0");

    strcpy(a, "abc");
    strcpy(b, "def");
    IO_printf("\na = %s b = %s\n", a, b);
    c = IO_concat(a, b);
    IO_printf("\nc = [%s]+[%s] = [%s]\n", a, b, c);

    strcpy(a, "c = ");
    strcpy(c, STR_EMPTY);
    IO_printf("%s\n", IO_concat(a, IO_toString_c(z)));
    IO_println(IO_concat("x = ", IO_toString_d(x)));
    IO_println(IO_concat("w = ", IO_toString_b(w)));

    strcpy(b, STR_EMPTY);
    IO_print("y = ");
    IO_print(IO_concat(b, IO_toString_f(y)));
    IO_print("\n");

    z = IO_readchar("char = ");
    IO_println(IO_concat(a, IO_toString_c(z)));

    y = IO_readdouble("double = ");
    IO_println(IO_concat(a, IO_toString_f(y)));

    x = IO_readint("int = ");
    IO_println(IO_concat(a, IO_toString_d(x)));

    w = IO_readbool("bool = ");
    IO_println(IO_concat(a, IO_toString_b(w)));

    b = IO_readstring("chars = ");
    IO_println(IO_concat(a, b));

    b = IO_readln("line = ");
    IO_println(IO_concat(a, b));

    IO_pause("Apertar ENTER para terminar");
}


int main ( int argc, char* argv [ ] )
{
// definir dado
int opcao = 0;
// identificar
printf ( "%s\n", "Exemplo0100 - Programa = v0.0" );
printf ( "%s\n", "Autor: Izadora Galarza Alves" );
printf ( "\n" ); // mudar de linha
// acoes
// repetir
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
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
0.1     01. ( ___ ) identificacao de programa
*/