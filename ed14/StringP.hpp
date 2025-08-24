#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include <string>
#include "erro.hpp"  // Biblioteca de erros

class StringP : public Erro {
private:
    std::string content;

public:
   StringP(std::string input) {
    if (input.empty()) {
        setErro(1);
        content = "[ERRO] Entrada vazia.";
    } else {
        content = input;
    }
}


    // 01. Conversão para inteiro
    int getInt() 
{
        int result = 0;
        bool isNegative = false;
        int x = 0;

        if (content.empty()) 
		{
            setErro(1);
            return -1;
        }
        if (content[0] == '-') 
		{ 
			isNegative = true; 
			x = x + 1; 
		}

        while (x < content.length()) 
		{
            if (content[x] < '0' || content[x] > '9') 
			{
                setErro(2);
                return -1;
            }
            result = result * 10 + (content[x] - '0');
            x = x + 1;
		}
        return result;
    }

    // 02. Conversão para double
    double getDouble() 
{
        double result = 0.0;
        bool isNegative = false;
		bool hasDecimal = false;
        int x = 0;
        double decimalPlace = 0.1;

        if (content.empty()) 
		{
            setErro(3);
            return 0.0;
        }
        if (content[0] == '-') 
		{
			isNegative = true; x = x + 1; 
		}
        while (x < content.length()) 
		{
            if (content[x] == '.' && !hasDecimal) 
			{
                hasDecimal = true;
                x = x + 1;
            }
            if (content[x] < '0' || content[x] > '9') 
			{
                setErro(4);
                return 0.0;
            }

            if (hasDecimal) 
			{
                result = result + (content[x] - '0') * decimalPlace;
                decimalPlace = decimalPlace * 0.1;
            } 
			else
			{
                result = result * 10 + (content[x] - '0');
            }
            x = x + 1;
        }

        return result;
    }

    // 03. Conversão para booleano
    bool getBoolean() 
	{
        std::string lowerContent = toLowerCase();
        return (lowerContent == "true" || lowerContent == "t" || lowerContent == "1" || lowerContent == "f" || lowerContent == "0");
    }

    // 04. Verificar se contém subtexto
    bool contains(std::string subtexto) 
	{
        return content.find(subtexto) != std::string::npos;
    }

    // 05. Converter para maiúsculas
    std::string toUpperCase() 
	{
        std::string result = content;
        int x = 0;

        while (x < result.length())
			{
            if (result[x] >= 'a' && result[x] <= 'z') 
			{
                result[x] = result[x] - 32;
            }
            x = x + 1;
        }

        return result;
    }

    // 06. Converter para minúsculas
    std::string toLowerCase() 
{
        std::string result = content;
        int x = 0;

        while (x < result.length()) 
		{
            if (result[x] >= 'A' && result[x] <= 'Z') 
			{
                result[x] = result[x] + 32;
            }
            x = x + 1;
        }

        return result;
    }

    // 07. Substituir caracteres
    std::string replace(char original, char novo) 
{
        std::string result = content;
        int x = 0;

        while (x < result.length()) 
		{
            if (result[x] == original)
			{
                result[x] = novo;
            }
            x = x + 1;
        }

        return result;
    }

    // 08. Cifra de César
    std::string encrypt() 
{
        std::string result = content;
        int x = 0;

        while (x < result.length()) 
		{
            if ((result[x] >= 'a' && result[x] <= 'z'))
			{
                result[x] = (result[x] - 'a' + 3) % 26 + 'a';
            } 
			else if ((result[x] >= 'A' && result[x] <= 'Z'))
			{
                result[x] = (result[x] - 'A' + 3) % 26 + 'A';
            }
            x = x + 1;
        }

        return result;
    }

    // 09. Decodificar Cifra de César
    std::string decrypt() 
{
        std::string result = content;
        int x = 0;

        while (x < result.length()) 
		{
            if ((result[x] >= 'a' && result[x] <= 'z')) 
			{
                result[x] = (result[x] - 'a' - 3 + 26) % 26 + 'a';
            }
			else if ((result[x] >= 'A' && result[x] <= 'Z')) 
			{
                result[x] = (result[x] - 'A' - 3 + 26) % 26 + 'A';
            }
            x = x + 1;
        }

        return result;
    }

    // 10. Separação por espaços em branco
    int split(std::string sequencia[]) 
{
        int count = 0;
        std::string temp = "";
        int x = 0;

        while (x < content.length()) 
		{
            if (content[x] == ' ') 
			{
                if (!temp.empty()) 
				{
                    sequencia[count] = temp;
                    count = count + 1;
                    temp = "";
                }
            } 
			else
			{
                temp = temp + content[x];
            }
            x = x + 1;
        }

        if (!temp.empty())
		{
            sequencia[count] = temp;
            count = count + 1;
        }

        return count;
    }

    // Extra E1: Separação por delimitador personalizado
    int split(std::string sequencia[], char delimiter)
	{
        int count = 0;
        std::string temp = "";
        int x = 0;

        while (x < content.length()) 
		{
            if (content[x] == delimiter) 
			{
                if (!temp.empty())
				{
                    sequencia[count] = temp;
                    count = count + 1;
                    temp = "";
                }
            } 
			else 
			{
                temp = temp + content[x];
            }
            x = x + 1;
        }

        if (!temp.empty()) 
		{
            sequencia[count] = temp;
            count = count + 1;
        }

        return count;
    }

    // Extra E2: Inverter ordem dos símbolos
    std::string reverse() 
{
        std::string result = content;
        int len = result.length();
        int x = 0;
        int y = len - 1;

        while (x < y) 
		{
            char temp = result[x];
            result[x] = result[y];
            result[y] = temp;
            x = x + 1;
            y = y - 1;
        }

        return result;
    }
};

#endif
