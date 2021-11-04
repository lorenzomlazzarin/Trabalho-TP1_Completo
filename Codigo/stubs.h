#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes stub.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarParticipante(Participante);
};

//--------------------------------------------------------------------------------------------

class StubServicoPeca:public IServicoPeca {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarPeca(Peca);
        bool consultarPeca(Peca*);
        bool descadastrarPeca(Codigo);
        bool editarPeca(Codigo);
        //bool cadastrarProdutoInvestimento(Produto);
        // bool descadastrarProdutoInvestimento(Codigo);
        // bool realizarAplicacao(Aplicacao);
        // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

//--------------------------------------------------------------------------------------------

class StubServicoSessao:public IServicoSessao {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarSessao(Sessao);
        bool consultarSessao(Sessao*);
        bool descadastrarSessao(Codigo);
        bool editarSessao(Codigo);
        //bool cadastrarProdutoInvestimento(Produto);
        // bool descadastrarProdutoInvestimento(Codigo);
        // bool realizarAplicacao(Aplicacao);
        // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

//--------------------------------------------------------------------------------------------

class StubServicoSala:public IServicoSala {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarSala(Sala);
        bool consultarSala(Sala*);
        bool descadastrarSala(Codigo);
        bool editarSala(Codigo);
        //bool cadastrarProdutoInvestimento(Produto);
        // bool descadastrarProdutoInvestimento(Codigo);
        // bool realizarAplicacao(Aplicacao);
        // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

//--------------------------------------------------------------------------------------------
#endif // STUBS_H_INCLUDED
