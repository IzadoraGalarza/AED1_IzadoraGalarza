/** Aluna: Izadora Galarza Alves
 * ED13 -  Exemplos
 * Professor: Theldo Cruz
 */

 #include<iostream>
using std::cin; //entrada
using std::cout; // saida
using std::endl; //pular linha

#include<iomanip>
using std::setw; //definir espacamento

#include<string>
using std::string; //cadeia de carateres

#include<fstream>
using std::ifstream; //ler arquivo
using std::ofstream; //gravar arquivo

//outras dependencias


#include "Contato.hpp" 

 // ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos

/** Exemplo00 - Nao faz nada */

void exemplo1300 ()
{

}

/** Exemplo1301 - Testar definicoes da classe */

void exemplo1301()
{
    Contato pessoa1;
    ref_Contato pessoa2 = nullptr;
    ref_Contato pessoa3 = new Contato ();

    //identificar
    cout<<"\nExemplo1301 - v1.0\n"<<endl;

    //encerrar
    pause("Apertar ENTER para continuar.");

}


void exemplo1302()
{
	Contato pessoa1;
	ref_Contato pessoa2 = nullptr;
	ref_Contato pessoa3= new Contato();

	cout<<"Exemplo1302"<<endl;

	//testar atribuicoes

	pessoa1.setNome("Pessoa_01");
	pessoa1.setFone("111");
	pessoa3->setNome("Pessoa_03");
	pessoa3->setFone("333");

	cout<<"Pessoa 1 - {" <<pessoa1.getNome() << "," <<pessoa1.getFone() << "}" <<endl;
	cout<<"Pessoa 3 - {" <<pessoa3->getNome() << "," <<pessoa3->getFone() << "}" <<endl;

	pause("Apertar ENTER para continuar.");
}

void exemplo1303()
{
	 Contato pessoa1;
	 ref_Contato pessoa2 = nullptr;
	 ref_Contato pessoa3 = new Contato ( );

	cout<<"Exemplo1303"<<endl;
	pessoa1.setNome("Pessoa_01");
	pessoa1.setFone("111");
	pessoa3->setNome("Pessoa_03");
	pessoa3->setFone("333");

	cout<<"Pessoa 1 - "<< pessoa1.toString() <<endl;
	cout<<"Pessoa 3 -" <<pessoa3->toString()  <<endl;
	pause("Apertar ENTER para continuar.");
	
}

void exemplo1304()
{
	Contato pessoa1("Pessoa_01","111");
	ref_Contato pessoa2=nullptr;
	ref_Contato pessoa3 = new Contato("Pessoa_03","333");
	cout<<"Exemplo1304"<<endl;

	cout<<"pessoa1- "<< pessoa1.toString () <<endl;
	cout<<"Pessoa3 - "<<pessoa3->toString() << endl;
	pause("Apertar ENTER para continuar.");
}

void exemplo1305()
{
	Contato pessoa1 ( "Pessoa_01", "111" );
	ref_Contato pessoa2 = nullptr;
	ref_Contato pessoa3 = new Contato ( "", "333" );
	cout<<"Exemplo1302"<<endl;

	cout<<"pessoa1 -" <<pessoa1.toString() <<"("<<pessoa1.getErro() << ")"<<endl;
	cout<<"pessoa1 -" <<pessoa3->toString() <<"("<<pessoa3->getErro() << ")"<<endl;
	pause("Apertar ENTER para continuar.");
}
void exemplo1306()
{
	Contato pessoa1 ( "Pessoa_01", "111" );
	ref_Contato pessoa2 = nullptr;
	ref_Contato pessoa3 = new Contato ( "", "333" );
	cout<<"Exemplo1306"<<endl;
	if(!pessoa1.hasErro())
		cout<<"pessoa1 - "<<pessoa1.toString()<<endl;
	else
		cout<<"pessoa1 tem erro(" <<pessoa1.getErro() << ")" <<endl;
	if(!pessoa3->hasErro())
		cout<<"pessoa3 - "<<pessoa3->toString()<<endl;
	else
		cout<<"pessoa3 tem erro(" <<pessoa3->getErro() << ")" <<endl;
	pause("Apertar ENTER para continuar.");
}

void exemplo1307()
{
	Contato pessoa1("Pessoa_01","111");
	ref_Contato pessoa2=nullptr;
	ref_Contato pessoa3 = new Contato("","333");
	cout<<"Exemplo1307"<<endl;

	pessoa2=&pessoa1; //copiar endereco de objeto
	if(!pessoa2->hasErro())
		cout << "pessoa1 - "<<pessoa2 ->toString()<<endl;
	else
		cout << "pessoa1 tem erro ( " << pessoa2->getErro() << ")" << endl;

	pessoa2 = pessoa3; //vincular obejet
	if(!pessoa2 ->hasErro())
		cout<<"pessoa3 - " << pessoa2->toString() <<endl;
	else
		cout<<"pessoa3 tem erro (" << pessoa3->getErro() << ")"<<endl;
	pause("Apertar ENTER para continuar.");
}

void exemplo1308()
{
	Contato pessoa1 ( "Pessoa_01", "111" );
	ref_Contato pessoa2 = nullptr;
	ref_Contato pessoa3 = new Contato ( "", "333" );
	ref_Contato pessoa4 = nullptr;

	cout<<"Exemplo1308"<<endl;
	pessoa2 = new Contato ( pessoa1 );
	 if ( pessoa2 )
		 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
	 else
		 cout << "pessoa2 tem erro (" << pessoa2->getErro( ) << ")" << endl;
	 if ( pessoa3 ) 
	 {
		 pessoa2 = new Contato ( *pessoa3 );
		if ( pessoa2 )
			 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
		else
			 cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
	 } 
	 if ( pessoa4 ) // o teste de existencia deve ser feito previamente
	 {
		 pessoa2 = new Contato ( *pessoa4 );
		 if ( pessoa2 )
			 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
		 else
			 cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
	 }
	pause("Apertar ENTER para continuar.");
}

void exemplo1309()
{
	Contato pessoa[3];
	int x=0;
	cout<<"Exemplo1309"<<endl;

	pessoa[0].setNome("Pessoa_01");
	pessoa[0].setFone("111");

	pessoa[1].setNome("Pessoa_02");
	pessoa[1].setFone("222");

	pessoa[2].setNome("Pessoa_03");
	pessoa[2].setFone("333");

	for ( x=0; x < 3; x=x+1 )
	{
	    cout << x << " : " << pessoa[ x ].toString( ) << endl;
	}
	pause("Apertar ENTER para continuar.");
}

void exemplo1310()
{
	Contato *pessoa[3];
	int x=0;
	cout<<"Exemplo1310"<<endl;

	pessoa [ 0 ] = new Contato ( "Pessoa_1", "111" );
	pessoa [ 1 ] = new Contato ( "Pessoa_2", "222" );
	pessoa [ 2 ] = new Contato ( "Pessoa_3", "333" );
	for ( x=0; x < 3; x=x+1 )
	{
		 cout << x << " : " << pessoa[ x ]->toString( ) << endl;
	} 
	pause("Apertar ENTER para continuar.");
}

int main ( int argc, char** argv )
{

 int x = 0; 
do   
{
    cout << "EXEMPLO1300 - Programa - v0.0\n " << endl;
    cout << "Opcoes " << endl;
    cout << " 0 - parar " << endl;
    cout << " 1 - testar definicao de contatos (objetos) " << endl;
	cout << " 2 - atribuir informacoes (get) " << endl;
	cout << " 3 - atribuir informacoes (toString) " << endl;
	cout << " 4 - atribuir informacoes (Construtor alternativo)" << endl;
	cout << " 5 - atribuir informacoes (Verifica erro)" << endl;
	cout << " 6 - testar se tem erro (usando pessoa2) " << endl;
	cout << " 7 - atribuir informacoes (erro)" << endl;
	cout << " 8 - atribuir informacoes (teste previamente existencia)" << endl;
	cout << " 9 - atribuir informacoes (arranjo)" << endl;
	cout << " 10 - atribuir informacoes (arranjo por referencia)" << endl;

    cout << endl << "Entrar com uma opcao: ";
    cin >> x;
        switch ( x )
        {
	        case 0: exemplo1300( ); break;
	        case 1: exemplo1301 ( ); break;
			case 2: exemplo1302();break;
			case 3: exemplo1303();break;
			case 4: exemplo1304();break;
			case 5: exemplo1305();break;
			case 6: exemplo1306();break;
			case 7: exemplo1307();break;
			case 8: exemplo1308();break;
			case 9: exemplo1309();break;
			case 10: exemplo1310();break;
        default: cout << endl << "ERRO: Valor invalido." << endl;
        }
}while ( x != 0 );
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
}