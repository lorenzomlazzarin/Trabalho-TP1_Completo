#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

// Forward declarations.

class IServicoAutenticacao;
class IServicoPessoal;
class IServicoPeca;
class IServicoSessao; //Manual
class IServicoSala; //Manual

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de apresenta��o.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Matricula*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(Matricula) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        // virtual void setCntrServicoPeca(IServicoPeca*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoPeca{
    public:
        virtual void executar(Codigo) = 0;
        virtual void mostrarPeca() = 0;
        virtual void setCntrServicoPeca(IServicoPeca*) = 0;
        virtual ~IApresentacaoPeca(){}
};

class IApresentacaoSessao{
    public:
        virtual void executarSessao(Codigo) = 0;
        virtual void mostrarSessao() = 0;
        virtual void setCntrServicoSessao(IServicoSessao*) = 0;
        virtual ~IApresentacaoSessao(){}
};

class IApresentacaoSala{
    public:
        virtual void executarSala(Codigo) = 0;
        virtual void mostrarSala() = 0;
        virtual void setCntrServicoSala(IServicoSala*) = 0;
        virtual ~IApresentacaoSala(){}
};

//--------------------------------------------------------------------------------------------
// Declara��es das interfaces da camada de servi�o.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Matricula*, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
        public:
                virtual bool cadastrarParticipante(Participante) = 0;
                virtual bool editarParticipante1(Participante)=0;
                virtual bool excluirParticipante1(Matricula)=0;
                virtual ~IServicoPessoal(){}
};

class IServicoPeca{  //Class IServicoProdutosFinanceiros
        public:
                virtual bool incluirPeca1(Peca) = 0;  //CadastrarConta(Conta)
                virtual bool visualizarPeca1(Peca*) = 0;  //ConsultarConta(Conta*)
                virtual bool excluirPeca1(Codigo) = 0; //Manual  
                virtual bool editarPeca1(Peca) = 0; //Manual
                virtual ~IServicoPeca(){}  //~IServicoProdutosFinanceiros
};

class IServicoSessao{
        public:
                virtual bool incluirSessao1(Sessao) = 0;  
                virtual bool visualizarSessao1(Sessao*) = 0;
                virtual bool excluirSessao1(Codigo) = 0;
                virtual bool editarSessao1(Sessao) = 0;
                virtual ~IServicoSessao(){}
};

class IServicoSala{
        public:
                virtual bool incluirSala1(Sala) = 0;
                virtual bool visualizarSala1(Sala*) = 0;
                virtual bool excluirSala1(Codigo) = 0;
                virtual bool editarSala1(Sala) = 0;
                virtual ~IServicoSala(){}
};

#endif // INTERFACES_H_INCLUDED
