/** Aluna: Izadora Galarza Alves
Professor : Theldo Cruz
ED08  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"io.h"


/** 
   printIntArray    - Mostrar arranjo com valores inteiros. 
   @param n        - quantidade de valores 
   @param array  - grupo de valores inteiros 
 */

 void printIntArray(int n, int array [])
 {
    int x =0; 

    for(x=0; x<n;x=x+1)
    {
        IO_printf("%2d : %d\n", x ,array[x]);
    }
 }

 /** Exemplo0801 - Mostrar quantidade de valores*/

 void exemplo_0801 ()
 {
    int array [] = {1,2,3,4,5};

    IO_id("Exemplo0801 - v0.0");
    printIntArray (5,array);
    IO_pause("Apertar ENTER para continuar.");
 }

 /**
  *
 0 : 1
 1 : 2
 2 : 3
 3 : 4
 4 : 5
  */
 /** 
   readIntArray    - Ler arranjo com valores inteiros. 
   @param n        - quantidade de valores 
   @param array  - grupo de valores inteiros 
 */ 

 void readIntArray (int n, int array [])
 {
    int x=0;
    int y=0;
    chars text = IO_new_chars(STR_SIZE);

    for (x=0; x< n; x=x+1)
    {
        strcpy (text, STR_EMPTY);
        y= IO_readint(IO_concat (IO_concat (text,IO_toString_d (x)), ":"));
        array[x]=y;
    }
 }

 /** exemplo_0802  */
 void exemplo_0802 ()
 {
    int n =5;
    int array [n];
    IO_id("Exemplo0802 - v0.0");
    readIntArray(n, array);
    IO_printf("\n");
    printIntArray(n,array);
    IO_pause("Apertar ENTER para continuar.");

 }
 /**
  * 0 : 1
    1 : 2
    2 : 3
    3 : 4
    4 : 5
  */
/** 
   fprintIntArray        - Gravar arranjo com valores inteiros. 
   @param fileName - nome do arquivo 
   @param n              - quantidade de valores 
   @param array        - grupo de valores inteiros 
 */ 

 void fprintfIntArray ( chars fileName, int n, int array[])
 {
    FILE* arquivo = fopen (fileName, "wt");
    int x =0;

    IO_fprintf(arquivo,"%d\n",n);
    for(x=0; x<n; x=x+1)
    {
        IO_fprintf(arquivo, "%d\n", array [x]); //gravar valores no arranjo
    }
    fclose(arquivo);
 }
 void exemplo_0803 ()
 {
    int n = 5;
    int array [n];
    IO_id("Exemplo0803 - v0.0");
    readIntArray (n, array);
    IO_printf("\n");
    fprintfIntArray("ARRAY1.TXT", n ,array);
    IO_pause("Apertar ENTER para continuar.");

 }

 //saida: 5,1,2,3,4,5


 /** 
   freadArraySize      - Ler tamanho do arranjo com valores inteiros. 
   @return quantidade de valores lidos 
   @param fileName - nome do arquivo 
 */ 

 int freadArraySize (chars fileName)
 {

    int n=0; //variaveç
    FILE* arquivo = fopen (fileName, "rt"); //abrir arquivo de leitura
    IO_fscanf(arquivo,"%d", &n); // entrar com quantidade

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n=0;
    }
    return(n);
 }

 /** 
   freadIntArray         - Ler arranjo com valores inteiros. 
   @param fileName - nome do arquivo 
   @param n              - quantidade de valores 
   @param array        - grupo de valores inteiros 
 */

 void freadIntArray (chars fileName, int n, int array [])
 {
    int x=0;
    int y=0;
    FILE* arquivo = fopen (fileName,"rt");

    //ler quantidade
    IO_fscanf (arquivo,"%d", &x);

    if( n <=0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        int x=0;
        while(!feof (arquivo) && x < n)
        {
            IO_fscanf(arquivo, "%d",&y);
            array[x] = y;
            x=x+1;
        }
    }
 }

 void exemplo_0804 ()
 {
  int n=0;
  IO_id("Exemplo0804 - v0.0");
  n = freadArraySize ("ARRAY1.TXT");
  if( n <=0)
  {
    IO_printf("\nERRO: Valor invalido.\n");
  }
  else
  {
    int array [n];
    freadIntArray("ARRAY1.TXT",n,array);
    IO_printf("\n");
    printIntArray(n,array);
  }

  IO_pause("Apertar ENTER para continuar.");

 }

 /** 
   copyIntArray      - Copiar arranjo com valores inteiros. 
   @param n           - quantidade de valores 
   @param copy     - copia do grupo de valores inteiros 
   @param array     - grupo de valores inteiros 
 */ 

 void copyIntArray (int n, int copy[], int array[])
 {
    int x=0;
    int y=0;

    if( n <=0)
    {
        IO_println("ERRO: Valor invalida.");
    }
    else
    {
        for(x=0; x < n; x=x+1)
        {
            copy[x] = array[x];
        }
    }
 }

 void exemplo_0805 ()
 {
    
    int n=0;
    IO_id("Exemplo0805 - v0.0");
    n = freadArraySize ("ARRAY1.TXT");

    if(n <= 0)
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [n];
        int other [n];

        freadIntArray("ARRAY1.TXT", n, array);

        copyIntArray(n,other,array);

        IO_printf ("\nOriginal\n");
        printIntArray(n,array);

        IO_printf("\nCopia\n");
        printIntArray(n,other);
    }
    IO_pause("Apertar ENTER para continuar.");
 }

 /** 
   sumIntArray    - Somar valores em arranjo com inteiros. 
   @return            - soma dos valores 
   @param n        - quantidade de valores 
   @param array  - grupo de valores inteiros 
 */

 int sumIntArray(int n, int array[])
 {
    int soma =0;
    int x=0;

    for (x =0; x <n; x=x+1)
    {
        soma = soma + array[x];
    }
    return (soma);
 }

 void exemplo_0806 ()
 {
    int n=0;
    IO_id("Exemplo0806 - v0.0");
    n = freadArraySize ("ARRAY1.TXT");

    if(n <= 0)
    {
        IO_printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        int array [n];
        freadIntArray("ARRAY1.TXT",n,array);
        IO_printf("\nSoma = %d\n", sumIntArray(n,array));
    }
    IO_pause("Apertar ENTER para continuar.");
 }

 /** 
   isAllZeros        - Testar valores inteiros em arranjo. 
   @return            - true, se todos os dados forem iguais a zero; 
                               false, caso contrario 
   @param n         - quantidade de valores 
   @param array  - grupo de valores inteiros 
 */

 bool isAllZeros (int n, int array [])
 {
    bool result = true;
    int x=0;
    x=0;
    while ( x<n && result)
    {
        result = result && (array [x] == 0);
        x=x+1;
    }
    return(result);
 }
 void exemplo_0807 ()
 {
    int n=5;
    int array1[] = {0,0,0,0,0};
    int array2[] = {1,2,3,4,5};
    int array3[] = {1,2,0,4,5};

    IO_id("Exemplo0806 - v0.0");

    IO_println("\nArray1");
    printIntArray (n, array1);
    IO_printf("isAllZeros(array1) = %d \n", isAllZeros(n, array1));

    IO_println("\nArray2");
    printIntArray (n, array2);
    IO_printf("isAllZeros(array2) = %d\n", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray (n, array3);
    IO_printf("isAllZeros(array3) = %d\n", isAllZeros(n, array3));

    IO_pause("Apertar ENTER para continuar.");
 }


 /** 
   addIntArray      - Somar arranjos com inteiros. 
   @return             - arranjo ocm a soma resultante 
   @param n          - quantidade de valores 
   @param array3 - soma de grupo de valores inteiros 
   @param array1 - grupo de valores inteiros (1) 
   @param k          - constante para multiplicar o segundo arranjo 
   @param array2 - grupo de valores inteiros (2) 
 */ 

 void addIntArray ( int n, int array3[], int array1 [],int k, int array2[])
 {
  int x=0;
  for (x =0; x <n; x=x+1)
  {
    array3[x] = array1[x] + k * array2 [x];
  }  
 }
 void exemplo_0808 ()
 {
  int n=0;
  IO_id("Exemplo0808 - v0.0");
  n = freadArraySize("ARRAY1.TXT"); 
  if ( n <= 0 ) 
  { 
     IO_printf ( "\nERRO: Valor invalido.\n" ); 
  } 
  else
  {
    int array [n];
    int other [n];
    int sum [n];

    freadIntArray("ARRAY1.TXT",n,array);
    copyIntArray (n,other,array);

    IO_printf("\nOriginal\n");
    printIntArray(n,array);

    IO_printf("\nCopia\n");
    printIntArray(n,other);

    addIntArray (n,sum,array, (-2),other);

    IO_printf ("\nSoma\n");
    printIntArray(n,sum);
  }

  IO_pause ( "Apertar ENTER para continuar" ); 
 }


 /** 
   isEqual              - Testar arranjos com inteiros sao iguais. 
   @return             - true, se todos os dados forem iguais; 
                                false, caso contrario 
   @param n         - quantidade de valores 
   @param array1 - grupo de valores inteiros (1) 
   @param array2 - grupo de valores inteiros (2) 
 */ 

 bool isEqual ( int n, int array1 [ ], int array2 [ ] ) 
{ 
    bool result = true; 
    int x = 0; 
 
    x = 0; 
    while ( x<n && result ) 
    { 
        result = result && ( array1 [ x ] == array2 [ x ] ); 
        x = x + 1; 
    }  
 
    return ( result ); 
} 
 void exemplo_0809 ()
 {
    int n = 0;
    IO_id("Exemplo0809 - v0.0");
    n = freadArraySize("ARRAY1.TXT"); 
  if ( n <= 0 ) 
  { 
     IO_printf ( "\nERRO: Valor invalido.\n" ); 
  } 
  else
  {
    int array [ n ]; 
        int other [ n ]; 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        copyIntArray  ( n, other, array ); 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
        IO_printf     ( "\nCopia\n" ); 
        printIntArray ( n, other ); 
 
        IO_printf     ( "\nIguais = %d\n", isEqual ( n, array, other ) ); 
 
        other [ 0 ] = (-1) * other [ 0 ]; 
 
        IO_printf     ( "\nCopia alterada\n" ); 
        printIntArray ( n, other ); 
 
        IO_printf     ( "\nIguais = %d\n", isEqual ( n, array, other ) ); 
    } 
 
    IO_pause ( "Apertar ENTER para continuar" ); 
  }

/** 
  searchArray     - Procurar valor em arranjo com inteiros. 
  @return            - true, se encontrar; 
                              false, caso contrario 
  @param value  - valor a ser procurado 
  @param n        - quantidade de valores 
  @param array  - grupo de valores inteiros 
*/ 
bool searchArray ( int value, int n, int array [ ] ) 
{ 
   bool result = false; 
   int x       = 0; 

   x = 0; 
   while ( x<n && ! result ) 
   { 
       result = ( value == array [ x ] ); 
       x = x + 1; 
   } 

   return ( result ); 
}
 void exemplo_0810 ()
 {
    int  n = 0;    
    int  value = 0;      
 
    IO_id ( "Exemplo0810 - v0.0" ); 
 
    n = freadArraySize ( "ARRAY1.TXT"   ); 
    if ( n <= 0 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
        int array [ n ]; 
        freadIntArray ( "ARRAY1.TXT", n, array ); 
        IO_printf     ( "\nOriginal\n" ); 
        printIntArray ( n, array ); 
 
     // mostrar resultados de procuras 
        value = array [ 0 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
                                value, searchArray ( value, n, array ) ); 
 
        value = array [ n / 2 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
                                value, searchArray ( value, n, array ) ); 
 
        value = array [ n - 1 ]; 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
                                value, searchArray ( value, n, array ) ); 
 
        value = (-1); 
        IO_printf     ( "\nProcurar por (%d) = %d\n",  
                                value, searchArray ( value, n, array ) ); 
    }
 
    IO_pause ( "Apertar ENTER para continuar" ); 
} 



 #include <stdio.h>

int main()

{
    
    int op = 0;

    
    printf("0 - Terminar\n");
    printf("1 - Exemplo_0801\n");
    printf("2 - Exemplo_0802\n");
    printf("3 - Exemplo_0803\n");
    printf("4 - Exemplo_0804\n");
    printf("5 - Exemplo_0805\n");
    printf("6 - Exemplo_0806\n");
    printf("7 - Exemplo_0807\n");
    printf("8 - Exemplo_0808\n");
    printf("9 - Exemplo_0809\n");
    printf("10 - Exemplo_0810\n");

    printf("%s\n", "Qual a opcao?");
    scanf("%d", &op);

    
    switch (op)
    {
    case 1: exemplo_0801();
        break;
    case 2: exemplo_0802();
        break;
    case 3: exemplo_0803();
        break;
    case 4: exemplo_0804();
        break;
    case 5: exemplo_0805();
        break;
    case 6: exemplo_0806();
        break;
    case 7: exemplo_0807();
        break;
    case 8: exemplo_0808();
        break;
    case 9: exemplo_0809();
        break;
    case 10: exemplo_0810();
        break;
    default:
        break;
    }
    return 0;
}

