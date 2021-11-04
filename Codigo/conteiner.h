#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "entidades.h"
#include "dominios.h"
#include <list>
#include <iostream>
#include <stdio.h>

using namespace std;

class ContainerPessoal {
    private:
        list<Participante> container;
        static ContainerPessoal *instancia;
        ContainerPessoal(){};

    public:
        static ContainerPessoal* getInstancia();       
        bool incluirParticipante(Participante);
        bool autenticarParticipante(Matricula*, Senha);
        bool editarParticipante(Participante);
        bool excluirParticipante(Matricula);                        
};

class ContainerPeca {
    private:
        list<Peca> container;
        static ContainerPeca *instancia;
        ContainerPeca(){};

    public:
        static ContainerPeca* getInstancia();       
        bool incluirPeca(Peca);                         
        bool visualizarPeca(Peca*);
        bool editarPeca(Peca);
        bool excluirPeca(Codigo);
};

class ContainerSessao {
    private:
        list<Sessao> container;
        static ContainerSessao *instancia;
        ContainerSessao(){};

    public:
        static ContainerSessao* getInstancia();       
        bool incluirSessao(Sessao);                         
        bool visualizarSessao(Sessao*);
        bool editarSessao(Sessao);
        bool excluirSessao(Codigo);
};

class ContainerSala {
    private:
        list<Sala> container;
        static ContainerSala *instancia;
        ContainerSala(){};

    public:
        static ContainerSala* getInstancia();       
        bool incluirSala(Sala);                         
        bool visualizarSala(Sala*);
        bool editarSala(Sala);
        bool excluirSala(Codigo);
};

#endif // CONTAINERS_H_INCLUDED

