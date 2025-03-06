// 866053_Izadora Galarza Alves
// Exemplo_0001

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

//calcular e mostrar a area de outro quadrado com o lado 3x maior
void method_01 (void)
{
	int qA =0;
	int qB =0;
	int area3 = 0;

	printf("%s\n","866053_AED1 - Exercicio0111");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s","Escolha um valor inteiro para o lado do quadrado: ");
	scanf("%d",&qA);
	printf("%s %d\n","O lado do quadrado A e'= ", qA);
	
	qB =3 * qA;
	area3= qB * qB;
	printf("%s %d","A area do quadrado que tem tres vezes o lado do quadrado A =",area3 );
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_02 (void)
{
	int qA =0;
	int qB =0;
	int area = 0;
	int perimetro=0;

	printf("%s\n","866053_AED1 - Exercicio0112");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s","Escolha um valor inteiro para o lado do quadrado: ");
	scanf("%d",&qA);
	printf("%s %d\n","O lado do quadrado A e'=", qA);
	
	qB = qA/2;
	area= qB * qB;
	perimetro = 2*qB + 2*qB;
	printf("%s %d\n","A area do quadrado que tem metade o lado do quadrado A =",area );
	printf("%s %d","O perimetro do quadrado que tem metade do lado do quadrado A =",perimetro );
	
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_03 (void)
{
	int x =0;
	int y =0;
	double a=0.0;
	printf("%s\n","866053_AED1 - Exercicio 0113");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");
	printf("%s","Entre com um valor inteiro para a altura:");
	scanf("%d",&x);

	printf("%s","Entre com um valor inteiro para o comprimento:");
	scanf("%d",&y);

	x= x*2;
	y= y*2;

	a = x*y;

	printf("%s %lf\n","A area com o dobro dos valor de entrada = ", a);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_04 (void)
{
	int x =0;
	int y =0;
	double a = 0.0;
	double lado1 = 0.0;
	double lado2 = 0.0;
	double p = 0.0;
	printf("%s\n","866053_AED1 - Exercicio 0114");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s","Entre com um valor inteiro para a altura:");
	scanf("%d",&x);

	printf("%s","Entre com um valor inteiro para o comprimento:");
	scanf("%d",&y);

	lado1 = (double)x/4;
	lado2 = (double)y/4;

	a = lado1 * lado2;
	p = 2*lado1 + 2*lado2;
	

	printf("%s %lf\n","A area com um quarto dos valor de entrada = ", a);
	printf("%s %lf\n","O perimetro com um quarto dos valor de entrada = ", p);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_05 (void)
{
	int h=0;
	int b=0;
	int area=0;
	int dobro=0;
	
	printf("%s\n","866053_AED1 - Exercicio 0115");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s","Entre com um valor inteiro para a altura:");
	scanf("%d",&h);

	printf("%s","Entre com um valor inteiro para a base:");
	scanf("%d",&b);

	dobro = h *2;
	area=(b*dobro)/2;

	printf("%s %d\n","A area do triangulo com o dobro da altura e =", area);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_06 (void)
{
	double l = 0.0;
    double perimetro = 0.0;
    double reducao = 0.0;
    double h = 0.0; 
	double area = 0.0;
    const double raiz = sqrt(3.0) / 2.0;

    printf("866053_AED1 - Exercicio 0115\n");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

    printf("Entre com um valor inteiro para o lado: ");
    scanf("%lf", &l);

    reducao = l / 3;
    h = reducao * raiz;
    area = (pow(reducao, 2) * raiz) / 2.0;
    perimetro = reducao * 3;

    printf("A altura com um terço do lado é: %.2lf\n", h);
    printf("A área com um terço do lado é: %.2lf\n", area);
    printf("O perímetro com um terço do lado é: %lf\n", perimetro);

    printf("\nApertar ENTER para terminar.");
    getchar();
	return;
}
void method_07 (void)
{
	double lado= 0.0;
	double volume=0.0;
	printf("%s\n","866053_AED1 - Exercicio_0117");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para o lado do cubo:");
	scanf("%lf",&lado);

	lado = lado*4;
	volume=pow(lado,3);
	printf("%s %lf","O volume do cubo quatro vezes maior e'=", volume);
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_08 (void)
{
	double c=0.0;
	double l=0.0;
	double h=0.0;
	double v=0.0;

	
	printf("%s\n","866053_AED1 - Exercicio0118");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para o comprimento:");
	scanf("%lf",&c);
	printf("%s\n","Entre com um valor para real para a largura:");
	scanf("%lf",&l);
	printf("%s\n","Entre com um valor para real para a altura:");
	scanf("%lf",&h);
	v=((c*5)*(l*5)*(h*5));
	printf("%s %lf\n","O volume do solido 5x maior e'=",v);
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_09 (void)
{

	double raio=0.0;
	double raio_att=0.0;
	double area=0.0;
	printf("%s\n","866053_AED1 - Exercicio0119");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para o raio:");
	scanf("%lf",&raio);
	raio_att= raio*4;
	area= (M_PI * pow(raio_att,2))/2;
	printf("%s %lf\n","A area do semicirculo com o raio 4x maior e'=",area);
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_10 (void)
{
	double raio=0.0;
	double raio_att=0.0;
	double v=0.0;
	printf("%s\n","866053_AED1 - Exercicio0120");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para o raio:");
	scanf("%lf",&raio);
	raio_att= raio*(5.0/8.0);
	v= ((4.0/3.0) * M_PI * pow(raio_att,3));
	printf("%s %lf\n","O volume da esfera e'=",v);
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}

void method_11 (void)
{
	double cir=0.0;
	double raio=0.0;
	double novaA=0.0;
	printf("%s\n","866053_AED1 - Exercicio0120");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para a circunferencia:");
	scanf("%lf",&cir);
	novaA= cir*7;
	raio = sqrt(novaA / M_PI);


	printf("%s %lf\n","O volume da esfera e'=",raio);
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}

void method_12 (void)
{
	double volume=0.0;
	double raio=0.0;
	double novaV=0.0;
	double area= 0.0;
	printf("%s\n","866053_AED1 - Exercicio0120");
	printf("%s\n","Autora: Izadora Galarza Alves");
	printf("\n");

	printf("%s\n","Entre com um valor para real para o volume:");
	scanf("%lf",&volume);

	novaV= volume * (3.0/5.0);
	raio = cbrt((3.0* novaV)/(4.0 * M_PI));
	 area = 4.0 * M_PI * pow(raio, 2);

	 printf("O raio da esfera e'= %lf\n", raio);
    printf("A area da superfície da esfera e'= %lf\n", area);

	getchar();
	return;
}



int main ()
{
	int opcao=0;

	do
		{
	    printf("\n%s\n","Opcoes:");
		printf("%s\n"," 0 - Terminar");
		printf("%s\n"," 1 - Exercicio 1");
	    printf("%s\n"," 2 - Exercicio 2");
		printf("%s\n"," 3 - Exercicio 3");
	    printf("%s\n"," 4 - Exercicio 4");
		printf("%s\n"," 5 - Exercicio 5");
		printf("%s\n"," 6 - Exercicio 6");
		printf("%s\n"," 7 - Exercicio 7");
		printf("%s\n"," 8 - Exercicio 8");
		printf("%s\n"," 9 - Exercicio 9");
		printf("%s\n"," 10 - Exercicio10");
		printf("%s\n"," 11 - Exercicio Extra 1");
		printf("%s\n"," 12 - Exercicio Extra 2");
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
				
				
					default: printf("\nERRO: Opcao invalida.\n");
                             break;
		        }
	      }
		  while (opcao!=0);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return(0);
}
	
