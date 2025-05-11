#include<stdio.h>
#include<stdlib.h>
#include"io.h"
#include<string.h>
#include<math.h>

/** 
 DEFINIR funções e procedimento para testes ( exercicio01 ) para:
- ler um valor inteiro (n) do teclado para indicar uma quantidade; OK
- ler outros tantos valores inteiros (x) do teclado, um por vez, até atingir a quantidade;
- dizer para cada valor lido se há mais divisores pares do que ímpares.
DICA: Usar apenas alternativas simples.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:
n = 5
x = { 22, 121, 440, 581, 814 }
soma_impares = soma_divisores_impares ( valor );
soma_pares = soma_divisores_pares ( valor );
@param 
*/

int soma_impares (int va)
{
	int x=1;
    int impar=0;
    for(x=1; x <= va ; x=x+1)
    {
        if(x%2 != 0 && va%x == 0 )
        {
            impar = impar +1;
        }
    }

    return impar; 
}

int soma_pares (int va)
{
    int x=1;
    int par=0;
    for(x=1; x <= va ; x=x+1)
    {
        if(  x%2 == 0 && va%x == 0 )
        {
                par = par +1;
        }
    }

    return par; 
}
void exe_r01 ()
{
	int n=0; // quantidade
	int v= 0; // valores
    int i=0;
    int p =0;
	n= IO_readint("Entre com uma quantidade (n): ");
	for(int x=0; x <n ; x=x+1)
		{
			printf("%s", "Entre com um valor :");
			scanf("%d",&v); 
            i=soma_impares(v);
            p=soma_pares(v);
            if(p>i)
            {
                printf("Existe mais divisores pares.\n");
            }
            else if (p < i)
            {
                printf("Existe mais divisores impares.\n");
            }
            if (p == i)
            {
                printf("Mesma quantidade de divisores pares e impares.\n");
            }

		}
}

/** DEFINIR função e procedimento para testes ( exercicio02 ) para:
- ler um valor inteiro (n) do teclado para indicar uma quantidade;
- ler outros tantos valores inteiros (x) do teclado, um por vez, até atingir a quantidade;
- dizer. para cada valor lido, se é primo, ou não, verificado por função lógica.
DICA: Usar alternativas dupla.
O resultado NÃO deverá ser mostrado dentro da função.
NÃO usar break ou continue.
Usar apenas 01 retorno.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:
n = 5
x = { -293, -107, 153, 199, 811 }
resposta = primo ( valor ); */
bool primos_n (int va)
{
    int x=1;
    int y=0;
    bool result = true;
    if (va <= 1)
    { 
        return false;
    }
    for(x=2; x < va ; x=x+1)
    {
        if( va % x ==0 )
        {
        result = false;
        }
    }

    return result; 
}
void exe_r02 ()
{
    int n=0; // quantidade
	int v= 0; // 
    bool primo =0;
	n= IO_readint("Entre com uma quantidade (n): ");
	for(int x=0; x <n ; x=x+1)
		{
			printf("%s", "Entre com um valor :");
			scanf("%d",&v); 
            primo = primos_n(v);
            if(primo == true)
            {
                printf("Numero primo\n");
            }
            else
            {
                printf("Numero nao e' primo\n");
            }
           

		}

}
/** DEFINIR funções e procedimento para testes ( exercicio03 ) para:
- ler uma cadeia de caracteres do teclado;
- dizer se cada símbolo é um operador lógico (&,|,!), aritmético (+,-,*,/,%), relacional (>,<,=),
separadores (espaço, ponto, vírgula, ponto-e-vírgula, dois-pontos, sublinha)
ou outro símbolo qualquer.
DICA: Definir e usar funções para identificar cada um desses tipos de símbolo.
NÃO usar funções semelhantes da biblioteca padrão da linguagem.
O resultado NÃO deverá ser mostrado dentro da função.
Usar switch para escolhas.
Usar apenas 01 retorno.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:


resposta = testar_simbolo_logico ( valor );
resposta = testar_simbolo_aritmetico ( valor );
resposta = testar_simbolo_relacional ( valor ); */
bool testar_simbolo_logico(char valor) 
{
    switch (valor) {
        case '&':
        case '|':
        case '!':
            return true; 
        default:
            return false;  
    }
}

bool testar_simbolo_aritmetico(char valor) 
{
    switch (valor) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
        default:
            return false; 
    }
}

bool testar_simbolo_relacional(char valor)
{
    switch (valor) 
    {
        case '>':
        case '<':
        case '=':
            return true; 
        default:
            return false;
    }
}

bool testar_simbolo_separadores(char valor) {
    switch (valor) {
        case ' ':
        case '.':
        case ',':
        case ';':
        case ':':
        case '_':
            return true;  // Verdadeiro se for separador
        default:
            return false;  

    }
}
void exe_r03 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    char simbolo = '_';
    palavra = IO_readstring("Entre com um conjunto de caracteres:");

    for(int x=0; x <strlen(palavra); x =x +1)
    {
        simbolo = palavra[x];
        if(testar_simbolo_logico(simbolo) ==  true)
        {
            printf(" %c =E' simbolo \n",simbolo);
        }
        else if (testar_simbolo_aritmetico(simbolo) == true)
        {
            printf(" %c E' simbolo aritmetico\n", simbolo);
        }
        else if (testar_simbolo_relacional(simbolo) == true)
        {
            printf(" %c E' simbolo relacional\n", simbolo);
        }
        else if (testar_simbolo_separadores(simbolo) == true)
        {
            printf(" %c E' simbolo separador\n", simbolo);
        }

    }
IO_pause("Apertar ENTER para continuar.");
}

/**DEFINIR funções e procedimento para testes ( exercicio04 ) para:
- ler um cadeia de caracteres (s) do teclado;
- testar cada símbolo na cadeia, um por vez,
e contar separadamente quantos desses são letras maiúsculas, minúsculas, dígitos e
operadores (lógicos, aritméticos e relacionais) e separadores.
DICA: Definir e reutilizar funções já definidas para identificar cada tipo de símbolo (ver acima).
NÃO usar funções semelhantes da biblioteca padrão da linguagem.
Os resultados NÃO deverão ser mostrados dentro das funções.
Usar switch para escolher os tipos de símbolos a serem contados..
Usar apenas 01 retorno.
Exemplos:
"for(X=0;X<y&&y>=0;X=X+1)"
resposta = testar_tipo ( valor );*/
/** void testar_tipo (chars cadeia)
{
    char simbolo = ' ';
    
    for(int x = 0; x < strlen(cadeia); x=x+1)
    {
        simbolo = cadeia[x];
        testar_simbolo_logico[x];
        testar_simbolo_aritmetico[x];
        testar_simbolo_relacional[x];
        testar_simbolo_separadores[x];
        
        testar_simbolo_logico[x];


    }
}
    */
void exe_r04 ()
{
    chars palavra = IO_new_chars(STR_SIZE);
    char simbolo = '_';
    palavra = IO_readln("Entre com um conjunto de caracteres:");

}

/** DEFINIR função e procedimento para testes ( exercicio05 ) para:
- ler um valor inteiro (n) do teclado; ok
- ler outros (n) valores reais (x) do teclado, um por vez; ok 
- calcular e mostrar a média dos valores menores que -21.75;
a média dos que estão entre -21.75 e 71.25, inclusive esses; ok
e a média dos maiores que 71.25. Dizer qual a maior média de todas.
DICA: Definir e usar função para calcular o maior dentre três valores.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:
n = 10
x = { -15.25, -12.50, 0.0, 6.75, 20.50, 50.0, 70.25, 85.25, 92.50, 98.75 }
resposta1 = no_intervalo ( inferior, superior, valor ); */

double maiorTodas(double menor, double entre, double maior) {
    double resposta = 0.0;

    if (menor > entre && menor > maior) {
        resposta = menor;
    } else if (entre > menor && entre > maior) {
        resposta = entre;
    } else if (maior > menor && maior > entre) {
        resposta = maior;
    }

    return resposta;
}

void exe_r05() {
    int n = 0; 
    double valor = 0.0;
    double somaMenores = 0.0, somaEntre = 0.0, somaMaiores = 0.0;
    int contadorMenores = 0, contadorEntre = 0, contadorMaiores = 0;
    double mediaMenores = 0.0, mediaEntre = 0.0, mediaMaiores = 0.0;
    double maiorMedia = 0.0;

    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    for (int x = 0; x < n; x = x + 1) 
    {
        printf("Digite um valor real: ");
        scanf("%lf", &valor);

        if (valor < -21.75)
        {
            somaMenores = somaMenores + valor;
            contadorMenores = contadorMenores + 1;
        } 
        else if (valor >= -21.75 && valor <= 71.25) 
        {
            somaEntre = somaEntre + valor;
            contadorEntre = contadorEntre + 1;
        } 
        else 
        {
            somaMaiores = somaMaiores + valor;
            contadorMaiores = contadorMaiores + 1;
        }
    }

    if (contadorMenores > 0) 
    {
        mediaMenores = somaMenores / contadorMenores;
    }

    if (contadorEntre > 0) 
    {
        mediaEntre = somaEntre / contadorEntre;
    }

    if (contadorMaiores > 0) 
    {
        mediaMaiores = somaMaiores / contadorMaiores;
    }

    maiorMedia = maiorTodas(mediaMenores, mediaEntre, mediaMaiores);
    printf("\n\n");
    printf("Media dos valores menores que -21.75: %.2lf\n", mediaMenores);
    printf("Media dos valores entre -21.75 e 71.25: %.2lf\n", mediaEntre);
    printf("Media dos valores maiores que 71.25: %.2lf\n", mediaMaiores);

    printf("\n\n");

    if (maiorMedia == mediaMenores) 
    {
        printf("A media dos menores que -21.75 e' a maior de todas.\n\n");
    } 
    else if (maiorMedia == mediaEntre) 
    {
        printf("A media dos valores entre -21.75 e 71.25 e' a maior de todas.\n\n");
    } 
    else 
    {
        printf("A media dos valores maiores que 71.25 e' a maior de todas.\n\n");
    }

    printf("Pressione ENTER para continuar...\n");
}

/** DEFINIR função e um procedimento para testes ( exercicio06 ) para:
- ler dois valores inteiros (a) e (b) do teclado,
- ler outros valores inteiros do teclado, um por vez,
até que o último valor seja igual a (-1).
- para cada valor lido que estiver no intervalo aberto ]a:b[;
calcular e mostrar a soma dos cubos dos inversos (1/x3) dos ímpares não múltiplos de 3.
DICA: Evitar divisão por zero mediante uso de alternativa dupla.
Definir e usar funções para testar o pertencimento ao intervalo,
e para calcular a soma.
O resultado NÃO deverá ser mostrado dentro da função.
Usar do-while na repetição de leitura.
Exemplos:
a = 15
b = 45
x = { -20, -11, 0, 1, 10, 21, 36, 51, 70, 80, -1 }
resposta = soma_inversos_dos_cubos ( a, b ); */

int pertenceAoIntervalo(int a, int b, int x) {
    return (x > a && x < b);
}

int ehImparNaoMultiploDe3(int x) {
    return (x % 2 != 0 && x % 3 != 0);
}

double somaInversosDosCubos(int a, int b) {
    int x;
    double soma = 0.0;

    do {
        printf("Digite um valor (-1 para parar): ");
        scanf("%d", &x);

        if (x == -1) break;

        if (pertenceAoIntervalo(a, b, x) && ehImparNaoMultiploDe3(x)) {
            if (x != 0) {
                soma = soma + 1.0 / (x * x * x);
            }
        }
    } while (x != -1);

    return soma;
}

void exe_r06() {
    int a, b;
    double resultado;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    resultado = somaInversosDosCubos(a, b);

    printf("Soma dos cubos dos inversos dos impares nao multiplos de 3 no intervalo ]%d:%d[ = %.6lf\n", a, b, resultado);
}

/** DEFINIR função e um procedimento para testes ( exercicio07 ) para:
- ler dois valores reais (a) e (b) do teclado,
- ler outros valores reais do teclado, um por vez,
até que o último valor seja igual a zero,
e não considerá-lo para os cálculos.
- contar quantos desses valores estão dentro ou fora
do intervalo definido pelo intervalo aberto ]a:b[;
- para os valores fora do intervalo, calcular separadamente
as porcentagens dos que estiverem acima e abaixo do intervalo, nessa ordem.
DICA: Evitar divisão por zero mediante uso de alternativas duplas.
Reutilizar a função para testar o pertencimento (ou não) ao intervalo.
O resultado NÃO deverá ser mostrado dentro da função.
Usar do-while na repetição de leitura.
Exemplos:
a = 15
b = 45
x = { -20, -10, 1, 10, 20, 30, 60, 70, 80, 0 }
resposta = no_intervalo ( a, b, valor ); */


void exe_r07() {
    double a, b, x;
    int dentro = 0, foraCima = 0, foraBaixo = 0, totalFora = 0;
    double percCima = 0.0, percBaixo = 0.0;

    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valor de b: ");
    scanf("%lf", &b);

    do {
        printf("Digite um valor (0 para parar): ");
        scanf("%lf", &x);

        if (x == 0) break;

        if (pertenceAoIntervalo(a, b, x)) {
            dentro++;
        } else {
            if (x < a) {
                foraBaixo= foraBaixo+1;
            } else if (x > b) {
                foraCima= foraCima+ 1;
            }
        }
    } while (x != 0);

    totalFora = foraBaixo + foraCima;

    if (totalFora > 0) {
        percCima = (100.0 * foraCima) / totalFora;
        percBaixo = (100.0 * foraBaixo) / totalFora;
    }

    printf("Valores dentro do intervalo ]%.2lf:%.2lf[: %d\n", a, b, dentro);
    printf("Valores fora do intervalo: %d\n", totalFora);
    printf("Porcentagem acima de %.2lf: %.2lf%%\n", b, percCima);
    printf("Porcentagem abaixo de %.2lf: %.2lf%%\n", a, percBaixo);
}

/** DEFINIR função e um procedimento para testes ( exercicio08 ) para:
- ler três valores reais (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.
DICA: Usar testes com maior número de comparações usando conectivos lógicos ( &&, || e ! ).
Definir funções para testar as ordens crescente e decrescente.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:
x = 10, y = 20, z = 30
x = 30, y = 20, z = 10
x = 10, y = 10, z = 10
resposta1 = crescente ( x, y, z );
resposta2 = decrescente ( x, y, z );
resposta3 = maior ( x, y, z );
resposta4 = menor ( x, y, z ); */


int crescente(double x, double y, double z) {
    return (x < y && y < z);
}

int decrescente(double x, double y, double z) {
    return (x > y && y > z);
}

double maior(double x, double y, double z) {
    double m = x;
    if (y > m) m = y;
    if (z > m) m = z;
    return m;
}

double menor(double x, double y, double z) {
    double m = x;
    if (y < m) m = y;
    if (z < m) m = z;
    return m;
}

void exe_r08() {
    double x, y, z;

    printf("Digite x: ");
    scanf("%lf", &x);
    printf("Digite y: ");
    scanf("%lf", &y);
    printf("Digite z: ");
    scanf("%lf", &z);

    if (crescente(x, y, z)) {
        printf("Valores em ordem crescente.\n");
    } else if (decrescente(x, y, z)) {
        printf("Valores em ordem decrescente.\n");
    } else {
        double mMaior = maior(x, y, z);
        double mMenor = menor(x, y, z);
        printf("Valores em nenhuma ordem.\n");
        printf("Maior: %.2lf\n", mMaior);
        printf("Menor: %.2lf\n", mMenor);
    }
}

/** DEFINIR função e um procedimento para testes ( exercicio09 ) para:
- ler três caracteres (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens.
DICA: Usar uma função lógica para comparar os códigos inteiros de cada caractere,
e dizer se o segundo sucede o primeiro em ordem alfabética.
Definir funções para testar as ordens alfabéticas crescente e decrescente.
O resultado NÃO deverá ser mostrado dentro da função.
Exemplos:
x = '1', y = '2', z = '3'
x = '3', y = '2', z = '1'
x = '1', y = '1', z = '1'
resposta1 = crescente ( x, y, z );
resposta2 = decrescente ( x, y, z );
resposta3 = sucessor ( x, y ); */

int s(char a, char b) {
    return (b > a);
}

int c(char x, char y, char z) {
    return (x < y && y < z);
}

int d(char x, char y, char z) {
    return (x > y && y > z);
}

void exe_r09() {
    char x, y, z;

    printf("Digite o caractere x: ");
    scanf(" %c", &x);
    printf("Digite o caractere y: ");
    scanf(" %c", &y);
    printf("Digite o caractere z: ");
    scanf(" %c", &z);

    if (c(x, y, z)) {
        printf("Caracteres em ordem crescente.\n");
    } else if (d(x, y, z)) {
        printf("Caracteres em ordem decrescente.\n");
    } else {
        printf("Caracteres em nenhuma ordem.\n");
    }
}

/** DEFINIR função e um procedimento para testes ( exercicio10 ) para:
- ler três cadeias de caracteres (x,y,z) do teclado, uma por vez;
- dizer se essas cadeias estão em ordem alfabética decrescente,
decrescente ou em nenhuma dessas ordens e, nesse caso, a menor e a maior.
DICA: Usar strcmp( ) da biblioteca <string.h> e comparar o resultado com zero.
A função para a comparação poderá retornar um dentre
os seguintes resultados:
O resultado NÃO deverá ser mostrado dentro da função.
negativo, se a primeira cadeia preceder a segunda (resultado menor que zero);
nulo , se as cadeias forem iguais (resultado igual a zero);
positivo , se a primeira cadeia suceder a segunda (resultado maior que zero).
Exemplo:
char s1 [ ] = “abc”;
char s2 [ ] = “ABC”;
if ( strcmp ( s1, s2 ) != 0 )
{
printf ( "%s\n", “diferentes” );
} // end if
 */
int compararOrdem(chars x, chars y, chars z)
{
    int xy = strcmp(x, y);
    int yz = strcmp(y, z);

    if (xy < 0 && yz < 0)
        return -1;
    else if (xy > 0 && yz > 0)
        return 1;
    else
        return 0;
}

void exe_r10()
{
    chars x = IO_readstring("Digite a primeira palavra: ");
    chars y = IO_readstring("Digite a segunda palavra: ");
    chars z = IO_readstring("Digite a terceira palavra: ");

    int resultado = compararOrdem(x, y, z);

    if (resultado == -1)
    {
        IO_println("As palavras estao em ordem alfabetica crescente.");
    }
    else if (resultado == 1)
    {
        IO_println("As palavras estao em ordem alfabetica decrescente.");
    }
    else
    {
        IO_println("As palavras NAO estao em ordem alfabetica.");

        chars menor = x;
        chars maior = x;

        if (strcmp(y, menor) < 0) menor = y;
        if (strcmp(z, menor) < 0) menor = z;

        if (strcmp(y, maior) > 0) maior = y;
        if (strcmp(z, maior) > 0) maior = z;

        IO_printf("A menor palavra eh: %s\n", menor);
        IO_printf("A maior palavra eh: %s\n", maior);
    }

    IO_pause("Aperte ENTER para continuar...");
}

int main ()
  {
    int op = 0;

    do
    {
        IO_id("Recuperacao - Izadora Galarza Alves");

        IO_println("Opcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - exercicio01");
        IO_println("2 - exercicio02");
        IO_println("3 - exercicio03");
        IO_println("4 - exercicio04");
        IO_println("5 - exercicio05");
        IO_println("6 - exercicio06");
        IO_println("7 - exercicio07");
        IO_println("8 - exercicio08");
        IO_println("9 - exercicio09");
        IO_println("10 - exercicio10");

        op = IO_readint("Escolha um exercicio: ");

        //testar valor 
        switch(op)
        {
            case 0 :  break;
            case 1 : exe_r01(); break;
            case 2 : exe_r02();break;
            case 3 : exe_r03(); break;
            case 4 : exe_r04();break;
            case 5 : exe_r05(); break;
            case 6 : exe_r06();break;
            case 7 : exe_r07(); break;
            case 8 : exe_r08();break;
            case 9 : exe_r09(); break;
            case 10 : exe_r10(); break;
            default:
                IO_pause ( IO_concat ( "Valor diferente das opcoes (",
                IO_concat ( IO_toString_d ( op ), ")" ) ) );
        }
    } 
    while( op != 0);
    IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
}