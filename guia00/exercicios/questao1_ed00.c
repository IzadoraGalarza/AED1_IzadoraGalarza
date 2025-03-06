// 866053_Izadora Galarza Alves
// Exemplo_0001

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iso646.h>
#include <string.h> 
#include<time.h>
#include<math.h>
#include <errno.h>
/////////////////////////////////////////////////////////////////

/*Method_01*/

void method_01(void) 
{

  printf("866053_AED1 - Metodo 1\n");  
  return;
}

///////////////////////////////////////////////////////////////////

/*Method_02*/


void method_02 (void)
{
	printf("%s\n","866053_AED1 - Metodo 2");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}

///////////////////////////////////////////////////////////////////


/*Method_03*/

void method_03 (void)
{
	bool status= false; //logico v ou f
	int contador = 0; // inteiro
	float valor_01 = 0.00f; //real de precisao simples
	double valor_02 = 0.00; // real de precisao dupla
	char letra = 'A'; // caractere

	printf("%s\n","866053 - Metodo 3");

	printf("status: %d \n",status);
	printf("contador: %d \n", contador);
	printf("valor_01: %f \n", valor_01);
	printf("valor_02 : %lf \n", valor_02);
	printf("caractere: %c \n", letra);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;

}

///////////////////////////////////////////////////////////////////

/*Method_04*/


void method_04 (void)
{
	char x = 'A';
	int y = 5;
	double z = 1.2;

	printf("%s\n","866053 - Metodo 4");

	printf("\nOperacoes:\n");
	y= (int) z;
	printf("z = %lf\t y =%d\n",z,y);
	y = (int) x;
	printf("x = %c \t y = %d\n", x, y);
	y=x;
	printf("x = %c \t y=%d\n", x, y);
	printf("\n");


	x = (char) (32+y); 
  printf ("y = %d \t x = %c\n", y, x );
  x = (char) (48+(int) z);
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
                     
  z = z - (int) z;  
  printf ("z = %lf\n", z );
  z = (double) x;    
	#include <iso646.h>
  printf ("z = %lf\t x = %c\n", z, x );
  z = 1.0 * x;       
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
  
  z = x / 2;          
  printf ("z = %lf\n", z );
  z = (double) (x/2);
  printf ("z = %lf\n", z );
  z = (double) x / 2;
  printf ("z = %lf\n", z );
  z = x / (double) 2;
  printf ("z = %lf\n", z );
  z = (double) x / (double) 2;
  printf ("z = %lf\n", z );
  printf ("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return;
}


///////////////////////////////////////////////////////////////////


/*Method_05*/

void method_05 (void)
{

	 bool p = true ;
  bool q = false;
  bool r = false;
  char a =   'A';
  char b =   'a';
  int  x =    5 ;
  int  y =    7 ;
  
  printf("%s\n","866053 - Metodo - 5"); 
  
  printf("\nComparacoes\n");
  printf("   (%c==%c) = %d\n", a, a, (a==a));
  printf("   (%c!=%c) = %d\n", a, a, (a!=a));
  printf("\n");
  
  r =  !  (a==a);        // NOT - logical negation
  printf(" ! (%c==%c) = %d\n", a, a, r);
  r =  !  (a!=a);        // NOT - logical complement
  printf(" ! (%c!=%c) = %d\n", a, a, r);
  r = not (a==a);        // NOT - logical negation
  printf("not(%c==%c) = %d\n", a, a, r);
  printf("\n");

  r = (x<y)  &&  (x!=0); // AND - logical conjunction
  printf("(%d<%d)  && (%d!=0)= %d\n", x,y,x,r);
  r = (x<y)  and (x!=0); // AND - logical conjunction
  printf("(%d<%d) and (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) ||  (x!=0); // OR  - logical disjunction
  printf("(%d>=%d) || (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) or  (x!=0); // OR  - logical disjunction
  printf("(%d<%d)  or (%d!=0)= %d\n", x,y,x,r);
  r = (x<=y) &&  (x> 0); // AND - logical conjunction
  printf("(%d<%d)  && (%d> 0)= %d\n", x,y,x,r);
  r = (x<=y) and (x> 0); // AND - logical conjunction
  printf("(%d<%d) and (%d> 0)= %d\n", x,y,x,r);
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return;
}

//////////////////////////////////////////////////////////////////

/* Metodo_06 */

void method_06 (void)
{
	bool p = true ;
  bool q = false;
  bool r = false;
   
  printf("%s\n","866053 - Metodo 6"); 
  
  printf("     p = %d\n", p);
  printf("     q = %d\n", q);
  printf("\n");
  
  printf("\nNegacao\n");
  r = ! p;    // NOT 
  printf(" !   p = %d\n", r);
  r = ! q;    // NOT
  printf(" !   q = %d\n", r);
  r = not p;  // NOT
  printf("not  p = %d\n", r);
  printf("\n");

  printf("\nConjuncao\n");
  printf("0 && 0 = %d\n", (0 && 0) );
  printf("0 && 1 = %d\n", (0 && 1) );
  printf("1 && 0 = %d\n", (1 && 0) );
  printf("1 && 1 = %d\n", (1 && 1) );
  printf("\n");

  printf("\nDisjuncao\n");
  printf("0 || 0 = %d\n", (0 || 0) );
  printf("0 || 1 = %d\n", (0 || 1) );
  printf("1 || 0 = %d\n", (1 || 0) );
  printf("1 || 1 = %d\n", (1 || 1) );
  printf("\n");

  printf("\nDisjuncao exclusiva\n");
  printf("0 ^  0 = %d\n", (0 ^  0) );
  printf("0 ^  1 = %d\n", (0 ^  1) );
  printf("1 ^  0 = %d\n", (1 ^  0) );
  printf("1 ^  1 = %d\n", (1 ^  1) );
  printf("\n");

  printf("\nOperacoes logicas\n");
  r = p &&  q; // AND
  printf("p &&  q = %d\n", r);
  r = p and q; // AND 
  printf("p and q = %d\n", r);
  r = p ||  q; // OR  
  printf("p ||  q = %d\n", r);
  r = p or  q; // AND- logical conjunction
  printf("p or  q = %d\n", r);
  printf("\n");

  r = p ^   q; // XOR - logical exclusive disjunction
  printf("p  ^  q = %d\n", r);
  r = p xor q;
  printf("p xor q = %d\n", r);
  r = p ^   p; 
  printf("p  ^  p = %d\n", r);
  r = p xor p;
  printf("p xor p = %d\n", r);
  printf("\n");

 
  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}

//////////////////////////////////////////////////////////////////

/*  Method_07 */

void method_07 (void)
{
	printf("%s\n","866053 - Metodo_07"); 

  int valor = 0;

  // entrar dado
  printf("Entre com um valor: ");
  scanf("%d", &valor); getchar( ); 

  // testar se valor negativo
  if(valor < 0) 
  {
    printf("%d -> negativo\n", valor); 
  }
  
  // testar se valor menor que 100
  if(valor < 100) 
  {
    printf("%d menor que 100\n", valor); 
  }
  else 
  {
   // testar se igual a 100
    if(valor == 100) 
    {
      printf("%d igual a 100\n", valor);
    }
    else 
    {
      printf("%d diferente de 100\n", valor ); 
    }
  }

  // encerrar
  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}


///////////////////////////////////////////////////////////////////


/*  Method_8 */

void method_08 (void)
{
	printf("%s\n","866053 - Method_08"); 
  int opcao = 0;

  printf("%s", "Opcao: ");
  scanf("%d", &opcao);  
  getchar( );

  
  switch(opcao)
  {
    case 0: 
      printf("%s\n", "Opcao 0 escolhida");
      break;

    case 1: 
      printf("%s\n", "Opcao 1 escolhida");
      break;

    case 2: 
      printf("%s\n", "Opcao 2 escolhida");
      break;

    default:
      printf("%s\n", "Outra opcao escolhida");
      break;
  }


  printf("\n\nApertar ENTER para terminar.");
  getchar();
  return;
}

////////////////////////////////////////////////////////////////

/*  Method_09 */

void method_09 (void)
{
	printf("%s\n","866053 - Metodo_09"); 
  int opcao = 0;

  
  do
  {

    printf("%s", "Opcao: ");
    scanf("%d", &opcao);  getchar();

    switch(opcao)
    {
      case 0: 
        printf("%s\n", "Opcao 0 escolhida");
        break;

      case 1: 
        printf("%s\n", "Opcao 1 escolhida");
        break;

      case 2: 
        printf("%s\n", "Opcao 2 escolhida");
        break;

      default:
        printf("%s\n", "Outra opcao escolhida");
        break;
    }
  }
  while(opcao != 0);

  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}

///////////////////////////////////////////////////////////////////

/*  Method_10 */

void method_10 (void)
{
  int x = 0;
  printf ("%s\n","866053- Metodo_10"); 

	//Repetir enquanto condicao for verdadeira
  while(x < 5)
  {
   // mostrar valor atual
      printf("%d\n", x);
   // passar ao seguinte (em ordem crescente)  
      x = x+1;   
  }

  
  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}


//////////////////////////////////////////////////////////////////

/*  Method_11 */

void method_11 (void)
{
  int x = 5;
  printf ("%s\n","866053- metodo_11"); 
  
  // repetir enquanto condicao verdadeira
  while(x > 0)
  {
   // mostrar valor atual
      printf("%d\n", x);
   // passar ao seguinte (em ordem decrescente)  
      x = x-1;   
  }
  
  // mostrar mensagem com formato 
  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}


///////////////////////////////////////////////////////////////////

/*  Method_12 */

void method_12 (void)
{
	int x = 0;
  
  // mostrar mensagem com formato 
  printf ("%s\n","866053 - Metodo_12"); 
  
  // repetir enquanto condicao verdadeira
  for(x=0; x < 5; x=x+1)
  {
   // mostrar valores em ordem crescente
      printf("%d\n", x);
  }

  printf("\n\nApertar ENTER para terminar.");
  getchar( );
  return;
}

////////////////////////////////////////////////////////////////


/* Method_13 */
void method_13(void) {
    int x = 0;
    printf("%s\n", "866053 - Metodo_13");

    for (x = 5; x > 0; x = x - 1) {
        printf("%d\n", x);
    }

    printf("\n\nApertar ENTER para terminar.");
    while (getchar() != '\n'); 
    getchar();
    return;
}
/////////////////////////////////////////////////

/* Funções Auxiliares */
void print_header(const char *message) {
    printf("%s\n", message);
}

void print_footer(const char *message) {
    printf("%s\n", message);
    while (getchar() != '\n'); 
    getchar();
}

/* Method_14 */
void method_14(void) {
    print_header("866053 - Metodo_14");
    printf("%s\n", "de volta ao main()");
    print_footer("Apertar ENTER para terminar.");
    return;
}
////////////////////////////////////////////////

/* Method_15 */
void method_15(void) {
    print_header("866053 - Metodo_15");
    printf("%s\n", "de volta ao main()");
    print_footer("Apertar ENTER para terminar.");
    return;
}

/////////////////////////////////////////

/* Method_16 */
int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

void method_16(void) {
    int x = 3, y = 5, z = 7;
    print_header("866053 - Metodo_16");
    printf("\nAplicar funcoes\n");
    printf("maior(%d,%d) = %d\n", x, y, max(x, y));
    printf("maior(%d,%d,%d) = %d\n", x, y, z, max(x, max(y, z)));
    printf("menor(%d,%d) = %d\n", x, y, min(x, y));
    printf("menor(%d,%d,%d) = %d\n", x, y, z, min(min(x, y), z));
    print_footer("Apertar ENTER para terminar.");
    return;
}

///////////////////////////////////////////////
/* Method_17 */
double sqr(double x) { return x * x; }
double lg(double x) { return log10(x) / log10(2.0); }

void method_17(void) {
    int x = 0;
    double y = 1.5;
    printf("%s\n", "866053 - Metodo 17");
    printf("\nAplicar funcoes\n");
    printf("floor(%lf) = %lf\n", y, floor(y));
    printf("ceil(%lf) = %lf\n", y, ceil(y));
    x = trunc(y);
    printf("trunc(%lf) = %d\n", y, x);
    x = round(y);
    printf("round(%lf) = %d\n", y, x);
    y = sin(30.0 * M_PI / 180.0);
    printf("sin(30) = %5.2lf\n", y);
    y = cos(60.0 * M_PI / 180.0);
    printf("cos(60) = %5.2lf\n", y);
    y = atan(1.00) * 180.0 / M_PI;
    printf("atan(1) = %5.2lf\n", y);
    y = pow(2.0, 3.0);
    printf("pow(2,3) = %5.0lf\n", y);
    y = lg(y);
    printf("lg(8,2) = %5.0lf\n", y);
    y = sqr(2.0);
    printf("sqr(2) = %5.0lf\n", y);
    y = sqrt(y);
    printf("sqrt(4) = %5.0lf\n", y);
    print_footer("Apertar ENTER para terminar.");
    return;
}

//////////////////////////////////////////////

/* Method_18 */
void method_18(void) {
	char s1[] = "abc";
    char s2[10];
    strcpy(s2, "def");
    char *s3 = "ghi";

    printf("%s\n", "866053 - Metodo_18");

    printf("\nAplicar funcoes\n");

    printf("s1 = [%s] (%d)\n", s1, strlen(s1));
    printf("s2 = [%s] (%d)\n", s2, strlen(s2));
    printf("s3 = [%s] (%d)\n", s3, strlen(s3));
    printf("\n");

    s3 = &s1[0];
    printf("s1 = [%s] (%d)\n", s3, strlen(s3));
    s3 = &s2[0];
    printf("s2 = [%s] (%d)\n", s3, strlen(s3));
    printf("\n");

    strcat(s2, s1);
    printf("s1 = [%s] (%d)\n", s1, strlen(s1));
    printf("s2 = [%s] (%d)\n", s2, strlen(s2));
    printf("\n");

    s3 = s1;
    printf("s1 = [%s] (%d) (%p)\n", s1, strlen(s1), &s1[0]);
    printf("s3 = [%s] (%d) (%p)\n", s3, strlen(s3), s3);
    printf("\n");

    s3 = calloc(strlen(s1) + 1, sizeof(char));
    strcpy(s3, s1);

    printf("s1 = [%s] (%d) (%p)\n", s1, strlen(s1), &s1[0]);
    printf("s3 = [%s] (%d) (%p)\n", s3, strlen(s3), s3);
    printf("\n");

    s3 = strdup(s1);
    printf("s1 = [%s] (%d) (%p)\n", s1, strlen(s1), &s1[0]);
    printf("s3 = [%s] (%d) (%p)\n", s3, strlen(s3), s3);
    printf("\n");

    if (strcmp(s1, s3) == 0)
        printf("%s igual a %s\n", s1, s3);
    if (strcmp(s1, s3) != 0)
        printf("%s igual a %s\n", s1, s3);
    if (strcmp(s1, s2) < 0)
        printf("%s antecede a %s\n", s1, s2);
    if (strcmp(s2, s1) > 0)
        printf("%s sucede a %s\n", s2, s1);
    printf("\n");

    for (int x = 0; x < strlen(s1); ++x)
        printf("%c ", s1[x]);
    printf("\n");

    for (int x = 0; x < strlen(s1); x++)
        printf("%c ", *(s1 + x));
    printf("\n");

    s3 = &s1[0];
    while (*s3) {
        printf("%c ", *s3);
        s3++;
    }
    printf("\n");

    for (int x = strlen(s1) - 1; x >= 0; --x)
        printf("%c ", s1[x]);
    printf("\n");
    printf("\n");

    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
    return (0);
}
    


///////////////////////////////////////////////////////////////////



/*  Method_19 */
	
void print_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  printf("%d ", v[x]);  }
  printf("\n");
}

void scan_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  scanf("%d", &v[x]); getchar( );  }
  printf("\n");  
}

void method_19 (void)
{
  
  int a [ ] = {1,2,3};  // arranjo com valores
  int b [3];            // espaco para arranjo
                        // definir valores iniciais
  b[0] = 4; b[1] = 5; b[2] = 6;
                        // reservar espaco
  int *c    = malloc(3 * sizeof(int));
                        // definir valores iniciais
  if ( c )              // se houver espaco reservado
    for(int x=0; x < 3; x=x+1)
    { c[x] = (x+1)*10; }
  
  printf("%s\n","866053_19"); 

  // aplicar metodos sobre em arranjos
  printf("\nOperacoes com arranjos\n");
  printf("a:\n");
  print_array(3, a);
  printf("\n");
  
  printf("b:\n");
  print_array(3, b);
  printf("\n");

  printf("c:\n");
  print_array(3, c);
  printf("\n");

  // ler     dados para arranjo
  printf("Entrar dados:\n");
  scan_array(3, c);
  printf("c:\n");
  // mostrar dados em   arranjo
  printf("\nDados lidos (c):\n");
  print_array(3, c);
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return;
}

///////////////////////////////////////////////////////////////////


/*  Methodo_20 */

void print_matrix(int m, int n, int v[][n])
{
  for(int x=0; x < m; x=x+1)
  {
    for(int y=0; y < n; y=y+1)
    {  printf("%d ", v[x][y]);  }
    printf("\n");
  }	
}


void scan_matrix(int m, int n, int v[][n])
{
  for(int x=0; x < m; x=x+1)
  {
    for(int y=0; y < n; y=y+1)
    {  scanf("%d", &v[x][y]); getchar( );  }
    printf("\n");
  }	
  printf("\n");  
}

void method_20 (void)
{
  int a [ ][3] = {{1,2,3},  // definir com valores
                  {4,5,6}};
  int b [2][3];             // espaco para matriz
                            // definir valores iniciais
  b[0][0] = 6; b[0][1] = 5; b[0][2] = 4;
  b[1][0] = 3; b[1][1] = 2; b[1][2] = 1;
  
  // mostrar mensagem  
  printf("%s\n","866053 - Metodo_20"); 

  // aplicar metodos sobre em matrizeos
  printf("\nOperacoes com matrizes\n");
  // mostrar dados
  printf("a:\n");
  print_matrix(2,3, a);
  printf("\n");
  
  printf("b:\n");
  print_matrix(2,3, b);
  printf("\n");

  // ler dados para matriz
  printf("Entrar dados:\n");
  scan_matrix(2,3, a);
  printf("a:\n");
  print_matrix(2,3, a);
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return;
}


//////////////////////////////////////////////////////////////////


//Method_21 - Arquivo
	
void method_21(void) 
{
	
  srand(time(NULL)); // semear aleatoriedade
  FILE *a = fopen("DATA21.TXT","w"); // abrir para gravar
  int   n = 5;
  int   b = 0;  
  
  // mostrar mensagem  
  printf("%s\n","866053 - Metodo_21"); 

  // gravar valores
  fprintf(a, "%d\n", n);      // guardar a quantidade
  for(int x = 0; x < n; x = x+1)
  {  fprintf(a, "%d\n", rand()%100); }
  fclose(a);                  // fechar (INDISPENSAVEL)
	 
  // ler valores 
  a = fopen("DATA21.TXT","r");  // abrir para ler
  fscanf(a, "%d", &n);        // obter  a quantidade
  // ler e mostrar dados
  printf("\nDados em arquivo:\n");
  for(int x = 0; x < n; x = x+1)
  {  
     fscanf(a, "%d", &b);   
	 printf("%d\n", b); 
  }
  fclose(a);                  // fechar (RECOMNDAVEL)
  
  printf("\n");
  
  
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return;
}

///////////////////////////////////////////////////////////////////


// Method_22
	
void method_22(void) 
{
	FILE *a = fopen("DATA22.TXT", "r");
    int n = 0;
    int *b = NULL;

    printf("%s\n", "866053 - Metodo_22");

    a = fopen("DATA22.TXT", "r");
    fscanf(a, "%d", &n);
    b = malloc(n * sizeof(int));
    for (int x = 0; x < n; x = x + 1) {
        fscanf(a, "%d", &b[x]);
    }
    fclose(a);

    printf("\nDados em arquivo:\n");
    for (int x = 0; x < n; x = x + 1) {
        printf("%2d\n", b[x]);
    }
    printf("\n");

    printf("%s\n", "Apertar ENTER para terminar.");
    getchar();
    return ;
}
		

/////////////////////////////////////////////////////////////////

// Method_23
struct s_array
{
  int  n;   // tamanho
  int *data;// referencia para espaco de armazenamento  
};

/*
  Funcao principal.
 */
void method_23(void) 
{
  // definir dados
  FILE *a = fopen("DATA23.TXT","r");
  struct s_array b;
  
  // mostrar mensagem  
  printf("%s\n","866053 - Metodo_23"); 

  // ler valores 
  a = fopen("DATA23.TXT","r");
  fscanf(a, "%d", &b.n);
  b.data = malloc(b.n * sizeof(int));
  for(int x = 0; x < b.n; x = x+1)
  {  fscanf(a, "%d", &b.data[x]);   }
  fclose(a);
  
  // mostrar valores 
  printf("\nDados guardados:\n");
  for(int x = 0; x < b.n; x = x+1)
  {  printf("%2d\n", b.data[x]);   }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return ;
}


	
/////////////////////////////////////////////////////////////////
// Method_24

// Estrutura para Array
typedef struct s_arrayA {
    int n;
    int *data;
} Array;

// Method_24
void method_24(void) {
    FILE *a = fopen("DATA24.TXT", "r");
    if (a == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    Array b;
    printf("866053 - Metodo_24\n");
    fscanf(a, "%d", &b.n);
    b.data = (int *)malloc(b.n * sizeof(int));
    
    if (b.data == NULL) {
        perror("Erro ao alocar memoria");
        fclose(a);
        return;
    }
    
    for (int x = 0; x < b.n; x++) {
        fscanf(a, "%d", &b.data[x]);
    }
    fclose(a);
    
    printf("\nDados guardados:\n");
    for (int x = 0; x < b.n; x++) {
        printf("%2d\n", b.data[x]);
    }
    printf("\nApertar ENTER para terminar.\n");
    free(b.data);
    getchar();
}

///////////////////////////////////////////////////////


// Method_25
void method_25(void) {
    FILE *a = fopen("DATA25.TXT", "r");
    if (a == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    Array *b = (Array *)malloc(sizeof(Array));
    if (b == NULL) {
        perror("Erro ao alocar memoria");
        fclose(a);
        return;
    }
    
    fscanf(a, "%d", &b->n);
    b->data = (int *)malloc(b->n * sizeof(int));
    
    if (b->data == NULL) {
        perror("Erro ao alocar memoria");
        free(b);
        fclose(a);
        return;
    }
    
    for (int x = 0; x < b->n; x++) {
        fscanf(a, "%d", &b->data[x]);
    }
    fclose(a);
    
    printf("\nDados guardados:\n");
    for (int x = 0; x < b->n; x++) {
        printf("%2d\n", b->data[x]);
    }
    
    free(b->data);
    free(b);
    printf("\nApertar ENTER para terminar.\n");
    getchar();
}


////////////////////////////////////////////////////////////////

// Method_26
void method_26(void) {
    FILE *a = fopen("DATA26.TXT", "r");
    if (a == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    Array *b = (Array *)malloc(sizeof(Array));
    if (b == NULL) {
        perror("Erro ao alocar memoria");
        fclose(a);
        return;
    }
    
    fscanf(a, "%d", &b->n);
    b->data = (int *)malloc(b->n * sizeof(int));
    
    if (b->data == NULL) {
        perror("Erro ao alocar memoria");
        free(b);
        fclose(a);
        return;
    }
    
    for (int x = 0; x < b->n; x++) {
        fscanf(a, "%d", &b->data[x]);
    }
    fclose(a);
    
    printf("\nDados guardados:\n");
    for (int x = 0; x < b->n; x++) {
        printf("%2d\n", b->data[x]);
    }
    
    free(b->data);
    free(b);
    printf("\nApertar ENTER para terminar.\n");
    getchar();
}
//////////////////////////////////////////////////////////////

// Method_27
typedef struct s_matrix {
    int rows;
    int columns;
    int **data;
} Matrix;

void method_27(void) {
    Matrix *a = (Matrix *)malloc(sizeof(Matrix));
    if (a == NULL) {
        perror("Erro ao alocar memoria");
        return;
    }
    
    a->rows = 2;
    a->columns = 3;
    a->data = (int **)malloc(a->rows * sizeof(int *));
    
    for (int x = 0; x < a->rows; x++) {
        a->data[x] = (int *)malloc(a->columns * sizeof(int));
        if (a->data[x] == NULL) {
            perror("Erro ao alocar memoria");
            return;
        }
    }
    
    for (int x = 0; x < a->rows; x++) {
        printf("\nDados para a linha %d:\n", x);
        for (int y = 0; y < a->columns; y++) {
            scanf("%d", &a->data[x][y]);
        }
    }
    
    printf("\nDados guardados:\n");
    for (int x = 0; x < a->rows; x++) {
        for (int y = 0; y < a->columns; y++) {
            printf("%2d\t", a->data[x][y]);
        }
        printf("\n");
    }
    
    for (int x = 0; x < a->rows; x++) {
        free(a->data[x]);
    }
    free(a->data);
    free(a);
    
    printf("\nApertar ENTER para terminar.\n");
    getchar();
}
////////////////////////////////////////////////////////////

// Method_28
void method_28(void) {
    char Semana_str[7][8] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
    printf("866053 - Metodo_28\n\nMostrar dias da semana:\n");
    for (int dia = 0; dia < 7; dia++) {
        printf("%d: %s\n", dia, Semana_str[dia]);
    }
    printf("\nApertar ENTER para terminar.\n");
    getchar();
}

//////////////////////////////////////////
// Method_29
void method_29(void) {
    method_28(); // Reaproveita a implementação do método 28
}


///////////////////////////////////////////////////////
// Method_30
void method_30(int argc, char **argv) {
    printf("866053 - Metodo_30\n\nQuantidade de argumentos: %d\n", argc);
    for (int x = 0; x < argc; x++) {
        printf("%d: %s\n", x, argv[x]);
    }
    printf("\nApertar ENTER para terminar.\n");
    getchar();
}

 
	


////////////////////////////////////////////////////////////

int main (int argc, char **argv)
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
		printf("%s\n", " 11 - Metodo 11");
	    printf("%s\n", " 12 - Metodo 12");
		printf("%s\n", " 13 - Metodo 13");
		printf("%s\n", " 14 - Metodo 14");
		printf("%s\n", " 15 - Metodo 15");
		printf("%s\n", " 16 - Metodo 16");
		printf("%s\n", " 17 - Metodo 17");
		printf("%s\n", " 18 - Metodo 18");
		printf("%s\n", " 19 - Metodo 19");
		printf("%s\n", " 20 - Metodo 20");
		printf("%s\n", " 21 - Metodo 21");
		printf("%s\n", " 22 - Metodo 22");
		printf("%s\n", " 23 - Metodo 23");
		printf("%s\n", " 24 - Metodo 24");
		printf("%s\n", " 25 - Metodo 25");
		printf("%s\n", " 26 - Metodo 26");
		printf("%s\n", " 27 - Metodo 27");
		printf("%s\n", " 28 - Metodo 28");
		printf("%s\n", " 29 - Metodo 29");
		printf("%s\n", " 30 - Metodo 30");
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
					case 11: method_11(); 
						break;
		            case 12: method_12(); 
						break;
		            case 13: method_13(); 
						break;
		            case 14: method_14(); 
						break;
		            case 15: method_15(); 
						break;
			        case 16: method_16();
						break;
		            case 17: method_17(); 
						break;
		            case 18: method_18(); 
						break;
		            case 19: method_19(); 
						break;
		            case 20: method_20(); 
						break;
		            case 21: method_21(); 
						break;
		            case 22: method_22(); 
						break;
		            case 23: method_23();
						break;
		            case 24: method_24(); 
						break;
		            case 25: method_25();
						break;
		            case 26: method_26();
						break;
		            case 27: method_27(); 
						break;
		            case 28: method_28(); 
						break;
		            case 29: method_29(); 
						break;
		            case 30: method_30(argc, argv);
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
Saida metodos : 
01 - ( OK )  - Direto para "Apertar ENTER".
02 - ( OK ) - voltando para opcoes.
03 - ( OK ) - Mostrando os dados corretamente
04 - ( OK ) - Mostrando os dados
05 - ( OK ) - Apresentando conjuncoes corretas.
06  -( OK ) - Saida correta
07 - ( OK ) - Apresentando resposta correta ( ex: entrada 5 = resposta : menor que 100)
08 - ( OK ) - Respostas desejadas.
09 - ( OK )
10 ( OK)
11 ( OK )
12 ( OK )
13 ( OK )
14 ( OK )
15 ( OK )
16 ( OK )
17 ( OK )
18 ( OK )
19 ( OK )
20 ( OK )
21 ( OK )
22 ( ERRO ) 
23 ( ERRO )
24 ( ERRO )
25 ( ERRO )
26 ( ERRO )
27 ( ERRO )
28 ( OK )
29 ( OK )
30 ( OK )

TODOS OS ERROS EM ARQUIVO, TENTEI RESOLVER MAS NAO SEI O QUE E
*/
	
	
	
	

