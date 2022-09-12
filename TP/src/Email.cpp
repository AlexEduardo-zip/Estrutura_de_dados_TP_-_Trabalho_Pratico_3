#include <iostream>
#include <string>
#include "Email.hpp"

using namespace std;

typedef int TipoChave;

/////////////////////////////

bool TipoItem::Vazio()
{
    return chave;
}
TipoItem::TipoItem()
{
    chave = -1;
} // indica um item vazio
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}
TipoChave TipoItem::GetChave()
{
    return chave;
}

void TipoItem::SetChaveUsuario(TipoChave c)
{
    ChaveUsuario = c;
}
TipoChave TipoItem::GetChaveUsuario()
{
    return ChaveUsuario;
}
void TipoItem::Imprime()
{
    printf("%d ", chave);
}

void TipoItem::SetEmail(string corpo)
{
    CorpoEmail = corpo;
}
string TipoItem::GetEmail()
{
    return CorpoEmail;
};