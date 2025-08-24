/** 
/** 
Aluna: Izadora Galarza Alves
Matricula: 866053
Prof: Theldo Cruz
	*/
#include<iostream>
using std::cin; //pra entrada
using std::cout; //para saida
using std::endl; // mudar de linha

#include<iomanip>
using std::setw; // para definir espacamento

#include<string>
using std::string; // ara cadeia de caractereres

#include<fstream>
using std:: ofstream; // gravar arquivo
using std:: ifstream; //ler arquivo


//______________________________________________ definicoes globais //

void pause (std::string text)
{
	std:: string dummy;
	std::cin.clear();
	std:: cout<<std::endl <<text;
	std::cin.ignore();
	std::getline (std::cin, dummy);
	std::cout <<std::endl<<std::endl;
}

//______________________________________________ classe/pacotes
using namespace std;
#include "mymatrix.hpp" //usando e add as coisas nela


void exe1200()
{
}


/**
Incluir métodos (1211) para
- ler a quantidade de elementos ( MxN ) a serem gerados; OK
- gerar essa quantidade ( MxN ) de valores aleatórios
- dentro do intervalo e armazená-los em matriz;
- gravá-los, um por linha, em um arquivo ("DADOS.TXT").
-  primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
- DICA: Usar a função rand( ), mas tentar limitar valores ao intervalo [1:100].
Exemplo: matrix.randomIntGenerate ( inferior, superior );
	*/
void exe1211()
{
	int m=0; // linhas
	int n=0; //colunas
	int sup=0; // superior
	int inf =0; //inferior
	cout << "Exericicio1201 - Gerar valores aleatorios"<< endl;
	do 
	{
    cout << "Digite a quantidade de linhas (M > 0): ";
    cin >> m;
	} while (m <= 0);

	do 
	{
    cout << "Digite a quantidade de colunas (N > 0): ";
    cin >> n;
	} while (n <= 0);
	
	do {
    cout << "Digite o limite inferior: ";
    cin >> inf;
    cout << "Digite o limite superior: ";
    cin >> sup;

    if (inf > sup) {
        cout << "Erro: O limite inferior deve ser menor ou igual ao superior! Tente novamente.\n";
    }
		
	} while (inf > sup);

		Matrix <int> int_matrix(m,n,0);
		int_matrix.randomIntGenerate(inf, sup);
		int_matrix.print();
		int_matrix.fprint("DADOS.TXT");

	pause("Apertar ENTER para continuar");
}

/**
Incluir uma função (1212) para
- escalar uma matriz, multiplicando todos os seus valores por uma constante.
- Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre a matriz com os valores lidos.
DICA: Usar o modelo de matriz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix2 = matrix1.scalar ( 3 ); // multiplicar cada valor pelo argumento
	*/
void exe1212()
{
	Matrix <int> int_matrix1(1,1,0);
	Matrix <int> int_matrix2 (1,1,0);
	int c=0;
	cout<<"entre com o valor de uma constante"<<endl;
	cin>>c;
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	cout << "Matrix original" << endl;
	int_matrix1.print();

	int_matrix2 = int_matrix1.scalar(c);
	cout<<"Matrix modificada"<<endl;
	int_matrix2.print();
	pause("Apertar ENTER para continuar.");
	
}


/**
Incluir uma função (1213) para
testar se uma matriz é a identidade.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre a matriz com os valores lidos.
DICA: Usar o modelo de matriz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
teste = matrix1.identidade ( );
	*/


void exe1213()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int_matrix1.print();
	if (int_matrix1.identidade()) 
	{
    cout << "A matrix e' identidade!" << endl;
	}
	else 
	{
    cout << "A matrix NAO e' identidade." << endl;
	}
	pause("Apertar ENTER para continuar");
}

/**
Incluir em um programa (Exemplo1214) um operador para
testar a igualdade de duas matrizes.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos.
DICA: Usar o modelo de matrz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix2 = readMatrixFromFile ( "DADOS2.TXT" );
teste = (matrix1 == matrix2);
	*/
void exe1214()
{
	Matrix <int> int_matrix1(1,1,0);
	Matrix <int> int_matrix2(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int_matrix2.readMatrixFromFile("DADOS2.TXT");
	cout<<"Matrix1"<<endl;
	int_matrix1.print();

	cout<<"Matrix2"<<endl;
	int_matrix2.print();

	if(int_matrix1 == int_matrix2)
	{
		cout<<"Ambas as matrizes sao iguais"<<endl;
	}
	else
	{
		cout<<"Matrizes sao diferentes"<<endl;
	}

	pause("Apertar ENTER para continuar");
	
}


/**
Incluir uma função (1215) para
somar duas matrizes e mostrar o resultado.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos.
DICA: Usar o modelo de matrz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix2 = readMatrixFromFile ( "DADOS2.TXT" );
soma = matrix1.add ( matrix2 );
	*/

void exe1215()
{
	Matrix<int> int_matrix1(1,1,0);
    Matrix<int> int_matrix2(1,1,0);

    int_matrix1.readMatrixFromFile("DADOS.TXT");
    int_matrix2.readMatrixFromFile("DADOS2.TXT");

    cout << "Matrix1:" << endl;
    int_matrix1.print();
    cout << "Matrix2:" << endl;
    int_matrix2.print();

    Matrix<int> soma = int_matrix1.add(int_matrix2);
    cout << "Matrix resultante da soma:" << endl;
    soma.print();	

	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1216) para
operar duas linhas da matriz, guardando no lugar da primeira,
as somas de cada elemento da primeira linha com o respectivo da segunda linha
multiplicado por uma constante.
DICA: Usar o modelo de matrz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix1.addRows ( 0, 1, (-1) );

obs: tive uma dificuldade em entender essa questao, entao pesquisei, por isso n sei se a resposta e essa
	*/
void exe1216()
{
	Matrix <int> int_matrix1 (1,1,0);
	int m=0;
	int n=0;
	int c=0;
	cout<<"Entre com as linhas desejadas, respectivamente"<<endl;
	cin>>m; //primeira linha
	cin>>n; //segunda linha
	cin>>c; //constante
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int_matrix1.addRows(m,n,(c));

	int_matrix1.print();
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1217) para
operar duas linhas da matriz, guardando no lugar da primeira,
as diferenças de cada elemento da primeira linha com o respectivo da segunda linha
multiplicado por uma constante.
DICA: Usar o modelo de matrz proposto nos exemplos.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix1.subtractRows ( 0, 1, (2) );
	*/
void exe1217()
{
	Matrix <int> int_matrix1 (1,1,0);
	int m=0;
	int n=0;
	int c=0;
	cout<<"Entre com as linhas desejadas, respectivamente"<<endl;
	cin>>m; //primeira linha
	cin>>n; //segunda linha
	cin>>c; //constante
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int_matrix1.subtractRows(m,n,(c));

	int_matrix1.print();
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1218) para
dizer em qual linha da matriz se encontra certo valor, se houver.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
teste = matrix1.searchRows ( procurado );
	*/
void exe1218()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int n=0;
	int posicao=0;
	cout<<"Entre com o valor procurado"<<endl;
	cin>>n;
	posicao = int_matrix1.searchRows(n);
	if(posicao >= 0)
	{
		cout<<"Valor encontrado na linha: "<<posicao<<endl;
	}
	else
	{
		cout<<"Valor nao encontrado em nenhuma linha"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1219) para
dizer em qual coluna da matriz se encontra certo valor, se houver.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
teste = matrix1.searchColumns ( procurado );
	*/
void exe1219()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	int n=0;
	int posicao=0;
	cout<<"Entre com o valor procurado"<<endl;
	cin>>n;
	posicao = int_matrix1.searchColumns(n);
	int_matrix1.print();
	if(posicao >= 0)
	{
		cout<<"Valor encontrado na coluna: "<<posicao<<endl;
	}
	else
	{
		cout<<"Valor nao encontrado em nenhuma coluna"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

/**
Incluir uma função (1220) para
transpor os dados em uma matriz.
Exemplo: matrix1 = readMatrixFromFile ( "DADOS1.TXT" );
matrix1.transpose ( );
	*/
void exe1220()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS.TXT");
	cout << "Matriz original:" << endl;
	int_matrix1.print();

	int_matrix1.transpose();  // Transpõe a matriz

	cout << "Matriz transposta:" << endl;
	int_matrix1.print();
}

void exe12E1()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS2.TXT");
	int_matrix1.print();
	if(int_matrix1.sequencial())
	{
		cout<<"Matrix e sequencial"<<endl;
	}
	else
	{
		cout<<"Matrix nao e sequencial"<<endl;
	}
	pause("Apertar ENTER para continuar.");
}

void exe12E2()
{
	Matrix <int> int_matrix1(1,1,0);
	int_matrix1.readMatrixFromFile("DADOS2.TXT");
	if(int_matrix1.sequencial())
	{
		cout<<"Matrix e sequencial"<<endl;
		cout<<"Matrix original"<<endl;
	int_matrix1.print();
	int_matrix1.inverter();
	cout<<"Matrix modificada"<<endl;
	int_matrix1.print();
	}
	else
	{
		cout<<"Matrix nao e sequencial"<<endl;
	}
	
	pause("Apertar ENTER para continuar");
}
	

int main ( int argc, char** argv )
{
	int x = 0; 
	do
	 {
		 // identificar
		 cout << "Exercicios 1200 - Programa - v0.0\n " << endl;
		 cout << "Opcoes " << endl;
		 cout << " 0 - parar " << endl;
		 cout << " 1 - Gerar valores aleatorios e gravar em arquivo " << endl;
		 cout << " 2 - Constante" << endl;
		 cout << " 3 - Identidade" << endl;
		 cout << " 4 - Igualdade" << endl;
		 cout << " 5 - Soma" << endl;
		 cout << " 6 - troca e soma" << endl;
		 cout << " 7 -troca e subtracao" << endl;
		 cout << " 8 - Procurar valor: Linha" <<endl;
		 cout << " 9 - Procurar valor : Coluna" << endl;
		 cout << "10 - Transpor" << endl;
		 cout<< "11 - sequencia - EXTRA"<<endl;
		 cout<< "12 - Inverter - EXTRA"<<endl;

		 cout << endl << "Entrar com uma opcao: ";
		 cin >> x;
		 
		 switch ( x )
		 {
		 case 0: exe1200 ( ); break;
		 case 1: exe1211 ( ); break;
		 case 2: exe1212 ( ); break;
		 case 3: exe1213 ( ); break;
		 case 4: exe1214 ( ); break;
		 case 5: exe1215 ( ); break;
		 case 6: exe1216 ( ); break;
		 case 7: exe1217 ( ); break;
		 case 8: exe1218 ( ); break;
		 case 9: exe1219 ( ); break;
		 case 10: exe1220 ( ); break;
		case 11: exe12E1 ( ); break;
			 case 12: exe12E2 ( ); break;
		 default:
		 cout << endl << "ERRO: Valor invalido." << endl;
		 } 
	}while ( x != 0 );
	 pause ( "Apertar ENTER para terminar" );
	 return ( 0 );
}
