#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "conteiner.h"

//--------------------------------------------------------------------------------------------

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Matricula*, Senha);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal:public IServicoPessoal{
    public:
        bool cadastrarParticipante(Participante);
        bool editarParticipante1(Participante);
        bool excluirParticipante1(Matricula);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPeca:public IServicoPeca{
    public:
        bool incluirPeca1(Peca);
        bool visualizarPeca1(Peca*);
        bool editarPeca1(Peca);
        bool excluirPeca1(Codigo);

};

//---------------------------------------------------------------------------------------------

class CntrServicoSessao:public IServicoSessao{
    public:
        bool incluirSessao1(Sessao);
        bool visualizarSessao1(Sessao*);
        bool editarSessao1(Sessao);
        bool excluirSessao1(Codigo);
};

//--------------------------------------------------------------------------------------------

class CntrServicoSala:public IServicoSala{
    public:
        bool incluirSala1(Sala);
        bool visualizarSala1(Sala*);
        bool editarSala1(Sala);
        bool excluirSala1(Codigo);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED