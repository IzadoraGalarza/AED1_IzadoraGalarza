/** Aluna: Izadora Galarza Alves
* Recuperacao - 2 
* Prof: Theldo Cruz
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#define MAX_LINE_LENGTH 64


/**
FAZER um programa para:
- definir uma função para determinar se os valores
no arranjo estão em ordem decrescente;
- ler arranjo do arquivo DADOS1.TXT;
- se não estiverem, colocá-los em ordem decrescente,
antes de regravar os dados no arquivo CRESCENTE.TXT,
colocando a quantidade de elementos na primeira linha do arquivo.
DICA: Para ordenar usar o princípio de troca dos elementos vizinhos
que não estiverem ordenados, e testar novamente usando a função,
até que não seja necessário fazer mais trocas.
*/

bool isDecrecent (int array[], int size)
{
	int tam = size -1;
	for(int x =0; x < tam; x =x+1)
		{
			if(array[x] < array[x+1])
			{
				return (false);
			}
		}
	return(true);
}

void ordenar (int array[], int size)
{
	int tam = size-1;
	while(!isDecrecent(array, size))
		{
			for(int x=0; x < tam; x=x+1)
				{
					if(array[x] < array[x+1])
					{
						int atual = array[x];
						array[x] = array[x+1];
						array[x+1] = atual;
					}
				}
		}
}
void exe01 ()
{
	FILE* entrada = fopen ("DADOS1.TXT", "rt");
	FILE* saida = fopen("DECRESCENTE.TXT", "wt");
	int *array = NULL;;
	int tamanho=0;

	if(!entrada || entrada == NULL )
	{
		printf("%s\n","ERRO: Nao foi possivel abrir arquivo de entrada");
	}
	
	 fscanf(entrada, "%d", &tamanho);
	array = (int*) malloc(tamanho * sizeof(int));

	//fazer a leitura e mandar pro array
	for(int y=0; y < tamanho; y=y+1)
	{
		fscanf(entrada, "%d", &array[y]);
	}

	printf("%s: ", "Arranjo lida em arquivo");
	for(int x=0; x < tamanho; x=x+1)
	{
		printf("%d ", array[x]);
	}
	printf("\n");
	if(isDecrecent(array,tamanho))
	{
		printf("%s\n","O arranjo esta em ordem decrescente.");
	}
	else
	{
		printf("%s\n","O arranjo NAO esta em ordem decrescente.");
		ordenar(array, tamanho);
	}

	if(!saida || saida==NULL)
	{
		printf("%s\n","ERRO: Nao foi possivel abrir arquivo de saida");
	}

	fprintf(saida, "%d", tamanho);
	for(int x=0; x < tamanho; x=x+1)
	{
		fprintf(saida,"\n%d",array[x]);
	}


	fclose(entrada);
	fclose(saida);

}

/**
* FAZER um programa para:
- definir uma função para receber o arranjo como
parâmetro e inverter a ordem de seus elementos;
- ler arranjo do arquivo CRESCENTE.TXT;
- gravar o arranjo invertido no arquivo INVERTIDOS.TXT,
colocando a quantidade de dados elementos na primeira linha.
DICA: Trocar o último com o primeiro e prosseguir até a metade.
Exemplo:
// arranjo1 = { 4, 3, 2, 1 };
arranjo_inverter ( arranjo2, arranjo1 ); // [ 1, 2, 3, 4 ]*/

void inverter (int array2[] , int array1[], int tamanho)
{
	int size = tamanho - 1;
	int x=0;
	int y= size;
	while(x <= size )
		{
			array2[y] = array1[x];
			y=y-1;
			x=x+1;
		}
}
		
	
void exe02()
{
	FILE* entrada= fopen("DECRESCENTE.TXT","rt");
	FILE* saida = fopen("INVERTIDOS.TXT","wt");
	int *array1 = NULL;
	int *array2 = NULL;
	int tamanho=0;
	
	if(!entrada || entrada == NULL )
	{
		printf("%s\n","ERRO: Nao foi possivel abrir arquivo de entrada");
	}
	
	 fscanf(entrada, "%d", &tamanho);
	array1 = (int*) malloc(tamanho * sizeof(int));
	array2 = (int*) malloc(tamanho * sizeof(int));

	//fazer a leitura e mandar pro array
	for(int y=0; y < tamanho; y=y+1)
	{
		fscanf(entrada, "%d", &array1[y]);
	}

	inverter(array2, array1, tamanho);
	printf("%s: ", "Arranjo decrescente");
	for(int x=0; x < tamanho; x=x+1)
	{
		printf("%d ", array1[x]);
	}
	printf("\n");

	printf("%s: ", "Arranjo invertido");
	for(int x=0; x < tamanho; x=x+1)
	{
		printf("%d ", array2[x]);
	}
	printf("\n");

	if(!saida || saida==NULL)
	{
		printf("%s\n","ERRO: Nao foi possivel abrir arquivo de saida");
	}

	fprintf(saida, "%d", tamanho);
	for(int x=0; x < tamanho; x=x+1)
	{
		fprintf(saida,"\n%d",array2[x]);
	}


	fclose(entrada);
	fclose(saida);
	
}

/**
FAZER um programa para:
- definir uma função para receber um arranjo e um valor inteiro
como parâmetros, e achar a mediana (valor mais perto da média); 
se houver dois próximos e diferentes, usar a média desses dois;
- ler arranjo do arquivo DADOS1.TXT;
- receber e mostrar a moda usando a função definida;
DICA: Montar uma tabela para cada valor e quantas vezes aparece,
quando o procurar por outra função.
Exemplo:
arranjo_ler ( "DADOS1.TXT", tabela );
valor = arranjo_mediana ( tabela );
tela <- valor
*/


typedef struct 
{
    int valor;
    int contagem;
} 
FrequenciaItem;

double mediana(FrequenciaItem* tabela_frequencia, int num_itens_distintos) 
{
    if (num_itens_distintos == 0 || tabela_frequencia == NULL) 
    {
        return 0.0;
    }

    double soma_total = 0.0;
    int contador_total_valores = 0;

    for (int i = 0; i < num_itens_distintos; i = i + 1) 
    {
        soma_total = soma_total + (double)tabela_frequencia[i].valor * tabela_frequencia[i].contagem;
        contador_total_valores = contador_total_valores + tabela_frequencia[i].contagem;
    }

    if (contador_total_valores == 0) 
    {
        return 0.0;
    }

    double media_aritmetica = soma_total / contador_total_valores;

    double menor_diferenca = HUGE_VAL; 
    int valor1_proximo = 0; 
    int valor2_proximo = 0; 
    bool encontrou_primeiro = false;
    bool encontrou_segundo_diferente = false;

    for (int i = 0; i < num_itens_distintos; i = i + 1) 
    {
        double diferenca_atual = fabs((double)tabela_frequencia[i].valor - media_aritmetica);

        if (diferenca_atual < menor_diferenca) 
        {
            menor_diferenca = diferenca_atual;
            valor1_proximo = tabela_frequencia[i].valor;
            encontrou_primeiro = true;
            encontrou_segundo_diferente = false; 
        } 
        else if (diferenca_atual == menor_diferenca) 
        {
            if (encontrou_primeiro && tabela_frequencia[i].valor != valor1_proximo) 
            {
                valor2_proximo = tabela_frequencia[i].valor;
                encontrou_segundo_diferente = true;
            }
        }
    }

    if (encontrou_primeiro && encontrou_segundo_diferente) 
    {
        return (valor1_proximo + valor2_proximo) / 2.0;
    } 
    else if (encontrou_primeiro) 
    {
        return (double)valor1_proximo;
    }
    
    return 0.0; 
}

int* array_moda(const FrequenciaItem* tabela_frequencia, int num_itens_distintos, int* num_modas) 
{
    *num_modas = 0;
    if (num_itens_distintos == 0 || tabela_frequencia == NULL) 
    {
        return NULL;
    }

    int maior_frequencia = 0;
    for (int i = 0; i < num_itens_distintos; i = i + 1) 
    {
        if (tabela_frequencia[i].contagem > maior_frequencia) 
        {
            maior_frequencia = tabela_frequencia[i].contagem;
        }
    }

    int* modas_arr = (int*)malloc(num_itens_distintos * sizeof(int));
    if (modas_arr == NULL) 
    {
        printf("Erro de alocacao de memoria para as modas");
        return NULL;
    }

    for (int i = 0; i < num_itens_distintos; i = i + 1) 
    {
        if (tabela_frequencia[i].contagem == maior_frequencia) 
        {
            modas_arr[*num_modas] = tabela_frequencia[i].valor;
            *num_modas = *num_modas + 1;
        }
    }
    return modas_arr;
}

FrequenciaItem* array_ler(const char* nome_arquivo, int* num_itens_distintos) 
{
    FILE* arquivo = fopen(nome_arquivo, "rt");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo");
        *num_itens_distintos = 0;
        return NULL;
    }

    int tamanho_total_elementos = 0;
    if (fscanf(arquivo, "%d", &tamanho_total_elementos) != 1) 
    {
        fclose(arquivo);
        return NULL;
    }

    FrequenciaItem* tabela_frequencia = (FrequenciaItem*)malloc(tamanho_total_elementos * sizeof(FrequenciaItem));
    if (tabela_frequencia == NULL) 
    {
        printf("Erro de alocacao de memoria para a tabela de frequencia");
        fclose(arquivo);
        return (NULL);
    }

    *num_itens_distintos = 0;
    int numero_lido;

    for (int i = 0; i < tamanho_total_elementos; i = i + 1) 
    {
        if (fscanf(arquivo, "%d", &numero_lido) != 1) 
        {
            fclose(arquivo);
            free(tabela_frequencia);
            return (NULL);
        }

        bool encontrado = false;
        for (int j = 0; j < *num_itens_distintos; j = j + 1) 
        {
            if (tabela_frequencia[j].valor == numero_lido) 
            {
                tabela_frequencia[j].contagem = tabela_frequencia[j].contagem + 1;
                encontrado = true;
            }
        }

        if (!encontrado) 
        {
            tabela_frequencia[*num_itens_distintos].valor = numero_lido;
            tabela_frequencia[*num_itens_distintos].contagem = 1;
            *num_itens_distintos = *num_itens_distintos + 1;
        }
    }

    fclose(arquivo);
    return tabela_frequencia;
}

void exe03 () 
{
    FrequenciaItem* tabela;
    int num_itens_distintos = 0;
    double valor;

    tabela = array_ler("DADOS1.TXT", &num_itens_distintos);

    if (tabela == NULL || num_itens_distintos == 0) 
    {
        printf("Nao foi possivel ler dados validos do arquivo ou o arquivo esta vazio.\n");

    }


    valor = mediana(tabela, num_itens_distintos);
    printf("A mediana (valor mais perto da media) e': %.2f\n", valor);

    int* modas_encontradas = NULL;
    int quantidade_modas = 0;

    modas_encontradas = array_moda(tabela, num_itens_distintos, &quantidade_modas);

    if (modas_encontradas != NULL && quantidade_modas > 0) 
    {
        printf("A moda do conjunto de dados e': ");
        for (int i = 0; i < quantidade_modas; i = i + 1) 
        {
            printf("%d ", modas_encontradas[i]);
        }
        printf("\n");
        free(modas_encontradas);
    } 
    else 
    {
        printf("Nao foi possivel determinar a moda.\n");
    }

    free(tabela);
}


/**
FAZER um programa para:
- ler um arranjo do arquivo DADOS1.TXT;
- ler outro arranjo do arquivo DADOS2.TXT;
- filtrar e mostrar os elementos comuns aos dois arranjos, sem repetições;
- gravar o resultado no arquivo FILTRADOS.TXT,
colocando a quantidade de dados únicos na primeira linha.
Exemplo:
arranjo_ler ( "DADOS1.TXT", arranjo_1 );
arranjo_ler ( "DADOS2.TXT", arranjo_2 );
arranjo_filtrar ( arranjo3, arranjo1, arranjo2 );
arranjo_gravar ( "FILTRADOS.TXT", arranjo3 );
*/

bool existe_em_array(int valor, const int* array, int tamanho)
{
    for (int i = 0; i < tamanho; i = i + 1)
    {
        if (array[i] == valor)
        {
            return true;
        }
    }
    return false;
}

int* ler(const char* nome_arquivo, int* tamanho_array)
{
    FILE* arquivo;
    int tamanho_lido_do_arquivo;
    int* array_lido;
    int i;
    int numero_lido;

    arquivo = fopen(nome_arquivo, "rt");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
        *tamanho_array = 0;
        return NULL;
    }

    if (fscanf(arquivo, "%d", &tamanho_lido_do_arquivo) != 1)
    {
        printf("ERRO: Nao foi possivel ler o tamanho do array do arquivo %s\n", nome_arquivo);
        fclose(arquivo);
        *tamanho_array = 0;
        return NULL;
    }

    array_lido = (int*)malloc(tamanho_lido_do_arquivo * sizeof(int));
    if (array_lido == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para o array\n");
        fclose(arquivo);
        *tamanho_array = 0;
        return NULL;
    }

    for (i = 0; i < tamanho_lido_do_arquivo; i = i + 1)
    {
        if (fscanf(arquivo, "%d", &array_lido[i]) != 1)
        {
            printf("ERRO: Nao foi possivel ler todos os elementos do array do arquivo %s\n", nome_arquivo);
            fclose(arquivo);
            free(array_lido);
            *tamanho_array = 0;
            return NULL;
        }
    }

    fclose(arquivo);
    *tamanho_array = tamanho_lido_do_arquivo;
    return array_lido;
}

int* array_filtrar(int* array1, int tamanho1, int* array2, int tamanho2, int* tamanho3)
{
    int max_possivel;
    int* array3;
    int i;
    int elemento_atual;

    if (tamanho1 < tamanho2)
    {
        max_possivel = tamanho1;
    }
    else
    {
        max_possivel = tamanho2;
    }
    
    array3 = (int*)malloc(max_possivel * sizeof(int));
    if (array3 == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para o array filtrado\n");
        *tamanho3 = 0;
        return NULL;
    }

    *tamanho3 = 0;

    for (i = 0; i < tamanho1; i = i + 1)
    {
        elemento_atual = array1[i];
        
        if (existe_em_array(elemento_atual, array2, tamanho2))
        {
            if (!existe_em_array(elemento_atual, array3, *tamanho3))
            {
                array3[*tamanho3] = elemento_atual;
                *tamanho3 = *tamanho3 + 1;
            }
        }
    }
    
    return array3;
}

void array_gravar(const char* nome_arquivo, const int* array, int tamanho)
{
    FILE* arquivo;
    int i;

    arquivo = fopen(nome_arquivo, "wt");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s para gravar\n", nome_arquivo);
        return;
    }

    fprintf(arquivo, "%d", tamanho);
    for (i = 0; i < tamanho; i = i + 1)
    {
        fprintf(arquivo, "\n%d", array[i]);
    }

    fclose(arquivo);
}

void exe04()
{
    int* array_1 = NULL;
    int* array_2 = NULL;
    int* array_3 = NULL;
    int tamanho_1 = 0;
    int tamanho_2 = 0;
    int tamanho_3 = 0;

    array_1 = ler("DADOS1.TXT", &tamanho_1);
    if (array_1 == NULL)
    {
        printf("ERRO\n");
    }
    printf("Elementos array1: %d\n", tamanho_1);

    array_2 = ler("DADOS2.TXT", &tamanho_2);
    if (array_2 == NULL)
    {
        free(array_1);
        printf("ERRO\n");
    }
    printf("Elementos array2: %d\n", tamanho_2);

    
    array_3 = array_filtrar(array_1, tamanho_1, array_2, tamanho_2, &tamanho_3);
    if (array_3 == NULL)
    {
        free(array_1);
        free(array_2);
        printf("ERRO\n");
    }

    printf("Elementos comuns (sem repeticoes): ");
    if (tamanho_3 == 0)
    {
        printf("Nenhum.\n");
    }
    else
    {
        for (int i = 0; i < tamanho_3; i = i + 1)
        {
            printf("%d ", array_3[i]);
        }
        printf("\n");
    }

    array_gravar("FILTRADOS.TXT", array_3, tamanho_3);

    free(array_1);
    free(array_2);
    free(array_3);

}


/**  FAZER um programa para:
- ler cadeias de caracteres do arquivo BINARIOS1.TXT, uma por vez, em cada linha;
- considerar válidos apenas sequências de valores iguais a zero ou a um;
- converter e armazenar em um arranjo de inteiros (int);
- supondo serem dígitos de um número binário,
convertê-los para decimal mediante o uso de uma função*/

bool binario_valido(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '0' && str[i] != '1')
        {
            return false;
        }
        i = i + 1;
    }
    return true;
}

int arranjo_paraDecimal(const char* binario_str)
{
    int decimal = 0;
    int comprimento = strlen(binario_str);
    int potencia = 0;
    int i;

    for (i = comprimento - 1; i >= 0; i = i - 1)
    {
        if (binario_str[i] == '1')
        {
            decimal = decimal + (int)pow(2, potencia);
        }
        potencia = potencia + 1;
    }
    return decimal;
}

void exe05()
{
    FILE* arquivo_entrada;
    char linha[MAX_LINE_LENGTH];
    int* array_decimal = NULL;
    int num_elementos_decimal = 0;
    int capacidade_decimal = 10;

    arquivo_entrada = fopen("BINARIOS1.TXT", "rt");
    if (arquivo_entrada == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo BINARIOS1.TXT\n");
       
    }

    array_decimal = (int*)malloc(capacidade_decimal * sizeof(int));
    if (array_decimal == NULL)
    {
        printf("ERRO: Falha na alocacao inicial de memoria para o array decimal\n");
        fclose(arquivo_entrada);
         
    }

    while (fgets(linha, MAX_LINE_LENGTH, arquivo_entrada) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (binario_valido(linha))
        {
            if (num_elementos_decimal == capacidade_decimal)
            {
                capacidade_decimal = capacidade_decimal * 2;
                int* temp_array = (int*)malloc(capacidade_decimal * sizeof(int));
                if (temp_array == NULL)
                {
                    printf("ERRO: Falha na realocacao de memoria para o array decimal\n");
                    free(array_decimal);
                    fclose(arquivo_entrada);
                     
                }
                for (int i = 0; i < num_elementos_decimal; i = i + 1)
                {
                    temp_array[i] = array_decimal[i];
                }
                free(array_decimal);
                array_decimal = temp_array;
            }
            
            array_decimal[num_elementos_decimal] = arranjo_paraDecimal(linha);
            num_elementos_decimal = num_elementos_decimal + 1;
        }
        else
        {
            printf("Aviso: Sequencia invalida ignorada: %s\n", linha);
        }
    }

    fclose(arquivo_entrada);

    printf("Numeros binarios convertidos para decimal:\n");
    if (num_elementos_decimal == 0)
    {
        printf("Nenhum binario valido encontrado no arquivo.\n");
    }
    else
    {
        for (int i = 0; i < num_elementos_decimal; i = i + 1)
        {
            printf("%d\n", array_decimal[i]);
        }
    }

    free(array_decimal);
}

/**
FAZER um programa para:
- ler dados para matrizes do arquivo MATRIZ1.TXT;
- ler um número inteiro ( N ), por vez, para indicar
a quantidade de linhas e colunas de uma matriz quadrada;
- montar, mostrar e gravar no arquivo MATRIZ2.TXT
uma matriz com a característica abaixo
(tridiagonal crescente).
*/



void gerar_matriz(int N)
{
    FILE* saida = fopen("MATRIZ2.TXT","wt");
    int** matriz;
    int contador;
    int x, y;

    matriz = (int**)malloc(N * sizeof(int*));
    if (matriz == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para as linhas da matriz.\n");
    }

    for (x = 0; x < N; x = x + 1)
    {
        matriz[x] = (int*)malloc(N * sizeof(int));
        if (matriz[x] == NULL)
        {
            printf("ERRO: Falha na alocacao de memoria para a coluna %d da matriz.\n", x);
            for (y = 0; y < x; y = y + 1)
            {
                free(matriz[y]);
            }
            free(matriz);
    
        }
        for (y = 0; y < N; y = y + 1)
        {
            matriz[x][y] = 0;
        }
    }
    
    contador = (N * 3) - 2;

    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            if (x == y)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
            else if (x == y - 1)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
            else if (x == y + 1)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
        }
    }

    printf("Matriz Tridiagonal:\n");
    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            printf("%d\t", matriz[x][y]);
        }
        printf("\n");
    }

    if (saida == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo MATRIZ2.TXT para gravar.\n");
        for (x = 0; x < N; x = x + 1)
        {
            free(matriz[x]);
        }
        free(matriz);

    }

    fprintf(saida, "%d\n", N); 
    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            fprintf(saida, "%d\t", matriz[x][y]);
        }
        fprintf(saida, "\n");
    }

    fclose(saida);

    for (x = 0; x < N; x = x + 1)
    {
        free(matriz[x]);
    }
    free(matriz);
}

void exe06()
{
    FILE* entrada = fopen("MATRIZ1.TXT", "rt");
    int N;

    
    if (entrada == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo MATRIZ1.TXT.\n");
       
    }

    if (fscanf(entrada, "%d", &N) != 1)
    {
        printf("ERRO: Nao foi possivel ler o tamanho da matriz (N) do arquivo MATRIZ1.TXT.\n");
        fclose(entrada);
      
    }

    fclose(entrada);

    if (N <= 0)
    {
        printf("ERRO: O tamanho da matriz (N) deve ser um numero inteiro positivo.\n");
     
    }

    gerar_matriz(N);

}

/**
FAZER um programa para:
- ler dados para matrizes do arquivo MATRIZ1.TXT;
- ler um número inteiro ( N ), por vez, para indicar
a quantidade de linhas e colunas de uma matriz quadrada;
- montar, mostrar e gravar no arquivo MATRIZ2.TXT
uma matriz com a característica abaixo
(tridiagonal secundária decrescente).
*/

void gerar_matriz_secundaria(int N)
{
    FILE* saida = fopen("MATRIZ2.TXT", "wt");
    int** matriz;
    int contador;
    int x, y;

    matriz = (int**)malloc(N * sizeof(int*));
    if (matriz == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para as linhas da matriz.\n");
        return; 
    }

    for (x = 0; x < N; x = x + 1)
    {
        matriz[x] = (int*)malloc(N * sizeof(int));
        if (matriz[x] == NULL)
        {
            printf("ERRO: Falha na alocacao de memoria para a coluna %d da matriz.\n", x);
            for (y = 0; y < x; y = y + 1)
            {
                free(matriz[y]);
            }
            free(matriz);
    
        }
        for (y = 0; y < N; y = y + 1)
        {
            matriz[x][y] = 0;
        }
    }
    
    contador = (N * 3) - 2;

    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            if (x + y == N - 1)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
            else if (x + y == N - 2)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
            else if (x + y == N)
            {
                matriz[x][y] = contador;
                contador = contador - 1;
            }
        }
    }

    printf("Matriz Tridiagonal Secundaria:\n");
    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            printf("%d\t", matriz[x][y]);
        }
        printf("\n");
    }

    if (saida == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo MATRIZ2.TXT para gravar.\n");
        for (x = 0; x < N; x = x + 1)
        {
            free(matriz[x]);
        }
        free(matriz);
    }

    fprintf(saida, "%d\n", N); 
    for (x = 0; x < N; x = x + 1)
    {
        for (y = 0; y < N; y = y + 1)
        {
            fprintf(saida, "%d\t", matriz[x][y]);
        }
        fprintf(saida, "\n");
    }

    fclose(saida);

    for (x = 0; x < N; x = x + 1)
    {
        free(matriz[x]);
    }
    free(matriz);
}

void exe07()
{
    FILE* entrada= fopen("MATRIZ1.TXT", "rt");
    int N;

     
    if (entrada == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo MATRIZ1.TXT.\n");
        
    }

    if (fscanf(entrada, "%d", &N) != 1)
    {
        printf("ERRO: Nao foi possivel ler o tamanho da matriz (N) do arquivo MATRIZ1.TXT.\n");
        fclose(entrada);
      
    }

    fclose(entrada);

    if (N <= 0)
    {
        printf("ERRO: O tamanho da matriz (N) deve ser um numero inteiro positivo.\n");
   
    }

    gerar_matriz_secundaria(N);

    
}

/**
FAZER um programa para:
- ler matriz do arquivo MATRIZ3.TXT;
- definir uma função lógica para verificar
se a matriz lida apresenta a característica abaixo (potências por colunas).
*/ 
bool verifica(int** matriz, int n)
{
    int x, y;
    double valor_esperado_double;
    int valor_esperado_int;

    if (matriz == NULL || n <= 0)
    {
        return false;
    }

    for (x = 0; x < n; x = x + 1)
    {
        for (y = 0; y < n; y = y + 1)
        {
            valor_esperado_double = pow((double)(x + 1), (double)y);
            valor_esperado_int = (int)round(valor_esperado_double);

            if (matriz[x][y] != valor_esperado_int)
            {
                return false;
            }
        }
    }
    return true;
}

int** le_matriz(const char* nome_arquivo, int* n_ptr)
{
    FILE* arquivo;
    int n_lido;
    int** matriz_lida;
    int x, y;

    arquivo = fopen(nome_arquivo, "rt");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
        *n_ptr = 0;
        return NULL;
    }

    if (fscanf(arquivo, "%d", &n_lido) != 1)
    {
        printf("ERRO: Nao foi possivel ler o tamanho da matriz (n) do arquivo %s\n", nome_arquivo);
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    if (n_lido <= 0)
    {
        printf("ERRO: O tamanho da matriz (n) deve ser um numero inteiro positivo.\n");
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    matriz_lida = (int**)malloc(n_lido * sizeof(int*));
    if (matriz_lida == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para as linhas da matriz.\n");
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    for (x = 0; x < n_lido; x = x + 1)
    {
        matriz_lida[x] = (int*)malloc(n_lido * sizeof(int));
        if (matriz_lida[x] == NULL)
        {
            printf("ERRO: Falha na alocacao de memoria para a coluna %d da matriz.\n", x);
            for (y = 0; y < x; y = y + 1)
            {
                free(matriz_lida[y]);
            }
            free(matriz_lida);
            fclose(arquivo);
            *n_ptr = 0;
            return NULL;
        }
        for (y = 0; y < n_lido; y = y + 1)
        {
            if (fscanf(arquivo, "%d", &matriz_lida[x][y]) != 1)
            {
                printf("ERRO: Nao foi possivel ler todos os elementos da matriz do arquivo %s.\n", nome_arquivo);
                for (int k = 0; k <= x; k = k + 1)
                {
                    free(matriz_lida[k]);
                }
                free(matriz_lida);
                fclose(arquivo);
                *n_ptr = 0;
                return NULL;
            }
        }
    }

    fclose(arquivo);
    *n_ptr = n_lido;
    return matriz_lida;
}

void libera_matriz(int** matriz, int n)
{
    if (matriz == NULL)
    {
        printf("ERRO\n");
    }
    for (int x = 0; x < n; x = x + 1)
    {
        free(matriz[x]);
    }
    free(matriz);
}

void exe08() 
{
    int** matriz_lida = NULL;
    int n = 0;
    bool caracteristica;

   
    matriz_lida = le_matriz("MATRIZ3.TXT", &n);

    if (matriz_lida == NULL)
    {
        printf("ERRO\n");
    }

   
    for (int x = 0; x < n; x = x + 1)
    {
        for (int y = 0; y < n; y = y + 1)
        {
            printf("%d\t", matriz_lida[x][y]);
        }
        printf("\n");
    }

    caracteristica = verifica(matriz_lida, n);

    if (caracteristica)
    {
        printf("A matriz LIDA APRESENTA a caracteristica 'potencias por colunas'.\n");
    }
    else
    {
        printf("A matriz LIDA NAO APRESENTA a caracteristica 'potencias por colunas'.\n");
    }

    libera_matriz(matriz_lida, n);

}

/**
FAZER um programa para:
- ler matriz do arquivo MATRIZ4.TXT;
- definir uma função lógica para verificar e
testar se a matriz lida apresenta a característica abaixo (potências decrescentes por colunas).
*/

bool verifica_potencias_decrescentes(int** matriz, int n)
{
    int x, y;
    double valor_esperado_double;
    int valor_esperado_int;

    if (matriz == NULL || n <= 0)
    {
        return false;
    }

    for (x = 0; x < n; x = x + 1)
    {
        for (y = 0; y < n; y = y + 1)
        {
            // Base for power is (y + 1)
            // Exponent for power is (n - 1) - x
            valor_esperado_double = pow((double)(y + 1), (double)((n - 1) - x));
            valor_esperado_int = (int)round(valor_esperado_double);

            if (matriz[x][y] != valor_esperado_int)
            {
                return false;
            }
        }
    }
    return true;
}

int** ler_matriz_arquivo(const char* nome_arquivo, int* n_ptr)
{
    FILE* arquivo;
    int n_lido;
    int** matriz_lida;
    int x, y;

    arquivo = fopen(nome_arquivo, "rt");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
        *n_ptr = 0;
        return NULL;
    }

    if (fscanf(arquivo, "%d", &n_lido) != 1)
    {
        printf("ERRO: Nao foi possivel ler o tamanho da matriz (n) do arquivo %s\n", nome_arquivo);
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    if (n_lido <= 0)
    {
        printf("ERRO: O tamanho da matriz (n) deve ser um numero inteiro positivo.\n");
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    matriz_lida = (int**)malloc(n_lido * sizeof(int*));
    if (matriz_lida == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para as linhas da matriz.\n");
        fclose(arquivo);
        *n_ptr = 0;
        return NULL;
    }

    for (x = 0; x < n_lido; x = x + 1)
    {
        matriz_lida[x] = (int*)malloc(n_lido * sizeof(int));
        if (matriz_lida[x] == NULL)
        {
            printf("ERRO: Falha na alocacao de memoria para a coluna %d da matriz.\n", x);
            for (y = 0; y < x; y = y + 1)
            {
                free(matriz_lida[y]);
            }
            free(matriz_lida);
            fclose(arquivo);
            *n_ptr = 0;
            return NULL;
        }
        for (y = 0; y < n_lido; y = y + 1)
        {
            if (fscanf(arquivo, "%d", &matriz_lida[x][y]) != 1)
            {
                printf("ERRO: Nao foi possivel ler todos os elementos da matriz do arquivo %s.\n", nome_arquivo);
                for (int k = 0; k <= x; k = k + 1)
                {
                    free(matriz_lida[k]);
                }
                free(matriz_lida);
                fclose(arquivo);
                *n_ptr = 0;
                return NULL;
            }
        }
    }

    fclose(arquivo);
    *n_ptr = n_lido;
    return matriz_lida;
}

void liberar_memoria_matriz(int** matriz, int n)
{
    if (matriz == NULL)
    {
        return;
    }
    for (int x = 0; x < n; x = x + 1)
    {
        free(matriz[x]);
    }
    free(matriz);
}

void exe09() 
{
    int** matriz_lida = NULL;
    int n = 0;
    bool eh_caracteristica;

    matriz_lida = ler_matriz_arquivo("MATRIZ4.TXT", &n); 

    if (matriz_lida == NULL)
    {
        return;
    }

    printf("Matriz lida (n=%d):\n", n);
    for (int x = 0; x < n; x = x + 1)
    {
        for (int y = 0; y < n; y = y + 1)
        {
            printf("%d\t", matriz_lida[x][y]);
        }
        printf("\n");
    }

    eh_caracteristica = verifica_potencias_decrescentes(matriz_lida, n);

    if (eh_caracteristica)
    {
        printf("A matriz LIDA APRESENTA a caracteristica 'potencias decrescentes por colunas'.\n");
    }
    else
    {
        printf("A matriz LIDA NAO APRESENTA a caracteristica 'potencias decrescentes por colunas'.\n");
    }

    liberar_memoria_matriz(matriz_lida, n);
}

/**
FAZER um programa para:
- ler do arquivo DADOS3.TXT:
- um número inteiro ( N ) para indicar
a quantidade de supermercados cujos preços de produtos serão avaliados;
- o nome e o código (int) de cada supermercado;
- ler o preço de um produto de cada supermercado;
- calcular o preço médio desse produto;
- informar pelo menos dois supermercados com preços inferiores à média.
*/


typedef struct
{
    char nome[50];
    int codigo;
    double preco;
}
Supermercado;

void exe10()
{
    FILE* entrada  = fopen("DADOS3.TXT", "rt");;
    int N;
    Supermercado* supermercados;
    double soma_precos = 0.0;
    double preco_medio;
    int x;
    int count_abaixo_media = 0;

    if (entrada == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo DADOS3.TXT.\n");
       
    }

    if (fscanf(entrada, "%d", &N) != 1)
    {
        printf("ERRO: Nao foi possivel ler a quantidade de supermercados (N).\n");
        fclose(entrada);
       
    }

    if (N <= 0)
    {
        printf("ERRO: A quantidade de supermercados (N) deve ser um numero inteiro positivo.\n");
        fclose(entrada);
       
    }

    supermercados = (Supermercado*)malloc(N * sizeof(Supermercado));
    if (supermercados == NULL)
    {
        printf("ERRO: Falha na alocacao de memoria para os supermercados.\n");
        fclose(entrada);
     
    }

    
    for (x = 0; x < N; x = x + 1)
    {
        
        if (fscanf(entrada, "%s %d %lf", supermercados[x].nome, &supermercados[x].codigo, &supermercados[x].preco) != 3)
        {
            printf("ERRO: Falha na leitura dos dados do supermercado %d.\n", x + 1);
            free(supermercados);
            fclose(entrada);
        }
        soma_precos = soma_precos + supermercados[x].preco;
    }

    fclose(entrada);

    preco_medio = soma_precos / N;

    printf("Preco medio do produto: %.2f\n", preco_medio);
    printf("Supermercados com precos inferiores a media:\n");

    for (x = 0; x < N; x = x + 1)
    {
        if (supermercados[x].preco < preco_medio)
        {
            printf("- %s (Codigo: %d, Preco: %.2f)\n", supermercados[x].nome, supermercados[x].codigo, supermercados[x].preco);
            count_abaixo_media = count_abaixo_media + 1;
        }
    }

    if (count_abaixo_media == 0)
    {
        printf("Nenhum supermercado encontrado com preco inferior a media.\n");
    }
    else if (count_abaixo_media == 1)
    {
        printf("Apenas 1 supermercado encontrado com preco inferior a media.\n");
    }
   

    free(supermercados);


}

int main ()
{
	int opcao=0;

	do
		{
	    printf("\n%s\n","Opcoes:");
		printf("%s\n"," 0 - Terminar");
		printf("%s\n"," 1 - Exercicio -01");
	    printf("%s\n"," 2 - Exercicio - 02");
		printf("%s\n"," 3 - Exercicio - 03");
	    printf("%s\n"," 4 - Exercicio - 04");
		printf("%s\n"," 5 - Exercicio - 05");
		printf("%s\n"," 6 - Exercicio - 06");
		printf("%s\n"," 7 - Exercicio - 07");
		printf("%s\n"," 8 - Exercicio - 08");
		printf("%s\n"," 9 - Exercicio - 09");
		printf("%s\n"," 10 - Exercicio - 10");
		printf("\n");

		printf("%s","Escolha uma opcao:");
		scanf("%d",&opcao);
		getchar();
			
		printf("%s: %d\n\n","Opcao escolhida",opcao);

				switch(opcao)
				{
					case 0: break;
					case 1: exe01(); 
						    break;
					case 2: exe02(); 
						    break;
					case 3: exe03(); 
						    break;
					case 4: exe04(); 
						    break;
					case 5: exe05(); 
						    break;
					case 6: exe06(); 
					        break;
					case 7:exe07(); 
						    break;
					case 8: exe08(); 
						    break;
					case 9: exe09(); 
						    break;
					case 10: exe10(); 
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
	
