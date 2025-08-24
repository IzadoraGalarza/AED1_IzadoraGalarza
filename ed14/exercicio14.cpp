/**Aluna: Izadora Galarza Alves
ed14
*/

#include <iostream>
#include "StringP.hpp"

using namespace std;



// 01. Teste de conversão para inteiro
void void1411() {
    StringP s1("12345");
    cout << "Teste getInt(12345): "  << endl;
	if(s1.getInt())
	{
		cout<<"Verdadeiro";
	}
	else
	{
		cout<<"Falso";
	}
	pause("Apertar ENTER para continuar.");
	
}

// 02. Teste de conversão para double
void void1412() {
    StringP s1("123.45");
    cout << "Teste getDouble(123.45): " << endl;
	if(s1.getDouble())
	{
		cout<<"Verdadeiro";
	}
	else
	{
		cout<<"Falso";
	}
	pause("Apertar ENTER para continuar.");
}

// 03. Teste de conversão para booleano
void void1413() {
    StringP s1("true");
    cout << "Teste getBoolean(true): "  << endl;
	if(s1.getBoolean())
	{
		cout<<"Verdadeiro";
	}
	else
	{
		cout<<"Falso";
	}
	pause("Apertar ENTER para continuar.");
}

// 04. Teste de contains()
void void1414() {
    StringP s1("Hello World");
    cout << "Teste contains('World'): " << (s1.contains("World") ? "Sim" : "Não") << endl;
	pause("Apertar ENTER para continuar.");
}

// 05. Teste de toUpperCase()
void void1415() {
    StringP s1("hello world");
    cout << "Teste toUpperCase(): " << s1.toUpperCase() << endl;
	pause("Apertar ENTER para continuar.");
}

// 06. Teste de toLowerCase()
void void1416() {
    StringP s1("HELLO WORLD");
    cout << "Teste toLowerCase(): " << s1.toLowerCase() << endl;
	pause("Apertar ENTER para continuar.");
}

// 07. Teste de replace()
void void1417() {
    StringP s1("banana");
    cout << "Teste replace('a', 'o'): " << s1.replace('a', 'o') << endl;
	pause("Apertar ENTER para continuar.");
}

// 08. Teste de cifra de César
void void1418() {
    StringP s1("Hello");
    cout << "Teste encrypt(): " << s1.encrypt() << endl;
	pause("Apertar ENTER para continuar.");
}

// 09. Teste de decodificação da cifra de César
void void1419() {
    StringP s1("Khoor");
    cout << "Teste decrypt(): " << s1.decrypt() << endl;
	pause("Apertar ENTER para continuar.");
}

// 10. Teste de split por espaços
void void1420() {
    StringP s1("banana maçã uva");
    string sequencia[10];
    int qtd = s1.split(sequencia);
    cout << "Split detectou " << qtd << " palavras." << endl;
    for (int x = 0; x < qtd; x++) {
        cout << "Palavra " << x + 1 << ": " << sequencia[x] << endl;
		
    }
	pause("Apertar ENTER para continuar.");
}

// E1. Teste de split por delimitador personalizado
void void1421() 
{
    StringP s1("banana,maçã,uva");
    string sequencia[10];
    int qtd = s1.split(sequencia, ',');
    cout << "Split por ',' detectou " << qtd << " palavras." << endl;
    for (int x = 0; x < qtd; x=x+1) 
	{
        cout << "Palavra " << x + 1 << ": " << sequencia[x] << endl;
    }
	pause("Apertar ENTER para continuar.");
}

// E2. Teste de reversão de string
void void1422() {
    StringP s1("hello");
    cout << "Teste reverse(): " << s1.reverse() << endl;
}

// Função principal com menu interativo
int main(int argc, char** argv) {
    int x = 0;

    do {
        cout << "Exercicios14 - ed14 - v0.0\n" << endl;
        cout << "Opcoes: " << endl;
        cout << " 0  - parar" << endl;
        cout << " 1  - testar getInt()" << endl;
        cout << " 2  - testar getDouble()" << endl;
        cout << " 3  - testar getBoolean()" << endl;
        cout << " 4  - testar contains()" << endl;
        cout << " 5  - testar toUpperCase()" << endl;
        cout << " 6  - testar toLowerCase()" << endl;
        cout << " 7  - testar replace()" << endl;
        cout << " 8  - testar encrypt()" << endl;
        cout << " 9  - testar decrypt()" << endl;
        cout << " 10 - testar split()" << endl;
        cout << " 11 - testar split() com delimitador" << endl;
        cout << " 12 - testar reverse()" << endl;
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        switch (x) {
            case 0:
                cout << "" << endl;
                break;
            case 1:
                void1411();
                break;
            case 2:
                void1412();
                break;
            case 3:
                void1413();
                break;
            case 4:
                void1414();
                break;
            case 5:
                void1415();
                break;
            case 6:
                void1416();
                break;
            case 7:
                void1417();
                break;
            case 8:
                void1418();
                break;
            case 9:
                void1419();
                break;
            case 10:
                void1420();
                break;
            case 11:
                void1421();
                break;
            case 12:
                void1422();
                break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
        }
    } while (x != 0);

    pause("Apertar ENTER para terminar.");
    return 0;
}
