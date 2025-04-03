/** ED06 - exemplos0600
 * Autora : Izadora Galarza Alves - 866053
 * Professor: Theldo Cruz
 */

 //Bibliotecas
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #include"io.h"

 /** 
   Method_01a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

void method_01a (int x)
{
    if(x > 0)
    {
        IO_printf("%s%d\n","Valor = ", x);
        method_01a(x-1);
    }
}

void method_01()
{
    int quantidade =0; //inutil nesse method
    int valor=0; // inutil nesse method
    int contador=0; //inutil nesse method

    IO_id("Method_01 -  Exemplos0601");
    method_01a(5);
    IO_pause("Apertar ENTER para continuar.");
}

// saida : 5,4,3,2,1 (ordem decrescente)

/** 
   Method_02a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

void method_02a (int x)
{
    if (x>0)
    {
        method_02a(x-1);
        IO_printf("%s%d\n","Valor = ",x);
    }
}

void method_02 ()
{   
    IO_id("Method_02 - exemplo0602");
    method_02a(5);
    IO_pause("Apertar ENTER para continuar.");
}

//saida: 1,2,3,4,5 (ordem crescente)

/** 
   Method_03a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */ 


void method_03a (int x)
{
 if(x>1)
 {
    method_03a(x-1);
    IO_printf("%s%d\n", "Valor= ",x);
 }   
 else
 {
    IO_printf("%s\n","Valor = 1"); //mostrar o ultimo
 }
}

void method_03 ()
{
    IO_id("Method_03 - exemplo0603");
    method_03a(5);
    IO_pause("Apertar ENTER para continuar.");
}

// saida: 1,2,3,4,5

/** 
   Method_04a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */ 

void method_04a(int x)
{
    if(x>1)
 {
    method_04a(x-1);
    IO_printf("%s%d\n", "Valor= ",2*(x-1));
 }   
 else
 {
    IO_printf("%s\n","Valor = 1"); //mostrar o ultimo
 }
}

//saida : 1,2,4,6,8

void method_04 ()
{
    IO_id("Method_04 - exemplo0604");
    method_04a(5);
    IO_pause("Apertar ENTER para continuar.");   
}

/** Acrescentar outro método para mostrar valores de parcelas do somatório: 
1 + 2/3 + 4/5 + 6/7 + 8/9 ... 

Method_05a - Mostrar certa quantidade de valores recursivamente. 
   @param x - quantidade de valores a serem mostrados 
 */

 

 void method_05a (int x)
 {
    if (x>1)
    {
        method_05a( x-1);
        IO_printf( "%d : %d/%d\n", x, (2*(x-1)), (2*(x-1)+1));
    }
    else
    {
        IO_printf("%d: %d\n",x,1);
    }
 }
void method_05 ()
{
    IO_id("Method_05 - exemplo0605");
    method_05a(5);
    IO_pause("Apertar ENTER para continuar.");     
}

/** Acrescentar uma função para calcular o somatório: 1 + 2/3 + 4/5 + 6/7 +
 * somarFracoes - Somar certa quantidade de fracoes recursivamente. 
   @return soma de valores 
   @param x - quantidade de valores a serem mostrados
 */

double somarFracoes (int x)
{
	double soma=0.0;
	if(x>1)
	{
		soma = (2.0*(x-1))/(2.0*(x-1)+1) + somarFracoes (x-1);
		IO_printf ( "%d: %.4lf/%.4lf\n", x, (2.0*(x-1)), (2.0*(x-1)+1) );
	}
	else
	{
		soma=1.0;
		IO_printf("%d: %lf\n",x,1.0);
	}
	return(soma);
}

void method_06 ()
{
	double soma= 0.0;
	IO_id("Method_06 - exemplo0606");
	soma = somarFracoes(5);
	IO_printf("soma = %lf\n", soma);
	IO_pause("Apertar ENTER para terminar");
}

/** saida : 1: 1.000000
2: 2.0000/3.0000
3: 4.0000/5.0000
4: 6.0000/7.0000
5: 8.0000/9.0000
soma = 4.212698 */

/**
Acrescentar uma função para calcular o somatório: 1 + 2/3 + 4/5 + 6/7 + 8/9
somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados (controle)
 @param soma - valor atual da soma (historia = memoria)
 @param numerador - numerador da parcela a ser somada
 @param denominador - denominador da parcela a ser somada
*/
double somarFracoes2b (int x, double soma, double numerador, double denominador)
{
	if(x>0)
	{
		IO_printf("%d: %lf/%lf\n",x, numerador, denominador);
		soma= somarFracoes2b (x-1, soma + ((1.0*numerador)/ denominador),
			numerador +2.0, 
			denominador+2.0);
	}
	return(soma);
}

/**
 somarFracoes2a - Somar certa quantidade de fracoes.
 Funcao de servico para preparar e 
 disparar o mecanismo recursivo.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracoes2a(int x)
{
	double soma=0.0;

	if(x>0)
	{
		IO_printf("%d: %lf\n",x,1.0);
		soma= somarFracoes2b(x-1, 1.0, 2.0,3.0);
	}
	return(soma);
}
void method_07 ()
{
    double soma= 0.0;
	IO_id("Method_07 - exemplo0607");
	soma = somarFracoes2a(5);
	IO_printf("soma = %lf\n", soma);
	IO_pause("Apertar ENTER para continuar");
}

/** 
saida: 
5: 1.000000
4: 2.000000/3.000000
3: 4.000000/5.000000
2: 6.000000/7.000000
1: 8.000000/9.000000
soma = 4.212698
*/

/**
contarDigitos - Contar digitos recursivamente. 
   @return quantidade de digitos 
   @param x - numero cuja quantidade de digitos sera' calculada
*/

int contarDigitos (int x)
{
    int resposta =1;
    if( x>= 10)
    {
        resposta = 1 + contarDigitos(x/10); 
    }
    else
    {
        if(x<0)
        {
            resposta = contarDigitos (-x);
        }
    }
    return(resposta);
}


void method_08 ()
{
    IO_printf("Method_08 - exemplo0608");

    IO_printf("\nDigitos (%3d) = %d\n", 123, contarDigitos (123));
    IO_printf("Digitos (%3d) = %d\n", 1, contarDigitos (1));
    IO_printf("Digitos (%3d) = %d\n", -10, contarDigitos (-10));

    IO_pause("Apertar ENTER para continuar.");


}
/**
 * Digitos (123) = 3
   Digitos (  1) = 1
   Digitos (-10) = 2
 */

/** 
   fibonacci - Gerador de numero de Fibonacci. 
   @return numero de Fibonacci 
   @param x - numero de ordem cujo valor sera' calculado 
 */ 
int fibonacci (int x)
{
    int resposta=0;
    if ( x==1 || x ==2)
    {
        resposta =1;
    }
    else
    {
        if (x>1)
        {
            resposta = fibonacci (x-1) + fibonacci (x-2);
        }
    }
    return (resposta);
}
void method_09 ()
{

    IO_printf("Method_09 - exemplo0609");

    IO_printf ( "fibonacci (%d) = %d\n", 1, fibonacci ( 1 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 2, fibonacci ( 2 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 3, fibonacci ( 3 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 4, fibonacci ( 4 ) ); 
    IO_printf ( "fibonacci (%d) = %d\n", 5, fibonacci ( 5 ) );
    IO_pause("Apertar ENTER para continuar.");

}
/** 
   contarMinusculas - Contador de letras minusculas. 
   @return quantidade de letras minusculas 
   @param x - cadeia de caracteres a ser avaliada 
 */

 int contarMinusculas (chars cadeia, int x)
 {
    int resposta=0;
    if ( 0 <= x && x < strlen(cadeia))
    {
        if (cadeia [x] >= 'a'
        && cadeia[x] <= 'z')
        {
            resposta = 1;
        }
        resposta = resposta + contarMinusculas (cadeia, x+1);
    }
    return (resposta);
 }

void method_10 ()
{
    IO_printf("Method_10 - exemplo0610");
    IO_printf ( "Minusculas (\"abc\",0)  = %d\n", contarMinusculas ( "abc", 0 ) ); 
    IO_printf ( "Minusculas (\"aBc\",0)  = %d\n", contarMinusculas ( "aBc", 0 ) ); 
    IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarMinusculas ( "AbC", 0 ) ); 
    IO_pause ( "Apertar ENTER para continuar" );
}

int main ()
{
    int op = 0;

    do
    {
        IO_id("EXEMPLO ED05 - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - Exemplo01");
        IO_println("2 - Exemplo02");
        IO_println("3 - Exemplo03");
        IO_println("4 - Exemplo04");
        IO_println("5 - Exemplo05");
        IO_println("6 - Exemplo06");
        IO_println("7 - Exemplo07");
        IO_println("8 - Exemplo08");
        IO_println("9 - Exemplo09");
        IO_println("10 - Exemplo10");

        op = IO_readint("Escolha um exemplo: ");

        //testar valor 
        switch(op)
        {
            case 0 :  break;
            case 1 : method_01(); break;
            case 2 : method_02();break;
            case 3 : method_03(); break;
            case 4 : method_04();break;
            case 5 : method_05(); break;
            case 6 : method_06();break;
            case 7 : method_07(); break;
            case 8 : method_08();break;
            case 9 : method_09(); break;
            case 10 : method_10(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
}
