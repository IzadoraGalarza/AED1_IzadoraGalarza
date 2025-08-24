#include <iostream> //std::cout, std::cin, std::end1
#include <limits> //std::numeric_limits
#include<string> //cadeias de caracteres

void pause (std::string text)
{
	std:: string dummy;
	std::cin.clear();
	std:: cout<<std::endl <<text;
	std::cin.ignore();
	std::getline (std::cin, dummy);
	std::cout <<std::endl<<std::endl;
}


#include "myarray.hpp"
using namespace std;


void pararExe()
{
	
}

/**
Incluir métodos (1111) para
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores muito grandes.
Exemplo: valor = arranjo.randomIntGenerate ( inferior, superior );
*/
void exe1111 ()
{
	int n=0;
	int s=0;
	int i=0;
	cout<<"Entre com uma quantidade:" <<endl;
	cin>>n;
	cout<<"Entre com um valor inferior:" <<endl;
	cin>>i;
	cout<<"Entre com um valor superior:" <<endl;
	cin>>s;

	Array<int> int_array(n, 0);
    int_array.randomIntGenerate(i, s);
    int_array.fprint("DADOS.TXT");

	int_array.free();
	pause("Apertar ENTER para continuar.");
	
}

/**
Incluir uma função (1112) para
procurar o maior valor ímpar em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor ímpar, se houver, como referência inicial.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
maior = arranjo.searchFirstOdd ( );
*/ 
void exe1112 ()
{
	Array <int> int_array;
	int_array.fread("DADOS.TXT");
	int_array.print();
	int maior = int_array.searchFirstOdd();
	cout<<"O maior numero impar encontrado no arranjo foi:" << maior << endl;
	pause("Apertar ENTER para continuar.");

}

/**
Incluir uma função (1113) para
procurar o maior valor ímpar múltiplo de 3 em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor ímpar múltiplo de 3, se houver, como referência inicial.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
menor = arranjo.searchFirstOddx3 ( );
*/
void exe1113 ()
{
	Array <int> int_array;
	int_array.fread("DADOS.TXT");
	int_array.print();
	int maior = int_array.searchFirstOdd3();
	cout<<"O maior numero impar encontrado no arranjo foi:" << maior << endl;
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1114) para
somar todos os valores em um arranjo entre duas posições dadas.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
soma = arranjo.addInterval ( inicio, fim );
*/
void exe1114 ()
{
	Array <int> int_array;
	int inicial=0;
	int final=0;
	int_array.fread("DADOS.TXT");
	cout<<"Dê a posicao inicial e a posicao final para soma:"<<endl;
	cin>>inicial;
	cin>>final;
	int soma = int_array.addInterval(inicial, final);
	cout<<"A soma dos valores da posicao inicial ate a final e'"<<soma<<endl;
	pause("Apertar ENTER para continuar.");
}

/** 
Incluir uma função (1115) para
achar a média dos valores em um arranjo entre duas posições dadas.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
media = arranjo.averageInterval ( inicio, fim );
*/
void exe1115 ()
{
	Array <int> int_array;
	int inicial=0;
	int final=0;
	int_array.fread("DADOS.TXT");
	cout<<"Entre com valores para posicao inicial e final: "<<endl;
	cin>>inicial;
	cin>>final;
	double media = int_array.averageInterval(inicial, final);
	cout<<"A soma dos valores da posicao inicial ate a final e'"<<media<<endl;
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1116) para
verificar se todos os valores são positivos e maiores que 100 em um arranjo.
Para testar, ler o arquivo ("DADOS.TXT")
armazenar os dados em um arranjo.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
teste = arranjo.negatives ( );
*/
void exe1116 ()
{
	Array <int> int_array;
	int_array.fread("DADOS.TXT");
	bool resultado = int_array.negatives();
	if(resultado)
	{
	cout<<"Todos sao positivos e maior que 100"<<endl;
	}
	else
	{
	cout<<"Nem todos sao positivos e maior que 100"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

/**
 Incluir uma função (1117) para
dizer se está ordenado, ou não, em ordem decrescente.
DICA: Testar se não está desordenado, ou seja,
se existe algum valor que seja maior que o seguinte.
Não usar break !
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
teste = arranjo.isDecrescent ( );
*/

void exe1117 ()
{
	Array <int> int_array;
	int_array.fread("DADOS.TXT");
	bool resultado = int_array.isDecrescent();
	if(resultado)
	{
	cout<<"Arranjo esta em ordem descrecente"<<endl;
	}
	else
	{
	cout<<"Arranjo nao esta em ordem decrescente"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1118) para
dizer se determinado valor está presente em arranjo,
entre duas posições indicadas.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar se o valor procurado existe no arranjo.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
existe = arranjo.searchInterval ( procurado, inicio, fim );
*/
void exe1118 ()
{
	Array <int> int_array;
	int inicial=0;
	int final=0;
	int procurado =0;
	int_array.fread("DADOS.TXT");
	cout<<"Entre com valores para posicao inicial e final: "<<endl;
	cin>>inicial;
	cin>>final;
	cout<<"Entre com o valor procurado: "<<endl;
	cin>> procurado;
	bool result = int_array.searchInterval(procurado,inicial, final);
	if(result)
	{
	cout<<"Valor encontrado dentro das posicoes informadas"<<endl;
	}
	else
	{
	cout<<"Valor nao encontrado"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1119) para
escalar dados em arranjo, entre duas posições dadas,
multiplicando cada valor por uma constante.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para indicar a constante.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
novo = arranjo.scalar( constante, inicio, fim );
*/
void exe1119 ()
{
	Array <int> int_array;
	Array <int> int_array2;
	int inicial=0;
	int final=0;
	int constante =0;
	int_array.fread("DADOS.TXT");
	cout<<"Entre com valores para posicao inicial e final: "<<endl;
	cin>>inicial;
	cin>>final;
	cout<<"Entre com o valor para constante: "<<endl;
	cin>> constante;
	cout<<"Original"<<endl;
	int_array.print();
	cout<<endl;
	int_array.scalar(constante,inicial, final);
	int_array2 = int_array;
	cout<<"Modificada"<<endl;
	int_array.print();
	pause("Apertar ENTER para continuar.");
}

/**
Incluir um método (1120) para
colocar valores em arranjo em ordem decrescente,
mediante trocas de posições, até ficar totalmente ordenado.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo.
Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
arranjo.sortDown ( );
*/

void exe1120 ()
{
	Array<int> int_array;
    int_array.fread("DADOS.TXT"); // Lendo os valores do arquivo
    int_array.print();

    int_array.sortDown(); // Ordenando em ordem decrescente

    cout << "Arranjo ordenado em ordem decrescente:" << endl;
	int_array.print();

    pause("Apertar ENTER para continuar.");
}

void exe11E1()
{
    Array<int> array1;
	Array<int> array2;
    
    array1.fread("DADOS.TXT");
    array2.fread("DADOS2.TXT");
	
    if (array1 != array2) 
	{
        cout << "Os arranjos são diferentes em pelo menos uma posição." << endl;
    }
	else 
	{
        cout << "Os arranjos são iguais." << endl;
    }

    pause("Apertar ENTER para continuar.");
}


void exe11E2() 
{
    Array<int> array1;
	Array <int> array2;
    
    array1.fread("DADOS.TXT");
    array2.fread("DADOS2.TXT");

    Array<int> diferenca = array1 - array2;
    diferenca.print();

    pause("Apertar ENTER para continuar.");
}


int main ( int argc, char** argv )
{
	 int x = 0; 
	do
	 {
		 // identificar
		 cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
		 cout << "Opcoes " << endl;
		 cout << " 0 - parar " << endl;
		 cout << " 1 - " << endl;
		 cout << " 2 - " << endl;
		 cout << " 3 - " << endl;
		 cout << " 4 - " << endl;
		 cout << " 5 - " << endl;
		 cout << " 6 - " << endl;
		 cout << " 7 - " << endl;
		 cout << " 8 - " <<endl;
		 cout << " 9 - " << endl;
		 cout << "10 - " << endl;
		 cout << "11 - " << endl;
		 cout << "12 - " << endl;

		 cout << endl << "Entrar com uma opcao: ";
		 cin >> x;
		 
		 switch ( x )
		 {
		 case 0: pararExe ( ); break;
		 case 1: exe1111 ( ); break;
		 case 2: exe1112 ( ); break;
		 case 3: exe1113 ( ); break;
		 case 4: exe1114 ( ); break;
		 case 5: exe1115 ( ); break;
		 case 6: exe1116 ( ); break;
		 case 7: exe1117 ( ); break;
		 case 8: exe1118 ( ); break;
		 case 9: exe1119 ( ); break;
		 case 10: exe1120 ( ); break;
		 case 11: exe11E1 ( );break;
		 case 12: exe11E2 ( );break;
		 default:
		 cout << endl << "ERRO: Valor invalido." << endl;
		 } 
	 }
	 while ( x != 0 );
	 pause ( "Apertar ENTER para terminar" );
	 return ( 0 );
}
