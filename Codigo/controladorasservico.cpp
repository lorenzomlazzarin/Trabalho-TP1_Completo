#include "controladorasservico.h"
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------
//|                                 Participante                                       |
//--------------------------------------------------------------------------------------

bool CntrServicoAutenticacao::autenticar(Matricula *matricula, Senha senha) { // Armazena os dados em servidor ou lista
    ContainerPessoal *container;

    container = ContainerPessoal::getInstancia();

    return container->autenticarParticipante(matricula, senha); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarParticipante(Participante participante) { // Armazena os dados em servidor ou lista
    ContainerPessoal *container;

    container = ContainerPessoal::getInstancia();

    return container->incluirParticipante(participante); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::excluirParticipante1(Matricula matricula) { // Armazena os dados em servidor ou lista
    ContainerPessoal *container;

    container = ContainerPessoal::getInstancia();

    return container->excluirParticipante(matricula); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::editarParticipante1(Participante participante) { // Armazena os dados em servidor ou lista
    ContainerPessoal *container;

    container = ContainerPessoal::getInstancia();

    return container->editarParticipante(participante); // Retorna um bool
}

//--------------------------------------------------------------------------------------
//|                                 Peca                                               |
//--------------------------------------------------------------------------------------


bool CntrServicoPeca::incluirPeca1(Peca peca) { // Armazena os dados em servidor ou lista
    ContainerPeca *container;

    container = ContainerPeca::getInstancia();

    return container->incluirPeca(peca); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPeca::excluirPeca1(Codigo codigo) { // Armazena os dados em servidor ou lista
    ContainerPeca *container;

    container = ContainerPeca::getInstancia();

    return container->excluirPeca(codigo); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPeca::editarPeca1(Peca peca) { // Armazena os dados em servidor ou lista
    ContainerPeca *container;

    container = ContainerPeca::getInstancia();

    return container->editarPeca(peca); // Retorna um bool
}

bool CntrServicoPeca::visualizarPeca1(Peca *peca) { // Armazena os dados em servidor ou lista
    ContainerPeca *container;

    container = ContainerPeca::getInstancia();

    return container->visualizarPeca(peca); // Retorna um bool
}

//--------------------------------------------------------------------------------------
//|                                 Sessão                                             |
//--------------------------------------------------------------------------------------

bool CntrServicoSessao::incluirSessao1(Sessao sessao) { // Armazena os dados em servidor ou lista
    ContainerSessao *container;

    container = ContainerSessao::getInstancia();

    return container->incluirSessao(sessao); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoSessao::excluirSessao1(Codigo codigo) { // Armazena os dados em servidor ou lista
    ContainerSessao *container;

    container = ContainerSessao::getInstancia();

    return container->excluirSessao(codigo); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoSessao::editarSessao1(Sessao sessao) { // Armazena os dados em servidor ou lista
    ContainerSessao *container;

    container = ContainerSessao::getInstancia();

    return container->editarSessao(sessao); // Retorna um bool
}

bool CntrServicoSessao::visualizarSessao1(Sessao *sessao) { // Armazena os dados em servidor ou lista
    ContainerSessao *container;

    container = ContainerSessao::getInstancia();

    return container->visualizarSessao(sessao); // Retorna um bool
}

//--------------------------------------------------------------------------------------
//|                                 Sala                                               |
//--------------------------------------------------------------------------------------

bool CntrServicoSala::incluirSala1(Sala sala) { // Armazena os dados em servidor ou lista
    ContainerSala *container;

    container = ContainerSala::getInstancia();

    return container->incluirSala(sala); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoSala::excluirSala1(Codigo codigo) { // Armazena os dados em servidor ou lista
    ContainerSala *container;

    container = ContainerSala::getInstancia();

    return container->excluirSala(codigo); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoSala::editarSala1(Sala sala) { // Armazena os dados em servidor ou lista
    ContainerSala *container;

    container = ContainerSala::getInstancia();

    return container->editarSala(sala); // Retorna um bool
}

bool CntrServicoSala::visualizarSala1(Sala *sala) { // Armazena os dados em servidor ou lista
    ContainerSala *container;

    container = ContainerSala::getInstancia();

    return container->visualizarSala(sala); // Retorna um bool
}