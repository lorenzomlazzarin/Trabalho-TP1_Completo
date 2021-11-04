#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras e implementa��es de m�todos.

class CntrApresentacaoControle{
    private:
        Matricula matricula;
        Codigo identificador;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoPessoal *cntrApresentacaoPessoal;
        IApresentacaoPeca *cntrApresentacaoPeca;
        IApresentacaoSessao *cntrApresentacaoSessao;
        IApresentacaoSala *cntrApresentacaoSala;
    public:
        void executar();
        void executarSessao();
        void executarSala();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoPessoal(IApresentacaoPessoal*);
        void setCntrApresentacaoPeca(IApresentacaoPeca*);
        void setCntrApresentacaoSessao(IApresentacaoSessao*);
        void setCntrApresentacaoSala(IApresentacaoSala*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPessoal(IApresentacaoPessoal *cntr){
    cntrApresentacaoPessoal = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPeca(IApresentacaoPeca *cntr){
    cntrApresentacaoPeca = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntr){
    cntrApresentacaoSessao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSala(IApresentacaoSala *cntr){
    cntrApresentacaoSala = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    
    public:
        bool autenticar(Matricula*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPessoal:public IApresentacaoPessoal{
    private:
        IServicoPessoal *cntrServicoPessoal;
        void cadastrar();
        void incluir();
        void excluirParticipante(Matricula);
        void editar(Matricula);
    public:
        void executar(Matricula);
        void setCntrServicoPessoal(IServicoPessoal*);
        //void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*);
};

inline void CntrApresentacaoPessoal::setCntrServicoPessoal(IServicoPessoal *cntr){
    cntrServicoPessoal = cntr;
}

//inline void CntrApresentacaoPessoal::setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros *cntr){
    //cntrServicoProdutosFinanceiros = cntr;
//}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoPeca:public IApresentacaoPeca{  //Antigo CntrApresentacaoProdutosFinanceiros
    private:
        IServicoPeca *cntrServicoPeca;
        void mostrarPeca();
        void incluirPeca();
        void excluirPeca();
        void editarPeca();
    public:
        void executar();
        void executar(Codigo);
        void setCntrServicoPeca(IServicoPeca*);
};

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr){
    this->cntrServicoPeca = cntr;
}

class CntrApresentacaoSessao:public IApresentacaoSessao{
    private:
        IServicoSessao *cntrServicoSessao;
        void mostrarSessao();
        void incluirSessao();
        void excluirSessao();
        void editarSessao();
    public:
        void executarSessao();
        void executarSessao(Codigo);
        void setCntrServicoSessao(IServicoSessao*);
};

inline void CntrApresentacaoSessao::setCntrServicoSessao(IServicoSessao *cntr){
    this->cntrServicoSessao = cntr;
}

class CntrApresentacaoSala:public IApresentacaoSala{  //Antigo CntrApresentacaoProdutosFinanceiros
    private:
        IServicoSala *cntrServicoSala;
        void mostrarSala();
        void incluirSala();
        void excluirSala();
        void editarSala();
    public:
        void executarSala();
        void executarSala(Codigo);
        void setCntrServicoSala(IServicoSala*);
};

inline void CntrApresentacaoSala::setCntrServicoSala(IServicoSala *cntr){
    this->cntrServicoSala = cntr;
}

#endif CONTROLADORASAPRESENTACAO_H_INCLUDED
