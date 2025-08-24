#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

class Erro {
private:
    int erro;

public:
    ~Erro() {}  // Implementação direta do destrutor
    Erro() : erro(0) {}

    static const std::string NO_ERROR;

    int getErro() { return erro; }

    bool hasError() { return erro != 0; }

    virtual std::string getErroMsg() {
        return erro != 0 ? "[ERRO] Codigo: " + std::to_string(erro) : NO_ERROR;
    }

protected:
    void setErro(int codigo) { erro = codigo; }  // Implementação direta do método
};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif
