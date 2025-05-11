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

void exemplo_0901 ()
{
    int matrix [][3]= {
                       {1,2,3},
                       {4,5,6},
                       {7,8,9}
                    };
    IO_id("Exemplo0901 - Mostrar de matrix");
    printIntMatrix(3,3,matrix);
    IO_pause("Apertar ENTER para continuar.");
}

/** Saida:
 * 
  1       2       3
  4       5       6
  7       8       9

 */


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
            strcpy(text, STR_EMPTY); // strcpy(destino, origem) , ou seja, copia para algo
            z = IO_readint( IO_concat(
                    IO_concat(IO_concat(text, IO_toString_d(x)), ", "),
                    IO_concat( IO_toString_d(y), " : ")));
                    matrix[x][y] = z;

        }
    }
}
void exemplo_0902 ()
{
    IO_id("Exemplo0902 - Ler matrix");
    int n=2;
    int matrix[n][n];

    readIntMatrix(n,n,matrix);
    IO_printf("\n");
    IO_pause("Apertar ENTER para continuar.");

}

/** saida: 
 *  0, 0 : 1
    0, 1 : 2
    1, 0 : 3
    1, 1 : 4
 */

/** 
   fprintIntMatrix        - Gravar arranjo bidimensional com valores inteiros. 
   @param fileName  - nome do arquivo 
   @param rows         - quantidade de linhas 
   @param columns  - quantidade de colunas 
   @param matrix      - grupo de valores inteiros 
 */

 void fprintfIntMatrix (chars fileName, int rows, int columns, int matrix[][columns])
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
            IO_fprintf(arquivo, "%d\n",matrix[x][y]);
        }
        IO_printf("\n");
    }
    fclose(arquivo);
 }

void exemplo_0903 ()
{
    int rows=0;
    int columns =0;
    IO_id("Exemplo0903 - Arquivo");

    rows = IO_readint ("\nrows = " );
    columns = IO_readint ("\ncolumns = " );
    IO_printf("\n");

    if(rows <= 0 || columns <=0)
    {
        IO_println("\nERRO: Valor invalido.");
    }
    else
    {
        //reservar espaco
        int matrix [rows][columns];
        //ler dados
        readIntMatrix(rows, columns, matrix);
        IO_printf("\n");
        printIntMatrix(rows, columns, matrix);
        IO_printf("\n");
        fprintfIntMatrix("MATRIX1.TXT", rows, columns, matrix);
    }

    IO_pause("Apertar ENTER para continuar.");
}

/** 
   freadMatrixRows  - Ler tamanho (linhas) da matriz com valores inteiros. 
   @return quantidade de linhas da matriz 
   @param fileName - nome do arquivo 
 */
 
int freadMatrixRows ( chars fileName)
{
    int n =0;
    FILE* arquivo = fopen (fileName,"rt");
    ints array = NULL;

    IO_fscanf(arquivo, "%d", &n);
    if( n <= 0)
    {
        IO_println("ERRO: Valor invalido");
        n=0;
    }

    return(n);
}

/** 
   freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros. 
   @return quantidade de colunas da matriz 
   @param fileName     - nome do arquivo 
 */

int freadMatrixColumns (chars fileName)
{
    int n =0;
    FILE* arquivo =  fopen (fileName,"rt");

    IO_fscanf(arquivo,"%d", &n);
    IO_fscanf(arquivo, "%d",&n);

    if(n <= 0)
    {
        IO_println("ERRO: Valor invalido");
        n=0;
    }

    return (n);
}

/** 
   freadIntMatrix        - Ler arranjo bidimensional com valores inteiros. 
   @param fileName  - nome do arquivo 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */

 void freadIntMatrix (chars fileName, int rows, int columns, int matrix[][columns])
 {
    int x=0;
    int y=0;
    int z=0;
    FILE* arquivo = fopen(fileName, "rt");

    IO_fscanf(arquivo,"%d", &x);
    IO_fscanf(arquivo,"%d",&y);

    if(rows <=0 || rows > x || columns <=0 || columns > y)
    {
        IO_println ("ERRO: Valor invalido");
    } 
    else
    {
        x=0;
        while (! feof(arquivo) && x < rows)
        {
            y=0;
            while(!feof(arquivo) && y < columns )
            {
                IO_fscanf(arquivo, "%d", &z);
                matrix [x][y] = z;
                y=y+1;
            }
            x=x+1;
        }
    }
    fclose(arquivo);
 }
void exemplo_0904 ()
{
    int rows =0;
    int columns =0;

    IO_id("Exemplo0904 ");
    rows = freadMatrixRows("MATRIX1.TXT");
    columns = freadMatrixColumns("MATRIX1.TXT");

    if( rows <=0 || columns <= 0)
    {
        IO_println("\nERRO: Valor invalido.");
    }
    else
    {
        int matrix [rows][columns];

        freadIntMatrix ("MATRIX1.TXT", rows, columns, matrix);

        IO_printf("\n");
        printIntMatrix(rows,columns,matrix);
    }
    
    IO_pause("Apertar ENTER para continuar.");

}

/** 
   copyIntMatrix        - Copiar matriz com valores inteiros. 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */

 void copyIntMatrix (int rows, int columns, int matrix2[][columns], int matrix1[][columns])
 {
    int x=0;
    int y=0;
    if(rows <=0 || columns <=0)
    {
        IO_println("\nERRO: Valor invalido.");
    }
    else
    {
        for(x =0; x < rows; x=x+1)
        {
            for(y=0; y< columns; y=y+1)
            {
                //copiar valor de matrix2
                matrix2[x][y] = matrix1[x][y];
            }
        }
    }
 }

void exemplo_0905 ()
{
    int rows=0;
    int columns =0;

    IO_id("Exemplo0905 - ");

    rows = freadMatrixRows("MATRIX1.TXT");
    columns= freadMatrixColumns("MATRIX1.TXT");

    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_println ( "\nERRO: Valor invalido." ); 
    }
    else
    {
        int matrix[rows][columns];
        int other [rows][columns];

        freadIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        copyIntMatrix(rows, columns, other,matrix);
        
        IO_printf("\nOriginal\n");
        printIntMatrix(rows,columns, matrix);

        IO_printf("\nCopia\n");
        printIntMatrix(rows,columns, other);
    }
    IO_pause("Apertar ENTER para continuar.");
}

/** 
   transposeIntMatrix  - Transpor valores inteiros em matriz. 
   @param rows           - quantidade de valores 
   @param columns     - quantidade de valores 
   @param matrix2       - grupo de valores inteiros (transposto) 
   @param matrix1       - grupo de valores inteiros 
 */

 void transposeIntMatrix (int rows, int columns, int matrix2[][rows], int matrix1[][columns])
 {
    int x=0;
    int y=0;

    for ( x = 0; x<rows; x=x+1 ) 
    { 
        for ( y = 0; y<columns; y=y+1 ) 
        { 
            matrix2[ y ][ x ] = matrix1 [ x ][ y ];
        }
    }
 }

void exemplo_0906 ()
{
    int matrix1 [ ][2] = { {1, 0}, 
                           {0, 1}
                        }; 
    int matrix2 [ ][2] = { {0, 0}, 
                           {0, 0} 
                        }; 
    int matrix3 [ ][3] = { {1, 2, 3}, 
                           {4, 5, 6} 
                        }; 
    int matrix4 [ ][3] = { {1, 2, 3}, 
                           {4, 5, 6}, 
                           {7, 8, 9} 
                        }; 

    IO_id("Exemplo0906");
    IO_println("\nMatrix1");
    printIntMatrix(2,2,matrix1);
    transposeIntMatrix(2,2,matrix2,matrix1);

    IO_println("\nMatrix2");
    printIntMatrix(2,2,matrix2);

    IO_println("\nMatrix3");
    printIntMatrix(2,3,matrix2);

    transposeIntMatrix(2,3,matrix4,matrix3);

    IO_println("\nMatrix4");
    printIntMatrix(3,2,matrix4);
}

/** 
   isIdentity               - Testar se matriz identidade. 
   @return                  - true, se todos os dados forem iguais a zero; 
                                     false, caso contrario 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */

 bool isIdentity (int rows, int columns, int matrix[][columns])
 {
    bool result= false;
    int x=0;
    int y=0;

    if ( rows <= 0 || columns <= 0 || 
        rows != columns ) 
   { 
      IO_printf ( "\nERRO: Valor invalido.\n" ); 
   } 
   else
   {
    x=0;
    result=true;
    while(x < rows && result)
    {
        y=0;
        while(y < columns && result)
        {
            if(x==y)
            {
                result = result && (matrix[x][y] == 1);
            }
            else
            {
                result = result && (matrix[x][y]== 0);
            }
            y=y+1;
        }
        x=x+1;
    }
   }
   return (result);
 }

void exemplo_0907 ()
{
    int matrix1 [ ][2] = { {0, 0} , {0, 0} };  
int matrix2 [ ][3] = { {1, 2, 3} , {4, 5, 6} };  
int matrix3 [ ][2] = { {1, 0} , {0, 1} };  

IO_id ( "Exemplo0907" );  

IO_println( "\nMatrix1"  );  
printIntMatrix( 2, 2, matrix1 );  
IO_printf( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );  

IO_println( "\nMatrix2"  );  
printIntMatrix( 2, 3, matrix2 );  
IO_printf( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) );  

IO_println( "\nMatrix3"  );  
printIntMatrix( 2, 2, matrix3 );  
IO_printf( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );  

IO_pause( "Apertar ENTER para continuar" );  

}


bool isEqual ( int rows, int columns, int matrix1[ ][columns], int matrix2[ ][columns] )  
{  
    bool result = true;  
    int x = 0;  
    int y = 0;  

    x = 0;  
    while ( x < rows && result )  
    {  
        y = 0;  
        while ( y < columns && result )  
        {  
            result = result && ( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );  
            y = y + 1;  
        }  
        x = x + 1;  
    }  

    return ( result );  
}  


void exemplo_0908 ()
{
    int matrix1 [ ][2] = { {0, 0} , {0, 0} };  
    int matrix2 [ ][2] = { {1, 2} , {3, 4} };  
    int matrix3 [ ][2] = { {1, 0} , {0, 1} };  

    IO_id ( "Exemplo0909 - v0.0" );  

    IO_println ( "\nMatrix1" );  
    printIntMatrix( 2, 2, matrix1 );  

    IO_println ( "\nMatrix2" );  
    printIntMatrix( 2, 2, matrix2 );  

    IO_printf ( "isEqual (matrix1, matrix2) = %d", isEqual (2, 2, matrix1, matrix2) );  

    copyIntMatrix ( 2, 2, matrix1, matrix3 );  
    copyIntMatrix ( 2, 2, matrix2, matrix3 );  

    IO_println ( "\nMatrix1" );  
    printIntMatrix( 2, 2, matrix1 );  

    IO_println ( "\nMatrix2" );  
    printIntMatrix( 2, 2, matrix2 );  

    IO_printf ( "isEqual (matrix1, matrix2) = %d", isEqual (2, 2, matrix1, matrix2) );  

    IO_pause ( "Apertar ENTER para continuar" );  
}

/** 
   addIntMatrix         - Somar matrizes com inteiros. 
   @param rows       - quantidade de valores 
   @param columns - quantidade de valores 
   @param matrix3   - grupo de valores inteiros resultante 
   @param matrix1   - grupo de valores inteiros (1) 
   @param k              - constante para multiplicar o segundo termo 
   @param matrix2   - grupo de valores inteiros (2) 
 */ 

 void addIntMatrix ( int rows, int columns, int matrix3[ ][columns], int matrix1[ ][columns], int k, int matrix2[ ][columns] )  
{  
    int x = 0;  
    int y = 0;  

    for ( x = 0; x < rows; x = x + 1 )  
    {  
        for ( y = 0; y < columns; y = y + 1 )  
        {  
            matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];  
        }  
    }  
}  


 void exemplo_0909 ()
{
    int matrix1 [ ][2] = { {1, 2}, {3, 4} };  
    int matrix2 [ ][2] = { {1, 0}, {0, 1} };  
    int matrix3 [ ][2] = { {0, 0}, {0, 0} };  

    IO_id ( "Method_09 - v0.0" );  

    IO_println ( "\nMatrix1" );  
    printIntMatrix( 2, 2, matrix1 );  

    IO_println ( "\nMatrix2" );  
    printIntMatrix( 2, 2, matrix2 );  

    addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );  

    IO_println ( "\nMatrix3" );  
    printIntMatrix( 2, 2, matrix3 );  

    IO_pause ( "Apertar ENTER para continuar" );  
}

/** 
   mulIntMatrix           - Multiplicar matrizes com inteiros. 
   @param rows3       - quantidade de linhas     da matriz (3) 
   @param columns3 - quantidade de colunas da matriz (3) 
   @param matrix3     - grupo de valores inteiros resultante 
   @param rows1       - quantidade de linhas     da matriz (1) 
   @param columns1 - quantidade de colunas da matriz (1) 
   @param matrix1     - grupo de valores inteiros (1) 
   @param rows2       - quantidade de linhas     da matriz (2) 
   @param columns2 - quantidade de colunas da matriz (2) 
   @param matrix2     - grupo de valores inteiros (2) 
 */

 void mulIntMatrix ( int rows3, int columns3, int matrix3[ ][columns3],  
    int rows1, int columns1, int matrix1[ ][columns1],  
    int rows2, int columns2, int matrix2[ ][columns2] )  
{  
    int x = 0;  
    int y = 0;  
    int z = 0;  
    int soma = 0;  

    if ( rows1 <= 0 || columns1 <= 0 ||  
        rows2 <= 0 || columns2 <= 0 ||  
        rows3 <= 0 || columns3 <= 0 ||  
        columns1 != rows2 ||  
        rows1 != rows3 ||  
        columns2 != columns3 )  
    {  
            IO_printf ( "\nERRO: Valor invalido.\n" );  
    }  
        else  
        {  
            for ( x = 0; x < rows3; x = x + 1 )  
            {  
                for ( y = 0; y < columns3; y = y + 1 )  
                {  
                    soma = 0;  
                    for ( z = 0; z < columns1; z = z + 1 )  
                    {  
                        soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];  
                    }  
                    matrix3 [ x ][ y ] = soma;  
                }  
            }  
        }     
}  

 
void exemplo_0910 ()
{
    IO_id ( "Method_10 - v0.0" );  

int matrix1 [ ][2] = { {1, 2}, {3, 4} };  
int matrix2 [ ][2] = { {1, 0}, {0, 1} };  
int matrix3 [ ][2] = { {0, 0}, {0, 0} };  

IO_id ( "EXEMPLO0910 - Method_09 - v0.0" );  

IO_println ( "\nMatrix1" );  
printIntMatrix( 2, 2, matrix1 );  
IO_println ( "\nMatrix2" );  
printIntMatrix( 2, 2, matrix2 );  

mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );  
IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );  
printIntMatrix( 2, 2, matrix3 );  

IO_println ( "\nMatrix2" );  
printIntMatrix( 2, 2, matrix2 );  
IO_println ( "\nMatrix1" );  
printIntMatrix( 2, 2, matrix1 );  

mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );  
IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );  
printIntMatrix( 2, 2, matrix3 );  

IO_pause ( "Apertar ENTER para continuar" );  
}


int main()

{
    
    int op = 0;

    
    printf("0 - Terminar\n");
    printf("1 - Exemplo_0901\n");
    printf("2 - Exemplo_0902\n");
    printf("3 - Exemplo_0903\n");
    printf("4 - Exemplo_0904\n");
    printf("5 - Exemplo_0905\n");
    printf("6 - Exemplo_0906\n");
    printf("7 - Exemplo_0907\n");
    printf("8 - Exemplo_0908\n");
    printf("9 - Exemplo_0909\n");
    printf("10 - Exemplo_0910\n");

    printf("%s\n", "Qual a opcao?");
    scanf("%d", &op);

    
    switch (op)
    {
    case 1: exemplo_0901();
        break;
    case 2: exemplo_0902();
        break;
    case 3: exemplo_0903();
        break;
    case 4: exemplo_0904();
        break;
    case 5: exemplo_0905();
        break;
    case 6: exemplo_0906();
        break;
    case 7: exemplo_0907();
        break;
    case 8: exemplo_0908();
        break;
    case 9: exemplo_0909();
        break;
    case 10: exemplo_0910();
        break;
    default:
        break;
    }
    return 0;
}

