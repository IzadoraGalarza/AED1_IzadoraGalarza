/** 
/** 
Aluna: Izadora Galarza Alves
Matricula: 866053
Prof: Theldo Cruz
	*/

#include <iostream> //std::cout, std::cin, std::end1
#include <limits> //std::numeric_limits
#include<string> //cadeias de caracteres

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
#include "mymatrix.hpp"


void exemplo1200()
{
	//nada
}

void exemplo1201 ()
{
	Matrix <int> int_matrix (2,2,0);
	int_matrix.set(0,0,1);      int_matrix.set(0,1,2);
	int_matrix.set(1,0,3);      int_matrix.set(1,1,4);

	cout<<"\nExemplo1201 - v1.0\n"<<endl;

	int_matrix.print();

	pause("Apertar ENTER para continuar");
}

void exemplo1202 ()
{
	Matrix<int> matrix (2,2,0);

	cout<<endl<<"Exemplo1202"<<endl;

	matrix.read();
	matrix.print();
	pause("Apertar ENTER para continuar");
}

void exemplo1203 ()
{
	Matrix <int> matrix (2,2,0);
	cout << endl << "Exemplo1203 - v1.0" << endl;
	matrix.read();
	matrix.print();
	matrix.fprint("MATRIX1.TXT");
	pause("Apertar ENTER para continuar");
	
}

void exemplo1204 ()
{
	Matrix <int> matrix (1,1,0);
	cout << endl << "Exemplo1204 - v1.0" << endl;
	matrix.fread("MATRIX1.TXT");
	matrix.print();
	pause("Apertar ENTER para continuar");
}

void exemplo1205 ()
{
	Matrix <int> int_matrix1 (1,1,0);
	Matrix <int> int_matrix2 (1,1,0);
	cout << endl << "Exemplo1205 - v1.0" << endl;

	int_matrix1.fread("MATRIX1.TXT");
	cout << "\nOriginal\n" << endl;
	int_matrix1.print();
	int_matrix2 = int_matrix1;

	cout << "\nCopia\n" << endl;
	int_matrix2.print();
	pause("Apertar ENTER para continuar.");
	
}

void exemplo1206 ()
{
	Matrix <int> int_matrix (2,2,0);

	int_matrix.set(0,0,0); int_matrix.set(0,1,0);
	int_matrix.set(1,0,0); int_matrix.set(1,1,0);
	cout << endl << "Exemplo1206 - v1.0" << endl;

	int_matrix.print();

	cout << "Zeros ="<< int_matrix.isZeros()<< endl;

	int_matrix.fread("MATRIX1.TXT");
	int_matrix.print();
	cout << "Zeros ="<< int_matrix.isZeros()<< endl;
	pause("Apertar ENTER para continuar.");
	
}

void exemplo1207 ()
{
	Matrix <int> int_matrix1 (1,1,0);
	Matrix <int> int_matrix2 (1,1,0);
	cout << endl << "Exemplo1207 - v1.0" << endl;
	int_matrix1.fread("MATRIX1.TXT");

	cout << "\nMatrix_1\n";
	int_matrix1.print ( );

	int_matrix2 = int_matrix1;
	cout << "\nMatrix_2\n";
	int_matrix2.print ( );

	cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
	int_matrix2.set ( 0, 0, (-1) );

	cout << "\nMatrix_1\n";
	int_matrix1.print ( );

	cout << "\nMatrix_2\n";
	int_matrix2.print ( );

	cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;

	pause ( "Apertar ENTER para continuar" );
}

void exemplo1208 ()
{
	Matrix <int> int_matrix1 ( 1, 1, 0 );
	Matrix <int> int_matrix2 ( 1, 1, 0 );
	Matrix <int> int_matrix3 ( 1, 1, 0 );

	cout << endl << "Exemplo1208 - v0.0" << endl;

	int_matrix1.fread ( "MATRIX1.TXT" );

	cout << "\nMatrix_1\n";
	int_matrix1.print ( );

	int_matrix2 = int_matrix1;

	cout << "\nMatrix_2\n";
	int_matrix2.print ( );

	int_matrix3 = int_matrix1 - int_matrix2;
	cout << "\nMatrix_3\n";
	int_matrix3.print ( );
	pause ( "Apertar ENTER para continuar" );
}

void exemplo1209 ()
{
	Matrix <int> int_matrix1 ( 2, 2, 0 );
	int_matrix1.set ( 0, 0, 1 );
	int_matrix1.set ( 0, 1, 0 );
	int_matrix1.set ( 1, 0, 0 );
	int_matrix1.set ( 1, 1, 1 );
	Matrix <int> int_matrix2 ( 1, 1, 0 );
	Matrix <int> int_matrix3 ( 1, 1, 0 );

	cout << endl << "Exemplo1209 - v0.0" << endl;
	int_matrix2.fread ( "MATRIX1.TXT" );

	cout << "\nMatrix_1\n";
	int_matrix1.print ( );

	cout << "\nMatrix_2\n";
	int_matrix2.print ( );

	int_matrix3 = int_matrix1 * int_matrix2;
	cout << "\nMatrix_3\n";
	int_matrix3.print ( );
	pause ( "Apertar ENTER para continuar" );
}

void exemplo1210 ()
{
	Matrix <int> int_matrix ( 3, 3, 0 );
	int x = 0;
	int y = 0;

	cout << endl << "Exemplo1210 - v0.0" << endl;
	int_matrix.fread ( "MATRIX1.TXT" );
	cout << "\nMatrix\n";
	int_matrix.print ( );

	for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 )
	{
		for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
		{
			int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
		} 
	} 
	cout << "\nMatrix\n";
	int_matrix.print ( );
	pause ( "Apertar ENTER para continuar" );
}


int main ( int argc, char** argv )
{
	int x = 0; 
	do
	 {
		 // identificar
		 cout << "EXEMPLO1201 - Programa - v0.0\n " << endl;
		 cout << "Opcoes " << endl;
		 cout << " 0 - parar " << endl;
		 cout << " 1 - Mostrar matrix basica " << endl;
		 cout << " 2 - Entrada de dados para formar matrix" << endl;
		 cout << " 3 - Gravar em arquivo" << endl;
		 cout << " 4 - Le do arquivo" << endl;
		 cout << " 5 - Le do arquivo e mostra uma copia" << endl;
		 cout << " 6 - Se tem 0" << endl;
		 cout << " 7 - Diferenca" << endl;
		 cout << " 8 - Subtracao" <<endl;
		 cout << " 9 - * " << endl;
		 cout << "10 - negativo" << endl;

		 cout << endl << "Entrar com uma opcao: ";
		 cin >> x;
		 
		 switch ( x )
		 {
		 case 0: exemplo1200 ( ); break;
		 case 1: exemplo1201 ( ); break;
		 case 2: exemplo1202 ( ); break;
		 case 3: exemplo1203 ( ); break;
		 case 4: exemplo1204 ( ); break;
		 case 5: exemplo1205 ( ); break;
		 case 6: exemplo1206 ( ); break;
		 case 7: exemplo1207 ( ); break;
		 case 8: exemplo1208 ( ); break;
		 case 9: exemplo1209 ( ); break;
		 case 10: exemplo1210 ( ); break;
		 default:
		 cout << endl << "ERRO: Valor invalido." << endl;
		 } 
	}while ( x != 0 );
	 pause ( "Apertar ENTER para terminar" );
	 return ( 0 );
}
