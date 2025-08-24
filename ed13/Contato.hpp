
#ifndef _CONTATO_H_
#define _CONTATO_H_

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

/** Classe para tratar contatos, derivada da classe Erro */

class Contato : public Erro
{
    //atributos privados
    private: 
    string nome;
    string fone;

    //definicoes publicas

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
    }

	/**construto alternativo
	* @param nome_inicial a ser atribuido
	* @param fone_inicial a ser atribuido
	*/

	Contato (std::string nome_inicial, std::string fone_inicial)
	{
	setErro(0);
	setNome(nome_inicial);
	setFone(fone_inicial);
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

std::string toString()
{
	return("{"  +getNome() + "," + getFone() + "}");
}


	bool hasErro()
{
	return(getErro() !=0);
}
	
};

using ref_Contato = Contato*; //parece com o typedef de Struct
#endif