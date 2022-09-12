// #include <iostream>
// #include <string>
#include "Email.hpp"
#include "ArvoreBinaria.hpp"

using namespace std;

typedef int TipoChave;

TipoNo::TipoNo()
{
    item.SetChave(-1);
    esq = NULL;
    dir = NULL;
};

// Construtor
ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}

// Destrutor
ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}
void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

// Pesquisa pela chave
// Retorna TipoItem
TipoItem ArvoreBinaria::Pesquisa(TipoChave chave)
{
    return PesquisaRecursivo(raiz, chave);
}
TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave)
{
    TipoItem aux;
    if (no == NULL)
    {
        aux.SetChave(-1); // Flag para item não presente
        return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

// Insere TipoItem
void ArvoreBinaria::Insere(TipoItem item)
{
    InsereRecursivo(raiz, item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo *&p, TipoItem item)
{
    if (p == NULL)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if (item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

// Remove pela chave
// retorna -1 se não encontrar o item
int ArvoreBinaria::Remove(TipoChave chave)
{
    return RemoveRecursivo(raiz, chave);
}

int ArvoreBinaria::RemoveRecursivo(TipoNo *&no, TipoChave chave)
{
    TipoNo *aux;
    if (no == NULL)
    {
        return -1;
    }
    if (chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
    else
    {
        if (no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
    return 1;
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo *&r)
{
    if (r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}