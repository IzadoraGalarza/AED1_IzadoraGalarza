
#ifndef _CONTACT_H_
#define _CONTACT_H_

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

void pause (std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout<<std::endl<<text;
    std::cin.ignore();
    std::getline(std::cin,dummy);
    std::cout<<std::endl<<std::endl;
}

#include"Erro.hpp"

// --------------------- definicao de class
using namespace std;
/** Classe para tratar contatos, derivada da classe Erro */

class Contato : public Erro
{
    //atributos privados
    private: 
    string nome;
    string fone;
	string fone2;
	int quantidadeFone;

	bool ValidFone()
	{
		char atual;
		if(this->fone.empty())
		{
			return(false);
		}
		else
		{
			for(int index =0; index < this->fone.length(); index=index+1)
				{
					atual= this->fone[index];

					if(!(atual >='0' && atual<='9'|| atual == '-'))
					{
						return (false);
					}
				}
		}

		
			return (true);
	}

	bool ValidFone2()
	{
		char atual;
	if(this->fone2.empty())
		{
			return(false);
		}
		else
		{
			for(int index =0; index < this->fone2.length(); index=index+1)
				{
					atual= this->fone2[index];

					if(!(atual >='0' && atual<='9'|| atual == '-'))
					{
						return (false);
					}

				}
		}
		return(true);
	}
    public: 
    //destrutor
    ~Contato()
    {}

    //construtor padrao
    Contato()
    {
		setErro(0); //nenhum erro, por enquanto...
        //atribuir valores iniciais vazios
        nome = "";
        fone = "";
		fone2 = "";
		this -> quantidadeFone=0;
	
    }

	/**construto alternativo
	* @param nome_inicial a ser atribuido
	* @param fone_inicial a ser atribuido
	*/

	Contato (std::string nome_inicial, std::string fone_inicial, std::string fone_inicial2)
	{
	setErro(0);
	setNome(nome_inicial);
	setFone(fone_inicial);
	setFone2(fone_inicial2);
	this->quantidadeFone = 0;
        if (!this->fone.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
		if (!this->fone2.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
	}

	/** 
	*construtor açternativo baseado em copia
	*/
	Contato ( Contato const & another)
	{
		//atribuir valores iniciais por copia
		setErro(0); //copia erro
		setNome(another.nome);
		setFone(another.fone);
		setFone(another.fone2);
		this->quantidadeFone = another.quantidadeFone;
	}

	/**exemplo para atribuir nome
	* @param nome a ser atribuido
	*/

	void setNome (std::string nome)
{
	if(nome.empty())
	{
		setErro(1); //nome invalido
	}
	else
	this->nome = nome;
}

//atribuir fone
	void setFone (std::string fone)
{
	if(fone.empty())
	{
		setErro(2); //fone invalido
	}
	else
	this->fone = fone;
	this->quantidadeFone = 0;
        if (!this->fone.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
		if (!this->fone2.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
	
}

void setFone2 (std::string fone2)
{
	if(fone2.empty())
	{
		setErro(2); //fone invalido
	}
	else
	this->fone2 = fone2;
	this->quantidadeFone = 0;
        if (!this->fone.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
		if (!this->fone2.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
	
}



/** funcao para obter nome
* @param nome armazenado
*/

std::string getNome()
{
	return(this->nome);
}

std::string getFone()
{
	return(this->fone);
}

std::string getFone2()
{
	return(this->fone2);
}

int getQuantidade()
{
	return(this->quantidadeFone);
}
std::string toString()
{
	return("{"  +getNome() + "," + getFone() + "}");
}

std::string toString2()
{
	return("{"  +getNome() + "," + getFone() + ", "+ getFone2() + "}");
}


	bool hasErro()
{
	return(getErro() !=0);
}

///////////////////////////////////parte exercicios /////////////////////////////////////////////////////////////////

//usando construtor padrao

void readName (std::string novoNome)
{
	if(novoNome.empty())
	{
		setErro(1);
	}
	else
	this->nome = novoNome;
	cout<<"Nome:"<<novoNome<<endl;
}

void readPhone (std::string novoFone)
{
	if(novoFone.empty())
	{
		setErro(2);
		cout<<"Telefone invalido"<<endl;
	}
	else
	this->fone = novoFone;
	cout<<"Phone:"<<novoFone<<endl;
	this->quantidadeFone = 0;
        if (!this->fone.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
}

void readPhone2 (std::string novoFone, std::string novoFone2)
{
	if(novoFone.empty())
	{
		setErro(2);
		cout<<"Telefone invalido"<<endl;
	}
	else
	this->fone = novoFone;

	//fone2
	
	if(novoFone2.empty())
	{
		setErro(2);
		cout<<"Telefone invalido"<<endl;
	}
	else
	this->fone2 = novoFone2;
	cout<<"Phone2:"<<novoFone2<<endl;
	
	this->quantidadeFone = 0;
        if (!this->fone.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
		if (!this->fone2.empty()) 
		{
            this->quantidadeFone= quantidadeFone +1;
        }
}
void isValidPhone()
{
	bool OK = ValidFone();
	if(OK)
	{
		cout << "Telefone(1) Valido" << endl;
	}
	else
	{
		cout << "Telefone(1) Invalido" << endl;
	}

}

void isValidPhone2()
{
	bool OK = ValidFone2();
	if(OK)
	{
		cout << "Telefone(2) Valido" << endl;
	}
	else
	{
		cout << "Telefone(2) Invalido" << endl;
	}

}

	void readFromFile(std::string fileName)
	{
		string linhaNome;
		string linhaFone;
		setErro(0);
		ifstream leitura(fileName);
		if( fileName.empty())
		{
			setErro(4);
			cout<<"ERRO: Arquivo de nome vazio"<<endl;
		}

		if(!leitura)
		{
			setErro(5);
			cout<<"ERRO: Nao foi possivel abrir arquivo"<<endl;
		}

		if(std::getline(leitura, linhaNome) && std::getline(leitura, linhaFone))
		{
			if(!(linhaNome.empty() && linhaFone.empty()))
			{
				setNome(linhaNome);
				setFone(linhaFone);
				cout<<"Nome: "<< getNome() << "\n" << "Telefone: " << getFone()	<< endl;
			}
			else
			{
				setErro(5);
				cout<<"ERRO: Falha ao ler dados."<<endl;
			}
		}
		else
		{
			setErro(6);
			cout<<"ERRO: Dado(s) incompletos" <<endl;
		}

		leitura.close();
		
	}



void writeToFile(std::string fileName)
	{
		string linhaNome;
		string linhaFone;
		setErro(0);
		
		if(fileName.empty())
		{
			setErro(4);
			cout<<"ERRO: Arquivo de nome vazio"<<endl;
		}

		if(this->nome.empty() || this->fone.empty())
		{
			setErro(7);
			cout<<"ERRO: Nao foi possivel gravar nome e telefone"<<endl;
		}

		ofstream entrada (fileName);
		if(!entrada)
		{
			setErro(5);
			cout<<"ERRO: Nao foi possivel abrir arquivo"<<endl;
		}
		int tamanho = this->nome.length() + this->fone.length() +2;
		entrada << tamanho <<endl;

		entrada <<this->nome << endl;
		entrada << this->fone <<endl;

		if(entrada.good())
		{
			cout<<"Dados gravados em arquivo"<<endl;
		}
		else
		{
			setErro(8);
			cout<<"Dados nao gravados em arquivo"<<endl;
		}
		entrada.close();
		
	}

int phones()
{
	return(this->quantidadeFone);
}

void setPhone2a (std::string telefone2)
{
    this->fone2 = telefone2;
}

void setPhone2ab ()
{
    std::string tempFone1;
    std::string tempFone2;
    int result = 0;
	this->quantidadeFone= 0;
    cout << "Digite o Telefone 1: ";
    std::cin >> tempFone1;
    setFone(tempFone1);
    if (getErro() == 2)
    {
        cout << "Telefone 1 invalido." << endl;
    }
	
    cout << "Deseja inserir um segundo telefone? Sim(1) Nao(2)" << endl;
    do
    {
        std::cin >> result;
        if (result != 1 && result != 2)
        {
            cout << "Opcao invalida. Digite 1 para Sim ou 2 para Nao: ";
        }
		
    } while (result != 1 && result != 2);

	
    if (result == 1)
    {
        cout << "Digite o Telefone 2: ";
        std::cin >> tempFone2;
        setFone2(tempFone2);
        if (getErro() == 2)
        {
            cout << "Telefone 2 invalido." << endl;
        }
    }
    else
    {
        setFone2("");
        cout << "Segundo telefone nao inserido." << endl;
    }
}

void setPhone2b(std::string outroFone2)
{
	this->fone2 = outroFone2;
}

void setPhone2c()
{
	this->fone2 = "";
	if(fone2 == "")
	{
		this->quantidadeFone =  quantidadeFone -1;
	}
}
};

using ref_Contato = Contato*; //parece com o typedef de Struct
#endif