/** 
	myarray.hpp - v0.0 - 19/05/2025
	Autor: Izadora Galarza Alves
*/

#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_
#define null nullptr

//dependecias

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;

#include<string>
using std::string;

#include<fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // ler arquivo

template <typename T>
class Array
{
	private: //area reservada
	T optional;
	int length;
	T *data;

	public: //area aberta
	Array (int n, T initial)
	{
	//definir valores iniciais 
	optional = initial;
	length =0;
	data = nullptr;

	//reservar area
	if(n>0)
	{
		length =n;
		data = new T [length];
	}
	} //fim do construtor

	//liberar
	void free ()
	{
	if(data != nullptr)
	{
		delete (data); //como um free
		data = nullptr;
	}
	} // fim do free

	//alocar um valor em determinada posicao
	void set (int position, T value)
	{
	if(0<=position && position < length)
	{
		data [position] = value;
	}
	}

	//ter acesso ao valor da posicao
	T get ( int position)
	{
	T value = optional;
	if(0 <= position && position < length)
	{
		value = data[position];
	}

	return(value);
	}

	//mostrar
	void print ( )
	 {
		cout << endl;
		 for ( int x = 0; x < length; x=x+1 )
		 {
			 cout << setw( 3 ) << x << " : "
			 << setw( 9 ) << data[ x ]
			 << endl;
		 } 
		 cout << endl;
	 }

	//ler
	void read()
	{
		cout<<endl;
		for(int x=0; x<length; x=x+1)
			{
				cout<< setw(3) << x << ":";
				cin >> data[x];
			}
		cout<<endl;
	}

	void fprint(string fileName)
	{
		ofstream afile;  //"w" arquivo
		afile.open (fileName);
		afile<<length<<endl;
		for(int x=0; x< length; x=x+1)
			{
				afile << data[x]<<endl;
			}
		afile.close();
	}

	void fread (string fileName)
	{
		ifstream afile; //leitura de arquivo
		int n=0;
		afile.open(fileName);
		afile >> n;
		if(n <= 0)
		{
			cout <<"\nERRO: Tamanho invalido\n"<< endl;
		}
		else
		{
			length=n;
			data= new T [n];
			for(int x=0; x< length; x=x+1)
				{
					afile>>data[x];
				}
		}
		afile.close();
	}

	//construtor
	Array()
	{
		length=0;
		data=null;
	}

	//destrutor
	Array(int length, int other[])
	{
		if(length <=0)
		{
			cout<<"\nERRO: Tamanho invalido\n"<<endl;
		}
		else
		{
			this->length = length;
			data= new T [this->length];
			for (int x=0; x< this->length; x=x+1)
				{
					data[x]= other[x];
				}
		}
	}

	Array(const Array& other)
	{
		if(other.length <=0)
		{
			cout<< "\nERRO: Dado perdido\n"<<endl;
		}
		else
		{
			length = other.length;
			data = new T[other.length];
			for(int x=0; x< length; x=x+1)
				{
					data[x] = other.data[x];
				}
		}
	}


	Array& operator= (const Array <T> other)
	{
		if(other.length <=0)
		{
			cout<< "\nERRO: Dado perdido\n"<<endl;
		}
		else
		{
			this->length = other.length;
			this->data = new T[other.length];
			for(int x=0; x< this->length; x=x+1)
				{
					data[x] = other.data[x];
				}
		}
		return(*this);
	}	

	bool operator== (const Array <T> other)
	{
		bool result = false;
		int x=0;
		if(other.length == 0 || length != other.length)
		{
			cout<<"\nERRO: Missing Data\n"<<endl;
		}
		else
		{
			x=0;
			result=true;
			while(x<this->length && result)
				{
					result= result && (data[x] == other.data[x]);
					x=x+1;
				}
		}
		return(result);
	}


	Array& operator+ (const Array <T> other)
	{
		static Array <T> result (other);
		if(other.length <=0)
		{
			cout<<"\nERRO: Missing data.\n"<<endl;
		}
		else
		{
			for(int x=0;x<this->length;x=x+1)
				{
					result.data [x] = result.data [x] + this->data[x];
				}
		}
		return(result);
	}


	const int getLength()
	{
		return (length);
	}

	T& operator[] (const int position)
	{
		static T value = optional;

		if(position < 0 || length <= position)
		{
			cout<<endl<< "\nERROr: Invalid position.\n"<<endl;
		}
		else
		{
			value = data[position];
		}
		return(value);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void randomIntGenerate(int inferior, int superior)
	{
		if (!data || inferior > superior) return;

        for (int controle = 0; controle < length; controle = controle +1)
		{
            data[controle] = inferior + 1 + rand() % (superior - inferior - 1);
        }
	}


	int searchFirstOdd ( )
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou não inicializado.\n";
	    }
		
		int maior=-1;
		for(int x=0; x < length; x=x+1)
			{
				if(data[x]>maior && data[x] % 2 != 0)
				{
					maior=data[x];
				}
			}
		return(maior);
		}


	int searchFirstOdd3 ( )
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
	    }
		
		int maior=-1;
		for(int x=0; x < length; x=x+1)
			{
				if(data[x]>maior && data[x] % 2 != 0 && data[x]%3 ==0)
				{
					maior=data[x];
				}
			}
		return(maior);
		}


	int addInterval (int i, int f)
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
	    }

		int soma=0;
		for(int x = i; x <= f; x=x+1)
			{
				soma= soma + data[x];
			}
			return(soma);
	}


	double averageInterval (int i, int f)
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
	    }
		
		int denominador=0;
		int media=0;
		for(int x = i; x <= f; x=x+1)
			{
				media= media + data[x];
				denominador = denominador +1;
			}
			double result = media/denominador;
			return(result);
	}

	bool negatives ()
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
	    }

		for (int x = 0; x < length; x++) 
		{
	        if (data[x] <= 100) 
			{ 
	            return (false);
	        }
	    }

	    return true;
	}


	bool isDecrescent ()
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
	    }

		bool ordenado = true; //ate que se prove ao contrario
		int tamanho = length -1;
		for(int x=0; x < tamanho; x=x+1)
			{
				if(data[x] > data[x+1])
				{
					ordenado = false;
				}
			}
			return(ordenado);
	}

	bool searchInterval (int p, int i, int f)
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou nao inicializado.\n";
		return false;
	    }

		if (i < 0 || f >= length || i > f)
		{
        cout << "ERRO: Intervalo invalido.\n";
        return false;
		}
		
		bool resposta = false;

		for(int x =i; x <= f; x=x+1)
			{ 
				if(data[x] == p)
				{
					resposta = true;
				}
			}
		return(resposta);
	}

	void scalar(int c, int i, int f) 
	{
	    if (!data || length == 0) {
        cout << "ERRO: Array vazio ou nao inicializado.\n";
        return;
    }

    if (i < 0 || f >= length || i > f) 
	{
        cout << "ERRO: Intervalo invalido.\n";
        return;
    }

    for (int x = i; x <= f; x=x+1) 
	{
        data[x] = data[x] * c; 
    }
	}

	void sortDown() 
	{
		if (!data || length == 0) 
		{
        cout << "ERRO: Array vazio ou não inicializado.\n";
        return;
	    }

	    for (int x = 0; x < length - 1; x++) 
		{
        for (int y = 0; y < length - x - 1; y++)
			{
            if (data[y] < data[y + 1]) 
			{
                int temp = data[y];
                data[y] = data[y + 1];
                data[y + 1] = temp;
            }
        
			}
	    }
	}


	 bool operator!=(const Array<T>& other) const 
	{
        if (length != other.length) {
            return true;
        }

        for (int x = 0; x < length; x=x+1) {
            if (data[x] != other.data[x]) {
                return true;
            }
        }

        return false;
    }

	Array<T> operator-(const Array<T>& other) const {
        if (length != other.length) {
            cout << "ERRO: Os arranjos têm tamanhos diferentes.\n";
            return *this;
        }

        Array<T> resultado(length, 0);

        for (int x = 0; x < length; x=x+1) {
            resultado.data[x] = data[x] - other.data[x];
        }

        return resultado;
    }
		
	};

	#endif