/** Exemplos1000 - 18/05/2025 
	Autora: Izadora Galarza Alves
*/

//dependecias
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"io.h"

typedef
struct s_int_Array
{
	int length;
	int* data;
	int ix;
}
int_Array;

/**
Definicao de referencia para arranjo com inteiros
baseado em estrutura
*/
typedef int_Array* ref_int_Array;

/**
new_int_Array - Reservar espaco para arranjo com inteiros
@return referencia para arranjo com inteiros
@param n - quantidade de datos
*/

ref_int_Array new_int_Array (int n)
{
	//reserva de espaco
	ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));

	//estabelecer valores padroes
	if(tmpArray == NULL)
	{
		IO_printf("\nERRO: Falta de espaco.");
	}
	else
	{
		tmpArray->length =0;
		tmpArray->data   =NULL;
		tmpArray->ix     =-1;
		if(n>0)
		{
			//guardar a quantidade de dados
			tmpArray->length = n;
			//reservar indicador do primeiro elemento
			tmpArray->data = (int*)malloc (n * sizeof(int));
			//defnir indicador do primeiro elemento
			tmpArray->ix = 0;
		}
	}

	//retornar referencia para espaco reservador
	return(tmpArray);
}

/**
free_int_Array - Dispensar espaco para arranjo com inteiros
@param tmpArray - referencia para grupo de valores inteiros
*/

void free_int_Array (ref_int_Array tmpArray)
{
	//testar se ha' dados, antes de reciclar o espaco
	if(tmpArray != NULL)
	{
		if(tmpArray->data !=NULL)
		{
			free(tmpArray->data);
		}
	free(tmpArray);
	}
}


/**
printIntArray - Mostrar arranjo com valores inteiros.
@param array - grupo de valores inteiros
*/

void printIntArray(int_Array array)
{
	//mostrar alores no arranjo
	if(array.data)
	{
		for(array.ix =0; array.ix<array.length;array.ix= array.ix +1)
		{
			printf("%2d: %d\n", array.ix, array.data[array.ix]);
		}
	}
}
/** 
	EXEMPLO1001 - Mostrar certa quantidade de valore
*/

void exemplo_1001 ()
{
	int_Array array;

	//montar arranjo em estrutura
	array.length=5;
	array.data = (int*) malloc (array.length * sizeof(int));

	//testar a existencia de dados
	if(array.data)
	{
		array.data[0] =1;
		array.data[1] =2;
		array.data[2] =3;
		array.data[3] =4;
		array.data[4] =5;
	}
	IO_id("Exemplo_1001 - v1.0");
	printIntArray(array);

	//reciclar espaco
	if(array.data)
	{
		free(array.data);
	}
	IO_pause("Apertar ENTER para continuar.");
}


/////////////////////////////////////////////////////////////////////////

/**
IO_readintArray - Ler arranjo com valores inteiros.
@return arranjo com valores lidos
*/

int_Array IO_readIntArray()
{
	//definir dados locais
	chars text = IO_new_chars(STR_SIZE);
	static int_Array array;

	//ler quantidade de dados
	do
		{
			array.length = IO_readint ("\nlength = ");
		}while (array.length <= 0);
	//reservar espaco para armazenar
	array.data = IO_new_ints(array.length);

	//testar se ha espaco
	if(array.data == NULL)
	{
		array.length =0; //nao ha espaco
	}
	else
	{
		//ler e guardar valores em arranjo
		for(array.ix =0; array.ix <array.length; array.ix = array.ix +1)
			{
				strcpy(text, STR_EMPTY);
				array.data[array.ix]= IO_readint(IO_concat(IO_concat(text, IO_toString_d(array.ix)),":"));
			}
	}
	return(array);
}

/** exemplo1002 */

void exemplo_1002 ()
{
	int_Array array;
	IO_id("Exemplo1002");

	//ler dados
	array = IO_readIntArray();
	//testar existencia de dados
	if(array.data)
	{
		IO_printf("\n");
		printIntArray(array);
		//reciclar esapco
		free(array.data);
	}
	IO_pause("Apertar ENTER para continuar");
}


/**
fprintIntArray - Gravar arranjo com valores inteiros.
@param fileName - nome do arquivo
@param array - grupo de valores inteiros
*/

void fprintIntArray (chars fileName, int_Array array)
{
	//definir dados locais
	FILE*arquivo = fopen(fileName, "wt");
	//gravar quantidade de dados
	fprintf(arquivo,"%d\n",array.length);
	 //gravar valores no arquivo, se existirem
	if(array.data)
	{
		for(array.ix=0; array.ix < array.length;array.ix= array.ix +1)
			{
				//gravar valor
				fprintf(arquivo,"%d\n",array.data[array.ix]);
			}
	}
	fclose(arquivo);
}

/** 
exemplo_1003
*/

void exemplo_1003 ()
{
	int_Array array;

	IO_id("Exemplo1003");

	array= IO_readIntArray();

	if(array.data)
	{
		IO_printf("\n");
		printIntArray(array);
		fprintIntArray("ARRAY1.TXT",array);
		//reciclar espaco
		free(array.data);
	}
	IO_pause("Apertar ENTER apara continuar.");
}

//////////////////////////////////////////////////////////////////////////////////////////////
/**
 freadArraySize - Ler tamanho do arranjo com valores inteiros.
 @return quantidade de valores lidos
 @param fileName - nome do arquivo
*/

int freadArraySize (chars fileName)
{
	int n=0;
	FILE*arquivo = fopen(fileName,"rt");
	if(arquivo)
	{
		//ler quantidade de dados
		fscanf(arquivo,"%d",&n);
		if (n <=0)
		{
			IO_printf("\nERRO:Valor invalido.\n");
			n=0;
		}
		fclose(arquivo);
	}
	return(n);
}

/**
 fIO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com os valores lidos
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/

int_Array fIO_readintArray(chars fileName)
{
	int x=0; 
	int y =0;
	FILE* arquivo = fopen(fileName,"rt");
	static int_Array array;

	if(arquivo)
	{
		fscanf(arquivo,"%d",&array.length);

		if(array.length <=0)
		{
			IO_printf("\nERRO: Valor invalido.\n");
			array.length =0; 
		}
		else
		{
			array.data = IO_new_ints (array.length);
			if(array.data)
			{
				array.ix=0;
				while( !feof(arquivo) && array.ix <array.length)
					{
						fscanf(arquivo,"%d", &(array.data[array.ix]));
						array.ix = array.ix + 1;
					}
			}
		}
	}
	return(array);
}

/**Exemplo1004 */

void exemplo_1004 ()
{
int_Array array;

	IO_id("Exemplo1004");

	array= fIO_readintArray("ARRAY1.TXT");

	if(array.data)
	{
		IO_printf("\n");
		printIntArray(array);
		//reciclar espaco
		free(array.data);
	}
	IO_pause("Apertar ENTER apara continuar.");
}

////////////////////////////////////////////////////////////////////////////

/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @return referencia para copia do arranjo
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/

ref_int_Array copyIntArray (int_Array array)
{
	int x=0; 
	int y=0;
	ref_int_Array copy;

	if(array.length <= 0) 
	{
		IO_printf("\nERRO: Valor Invalido.\n");
		array.length=0;
	}
	else
	{
		//reservar area 
		copy = new_int_Array(array.length);
		if(copy)
		{
			copy->length = array.length;
			copy->data = IO_new_ints(copy->length);

			//testar se ha espaco
			if(copy ->data == NULL || array.data == NULL)
			{
				printf("\nERRO: Falta espaco ou dados.");
			}
			else
			{
				for(array.ix =0; array.ix < array.length; array.ix = array.ix +1)
					{
						copy->data [array.ix] = array.data [array.ix];
					}
			}
		}
	}
	return(copy);
}

/** Exemplo_1005 */

void exemplo_1005 ()

{
	int_Array array;
	ref_int_Array other;

	IO_id("Exemplo_1005");
	array = fIO_readintArray("ARRAY1.TXT");
	other = copyIntArray(array);

	//testar a existencia de dados
	if(array.data)
	{
		IO_printf("\nOriginal\n");
		printIntArray(array);

		//mostrar dados
		IO_printf("\nCopia\n");
		printIntArray(*other); //deferenciar a copia

		//reciclar os espaco
		free(array.data);
		free(other->data);
		free(other);
	}
	IO_pause("Apertar ENTER para continuar.");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/

typedef 
struct s_int_Matrix
{
int rows;
int columns;
ints* data;
int ix,iy;
}
int_Matrix;

/**
 Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix*ref_int_Matrix;

/**
 new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 @return referencia para arranjo com inteiros
 @param rows - quantidade de dados
 @param columns - quantidade de dados
*/

ref_int_Matrix new_int_Matrix (int rows, int columns)
{
	ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));

	if(tmpMatrix !=NULL)
	{
		tmpMatrix->rows =0;
		tmpMatrix-> columns =0;
		tmpMatrix-> data = NULL;

		//reservar espaco 
		if(rows>0 && columns >0)
		{
			tmpMatrix->rows = rows;
			tmpMatrix->columns = columns;
			tmpMatrix->data = malloc(rows*sizeof(ints));
			if(tmpMatrix->data)
			{
				for(tmpMatrix->ix=0;
					tmpMatrix->ix<tmpMatrix->rows;
					tmpMatrix->ix=tmpMatrix->ix+1)
					{
						tmpMatrix->data [tmpMatrix->ix] = (ints)malloc (columns * sizeof(int));
					}
			}
		}
		tmpMatrix->ix =0;
		tmpMatrix->iy =0;
	}
	return(tmpMatrix);
}

/**
 free_int_Matrix - Dispensar espaco para arranjo com inteiros
 @param tmpMatrix - referencia para grupo de valores inteiros
*/

void free_int_Matrix (ref_int_Matrix matrix)
{
	if(matrix != NULL)
	{
		if(matrix->data != NULL)
		{
			for(matrix->ix =0;
				matrix->ix <matrix->rows;
				matrix->ix= matrix->ix +1)
				{
					free(matrix->data[matrix->ix]);
				}
			free(matrix->data);
		}
		free(matrix);
	}
}


/**
 printIntMatrix - Mostrar matrix com valores inteiros.
 @param array - grupo de valores inteiros
*/

void printIntMatrix (ref_int_Matrix matrix)
{
	//testar a existencia
	if(matrix != NULL && matrix->data !=NULL )
	{
		for(matrix->ix =0; matrix->ix < matrix->rows; matrix->ix = matrix->ix +1)
			{
			for( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
				{
				printf("%3d\t", matrix->data [matrix->ix][matrix->iy]);
				}
			printf("\n");
			}
	}
}

/** exemplo_1006 */ 

void exemplo_1006 ()
{
	ref_int_Matrix matrix = new_int_Matrix (3,3);

	if(matrix != NULL && matrix->data != NULL)
	{
		matrix ->data [0][0] =1; matrix->data[0][1]=2; matrix->data[0][2]=3;
		matrix ->data [1][0] =3; matrix->data[1][1]=4; matrix->data[1][2]=5;
		matrix ->data [2][0] =6; matrix->data[2][1]=7; matrix->data[2][2]=8;
	}

	IO_id("Exemplo_1006");

	//executar o metodo
	printIntMatrix(matrix);

	//reciclar
	free_int_Matrix(matrix);

	//encerrar
	IO_pause("Apertar ENTER para continuar.");
}

//////////////////////////////////////////////////////////////////////////////

/**
 IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/

ref_int_Matrix IO_readintMatrix ()
{
	int rows=0;
	int columns=0;
	chars text = IO_new_chars(STR_SIZE);

	do
		{ 
			rows = IO_readint("\nrows = " );
		}while(rows <= 0);
	do
		{
			columns = IO_readint("\ncolumns = " );
		}while(columns <= 0);

	//reservar espaco para armazenar 

	ref_int_Matrix matrix =new_int_Matrix (rows, columns);

	if(matrix != NULL)
	{
		if(matrix ->data == NULL)
		{
			matrix->rows =0;
			matrix->columns =0;
			matrix->ix =0;
			matrix->iy =0;
		}
		else
		{
			//ler e guardar valores na matrix
			for( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
				{
				for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
					{
						strcpy ( text, STR_EMPTY );
						 matrix->data [ matrix->ix ][ matrix->iy ]
						 = IO_readint ( IO_concat (
						 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
						 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
					}
				}
		}
	}
	return(matrix);
}

/** exemplo_1007 */

void exemplo_1007 ()
{
	ref_int_Matrix matrix = NULL;
	IO_id("Exemplo_1007");

	matrix = IO_readintMatrix ();

	IO_printf("\n");
	printIntMatrix ( matrix );

	// reciclar espaco
	free_int_Matrix ( matrix );

	// encerrar
  IO_pause ( "Apertar ENTER para continuar" );
}

/**
 fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param matrix - grupo de valores inteiros
*/

void fprintfIntMatrix (chars fileName, ref_int_Matrix matrix)
{
	FILE*arquivo = fopen (fileName, "wt");
	if(matrix == NULL)
	{
		printf("\nERRO: Nao ha dados");
	}
	else
	{
		fprintf(arquivo, "%d\n", matrix->rows);
		fprintf(arquivo, "%d\n",matrix->columns);

		if(matrix->data != NULL)
		{
			for( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
				{
				for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
					{
					fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
					}
				}
		}
		fclose(arquivo);
	}
}

/** exemplo_1008 */

void exemplo_1008()
{
	ref_int_Matrix matrix = NULL;

	IO_id("Exemplo_1008");

	matrix = IO_readintMatrix();

	fprintfIntMatrix ("MATRIX1.TXT", matrix);
	free_int_Matrix(matrix);
	IO_pause("Apertar ENTER para continuar.");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
 @param fileName - nome do arquivo
*/

ref_int_Matrix freadintMatrix (chars fileName)
{
	ref_int_Matrix matrix = NULL;
	int rows =0;
	int columns =0;
	FILE* arquivo = fopen(fileName, "rt");

	fscanf(arquivo, "%d",&rows);
	fscanf(arquivo, "%d",&columns);
	if(rows <=0 || columns <= 0)
	{
		IO_printf("\nERRO: Valor invalido");
	}
	else
	{
		matrix= new_int_Matrix (rows,columns);

		if(matrix != NULL && matrix->data == NULL)
		{
			matrix->rows =0;
			matrix->columns=0;
			matrix->ix =0;
			matrix->iy=0;
		}
		else
		{
			if(matrix != NULL);
			{
				matrix->ix =0;
				while(!feof (arquivo) && matrix->ix <matrix->rows)
					{
						matrix->iy=0;
						while( ! feof (arquivo) && matrix->iy < matrix ->columns)
							{
								fscanf(arquivo, "%d", &(matrix->data [matrix ->ix][matrix->iy]));

								matrix->iy = matrix->iy +1;
							}
						matrix->ix = matrix->ix+1;
					}
				matrix->ix=0;
				matrix->iy=0;
			}
		}
	}
	return(matrix);
}

/** exemplo_1009*/

void exemplo_1009 ()
{
	IO_id("Exemplo_1008");
	ref_int_Matrix matrix = freadintMatrix ( "MATRIX1.TXT" );

	IO_printf ( "\n" );
	printIntMatrix ( matrix );

	free_int_Matrix ( matrix );

	IO_pause ( "Apertar ENTER para continuar" );
}

/////////////////////////////////////////////////////////////////////////////////////

/**
 copyIntMatrix - Copiar matriz com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/

ref_int_Matrix copyintMatrix (ref_int_Matrix matrix)
{
	ref_int_Matrix copy = NULL;
	if(matrix == NULL  ||  matrix ->data == NULL)
	{
		IO_printf("\nERRO: Faltam dados.\n" );
	}
	else
	{
		if(matrix ->rows <=0 || matrix -> columns <=0)
		{
			IO_printf("\nERRO: Faltam dados.\n");
		}
		else
		{
			copy = new_int_Matrix (matrix->rows, matrix->columns);

			if(copy == NULL || copy ->data == NULL)
			{
				printf ( "\nERRO: Falta espaco." );
			}
			else
			 {

			for ( copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1 )
			 {
				for ( copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1 )
					{
						copy->data [ copy->ix ][ copy->iy ]
						= matrix->data [ copy->ix ][ copy->iy ];
					}
			 }
			 }
			}
		}
	return(copy);
	}
	


					
/** exemplo_1010*/
void exemplo_1010 ()
{
	ref_int_Matrix matrix = NULL;
	ref_int_Matrix other = NULL;

	IO_id ( "Exemplo_1010" );
	matrix = freadintMatrix ( "MATRIX1.TXT" );
	other = copyintMatrix ( matrix );

	IO_printf ( "\nOriginal\n" );
    printIntMatrix ( matrix );

	 IO_printf ( "\nCopia\n" );
	 printIntMatrix(other);

	 free_int_Matrix ( matrix );
     free_int_Matrix ( other );

	 IO_pause ( "Apertar ENTER para continuar" );

}


int main ( void )
{
    // definir dados
    int opcao = 0;
    // identificar
    printf("\n%s\n\n", "999999_AED1");
    // acoes
       // repetir
       do
       {
        // ler opcao do teclado
        printf ( "%s", "Qual a opcao? " );
        scanf  ( "%d", &opcao ); getchar( );
        // mostrar valor lido
        printf ( "%s%d\n", "opcao = ", opcao );
        // escolher opcao
        switch ( opcao )
        {
           case  0: /* nada */     break;
           case  1: exemplo_1001 ( ); break;
           case  2: exemplo_1002 ( ); break;
           case  3: exemplo_1003 ( ); break;
           case  4: exemplo_1004 ( ); break;
           case  5: exemplo_1005 ( ); break;
           case  6: exemplo_1006 ( ); break;
           case  7: exemplo_1007 ( ); break;
           case  8: exemplo_1008 ( ); break;
           case  9: exemplo_1009 ( ); break;
           case 10: exemplo_1010 ( ); break;
           default: printf ( "\n%s\n",
                           "ERRO: Opcao invalida.\n\n" );
            break;
        }
       } while ( opcao != 0 );
    // encerrar
    printf("%s\n", "\nApertar ENTER para terminar\n");
    getchar( );
	return ( 0 );
}
/*
    Teste e anotacoes
*/
