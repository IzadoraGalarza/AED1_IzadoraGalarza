
// dependências
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;


#include "Contact.hpp" 


// Metodo 00 - nao faz nada.
void method_00 ()
{
    // Nao faz na
}

void method_01()
{
}
// Funções de teste para cada exercício

void test_01_02() {
    cout << "\n--- Teste 01 (readName) e Teste 02 (readPhone) ---" << endl;
    Contato contato1;

    cout << "\nTestando readName (Exercicio 01):" << endl;
    contato1.readName("Joao");

    cout << "\nTestando readPhone (Exercicio 02):" << endl;
    contato1.readPhone("1111-2222");

    pause("Fim do Teste 01 e 02. Aperte ENTER para continuar.");
}

// Teste para Exercício 03 (isValidPhone)
void test_03() {
    cout << "\n--- Teste 03: isValidPhone (Metodo Privado) ---" << endl;
    Contato contato2;

    cout << "\nTestando isValidPhone() para fone principal:" << endl;
    contato2.setFone("9999-9999");
    cout << "Fone: '" << contato2.getFone() << "'" << endl;
    contato2.isValidPhone(); 

    contato2.setFone("abc-123");
    cout << "Fone: '" << contato2.getFone() << "'" << endl;
    contato2.isValidPhone();

    contato2.setFone(""); // Vazio
    cout << "Fone: '" << contato2.getFone() << "'" << endl;
    contato2.isValidPhone();
    pause("Fim do Teste 03. Aperte ENTER para continuar.");
}

// Teste para Exercício 04 (readFromFile)
void test_04() {
    cout << "\n--- Teste 04: readFromFile ---" << endl;
    Contato contato3;

    
    contato3.readFromFile("PessoaTeste1.txt");
    cout << "Nome: '" << contato3.getNome() << "'" << endl;
    cout << "Fone1: '" << contato3.getFone() << "'" << endl;
    cout << "Fone2: '" << contato3.getFone2() << "'" << endl;
    cout << "Quantidade Fones: " << contato3.phones() << endl;

    pause("Fim do Teste 04. Aperte ENTER para continuar.");
}

// Teste para Exercício 05 (writeToFile)
void test_05() {
    cout << "\n--- Teste 05: writeToFile ---" << endl;
	
    Contato contato4("Pedro Alvares", "9999-0000",""); 
    cout << "Contato4 para gravacao:" << endl;
    cout << contato4.toString() << endl;
    contato4.writeToFile("ContatoPedro.txt");
    cout << "Erro: " << contato4.getErro() << endl;

    Contato contato5("Ana Clara", "1234-5678", "9876-5432"); // Com dois fones
    cout << "\nContato5 para gravacao:" << endl;
    cout << contato5.toString2() << endl;
    contato5.writeToFile("ContatoAna.txt");
    cout << "Erro: " << contato5.getErro() << endl;

    pause("Fim do Teste 05. Aperte ENTER para continuar.");
}

// Teste para Exercício 06 (Segundo telefone e construtores) e Exercício 07 (phones())
void test_06_07() {
    cout << "\n--- Teste 06 (Construtores com 2 Fones) e Teste 07 (phones()) ---\n" << endl;

    // Construtor padrão (0 fones)
    Contato c_padrao;
    cout << "Contato padrao: " << c_padrao.toString() << endl;
    cout << "Quantidade de fones: " << c_padrao.phones() << " (esperado 0)" << endl;

    // Construtor com 1 fone (usando o construtor de 3 strings, com o 3o vazio)
    Contato c_um_fone("TesteUmFone", "1111-1111", "");
    cout << "\nContato com 1 fone: " << c_um_fone.toString2() << endl;
    cout << "Quantidade de fones: " << c_um_fone.phones() << " (esperado 1)" << endl;

    // Construtor com 2 fones
    Contato c_dois_fones("TesteDoisFones", "2222-2222", "3333-3333");
    cout << "\nContato com 2 fones: " << c_dois_fones.toString2() << endl;
    cout << "Quantidade de fones: " << c_dois_fones.phones() << " (esperado 2)" << endl;

    // Construtor de cópia (testando com um de 2 fones)
    Contato c_copia(c_dois_fones);
    cout << "\nContato copia (de 2 fones): " << c_copia.toString2() << endl;
    cout << "Quantidade de fones: " << c_copia.phones() << " (esperado 2)" << endl;

    pause("Fim do Teste 06 e 07. Aperte ENTER para continuar.");
}

// Teste para Exercício 08 (setPhone2a/ab)
void test_08() {
    cout << "\n--- Teste 08: setPhone2a/ab ---\n" << endl;
    Contato contato6; // Começa sem nome/fone
    contato6.setNome("Roberto");
    cout << "Contato6 inicial: " << contato6.toString2() << endl;
    cout << "Quantidade de fones: " << contato6.phones() << endl;

    // Cenário 1: Tentar adicionar segundo fone sem fone principal (usando setPhone2a original)
    // Nota: O seu setPhone2a no .h é um setter direto. Ele não contém a lógica de erro 9
    // ou de perguntar ao usuário. Essa lógica está na sua setPhone2ab().
    // Para cumprir a DICA do exercício 08, preciso testar setPhone2ab.
    // O protótipo 08 pede setPhone2a(string). Há uma ambiguidade aqui.
    // Vou testar setPhone2ab, pois ela implementa a dica do exercício 08.
    cout << "\nTestando o setPhone2ab() (com interacao do usuario, como na DICA 08):" << endl;
    Contato contato7;
    contato7.setNome("Paula");
    // Sua setPhone2ab pede Telefone 1, depois pergunta do Telefone 2
    contato7.setPhone2ab(); // Necessita de interação do usuário no console
    cout << "Contato7 apos setPhone2ab (verifique saida e input): " << contato7.toString2() << endl;
    cout << "Quantidade de fones: " << contato7.phones() << endl;
    cout << "Erro: " << contato7.getErro() << endl;

    pause("Fim do Teste 08. Aperte ENTER para continuar.");
}

// Teste para Exercício 09 (setPhone2b)
void test_09() {
    cout << "\n--- Teste 09: setPhone2b ---\n" << endl;
    Contato contato8("Carlos", "111-222", "333-444"); // Contato com 2 fones
    cout << "Contato8 inicial: " << contato8.toString2() << endl;
    cout << "Quantidade de fones: " << contato8.phones() << endl;

    cout << "\nAlterando o segundo fone de contato8 (esperado sucesso):" << endl;
    contato8.setPhone2b("97777-3333");
    cout << "Contato8 apos setPhone2b: " << contato8.toString2() << endl;
    cout << "Erro: " << contato8.getErro() << endl; // Esperado 0

    // Teste com contato que só tem 1 fone (esperado erro)
    cout << "\nTestando setPhone2b em contato com apenas 1 fone:" << endl;
    Contato contato9("Fabio", "123-456", "");
    cout << "Contato9 inicial: " << contato9.toString2() << endl;
    cout << "Quantidade de fones: " << contato9.phones() << endl;
    contato9.setPhone2b("9999-9999");
    cout << "Contato9 apos setPhone2b: " << contato9.toString2() << endl;
    cout << "Erro: " << contato9.getErro() << endl; // Esperado erro 10

    pause("Fim do Teste 09. Aperte ENTER para continuar.");
}

// Teste para Exercício 10 (setPhone2c)
void test_10() {
    cout << "\n--- Teste 10: removePhone2 (setPhone2c) ---\n" << endl;
    Contato contato10("Julia", "111-222", "333-444"); // Contato com 2 fones
    cout << "Contato10 inicial: " << contato10.toString2() << endl;
    cout << "Quantidade de fones: " << contato10.phones() << endl;

    cout << "\nRemovendo o segundo fone de contato10 (esperado sucesso):" << endl;
    contato10.setPhone2c(); // Chama o metodo setPhone2c()
    cout << "Contato10 apos setPhone2c: " << contato10.toString2() << endl;
    cout << "Quantidade de fones: " << contato10.phones() << endl;
    cout << "Erro: " << contato10.getErro() << endl; // Esperado 0

    // Teste com contato que só tem 1 fone (esperado erro)
    cout << "\nTestando setPhone2c em contato com apenas 1 fone:" << endl;
    Contato contato11("Leo", "555-666", "");
    cout << "Contato11 inicial: " << contato11.toString2() << endl;
    cout << "Quantidade de fones: " << contato11.phones() << endl;
    contato11.setPhone2c();
    cout << "Contato11 apos setPhone2c: " << contato11.toString2() << endl;
    cout << "Erro: " << contato11.getErro() << endl; // Esperado erro 11

    pause("Fim do Teste 10. Aperte ENTER para continuar.");
}


// Funcao principal
int main (int argc, char** argv) {
    int x = 0;

    do {
        cout << "Opcoes:" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Testar definicoes (method_01)" << endl;
        cout << "2 - Teste 01 (readName) e 02 (readPhone)" << endl;
        cout << "3 - Teste 03 (isValidPhone)" << endl;
        cout << "4 - Teste 04 (readFromFile)" << endl;
        cout << "5 - Teste 05 (writeToFile)" << endl;
        cout << "6 - Teste 06 (Construtores com 2 Fones) e 07 (phones())" << endl;
        cout << "7 - Teste 08 (setPhone2a/ab)" << endl;
        cout << "8 - Teste 09 (setPhone2b)" << endl;
        cout << "9 - Teste 10 (setPhone2c)" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        

        switch (x) {
            case 0: method_00(); break;
            case 1: method_01(); break;
            case 2: test_01_02(); break;
            case 3: test_03(); break;
            case 4: test_04(); break;
            case 5: test_05(); break;
            case 6: test_06_07(); break;
            case 7: test_08(); break;
            case 8: test_09(); break;
            case 9: test_10(); break;
            default:
                cout << endl << "ERRO: Valor invalido." << endl;
                break;
        }
    } while (x != 0);

    pause("Apertar ENTER para terminar");
    return (0);
}

