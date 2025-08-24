** Aluna: Izadora Galarza Alves
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

void pause ( std::string text )
{
std::string dummy;
std::cin.clear ( );
std::cout << std::endl << text;
std::cin.ignore( );
std::getline(std::cin, dummy);
std::cout << std::endl << std::endl;
} 

#include "erro.hpp" 

class MyString : public Erro
{
public:

std::string getErroMsg ( )
{
return ( NO_ERROR ); 
} 
};
 // ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos

/** Exemplo00 - Nao faz nada */

void exemplo1300 ()
{

}

void method_01()
{
    MyString* s = new MyString();
    cout << "\nMethod_01 - v0.0\n" << endl;
    pause("Apertar ENTER para continuar");
}

int main(int argc, char** argv)
{
    int x = 0;
    do
    {
        cout << "EXEMPLO1401 - Programa - v0.0\n " << endl;
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - testar definicoes " << endl;
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        switch (x)
        {
            case 0:
                method_00();
                break;
            case 1:
                method_01();
                break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        }
    } while (x != 0);
    pause("Apertar ENTER para terminar");
    return (0);
}