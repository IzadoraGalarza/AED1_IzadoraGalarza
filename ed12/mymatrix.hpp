/*
mymatrix.hpp - v0.0 - 29/05/2025
	Author: Izadora Galarza Alves
*/

#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

//dependecias

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

template <typename T>
class Matrix
{
	private: //area reservada
	T optional;
	int rows;
	int columns;
	T** data;

	public:
	Matrix()
	{
		//definir valores iniciais
		this->rows    =0;
		this->columns =0;

		//sem reservar area
		data          =nullptr;
	}//fim construtor

	Matrix(int rows, int columns, T initial)
	{
		//definir dados locais
		bool OK   =true;
		//definir dados iniciais
		this->optional   = initial;
		this->rows       =rows;
		this->columns    =columns;
		//reserva area
		data             =new T*[rows];
		if(data != nullptr)
		{
			for(int x=0; x <rows; x=x+1)
				{
					data[x] = new T [columns];
					OK = OK && (data[x] != nullptr);
				}
			if(!OK)
			{
				data = nullptr;
			}
		}
	} //fim construtor

	~Matrix()
	{
		if(data !=nullptr)
		{
			for(int x=0; x < rows; x=x+1)
				{
					delete(data[x]);
				}
			delete(data);
			data = nullptr;
		}
	} //end destrutor()

	void set(int rows, int columns, T value)
	{
		if(rows < 0 || rows >= this->rows || columns < 0 || columns >= this->columns)

		{
			cout<<"\nERRO: Invalid position.\n";
		}
		else
		{
			data[rows][columns]= value;
		}
	}//end set()

	T get (int rows, int columns)
	{
		T value = optional;
		if(rows < 0 || rows >= this->rows || columns < 0 || columns >= this->columns)

		{
			cout<<"\nERRO: Invalid position.\n";
		}
		else
		{
			value=data[rows][columns];
		}
		return(value);
	}//end get()

	void print()
	{
		cout<<endl;
		for(int x=0; x < rows;x=x+1)
			{ 
				for(int y=0; y < columns;y=y+1)
					{
						cout<<data[x][y]<<"\t";
					}
				cout<<endl;
			}
		cout<<endl;
	}//fim print


	void read()
	{
		cout<<endl;
		for(int x=0; x<rows; x=x+1)
			{
				for(int y=0; y< columns; y=y+1)
					{
						cout<<setw(2) << x << "," << setw(2) <<y<<":";
						cin >> data[x][y];
					}
			}
		cout<<endl;
	}

	void fprint(string fileName)
	{
		ofstream afile;

		afile.open(fileName);
		afile<<rows<<endl;
		afile<<columns<<endl;
		for(int x=0; x < rows; x=x+1)
		{
			for(int y=0; y < columns; y=y+1)
			{
				afile << data[x][y]<<endl;
			}
		}
		afile.close();
	}

	void fread (string fileName)
{
	ifstream afile;
	int m =0;
	int n=0;

	afile.open(fileName);
	afile>>m;
	afile>>n;
	if(m<= 0 || n <=0)
	{
		cout<<"\nERRO: Invalid dimensions for matrix.\n"<<endl;
	}
	else
	{
		rows=m;
		columns =n;
		//reservar area
		data = new T* [rows];
		for(int x=0; x < rows; x=x+1)
			{
				data[x] = new T [columns];
			}
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						afile>>data[x][y];
					}
			}
	}
	afile.close();
	}


	Matrix& operator= (const Matrix <T> &other)
	{
		if(other.rows ==0 || other.columns ==0)
		{
			cout<<"\nERROR: Missing data.\n"<<endl;
		}
		else
		{
			this->rows  = other.rows;
			this->columns = other.columns;
			this->data = new T* [rows];
			for(int x=0; x < rows; x=x+1)
				{
					this->data[x] = new T[columns];
				}
			for(int x=0; x < this->rows; x=x+1)
				{
					for(int y=0; y < this->columns; y=y+1)
						{
							data[x][y] = other.data[x][y];
						}
				}
		}
		return(*this);
	}

	bool isZeros ()
	{
		bool result = false;
		int x=0;
		int y=0;
		if(rows > 0 && columns >0)
		{
			result=true;
			while(x < rows && result)
			{
				y=0;
			while(y< columns && result)
				{
					result =result && (data[x][y] ==0);
					y=y+1;
				}
			x=x+1;
		    }
		}
		return(result);
	}

	bool operator!= (const Matrix <T> &other)
	{
		bool result = false;
		int x=0;
		int y=0;
		if(other.rows ==0 ||rows != other.rows || 
		   other.columns ==0 ||columns != other.columns)
		{
			cout<<"\nERROR: Missing data.\n"<<endl;
		}
		else
		{
			x=0;
			while(x < rows && !result)
			{
				y=0;
			while(y< columns && !result)
				{
					result =(data[x][y] != other.data[x][y]);
					y=y+1;
				}
			x=x+1;
		    }
		}
		return(result);
	}

	Matrix& operator- ( const Matrix <T> &other )
	{
	static Matrix <T> result ( 1, 1, 0 );
	int x = 0;
	int y = 0;
	if ( other.rows == 0 || rows != other.rows ||
		other.columns == 0 || columns != other.columns )
		{
			cout << "\nERROR: Missing data.\n" << endl;
		}
		else
		{
			result.rows = rows;
			result.columns = other.columns;
			result.data = new T* [ result.rows ];
			for ( int x = 0; x < result.rows; x=x+1 )
			{
				result.data [x] = new T [ result.columns ];
			}

			for ( int x = 0; x < result.rows; x=x+1 )
			{
				for ( int y = 0; y < result.columns; y=y+1 )
				{
					result.data [ x ][ y ] = data [ x ][ y ] - other.data [ x ][ y ];
				}
			} 
		} 
		return ( result );
	}


	Matrix& operator* ( const Matrix <T> &other )
	{
	static Matrix <T> result ( 1, 1, 0 );
	int x = 0;
	int y = 0;
	int z = 0;
	int sum = 0;
	if ( rows <= 0 || columns == 0 ||
		other.rows <= 0 || other.columns == 0 ||
		columns != other.rows )
	{
		cout << endl << "ERROR: Invalid data." << endl;
		result.data [ 0 ][ 0 ] = 0;
	}
	else
	{
	result.rows = rows;
	result.columns = other.columns;
	result.data = new T* [ result.rows ];
	for ( int x = 0; x < result.rows; x=x+1 )
	{
		result.data [x] = new T [ result.columns ];
	}
	for ( x = 0; x < result.rows; x = x + 1 )
	{
		for ( y = 0; y < result.columns; y = y + 1 )
		{
			sum = 0;
			for ( z = 0; z < columns; z = z + 1 )
			{
				sum = sum + data [ x ][ z ] * other.data [ z ][ y ];
			}
			result.data [ x ][ y ] = sum;
		}
	} 
	} 
	return ( result );
}


	const int getRows ( )
	{
	return ( rows );
	} 

	const int getColumns ( )
	{
	return ( columns );
	} 




////////////////////////////////// parte dos exercicios /////////////////////////////////////////////////////////


//funcao para gerar valores aleatorios (1201)
	void randomIntGenerate(int inferior, int superior)
	{
		srand(time(0));
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y = y+1)
					{
						data[x][y] = inferior + rand() % ( superior - inferior +1);
					}
			}
	}


	void readMatrixFromFile(const string &fileName) 
{
    ifstream afile(fileName);
    if (!afile) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    afile >> rows >> columns;
    if (rows <= 0 || columns <= 0) {
        cout << "Erro: Dimensões inválidas!" << endl;
        return;
    }

    data = new int*[rows];
    for (int x = 0; x < rows; x++) {
        data[x] = new int[columns];
        for (int y = 0; y < columns; y++) {
            afile >> data[x][y];
        }
    }

    afile.close();
}

/**
	void scalar(int constante)
	{
		int result=0;
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						data[x][y] = data[x][y] * constante;
					}
			}
	*/

Matrix<T> scalar(T constante) {
    Matrix<T> result(rows, columns, 0); // Cria nova matriz

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            result.data[x][y] = data[x][y] * constante;
        }
    }

    return result;
}

	bool identidade ()
	{
		int result=true;
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						if((x==y && data[x][y] != 1 ) || (x != y && data[x][y] != 0))
						{
							result = false;
						}
					}
			}
		return(result);
	}

	 bool operator==(const Matrix<T>& other) 
	{
       
        if (rows != other.rows || columns != other.columns) 
		{
            return (false);
        }

        
        for (int x = 0; x < rows; x=x+1) 
		{
            for (int y = 0; y < columns; y=y+1)
				{
                if (data[x][y] != other.data[x][y]) 
				{
                    return (false);
                }
            }
        }

        return (true); 
    }

	Matrix<T> add(const Matrix<T>& other)
	{
		Matrix<T> result(rows, columns, 0); 

		for(int x =0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						result.data[x][y] = data[x][y] + other.data[x][y];
					}
			}
		return result;
	}


	void addRows(int m, int n, int c)
	{
		if (m < 0 || n < 0 ) 
		{
        cout << "Erro: Índices de linha invalidos!" << endl;
        return;
		}

		for (int y = 0; y < columns; y++) 
		{
        data[m][y] = data[m][y] + (c * data[n][y]);
		}
	}


	void subtractRows(int m, int n, int c)
	{
		if (m < 0 || n < 0 ) 
		{
        cout << "Erro: Índices de linha invalidos!" << endl;
        return;
		}

		for (int y = 0; y < columns; y++) 
		{
        data[m][y] = data[m][y] - (c * data[n][y]);
		}
	}

	int searchRows(int n)
	{
		int position=-1;
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						if(data[x][y] == n)
						{
							position = x;
						}
					}
			}
		return(position);
	}

	int searchColumns(int n)
	{
		int position=-1;
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y < columns; y=y+1)
					{
						if(data[x][y] == n)
						{
							position = y;
						}
					}
			}
		return(position);
	}

	void transpose()
	{
    T** temp = new T*[columns];
    for (int y = 0; y < columns; y=y+1) 
	{
        temp[y] = new T[rows];
    }

    for (int x = 0; x < rows; x=x+1) 
	{
        for (int y = 0; y < columns; y=y+1) 
		{
            temp[y][x] = data[x][y];
        }
    }

    for (int x = 0; x < rows; x++) 
	{
        delete[] data[x];
    }
    delete[] data;

    data = temp;
    swap(rows, columns);
}

	bool sequencial ()
	{
		
		int esperado =1;

		if(rows == columns)
		{
		for(int x=0; x < rows; x=x+1)
			{
				for(int y=0; y<columns; y=y+1)
					{
						if(data[x][y] != esperado)
						{
							return(false);
						}
						esperado= esperado+1;
					}
			}
		}
		else
		{
			return(false);
		}
		return(true);
	}

	void inverter() 
	{
	    for (int x = 0; x < rows / 2; x=x+1) 
		{
	        for (int y = 0; y < columns; y=y+1) 
			{
	            int temp = data[x][y];  
	            data[x][y] = data[rows - 1 - x][y];  
	            data[rows - 1 - x][y] = temp;  
	        }
	    }
	}

	

}; //fim class


	

#endif
