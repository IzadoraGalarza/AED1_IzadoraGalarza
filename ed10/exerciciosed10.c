/** Exercicio1000 - 18/05/2025 
	Autora: Izadora Galarza Alves
*/

//dependecias
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"io.h"
//#define val(k) (*k) JA TEM NA IO
//#define addr(k) (&k) JA TEM NA IO

//criando uma struct para coisas gerais.
typedef
struct s_int_Array
{
	int tamanho;
	int* datas;
	int ix;
}
int_Array;

//referenciar a struct

typedef int_Array* ref_int_Array;

//reservar espaco para o array

ref_int_Array novo_Array (int n)
{
	ref_int_Array espArray = (ref_int_Array) malloc (sizeof(int_Array));

	if(espArray == NULL)
	{
		printf("%s\n","ERRO: Espaco nao disponivel.");
	}
	else
	{
		espArray ->tamanho=0;
		espArray -> datas = NULL;
		espArray -> ix = -1;
		if(n>0)
		{ 
			espArray -> tamanho = n; //quantidade de espaco
			espArray -> datas = (int*) malloc (n * sizeof(int));//primeiro elemento
			espArray -> ix =0; //controle
		}
	}
	return(espArray);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
ref_int_Array IO_readIntArray()
{
	//definir dados locais
	chars text = IO_new_chars(STR_SIZE);
	static ref_int_Array array;

	//ler quantidade de dados
	do
		{
			array->tamanho = IO_readint ("\nTamanho = ");
		}while (array->tamanho <= 0);
	//reservar espaco para armazenar
	array->datas = IO_new_ints(array->tamanho);

	//testar se ha espaco
	if(array->datas == NULL)
	{
		array->tamanho  =0; //nao ha espaco
	}
	else
	{
		//ler e guardar valores em arranjo
		for(array->ix =0; array->ix <array->tamanho ; array->ix = array->ix +1)
			{
				strcpy(text, STR_EMPTY);
				array->datas[array->ix]= IO_readint(IO_concat(IO_concat(text, IO_toString_d(array->ix)),":"));
			}
	}
	return(array);
}

//////////////////////////////////////////////////////////////////////////////////

//liberar espaco
void free_int_Array (ref_int_Array espArray)
{
	//testar se ha' dados, antes de reciclar o espaco
	if(espArray != NULL)
	{
		if(espArray->datas !=NULL)
		{
			free(espArray->datas);
		}
	free(espArray);
	}
}

void fprintIntArray (chars fileName, ref_int_Array array)
{
	//definir dados locais
	FILE*arquivo = fopen(fileName, "wt");
	//gravar quantidade de dados
	fprintf(arquivo,"%d\n",array->tamanho);
	 //gravar valores no arquivo, se existirem
	if(array->datas)
	{
		for(array->ix=0; array->ix < array->tamanho;array->ix= array->ix +1)
			{
				//gravar valor
				fprintf(arquivo,"%d\n",array->datas[array->ix]);
			}
	}
	fclose(arquivo);
}


/** Incluir um método (1011) para
gerar um valor inteiro aleatoriamente dentro de um intervalo, ok
cujos limites de início e de fim serão recebidos como parâmetros. ok
Para para testar, ler os limites do intervalo do teclado; ok
ler a quantidade de elementos ( N ) a serem gerados; ok
gerar essa quantidade ( N ) de valores aleatórios  
dentro do intervalo e armazená-los em arranjo; 
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores maiores ou iguais a 106
.
Exemplo: valor = RandomIntGenerate ( inferior, superior );
*/

int randomIntGenerate (int inf, int sup)
{
	return (inf + rand() % (sup - inf +1));
}

void exe_1011 ()
{
	int inf=0, sup=0, n=0;

	srand(time(NULL));
	
	 //inserir valores 
	IO_id("Exercicio - 1011");
	inf= IO_readint("Limite inferior: ");
	sup= IO_readint("Limite superior: ");
	n= IO_readint("Quantidade de numeros gerados: ");

	//Valor invalido se superior for menor que inferior e se superior for maior que 106
	if (n <= 0 || sup < inf || sup > 106) 
	{
        printf("Valores invalidos.\n");
        return;
    }
	
	ref_int_Array array = novo_Array(n);
	if (array == NULL || array->datas == NULL) 
	{
        return;
    }

	for(array->ix =0; array->ix < array->tamanho; array->ix= array->ix+1)
		{
			array->datas[array->ix] = randomIntGenerate(inf,sup);
		}

	fprintIntArray("DADOS1.TXT", array); // gerei os dois arquivos aqui (DADOS1 e DADOS2)
	free_int_Array(array);
	
}


/** Incluir uma função (1012) para
procurar certo valor inteiro em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos.
DICA: Usar o modelo de arranjo proposto nos exemplos.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
resposta = arraySearch ( valor, arranjo ); */

ref_int_Array readArrayFromFile (chars fileName)
{
	FILE*arquivo = fopen(fileName,"rt");
	if(arquivo == NULL)
	{
		printf("ERRO: Nao foi possivel abrir o arquivo.");
	}
	int tam=0;
	fscanf(arquivo,"%d",&tam);
	ref_int_Array array = novo_Array(tam);
	if (array == NULL || array->datas == NULL)
	{
        fclose(arquivo);
        return (NULL);
    }

	for(array->ix=0; array->ix < array->tamanho; array->ix = array->ix +1)
		{
			fscanf(arquivo, "%d",&array->datas[array->ix]);
		}
	fclose(arquivo);
	return(array);
}

int searchArray ( int valor, ref_int_Array array)
{
	for(array->ix=0; array->ix < array->tamanho; array->ix=array->ix+1)
		{
			if(array->datas[array->ix] == valor)
			{
				return(array->ix);
			}
		}
	return(-1);
}
void exe_1012 ()
{
	int valor=0;
	int resposta=0;
	IO_id("Exercicio1012");
	ref_int_Array array = readArrayFromFile("DADOS1.TXT");
	if (array == NULL) return;
	valor = IO_readint("Entre com um valor a ser buscado: ");
	resposta = searchArray(valor, array);
	if (resposta == -1 )
	{
		printf("Valor %d nao encontrado.\n", valor);
	}
	else
	{
		printf("Valor %d encontrado na posicao %d.\n", valor, resposta);
	}
	free_int_Array(array);
	IO_pause("Apertar ENTER para continuar.");
	
}

/**) Incluir uma função (1013) para
operar a comparação de dois arranjos.
Para testar, receber dados de arquivos e
aplicar a função sobre os arranjos com os valores lidos.
DICA: Verificar se, e somente se, os tamanhos forem iguais.
 Usar o modelo de arranjo proposto nos exemplos.
Exemplo: arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
arranjo2 = readArrayFromFile ( "DADOS2.TXT" );
resposta = arrayCompare ( arranjo1, arranjo2 ) */

int arrayCompare(ref_int_Array array1, ref_int_Array array2) {
    if (array1 == NULL || array2 == NULL) 
	{
		return 0;
	}
    if (array1->tamanho != array2->tamanho)
	{
        return 0;
    }

    for (array1->ix= 0; array1->ix < array1->tamanho; array1->ix = array1->ix +1) 
	{
        if (array1->datas[array1->ix] != array2->datas[array1->ix]) {
            return 0; // encontrou diferenca
        }
    }

    return 1; // arrays iguais
}

void exe_1013 ()
{
	IO_id("Exercicio1003");
	ref_int_Array array1= readArrayFromFile("DADOS1.TXT");
	ref_int_Array array2 =readArrayFromFile("DADOS2.TXT");
	int iguais = arrayCompare(array1, array2);

    if (iguais) {
        IO_printf("Os arrays sao iguais.\n");
    } else {
        IO_printf("Os arrays sao diferentes.\n");
    }
	free_int_Array(array1);
	free_int_Array(array2);
    IO_pause("Apertar ENTER para continuar.");
	
	
}

/**
) Incluir uma função (1014) para
operar a soma de dois arranjos, com os elementos do segundo multiplicados por uma constante.
Para testar, receber dados de arquivos e
aplicar a função sobre os arranjos com os valores lidos;
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de arranjo proposto nos exemplos.
Exemplo: arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
arranjo2 = readArrayFromFile ( "DADOS2.TXT" );
soma = arrayAdd ( arranjo1, 1, arranjo2 );*/

ref_int_Array arrayAdd (ref_int_Array array1, int constante, ref_int_Array array2)
{
	if(array1 == NULL|| array2 == NULL ||array1->tamanho != array2->tamanho  ) // ver se e' do mesmo tamanho
	{
		printf("ERRO: Tamanhos incompativeis.");
		return (NULL);
	}
	ref_int_Array arrayF = novo_Array(array1->tamanho); // ja que precisa ser do mesmo tamanho, nao importa se for array1 ou array2

	for(arrayF->ix=0; arrayF->ix < arrayF->tamanho; arrayF->ix= arrayF->ix +1)
		{
			arrayF->datas[arrayF->ix] = array1->datas[arrayF->ix] + (constante * array2->datas[arrayF->ix]);
		}
	return(arrayF);
	
}

		
void exe_1014 ()
{
	IO_id("Exercicio1004");
	int n =0;
	n = IO_readint("Ente com um valor para constante: ");
	ref_int_Array array1= readArrayFromFile("DADOS1.TXT");
	ref_int_Array array2 =readArrayFromFile("DADOS2.TXT");
	ref_int_Array soma= arrayAdd(array1, n, array2);
	if (soma != NULL)
    {
        printf("Resultado da soma:\n");
        for (soma->ix=0; soma->ix < soma->tamanho;soma->ix =soma->ix+1)
        {
            printf("%d ", soma->datas[soma->ix]);
        }
        printf("\n");
	}
	free_int_Array(array1);
	free_int_Array(array2);
	free_int_Array(soma);
	IO_pause("Apertar ENTER para continuar.");
	
}


/** ) Incluir uma função (1015) para
dizer se um arranjo está em ordem decrescente.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos.
DICA: Usar o modelo de arranjo proposto nos exemplos.
 Não usar break!
Exemplo: arranjo1 = readArrayFromFile ( "DADOS1.TXT" );
resposta = isArrayDecrescent ( arranjo );*/

bool isArrayDecrescent (ref_int_Array array1)
{
	array1->ix = 1;
	if (array1 == NULL || array1->tamanho < 2)
    {
        // Array vazio ou com 1 elemento considerado decrescente
        return true;
    }
    while (array1->ix < array1->tamanho)
    {
        if (array1->datas[array1->ix] > array1->datas[array1->ix - 1])
        {
            return (false); // encontrou aumento
        }
        array1->ix = array1->ix +1;
    }
	return (true);
}

	
void exe_1015 ()
{
	IO_id("Exercicio1005");
	ref_int_Array array1= readArrayFromFile("DADOS1.TXT");
	int resposta = isArrayDecrescent (array1);
	if(resposta)
	{
		printf("e' decrescente.\n");
	}
	else
	{
		printf("nao e' decrescente.\n");
	}
	free_int_Array(array1);
	IO_pause("Apertar ENTER para continuar");
}
///////////////////////////////////////////////////////////////////////////////
typedef 
struct s_int_Matrix
{
int rows;
int columns;
ints* data;
int ix,iy;
}
int_Matrix;

typedef 
int_Matrix* ref_int_Matrix;

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

ref_int_Matrix readMatrixFromFile (chars fileName)
{
	FILE*arquivo = fopen(fileName,"rt");
	if(arquivo == NULL)
	{
		printf("ERRO: Nao foi possivel abrir o arquivo.");
	}
	int rows=0;
	int columns=0;
	fscanf(arquivo,"%d",&rows);
	fscanf(arquivo,"%d",&columns);
	ref_int_Matrix matrix = new_int_Matrix(rows,columns);
	if (matrix == NULL || matrix->data == NULL)
	{
        fclose(arquivo);
        return (NULL);
    }

	for(matrix->ix =0; matrix->ix < matrix->rows; matrix->ix = matrix->ix +1)
			{
			for( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
				{
				fscanf(arquivo, "%d",&matrix->data[matrix->ix][matrix->iy]);
				}
			}
	fclose(arquivo);
	return(matrix);
}

ref_int_Matrix matrixTranspose ( ref_int_Matrix matrixP) //matrix principal
{
	if(matrixP == NULL || matrixP->data == NULL)
	{
		printf("ERRO");
		return(NULL);
	}

	ref_int_Matrix maTroca = new_int_Matrix(matrixP->columns, matrixP->rows);

	for(matrixP->ix=0; matrixP->ix < matrixP->rows; matrixP->ix = matrixP->ix+1)
		{
			for(matrixP->iy=0; matrixP->iy < matrixP->columns; matrixP->iy = matrixP->iy +1)
				{
					maTroca->data[matrixP->iy][matrixP->ix] = matrixP->data[matrixP->ix][matrixP->iy];
				}
		}
	return(maTroca);

}

/** Incluir uma função (1016) para
obter a transposta de uma matriz.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1 = readMatrixFromFile ( "DADOS1.TXT" );
matriz2 = matrixTranspose ( matriz1 ); */
void exe_1016 ()
{
	ref_int_Matrix matrix1 = readMatrixFromFile("DADOS1_2.TXT"); 
	if(matrix1 == NULL)
	{
		printf("ERRO: Nao foi possivel continuar.");
		return;
	}
	ref_int_Matrix matrix2 = matrixTranspose(matrix1);
	if( matrix2== NULL)
	{
		printf("EERRO: Nao foi possivel continuar.");
		return;
	}
	printf("\nMatrix Original\n");
	printIntMatrix(matrix1);
	printf("\nMatrix transposta\n");
	printIntMatrix(matrix2);
	free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
	
}


/** ) Incluir uma função (1017) para
testar se uma matriz só contém valores iguais a zero.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1 = readMatrixFromFile ( "DADOS1.TXT" );
resposta = matrixZero ( matriz1 );*/

bool matrixZero(ref_int_Matrix matriz1)
{
    if (matriz1 == NULL || matriz1->data == NULL) {
        return false;
    }

    for (matriz1->ix = 0; matriz1->ix < matriz1->rows; matriz1->ix++) {
        for (matriz1->iy = 0; matriz1->iy < matriz1->columns; matriz1->iy++) {
            if (matriz1->data[matriz1->ix][matriz1->iy] != 0) {
                return false;
            }
        }
    }

    return true;
}
	
void exe_1017 ()
{
	ref_int_Matrix matrix1 = readMatrixFromFile("DADOS1_2.TXT");
	if(matrix1 == NULL || matrix1->data == NULL)
	{
		printf("ERRO");
	}
	bool resposta = matrixZero(matrix1);
	printIntMatrix(matrix1);
	if(resposta)
	{
		printf("Matrix composta por 0\n");
	}
	else
	{
		printf("Matrix nao e' composta apenas por 0\n");
	}
	free_int_Matrix(matrix1);
    
}


/** ) Incluir uma função (1018) para
testar a igualdade de duas matrizes.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1 = readMatrixFromFile ( "DADOS1.TXT" );
matriz2 = readMatrixFromFile ( "DADOS2.TXT" );
resposta = matrixCompare ( matriz1, matriz2 );
*/

bool matrixCompare(ref_int_Matrix matrix1, ref_int_Matrix matrix2) {
    if (matrix1 == NULL || matrix2 == NULL || matrix1->data == NULL || matrix2->data == NULL) {
        return false;
    }

    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns) {
        return false;
    }

    for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix= matrix1->ix +1) {
        for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy=matrix1->iy+1) {
            if (matrix1->data[matrix1->ix][matrix1->iy] != matrix2->data[matrix1->ix][matrix1->iy]) {
                return false;
            }
        }
    }

    return true;
}
void exe_1018 ()
{
	ref_int_Matrix matrix1 = readMatrixFromFile("DADOS1_2.TXT");
    ref_int_Matrix matrix2 = readMatrixFromFile("DADOS2_1.TXT");

    if (matrix1 == NULL || matrix2 == NULL) {
        printf("Erro ao carregar uma ou ambas as matrizes.\n");
        return;
    }

    bool resposta = matrixCompare(matrix1, matrix2);

    if (resposta) 
	{
        printf("As matrizes sao iguais.\n");
    } 
	else
	{
        printf("As matrizes sao diferentes.\n");
    }

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
}


/** ) Incluir uma função (1019) para
operar a soma de duas matrizes, com os elementos da segunda multiplicados por uma constante.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1 = readMatrixFromFile ( "DADOS1.TXT" );
matriz2 = readMatrixFromFile ( "DADOS2.TXT" );
soma = matrixAdd ( matriz1, -1, matriz2 
*/

ref_int_Matrix matrixAdd(ref_int_Matrix matrix1, int constante, ref_int_Matrix matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL || matrix1->data == NULL || matrix2->data == NULL)
    {
        printf("ERRO: Matrizes nulas.\n");
        return NULL;
    }

    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
    {
        printf("ERRO: Tamanhos incompativeis.\n");
        return NULL;
    }

    ref_int_Matrix matrixSoma = new_int_Matrix(matrix1->rows, matrix1->columns);

    if (matrixSoma == NULL || matrixSoma->data == NULL)
    {
        printf("ERRO: Falha ao criar matriz resultado.\n");
        return NULL;
    }

    for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1)
    {
        for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy = matrix1->iy + 1)
        {
            matrixSoma->data[matrix1->ix][matrix1->iy] = 
                matrix1->data[matrix1->ix][matrix1->iy] + constante * matrix2->data[matrix1->ix][matrix1->iy];
        }
    }

    return matrixSoma;
}


void exe_1019 ()
{
IO_id("Exercicio1009");
	int n =0;
	n = IO_readint("Ente com um valor para constante: ");
	ref_int_Matrix matrix1= readMatrixFromFile("DADOS1_2.TXT");
	ref_int_Matrix matrix2 =readMatrixFromFile("DADOS2_1.TXT");
	ref_int_Matrix soma= matrixAdd(matrix1, n, matrix2);
	if (soma != NULL)
    {
        printf("\nMatrix 1:\n");
        printIntMatrix(matrix1);

        printf("\nMatrix 2:\n");
        printIntMatrix(matrix2);

        printf("\nResultado da Soma:\n");
        printIntMatrix(soma);
    }

	free_int_Matrix(matrix1);
	free_int_Matrix(matrix2);
	free_int_Matrix(soma);
	IO_pause("Apertar ENTER para continuar.");
}


/**) Incluir uma função (1020) para
obter o produto de duas matrizes.
Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
 Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1 = readMatrixFromFile ( "DADOS1.TXT" );
matriz2 = readMatrixFromFile ( "DADOS2.TXT" );
soma = matrixProduct ( matriz1, matriz2 ); */

/** Fiquei em duvida de como era pra multiplicar, se era um por um, ou o jeito padrao*/


ref_int_Matrix matrixProduct(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL || matrix1->data == NULL || matrix2->data == NULL)
    {
        return NULL;
    }

    if (matrix1->columns != matrix2->rows)
    {
        return NULL;
    }

    ref_int_Matrix result = new_int_Matrix(matrix1->rows, matrix2->columns);

    if (result == NULL || result->data == NULL)
    {
        return NULL;
    }

    for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1)
    {
        for (matrix1->iy = 0; matrix1->iy < matrix2->columns; matrix1->iy = matrix1->iy + 1)
        {
            result->data[matrix1->ix][matrix1->iy] = 0;

            for (int n = 0; n < matrix1->columns; n = n + 1)
			{
			    result->data[matrix1->ix][matrix1->iy] = result->data[matrix1->ix][matrix1->iy] +
		        (matrix1->data[matrix1->ix][n] * matrix2->data[n][matrix1->iy]);
			}

	    }
	}
    return result;
}

void exe_1020 ()
{	
    IO_id("EXEMPLO1020");

    ref_int_Matrix matrix1 = readMatrixFromFile("DADOS1_2.TXT");
    ref_int_Matrix matrix2 = readMatrixFromFile("DADOS2_1.TXT");

    if (matrix1 == NULL || matrix2 == NULL)
    {
        return;
    }

    ref_int_Matrix produto = matrixProduct(matrix1, matrix2);

		printf("\nMatrix1\n");
        printIntMatrix(matrix1);
		printf("\nMatrix2\n");
        printIntMatrix(matrix2);
		printf("\nProduto:\n");
        printIntMatrix(produto);

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
	free_int_Matrix(produto);

    IO_pause("Aperte ENTER para continuar.");

}

ref_int_Array sortArrayDown(ref_int_Array array)
{
    if (array == NULL || array->datas == NULL)
        return NULL;

    int temp;
    for (array->ix = 0; array->ix < array->tamanho - 1; array->ix = array->ix + 1)
    {
        for (int iy = array->ix + 1; iy < array->tamanho; iy = iy + 1)
        {
            if (array->datas[array->ix] < array->datas[iy])
            {
                temp = array->datas[array->ix];
                array->datas[array->ix] = array->datas[iy];
                array->datas[iy] = temp;
            }
        }
    }
    return array;
}

void exe_10E1()
{
    IO_id("EXERCICIO10E1");

    ref_int_Array array = readArrayFromFile("DADOS1.TXT");

    if (array == NULL)
    {
        printf("Erro ao ler o arranjo.\n");
        return;
    }

    printf("Arranjo original:\n");
    for (array->ix = 0; array->ix < array->tamanho; array->ix = array->ix + 1)
    {
        printf("%d ", array->datas[array->ix]);
    }
    printf("\n");

    sortArrayDown(array);

    printf("Arranjo ordenado decrescente:\n");
    for (array->ix= 0; array->ix < array->tamanho; array->ix = array->ix + 1)
    {
        printf("%d ", array->datas[array->ix]);
    }
    printf("\n");

    free_int_Array(array);

    IO_pause("Aperte ENTER para continuar.");
}



int isIdentityMatrix(ref_int_Matrix matrix)
{
    if (matrix == NULL || matrix->data == NULL)
        return 0;

    if (matrix->rows != matrix->columns)
        return 0;

    for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
    {
        for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
        {
            if (matrix->ix == matrix->iy && matrix->data[matrix->ix][matrix->iy] != 1)
                return 0;

            if (matrix->ix != matrix->iy && matrix->data[matrix->ix][matrix->iy] != 0)
                return 0;
        }
    }

    return 1;
}

void exe_10E2()
{
    IO_id("EXERCICIO10E2");

    ref_int_Matrix matrix1 = readMatrixFromFile("DADOS1_2.TXT");
    ref_int_Matrix matrix2 = readMatrixFromFile("DADOS2_1.TXT");

    if (matrix1 == NULL || matrix2 == NULL)
    {
        printf("Erro ao ler matrizes.\n");
        return;
    }

    ref_int_Matrix produto = matrixProduct(matrix1, matrix2);

    if (produto == NULL)
    {
        printf("Produto nao pode ser calculado.\n");
        free_int_Matrix(matrix1);
        free_int_Matrix(matrix2);
        return;
    }

    int resposta = isIdentityMatrix(produto);

    if (resposta)
        printf("Produto e matriz identidade.\n");
    else
        printf("Produto nao e matriz identidade.\n");

    free_int_Matrix(matrix1);
    free_int_Matrix(matrix2);
    free_int_Matrix(produto);

    IO_pause("Aperte ENTER para continuar.");
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
           case  1: exe_1011 ( ); break;
           case  2: exe_1012 ( ); break;
           case  3: exe_1013 ( ); break;
           case  4: exe_1014 ( ); break;
           case  5: exe_1015 ( ); break;
           case  6: exe_1016 ( ); break;
           case  7: exe_1017 ( ); break;
           case  8: exe_1018 ( ); break;
           case  9: exe_1019 ( ); break;
           case 10: exe_1020 ( ); break;
			case 11: exe_10E1( );break;
			case 12: exe_10E2( );break;
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
