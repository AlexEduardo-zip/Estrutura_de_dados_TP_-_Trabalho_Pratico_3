#include "hash.hpp"

using namespace std;

typedef int TipoChave; // Define o TipoChave

Hash_LE::Hash_LE()
{
}

// Funçao hash!
// Calcula o resto da divisão da chave pelo tamanho da tabela
int Hash_LE::Hash(TipoChave Chave)
{
    return (Chave % m);
}

// Atribui o tamanho da tabela
void Hash_LE::SetM(int iM)
{
    m = iM;
}

// Retorna o tamanho da tabela
int Hash_LE::GetM()
{
    return m;
}

// Retorna o item encontrado ou um item vazio
// (chave == -1) se não estiver presente
TipoItem Hash_LE::Pesquisa(TipoChave chave, TipoChave chaveUsuario)
{
    int pos;
    TipoItem item;
    pos = Hash(chaveUsuario);
    item = Tabela[pos].Pesquisa(chave);
    if (item.GetChaveUsuario() == chaveUsuario)
        return item;
    else
    {
        TipoItem itemNulo;
        return itemNulo;
    }
}

// Insere um novo item
// Retorna -1 se o item ja foi inserido
int Hash_LE::Insere(TipoItem item)
{
    TipoItem aux;
    int pos;
    aux = Pesquisa(item.GetChave(), item.GetChaveUsuario());
    if (!aux.Vazio())
        return -1;
    else
    {
        pos = Hash(item.GetChaveUsuario());
        Tabela[pos].Insere(item);
        return 1;
    }
}

// Remove o item
// (ID_Email, ID_Usuario)
// Retorna -1 se o item não existe
int Hash_LE::Remove(TipoChave chave, TipoChave chaveUsuario)
{
    int pos;
    TipoItem itemAux = Pesquisa(chave, chaveUsuario);
    if (itemAux.GetChave() == -1)
        return -1;
    else
    {
        pos = Hash(chaveUsuario);
        return Tabela[pos].Remove(chave);
    }
}