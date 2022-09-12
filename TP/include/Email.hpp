#ifndef EMAIL_H
#define EMAIL_H

#include <string>

using namespace std;

typedef int TipoChave;

class TipoItem
{
public:
    TipoItem();
    TipoItem(TipoChave c);
    void SetChave(TipoChave c);
    TipoChave GetChave();
    void SetChaveUsuario(TipoChave c);
    TipoChave GetChaveUsuario();
    void Imprime();
    bool Vazio();
    void SetEmail(string corpo);
    string GetEmail();

private:
    TipoChave chave;
    // outros membros
    TipoChave ChaveUsuario;
    string CorpoEmail;
};

#endif