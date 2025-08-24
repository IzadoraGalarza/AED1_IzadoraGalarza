/**
*Exemplo ed15 
*Aluna: Izadora Galarza Alves
*Professor : Theldo Cruz
*/

#include<iostream> 
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>
#include<string>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>

/// Outras dependencias ////

void pause (std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout<<std::endl<<text;
    std::cin.ignore();
    std::getline(std::cin,dummy);
    std::cout<<std::endl<<std::endl;
}
////////////////////////////////////////


/**
Funcao para acrescentar caractere ao final
de uma cadeia de caracteres, por meio de apontador.
@return apontador para a cadeia atualizada
@param s - apontador para cadeia de caracteres
@param c - caractere a ser inserido
*/

char* str_push_back(char *s, char c) 
{
    if (s == NULL) //caso esteja vazio 
	{
        char *novo = (char*) malloc(2 * sizeof(char)); //primeiro aloco espaco
        if (novo == NULL) 
		{
			return (NULL);
		}
        novo[0] = c;
        novo[1] = '\0';
        return(novo);
    }

    int length = 0;
    while (*(s + length) != '\0') 
	{
        length = length +1;
    }

    char *novo = (char*) malloc((length + 2) * sizeof(char));
    if (novo == NULL)
	{
		return (NULL);
	}
	
    for (int x = 0; x < length; x=x+1) 
	{
        *(novo + x) = *(s + x);
    }

    *(novo + length) = c;
    *(novo + length + 1) = '\0';

    free(s);
    return novo;
}

void exe1500()
{
}
void exe1501()
{
	char* s = NULL;

    printf("01 - push_back:\n");
	s = str_push_back(s, 'O');
    printf("Resultado: %s\n", s);

    free(s);
	pause("Apertar ENTER para continuar.");
}

/*Funcao para remover caractere do final
de uma cadeia de caracteres, por meio de apontador.
@return apontador para a cadeia atualizada, ou vazia,
@param s - apontador para cadeia de caracteres
*/
char* str_pop_back ( char *s )
{
	if(s==NULL)
	{
		return(NULL);
	}

	int length = 0;
    while (*(s + length) != '\0') 
	{
        length= length +1;
    }

	char* novo = (char*) malloc(length * sizeof(char));
    if (novo == NULL) 
	{
		return (NULL);
	}
	
	int tamanho = length -1;
    for (int x = 0; x < tamanho; x=x+1) 
	{
        *(novo + x) = *(s + x);
    }

    *(novo + length - 1) = '\0';

    free(s);
    return novo;
}


void exe1502()
{
	char* s = NULL;

    printf("01 - push_back:\n");
    s = str_push_back(s, 'N');
    s = str_push_back(s, 'O');
    s = str_push_back(s, 'V');
	s = str_push_back(s, 'O');
    printf("%s%s\n", "Antes de pop_back: ",s);
    s = str_pop_back(s);
    s = str_pop_back(s);
    s = str_pop_back(s);
    printf("Resultado: %s\n", s);

    free(s);
	pause("Apertar ENTER para continuar.");
}

/**
3
	*/

char* str_push_front(char c, char *s) 
{
    int length = 0;
    while (*(s + length)) 
	{
		length=length+1;
	}
    for (int x = length; x >= 0; x=x-1) 
	{
        *(s + x + 1) = *(s + x);
    }
    *s = c;
    return s;
}


void exe1503()
{
    char s[100] = "ela";
    printf("\n03 - str_push_front: '%s'\n", s);
    str_push_front('B', s);
    printf("Resultado: '%s'\n", s); 
	pause("Apertar ENTER para continuar");
}


/**
4
*/

char* str_pop_front(char *s) 
{
    int x = 0;
    while (*(s + x)) 
	{
        *(s + x) = *(s + x + 1);
        x=x+1;
    }
    return s;
}

void exe1504()
{
    char s[100] = "bola";
    cout <<"\n04 - str_pop_front:" << s << endl;;
    str_pop_front(s);
    cout<< "Resultado: " <<  s;
	pause("Apertar ENTER para continuar");
}

/**5*/
char* str_push_mid(char *s, char c) 
{
    int length = 0;
    while (*(s + length)) 
		{
			length = length +1;
		}
    if (length < 2) 
	{
		return s;
	}

    int mid = length / 2;
    for (int x = length; x >= mid; x=x-1)
		{
        *(s + x + 1) = *(s + x);
        }
    *(s + mid) = c;
    return s;
}

void exe1505()
{
    char s[100] = "casa";
    cout << "\n05 - str_push_mid: " << s <<endl;
    str_push_mid(s, 'X');
    cout << "Resultado: "<< s; // Ex: "caXsa
	pause("Apertar ENTER para continuar");
}

/**6*/

char* str_pop_mid(char *s)
{
    int length = 0;
    while (*(s + length)) 
		{
			length = length +1;
		}

    if (length < 2) 
	{
		return s;
	}

    int mid = length / 2;
    for (int x = mid; x < length; x=x+1) 
	{
        *(s + x) = *(s + x + 1);
    }
    return s;
}

void exe1506 ()
{
    char s[100] = "gasto";
    cout << "\n06 - str_pop_mid: " << s << endl;
    str_pop_mid(s);
    cout<< "Resultado: " << s; 
    pause("Apertar ENTER para continuar.");
}

/**7*/

char* str_insert(char *s, char c, int index) 
{
    int length = 0;
    while (*(s + length)) 
	{
		length = length +1;
	}
    if (index < 0 || index > length) return s;

    for (int x = length; x >= index; x=x-1)
        *(s + x + 1) = *(s + x);

    *(s + index) = c;
    return s;
}

void exe1507()
{
    char s[100] = "sorir";
    cout<< "\n07 - str_insert: " << s;
    str_insert(s, 'r', 2); 
    cout << "Resultado: "<< s; 
    pause("Apertar ENTER para continuar.");
}


/**8*/
char* str_remove(char *s, int index) 
{
    int length = 0;
    while (*(s + length))
		{
			length = length +1;
		}
    if (index < 0 || index >= length) return s;

    for (int x = index; x < length; x=x+1)
        *(s + x) = *(s + x + 1);

    return s;
}

void exe1508()
{
    char s[100] = "flor";
    printf("\n08 - str_remove: '%s' \n", s);
    str_remove(s, 1); 
    cout <<"Resultado: " << s; 
    pause("Apertar ENTER para continuar.");
}

	/**9*/
	char* str_chr(char *s, char c) 
	{
    while (*s) 
	{
        if (*s == c)
		{
         return s;
		}	
        s=s+1;
    }
    return NULL;
}

void exe1509() {
    char s[] = "paralelepipedo";
    char* p = str_chr(s, 'i');

    if (p != NULL)
        printf("Caractere encontrado: %s\n", p);
    else
        printf("Caractere nao encontrado.\n");

    pause("Apertar ENTER para continuar.");
}


/**10*/
char* str_tok(char *s, char delimiter) 
	{
    while (*s && *s != delimiter)
		{
        s=s+1;
		}
    return *s == delimiter ? s : NULL;
	}
	
void exe1510()
	{
    char s[] = "Alasca, Brasil, Canada, Dinamarca";
    char* p = str_tok(s, ',');

    if (p != NULL)
        printf(" %s\n", p);
    else
        printf("Delimitador nao encontrado.\n");

    pause("Apertar ENTER para continuar.");
}


/**ex1*/
char* str_prefix(char *prefix, char *s) 
{
    while (*prefix && *prefix == *s) 
	{
        prefix= prefix +1; 
		s=s+1;
    }
    return (*prefix == '\0') ? s : NULL;
}

void exeEX1()
{
    char s[] = "coragem";
    char prefixo[] = "co";

    char* p = str_prefix(prefixo, s);

    if (p != NULL)
        printf("Restante: %s\n", p);
    else
        printf("Prefixo nao encontrado.\n");

    pause("Apertar ENTER para continuar.");
}

/**ex2*/
char* str_suffix_chr(char *s, char *suffix) 
{
    int len_s = 0, len_suf = 0;
    while (s[len_s]) 
		{
			len_s= len_s + 1;
		}
    while (suffix[len_suf])
		{
			len_suf= len_suf +1;
		}
    if (len_suf > len_s)
	{
		return NULL;
	}
		
    char *start = s + (len_s - len_suf);
		
    for (int x = 0; x < len_suf; x=x+1) 
	{
        if (*(start + x) != *(suffix + x)) 
		{
			return NULL;
		}
	}
    return start;
}

void exeEX2()
{
    char s[] = "felicidade";
    char sufixo[] = "dade";

    char* p = str_suffix_chr(s, sufixo);

    if (p != NULL)
        printf("Sufixo encontrado: %s\n", p);
    else
        printf("Sufixo nao encontrado.\n");

    pause("Apertar ENTER para continuar.");

}

int main ( int argc, char** argv )
{
	int x = 0; 
	do
	{
		cout << "EXEMPLO1500 - Programa - v0.0\n " << endl;
		cout << "Opcoes " << endl;
		cout << " 0 - Terminar " << endl;
		cout << " 1 - push_back" << endl;
		cout << " 2 - pop_back" << endl;
		cout << " 3 - push_front" <<endl;
		cout << " 4 - pop_front" <<endl;
		cout << " 5 - push_mid" <<endl;
		cout << " 6 - pop_mid" <<endl;
		cout << " 7 - insert" <<endl;
		cout << " 8 - remove" <<endl;
		cout << " 9 - chr" <<endl;
		cout << " 10 - tok" <<endl;
		cout << " 11 - extra 1 - prefix" <<endl;
		cout << " 12 - extra 2 - suffix" <<endl;
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;

		switch ( x )
		{
			case 0: exe1500 ( );
					break;
			case 1: exe1501 ( );
					break;
			case 2: exe1502 ( );
					break;
			case 3: exe1503 ( );
					break;
			case 4: exe1504 ( );
					break;
			case 5: exe1505 ( );
					break;
			case 6: exe1506 ( );
					break;
			case 7: exe1507 ( );
					break;
			case 8: exe1508 ( );
					break;
			case 9: exe1509 ( );
					break;
			case 10: exe1510 ( );
					break;
			case 11: exeEX1 ( );
					break;
			case 12: exeEX2 ( );
					break;
			default: cout << endl << "ERRO: Valor invalido." << endl;
		} 
	}
	while ( x != 0 );
pause ( "Apertar ENTER para terminar" );
return ( 0 );
} 