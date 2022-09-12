#ifndef HASH_H
#define HASH_H

#include <string>
#include "Email.hpp"
#include "ArvoreBinaria.hpp"

using namespace std;

typedef int TipoChave;

// Classe Hash
// Função Modulo
// Tamanho Maximo igual a 100!!!
class Hash_LE
{
public:
    Hash_LE();
    TipoItem Pesquisa(TipoChave chave, TipoChave chaveUsuario);
    int Insere(TipoItem item);
    int Remove(TipoChave chave, TipoChave chaveUsuario);
    void SetM(int iM);
    int GetM();
    void ImprimeTabela();

private:
    int m;
    static const int M = 100; // Tamanho Maximo da tabela, se necessario altere!!!
    int Hash(TipoChave Chave);
    ArvoreBinaria Tabela[M];
};

#endif