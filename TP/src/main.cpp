#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>

#include "ArvoreBinaria.hpp"
#include "hash.hpp"
#include "Email.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int c, MtamanhoTabela;
    string inputFileName, outputFileName, comando;
    extern char *optarg;

    while ((c = getopt(argc, argv, "i:I:o:O:h")) != EOF) // Leitura dos parametros de execução
    {
        c = ::tolower(c);
        switch (c)
        {
        case 'i':
            inputFileName = optarg;
            break;
        case 'o':
            outputFileName = optarg;
            break;
        };
    };

    ifstream inputFile(inputFileName);   // Abertura dos arquivos
    ofstream outputFile(outputFileName); // de entrada e saida

    inputFile >> MtamanhoTabela;

    Hash_LE Tabela;
    Tabela.SetM(MtamanhoTabela);

    while (inputFile >> comando) // Laço de repetição que termina quando alcança o fim do arquivo(EOF)
    {
        int UidentificadorUsuario, EidentificadorEmail, NnumeroPalavras;
        string mensagem;
        TipoItem EmailAuxiliar;
        switch (comando[0]) // Verifica o primeiro caracter lido do comando
        {
        case 'E': // Comando ENTREGA
            inputFile >> UidentificadorUsuario >> EidentificadorEmail >> NnumeroPalavras;
            getline(inputFile, mensagem);

            EmailAuxiliar.SetChaveUsuario(UidentificadorUsuario);
            EmailAuxiliar.SetChave(EidentificadorEmail);
            EmailAuxiliar.SetEmail(mensagem);

            if (Tabela.Insere(EmailAuxiliar) != -1) // Realiza o metodo e verifica a flag
                outputFile << "OK: MENSAGEM " << EidentificadorEmail << " PARA " << UidentificadorUsuario << " ARMAZENADA EM " << UidentificadorUsuario % MtamanhoTabela << endl;
            else
                outputFile << "ERRO: ITEM JÁ ESTÁ PRESENTE" << endl;
            break;

        case 'C': // Comando CONSULTA
            inputFile >> UidentificadorUsuario >> EidentificadorEmail;
            EmailAuxiliar = Tabela.Pesquisa(EidentificadorEmail, UidentificadorUsuario);
            if (EmailAuxiliar.GetChave() == -1) // Realiza o metodo e verifica a flag
            {
                outputFile << "CONSULTA " << UidentificadorUsuario << " " << EidentificadorEmail << ":"
                           << " MENSAGEM INEXISTENTE" << endl;
            }
            else
                outputFile << "CONSULTA " << UidentificadorUsuario << " " << EidentificadorEmail << ":" << EmailAuxiliar.GetEmail() << endl;
            break;

        case 'A': // Comando APAGA
            inputFile >> UidentificadorUsuario >> EidentificadorEmail;
            if (Tabela.Remove(EidentificadorEmail, UidentificadorUsuario) != -1) // Realiza o metodo e verifica a flag
            {
                outputFile << "OK: MENSAGEM APAGADA" << endl;
            }
            else
            {
                outputFile << "ERRO: MENSAGEM INEXISTENTE" << endl;
            }

            break;

        default:
            break;
        }
    }
    return 0;
}