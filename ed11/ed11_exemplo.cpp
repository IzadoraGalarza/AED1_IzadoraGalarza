/*
 Exemplo1100 - v0.0. - 19 / 05 / 2005
 Author: Izadora Galarza Alves
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

#include "myarray.hpp"
using namespace std;

//_______________________________________________ metodos

/** 
	Exemplo1000 - nao faz nada
*/

void exemplos1100 ()
{
	//nada
}


/** 
	Exemplo1101
*/

void exemplos_1101 ()
{
	Array <int> int_array (5,0);

	int_array.set(0,1);
	int_array.set(1,2);
	int_array.set(2,3);
	int_array.set(3,4);
	int_array.set(4,5);

	//identificar
	cout <<"\nExemplo_1101 - v0.0\n" <<endl;
	
	//mostrar dados
	int_array.print();

	//reciclar espaco
	int_array.free();

	//encerrar
	pause("Apertar ENTER para continuar");
}

void exemplos1102 ()

{
	Array <int> int_array (5,0);
	cout<<endl<<"Exemplo1102"<<endl;
	int_array.read();
	int_array.print();
	int_array.free();
	pause("Apertar ENTER para continuar");
}


void exemplos1103 ()
{
	Array <int> int_array(5,0);
	cout<<endl<<"Exemplo1103"<<endl;

	int_array.read();
	int_array.fprint ("INT_ARRAY1.TXT");
	int_array.free();
	pause("Apertar ENTER para continuar");
}

void exemplos1104 ()
{
	Array <int> int_array(5,0);
	cout<<endl<<"Exemplo1104"<<endl;
	int_array.fread("INT_ARRAY1.TXT");
	int_array.print();
	int_array.free();
	pause("Apertar ENTER para continuar");
}

	
void exemplos1105 ()
{
	int other[] = { 1,2,3,4,5};
	Array <int> int_array (5,other);
	cout<<endl<<"Exemplo1105"<<endl;

	cout<<"\nCopia\n"<<endl;
	int_array.print();
	int_array.free();
	pause("Apertar ENTER para continuar");
}

	
void exemplos1106 ()
{
	Array <int> int_array1 (1,0);
	cout<<endl<<"Exemplo1106"<<endl;
	int_array1.fread ("INT_ARRAY1.TXT");
	cout<<endl<<"\nOriginal\n"<<endl;
	int_array1.print();
	
	Array <int> int_array2 (int_array1);
	cout<<"\nCopia\n"<<endl;
	int_array2.print();

	int_array1.free();
	int_array2.free();
	pause("Apertar ENTER para continuar");
}

	
void exemplos1107 ()
{
	Array <int> int_array1(1,0);
	Array <int> int_array2 (1,0);
	cout<<endl<<"Exemplo1107"<<endl;

	int_array1.fread ("INT_ARRAY1.TXT");
	cout<<"\nOriginal\n"<<endl;
	int_array1.print();

	int_array2 = int_array1;
	cout<<"\nCopia\n"<<endl;
	int_array2.print();

	int_array1.free();
	int_array2.free();
	pause("Apertar ENTER para continuar");
}

	
void exemplos1108 ()
{
	int other[] = {1,2,3};
	Array <int> int_array1(3,other);
	Array <int> int_array2(3,other);
	int x;
	cout<<endl<<"Exemplo1108"<<endl;
	cout<<endl;
	cout<<"Array1";
	int_array1.print();

	cout<<"Array2";
	int_array2.print();

	cout<<"Igualdade = "<< (int_array1==int_array2) <<endl;
	int_array2.set(0,(-1));

	cout<<endl;
	cout<<"Array1"<<endl;
	int_array1.print();

	cout<<"Array2"<<endl;
	int_array2.print();

	cout<<"Igualdade="<<(int_array1==int_array2)<<endl;

	int_array1.free();
	int_array2.free();
	pause("Apertar ENTER para continuar");
}

	
void exemplos1109 ()
{
	Array <int> int_array1 (1,0);
	Array <int> int_array2 (1,0);
	Array <int> int_array3 (1,0);
	cout<<endl<<"Exemplo1109"<<endl;

	int_array1.fread("INT_ARRAY1.TXT");
	int_array2= int_array1;
	int_array3= int_array2 + int_array2;
	cout<<"Original" <<endl;
	int_array1.print();

	cout<<"Copia"<<endl;
	int_array2.print();

	cout<<"Soma"<<endl;
	int_array3.print();

	int_array1.free();
	int_array2.free();
	int_array3.free();
	
	pause("Apertar ENTER para continuar");
}

	
void exemplos1110 ()
{
	int other[] = {1,2,3,4,5};
	Array <int> int_array(5,other);
	int x;
	cout<<endl<<"Exemplo1110"<<endl;

	cout<<"\nAcesso externo"<<endl;
	for(x=0; x <int_array.getLength(); x =x +1)
	{
		cout<<endl<<setw(3) << x<<":"<<int_array[x];
	}
	cout<<endl<<"\nFora dos limites:";
	cout << endl << "[-1]: " << int_array.get(-1) << endl;
	cout << endl << "[" << int_array.getLength( ) << "]: "
				 << int_array [ int_array.getLength( ) ] << endl;

	int_array.free();
	pause("Apertar ENTER para continuar");
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
		 cout << " 1 - mostrar dados inteiros em arranjo " << endl;
		 cout << " 2 - escreveer dados inteiros em um arranjo " << endl;
		 cout << " 3 - Gravar em arquivo valor escrito" << endl;
		 cout << " 4 - Le e mostra valores de um arquivo" << endl;
		 cout << " 5 - Copia valor dentro de arranjo" << endl;
		 cout << " 6 - Mostra o original e a copia de um arranjo dentro de arquivo" << endl;
		 cout << " 7 - Original e copia" << endl;
		 cout << " 8 - Compara(igualdade) e muda array2" <<endl;
		 cout << " 9 - Original + copia = soma" << endl;
		 cout << "10 - " << endl;

		 cout << endl << "Entrar com uma opcao: ";
		 cin >> x;
		 
		 switch ( x )
		 {
		 case 0: exemplos1100 ( ); break;
		 case 1: exemplos_1101 ( ); break;
		 case 2: exemplos1102 ( ); break;
		 case 3: exemplos1103 ( ); break;
		 case 4: exemplos1104 ( ); break;
		 case 5: exemplos1105 ( ); break;
		 case 6: exemplos1106 ( ); break;
		 case 7: exemplos1107 ( ); break;
		 case 8: exemplos1108 ( ); break;
		 case 9: exemplos1109 ( ); break;
		 case 10: exemplos1110 ( ); break;
		 default:
		 cout << endl << "ERRO: Valor invalido." << endl;
		 } 
	 }
	 while ( x != 0 );
	 pause ( "Apertar ENTER para terminar" );
	 return ( 0 );
}
