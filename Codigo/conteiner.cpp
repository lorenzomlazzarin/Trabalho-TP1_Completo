#include "conteiner.h"


//##############################################################################################################
//#                                          Participante                                                      #
//##############################################################################################################

ContainerPessoal* ContainerPessoal::instancia = nullptr;

ContainerPessoal* ContainerPessoal::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerPessoal();
    return instancia;
}

bool ContainerPessoal::incluirParticipante(Participante participante){;
    for(list<Participante>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == participante.getMatricula().getValor()){
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(participante);

    return true;
}

bool ContainerPessoal::autenticarParticipante(Matricula *matricula, Senha senha){
    for(list<Participante>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == matricula->getValor()){
            if(elemento->getSenha().getValor() == senha.getValor()) {
                return true;
            }
        }
    }
    return false;
}

bool ContainerPessoal::excluirParticipante(Matricula matricula){
    for(list<Participante>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == matricula.getValor()){
            // Remove objeto localizado.
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerPessoal::editarParticipante(Participante participante){
    for(list<Participante>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == participante.getMatricula().getValor()){
            elemento->setNome(participante.getNome());
            elemento->setSobrenome(participante.getSobrenome());
            elemento->setEmail(participante.getEmail());
            elemento->setTelefone(participante.getTelefone());
            elemento->setSenha(participante.getSenha());
            elemento->setCargo(participante.getCargo());
            return true;
        }
    }
    return false;
}

//##############################################################################################################
//#                                              Peca                                                          #
//##############################################################################################################

ContainerPeca* ContainerPeca::instancia = nullptr;

ContainerPeca* ContainerPeca::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerPeca();
    return instancia;
}

bool ContainerPeca::incluirPeca(Peca peca){;
    for(list<Peca>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == peca.getCodigo().getValor()){
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(peca);

    return true;
}

bool ContainerPeca::excluirPeca(Codigo codigo){
    for(list<Peca>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerPeca::editarPeca(Peca peca){
    for(list<Peca>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == peca.getCodigo().getValor()){
            elemento->setNome(peca.getNome());
            elemento->setTipo(peca.getTipo());
            elemento->setClassificacao(peca.getClassificacao());
            return true;
        }
    }
    return false;
}

bool ContainerPeca::visualizarPeca(Peca* peca){
    int numeracao = 1;

    char texto1[]="Essas são as peças existentes:";
    cout << texto1 << "\n" << endl;

    for(list<Peca>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        cout << numeracao << " - ";
        std::cout << elemento->getNome().getValor() << " (";
        std::cout << elemento->getCodigo().getValor() << ")" << endl;
        std::cout << "  Tipo:" << elemento->getTipo().getValor() << endl;
        std::cout << "  Classificação:" << elemento->getClassificacao().getValor() << endl;

        numeracao++;

    }
    return true;
}

//##############################################################################################################
//#                                              Sessão                                                        #
//##############################################################################################################

ContainerSessao* ContainerSessao::instancia = nullptr;

ContainerSessao* ContainerSessao::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerSessao();
    return instancia;
}

bool ContainerSessao::incluirSessao(Sessao sessao){;
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sessao.getCodigo().getValor()){
            return false;
        }
    }
    container.push_back(sessao);

    return true;
}

bool ContainerSessao::excluirSessao(Codigo codigo){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            // Remove objeto localizado.
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerSessao::editarSessao(Sessao sessao){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sessao.getCodigo().getValor()){
            elemento->setData(sessao.getData());
            elemento->setHorario(sessao.getHorario());
            return true;
        }
    }
    return false;
}

bool ContainerSessao::visualizarSessao(Sessao* sessao){
    int numeracao = 1;

    char texto1[]="Essas são as Sessões existentes:";
    cout << texto1 << "\n" << endl;

    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        cout << numeracao << " - ";
        std::cout << elemento->getCodigo().getValor() << endl;
        std::cout << "  Data:" << elemento->getData().getValor() << endl;
        std::cout << "  Horario:" << elemento->getHorario().getValor() << endl;

        numeracao++;

    }
    return true;
}

//##############################################################################################################
//#                                                Sala                                                        #
//##############################################################################################################

ContainerSala* ContainerSala::instancia = nullptr;

ContainerSala* ContainerSala::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerSala();
    return instancia;
}

bool ContainerSala::incluirSala(Sala sala){;
    for(list<Sala>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sala.getCodigo().getValor()){
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(sala);

    return true;
}

bool ContainerSala::excluirSala(Codigo codigo){
    for(list<Sala>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == codigo.getValor()){
            // Remove objeto localizado.
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerSala::editarSala(Sala sala){
    for(list<Sala>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getValor() == sala.getCodigo().getValor()){
            elemento->setNome(sala.getNome());
            elemento->setCapacidade(sala.getCapacidade());
            return true;
        }
    }
    return false;
}

bool ContainerSala::visualizarSala(Sala* sala){
    int numeracao = 1;

    char texto1[]="Essas são as Sala existentes:";
    cout << texto1 << "\n" << endl;

    for(list<Sala>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        cout << numeracao << " - ";
        std::cout << elemento->getNome().getValor() << " (";
        std::cout << elemento->getCodigo().getValor() << ")" << endl;
        std::cout << "  Capacidade:" << elemento->getCapacidade().getValor() << endl;

        numeracao++;

    }
    return true;
}