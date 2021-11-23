#include <string.h>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <tchar.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"


/*------------------------------
Amaral
Amorim
ederdeamaral@gmail.com
(61)-983196477
12345
Octav1@!
ator
------------------------------*/


using namespace std;

int a = 0;
extern int a;

int main()
{

    SetConsoleOutputCP( 65001 ); //Ativa os caracteres especiais no terminal.

    // Instanciar controladoras.
    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;
    IApresentacaoPeca *cntrApresentacaoPeca;
    IApresentacaoSessao *cntrApresentacaoSessao;
    IApresentacaoSala *cntrApresentacaoSala;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    cntrApresentacaoPeca = new CntrApresentacaoPeca();
    cntrApresentacaoSessao = new CntrApresentacaoSessao();
    cntrApresentacaoSala = new CntrApresentacaoSala();

    // Instanciar serviços.

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoPessoal *cntrServicoPessoal;
    IServicoPeca *cntrServicoPeca;
    IServicoSessao *cntrServicoSessao;
    IServicoSala *cntrServicoSala;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoPessoal = new CntrServicoPessoal();
    cntrServicoPeca = new CntrServicoPeca();
    cntrServicoSessao = new CntrServicoSessao();
    cntrServicoSala = new CntrServicoSala();

    // Interligar controladoras e serviço.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrApresentacaoPeca(cntrApresentacaoPeca);
    cntrApresentacaoControle->setCntrApresentacaoSessao(cntrApresentacaoSessao);
    cntrApresentacaoControle->setCntrApresentacaoSala(cntrApresentacaoSala);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrServicoPessoal(cntrServicoPessoal);
    cntrApresentacaoPeca->setCntrServicoPeca(cntrServicoPeca);
    cntrApresentacaoSessao->setCntrServicoSessao(cntrServicoSessao);
    cntrApresentacaoSala->setCntrServicoSala(cntrServicoSala);

    cntrApresentacaoControle->executar(); //Solicitar serviço (começar o programa).

    return 0; //Finaliza.
}
