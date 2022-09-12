#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "Email.hpp"

class TipoNo
{
public:
    TipoNo();

private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    void Caminha(int tipo);
    TipoItem Pesquisa(TipoChave chave);
    int Remove(TipoChave chave);
    void Limpa();

private:
    void InsereRecursivo(TipoNo *&p, TipoItem item);
    void ApagaRecursivo(TipoNo *p);
    TipoItem PesquisaRecursivo(TipoNo *p, TipoChave chave);
    int RemoveRecursivo(TipoNo *&p, TipoChave chave);
    void Antecessor(TipoNo *q, TipoNo *&r);
    TipoNo *raiz;
};
#endif