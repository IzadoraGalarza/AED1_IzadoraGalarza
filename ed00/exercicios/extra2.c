// 866053_Izadora Galarza Alves
// Exemplo_0001

#include <stdio.h>
#include<stdlib.h>

void method_01 (void)
{
	printf("%s\n","866053_AED1 - Metodo 1");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_02 (void)
{
	printf("%s\n","866053_AED1 - Metodo 2");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_03 (void)
{
	printf("%s\n","866053_AED1 - Metodo 3");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_04 (void)
{
	printf("%s\n","866053_AED1 - Metodo 4");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_05 (void)
{
	printf("%s\n","866053_AED1 - Metodo 5");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_06 (void)
{
	printf("%s\n","866053_AED1 - Metodo 6");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_07 (void)
{
	printf("%s\n","866053_AED1 - Metodo 7");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_08 (void)
{
	printf("%s\n","866053_AED1 - Metodo 8");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_09 (void)
{
	printf("%s\n","866053_AED1 - Metodo 9");
	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return;
}
void method_10 (void)
{
	printf("%s\n","866053_AED1 - Metodo 10");
	printf("\n\nApertar ENTER para terminar.");
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
				
					default: printf("\nERRO: Opcao invalida.\n");
                             break;
		        }
	      }
		  while (opcao!=0);

	printf("\n\nApertar ENTER para terminar.");
	getchar();
	return(0);
}
	
