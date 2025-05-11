/**Aluna: Izadora Galarza Alves
 * ed09 - Matrix
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"io.h"

/** 
   printIntMatrix        - Mostrar arranjo bidimensional com valores inteiros. 
   @param rows       - quantidade de linhas 
   @param columns - quantidade de colunas 
   @param matrix     - grupo de valores inteiros 
 */

 void printIntMatrix (int rows, int collumns, int matrix[][collumns])
 {
     //definir dados iniciais 
     int x=0;
     int y=0;
 
     //mostrar valores 
     for(x =0; x < rows ; x=x+1)
     {
         for(y=0; y < collumns; y=y+1)
         {
             //mostrar valor 
             IO_printf("%3d\t",matrix[x][y]);
         }
         IO_printf("\n");
     }
 }

 /** 
   readIntMatrix        - Ler arranjo bidimensional com valores inteiros. 
   @param rows       - quantidade de linhas 
   @param columns - quantidade de colunas 
   @param matrix     - grupo de valores inteiros 
 */


void readIntMatrix( int rows, int collumns, int matrix[][collumns])
{
    // Definir dados iniciais
    int x=0;
    int y =0;
    int z=0;
    chars text = IO_new_chars (STR_SIZE);

    //ler e guardar valores em arranjo
    for( x=0; x < rows; x=x+1)
    {
        for(y=0; y < collumns; y=y+1)
        {
            printf("Digite um valor para [%d, %d]: ", x, y);
            scanf("%lf", &matrix[x][y]);

        }
    }
}



/**Incluir um método (0911) para 
ler as dimensões (quantidade de linhas e de colunas) de uma matriz real do teclado,  
bem como todos os seus elementos (apenas valores positivos ou zeros). 
Verificar se as dimensões não são nulas ou negativas. 
Para testar, ler dados e mostrá-los na tela por outro método. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix ( 3, 3, positiveMatrix ); 
                  printDoubleMatrix              ( 3, 3, positiveMatrix ); */

void readPositiveDoubleMatrix (int rows, int columns, double matrix[][columns] )
{
    int x=0; //rows
    int y=0; //

    if(rows <= 0 || columns <= 0)
    {
        IO_printf("ERRO: Valor invalido");
    }
    for(x=0; x<rows; x=x+1)
    {
        for(y=0; y< columns; y=y+1)
        {
            printf("Digite um valor para [%d, %d]: ", x, y);
            scanf("%lf", &matrix[x][y]);
        }
    }
}

void printIntMatrix1 (int rows, int collumns, double matrix[][collumns])
 {
     //definir dados iniciais 
     int x=0;
     int y=0;
 
     //mostrar valores 
     for(x =0; x < rows ; x=x+1)
     {
         for(y=0; y < collumns; y=y+1)
         {
             //mostrar valor 
             IO_printf("%lf\t",matrix[x][y]);
         }
         IO_printf("\n");
     }
 }

void exercicio_0911 ()
{
    int rows =0;
    int columns =0;
    
    rows = IO_readint("Entre com uma quantidade de linhas: ");
    columns= IO_readint("Entre com uma quantidade de colunas: ");

    double positiveMatrix[rows][columns];  
    readPositiveDoubleMatrix(rows, columns, positiveMatrix);
    printIntMatrix1(rows,columns,positiveMatrix);
}

/** Incluir um método (0912) para  
gravar uma matriz real em arquivo. 
A matriz e o nome do arquivo serão dados como parâmetros. 
Para testar, usar a leitura da matriz do problema anterior. 
Usar outro método para ler e recuperar a matriz do arquivo, antes de mostrá-la na tela. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveMatrix DoubleMatrix          ( 3, 3, positiveMatrix ); 
                  fprintDoubleMatrix ( "MATRIX_01.TXT", 3, 3, positiveMatrix ); */


void fprintfIntMatrix (chars fileName, int rows, int columns, double matrix[][columns])
 {
    FILE*arquivo = fopen(fileName, "wt");
    int x=0;
    int y=0;

    IO_fprintf(arquivo,"%d\n", rows);
    IO_fprintf(arquivo,"%d\n", columns);

    for(x =0; x < rows ; x=x+1)
    {
        for(y=0; y < columns; y=y+1)
        {
            //mostrar valor 
            IO_fprintf(arquivo, "%.2lf\n",matrix[x][y]);
        }
        IO_printf("\n");
    }
    fclose(arquivo);
 }
void exercicio_0912 ()
{
    int rows =0;
    int columns =0;
    
    rows = IO_readint("Entre com uma quantidade de linhas: ");
    columns= IO_readint("Entre com uma quantidade de colunas: ");

    double Matrix[rows][columns];  
    readPositiveDoubleMatrix(rows, columns,Matrix);
    fprintfIntMatrix("MATRIX0912.TXT",rows,columns,Matrix);   
}

/** Incluir um método (0913) para  
mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveMatrix DoubleMatrix  ( 3, 3, positiveMatrix ); 
                  printDiagonalDoubleMatrix            ( 3, 3, positiveMatrix ); */

void exercicio_0913 ()
{
    
}

/** Incluir um método (0914) para 
mostrar somente os valores na diagonal secundária de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix     ( 3, 3, positiveMatrix ); 
                  printSDiagonalDoubleMatrix ( 3, 3, positiveMatrix ); */

void exercicio_0914 ()
{
    
}

/** cluir um método (0915) para  
mostrar somente os valores abaixo da diagonal principal de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix      ( 3, 3, positiveMatrix ); 
                  printLDTriangleDoubleMatrix ( 3, 3, positiveMatrix ); 
 
*/
void exercicio_0915 ()
{
    
}


/** Incluir um método (0916) para 
mostrar somente os valores acima da diagonal principal de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix      ( 3, 3, positiveMatrix ); 
                  printLUTriangleDoubleMatrix ( 3, 3, positiveMatrix ); */
void exercicio_0916 ()
{
    
}


/** cluir um método (0917) para 
mostrar somente os valores abaixo e na diagonal secundária de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix        ( 3, 3, positiveMatrix ); 
                  printSLDTriangleDoubleMatrix ( 3, 3, positiveMatrix ); */
void exercicio_0917 ()
{
    
}

/**  Incluir um método (0918) para 
mostrar somente os valores acima e na diagonal secundária de uma matriz real, se for quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix        ( 3, 3, positiveMatrix ); 
                  printSLUTriangleDoubleMatrix ( 3, 3, positiveMatrix ); */

void exercicio_0918 ()
{
    
}

/** Incluir uma função (0919) para 
testar se são todos zeros os valores abaixo da diagonal principal de uma matriz real quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix                              ( 3, 3, positiveMatrix ); 
                  bool result = allZerosLTriangleDoubleMatrix ( 3, 3, positiveMatrix ); */
void exercicio_0919 ()
{
    
}

/** ncluir uma função (0920) para 
testar se não são zeros os valores acima da diagonal principal de uma matriz real quadrada. 
 
Exemplo:   double positiveMatrix [10][10]; 
                  readPositiveDoubleMatrix                              ( 3, 3, positiveMatrix ); 
                  bool result = allZerosUTriangleDoubleMatrix ( 3, 3, positiveMatrix );   */
void exercicio_0920 ()
{
    
}

int main()

{
    
    int op = 0;

    
    printf("0 - Terminar\n");
    printf("1 - exercicio_0911\n");
    printf("2 - exercicio_0912\n");
    printf("3 - exercicio_0913\n");
    printf("4 - exercicio_0914\n");
    printf("5 - exercicio_0915\n");
    printf("6 - exercicio_0916\n");
    printf("7 - exercicio_0917\n");
    printf("8 - exercicio_0918\n");
    printf("9 - exercicio_0919\n");
    printf("10 - exercicio_0920\n");

    printf("%s\n", "Qual a opcao?");
    scanf("%d", &op);

    
    switch (op)
    {
    case 1: exercicio_0911();
        break;
    case 2: exercicio_0912();
        break;
    case 3: exercicio_0913();
        break;
    case 4: exercicio_0914();
        break;
    case 5: exercicio_0915();
        break;
    case 6: exercicio_0916();
        break;
    case 7: exercicio_0917();
        break;
    case 8: exercicio_0918();
        break;
    case 9: exercicio_0919();
        break;
    case 10: exercicio_0920();
        break;
    default:
        break;
    }
    return 0;
}

