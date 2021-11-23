#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes controladoras.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="\t\t\tMenu Iniciar";
    char texto2[]="1 - Autenticar/logar participante.";
    char texto3[]="2 - Cadastrar participante.";
    char texto4[]="3 - Listar pecas.";
    char textoA[]="4 - Listar sessao.";
    char textoB[]="5 - Listar sala.";
    char texto5[]="6 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de sele��o de servi�o.

    char texto6[]="\t\t\tUsuario autenticado/logado";
    char textoC[]="1 - Perfil do participante";  //manual
    char texto7[]="2 - Peça."; //antigo 1 - Selecionar servicos de pessoal.
    char texto8[]="3 - Sessão."; //antigo 2 - Selecionar servicos relacionados a produtos financeiros.
    char textoD[]="4 - Sala.";  //manual
    char texto9[]="5 - Encerrar sessao.";  //antigo numero 3.

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << textoA << endl;                                                                 // Imprime nome do campo.
        cout << textoB << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&matricula)){                         // Solicita autentica��o.
                        bool apresentar = true;                                                 // Controle de la�o.
                        while(apresentar){

                            // Apresenta tela de sele��o de servi�o.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << textoC << endl;                                             // Perfil do participante
                            cout << texto7 << endl;                                             // Peça
                            cout << texto8 << endl;                                             // Sessão.
                            cout << textoD << endl;                                             // Sala.
                            cout << texto9 << endl;                                             // Retornar menu inicial.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.

                            switch(campo){
                                case 1: cntrApresentacaoPessoal->executar(matricula);                 //semi-manual - Solicita servi�o de participante.
                                        apresentar = false;
                                        break;
                                case 2: cntrApresentacaoPeca->executar(identificador);     // Solicita servi�o de produto financeiro.
                                        break;
                                case 3: cntrApresentacaoSessao->executarSessao(identificador);     // Solicita servi�o de produto financeiro.
                                        break;
                                case 4: cntrApresentacaoSala->executarSala(identificador);     // Manual
                                        break;
                                case 5: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        CLR_SCR;                                                                // Limpa janela.
                        cout << texto10 << endl;                                                // Imprime mensagem.
                        getch();                                                                // Leitura de caracter digitado.
                    }
                    break;
            case 2: cntrApresentacaoPessoal->cadastrar();
                    break;
            case 3: cntrApresentacaoPeca->mostrarPeca();
                    break;
            case 4: cntrApresentacaoSessao->mostrarSessao();
                    break;
            case 5: cntrApresentacaoSala->mostrarSala();
                    break;
            case 6: apresentar = false;
                    break;
        }
    }
    return;
}

//#########################################################################################################################

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    // Mensagens a serem apresentadas na tela de autentica��o.

    CntrApresentacaoControle *cntrApresentacaoControle;

    char texto[]="\t\tAutenticar/Logar Participante";
    char texto1[]="Digite a Matricula  : ";
    char texto2[]="Digite a senha      : ";
    char texto4[]="1 - Tentar novamente.";
    char texto5[]="2 - Voltar para a tela inicial.";
    char texto3[]="Dado em formato incorreto. Digite algo.";
    char texto6[]="Autenticado com sucesso.";

    // Campos de entrada.

    int campo;
    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.
    bool apresentar = true;

    while(apresentar){

        // Apresenta tela de autentica��o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto << endl;
        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // L� valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // L� valor do campo.

            matricula->setValor(string(campo1));                                             // Atribui valor ao matricula
            senha.setValor(string(campo2));                                                  // Atribui Valor � senha.
            if (cntr->autenticar(matricula, senha)){
                 cout << texto6 << endl;
                 getch();
                 break;                                                                          // Abandona la�o em caso de formatos corretos.
            }

            CLR_SCR;                                                                            // Limpa janela.
            cout << texto3 <<"\n"<< endl;                                                             // Informa formato incorreto.
            cout << texto4 <<endl;
            cout << texto5 << endl;

            campo = getch() - 48;

            switch (campo){
                case 1: continue;                                     // Solicita servi�o de autentica��o.
                case 2: cntrApresentacaoControle->executar();
                    break;
            }
    }
    return true;                                                     // Solicita servi�o de autentica��o.
}

//#########################################################################################################################

void CntrApresentacaoPessoal::executar(Matricula matricula){

    // Mensagens a serem apresentadas na tela de sele��o de servi�o..

    char texto1[]="\t\tPerfil do Participante";
    char texto2[]="1 - Editar dados pessoais.";  //Consultar dados pessoais
    char textoA[]="2 - Excluir cadastro.";  //Manual
    char texto3[]="3 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela de sela��o de servi�o.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << textoA << endl;                                                                 // Excluir cadastro.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: editar(matricula);
                    break;
            case 2: excluirParticipante(matricula);
                    return;
            case 3: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\tCadastrar participante";
    char texto2[] ="Nome         :";
    char texto13[] ="Sobrenome    :"; //manual
    char texto3[] ="Email        :";
    char texto4[] ="Telefone     :";
    char texto5[] ="Matricula    :";
    char texto6[] ="Senha        :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";
    char texto15[] ="Cargo        :"; //manual


    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];                            // Cria campos para entrada dos dados.
    char campo6[80], campo7[80], campo8[80], campo9[80], campo10[80];                                                    // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Nome sobrenome; //manual
    Email email;
    Telefone telefone;
    Matricula matricula;
    Senha senha;
    Cargo cargo; //manual

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));                                                        // L� valor do campo composto.

    cout<<texto13 <<" "; //manual
    cin >> campo2; //manual
    cout << texto3 << " ";                                                                     // Imprime nome do campo.
    cin >> campo3;                                                                             // L� valor do campo.
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo4;                                                                             // L� valor do campo.
    cout << texto5 << " ";                                                                     // Imprime nome do campo.
    cin >> campo5;                                                                             // L� valor do campo.
    cout << texto6 << " ";                                                                     // Imprime nome do campo.
    cin >> campo6;                                                                             // L� valor do campo.

    cout << texto15 << " "; //manual                                                         // Imprime nome do campo.
    cin >> campo10; //manual

    try{
        nome.setValor(string(campo1));
        sobrenome.setValor(string(campo2));//manual
        email.setValor(string(campo3));
        telefone.setValor(string(campo4));
        matricula.setValor(string(campo5));
        senha.setValor(string(campo6));
        cargo.setValor(string(campo10));
        //numero.setValor(string(campo7));
        //agencia.setValor(string(campo8));
        //banco.setValor(string(campo9));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Participante participante;

    participante.setNome(nome);
    participante.setNome(sobrenome); //manual
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setMatricula(matricula);
    participante.setSenha(senha);
    participante.setCargo(cargo); //manual

    // //Cadastra usu�rio e conta.

    if(cntrServicoPessoal->cadastrarParticipante(participante)){
        cout << texto11 << endl;                                                                    // Informa sucesso.
        getch();
        return;
        }

    cout << texto12 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::editar(Matricula matricula){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\tEditar Dados Pessoais";
    char texto2[] ="Nome         :";
    char texto13[] ="Sobrenome    :";
    char texto3[] ="Email        :";
    char texto4[] ="Telefone     :";
    char texto6[] ="Senha        :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";
    char texto15[] ="Cargo        :";


    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];
    char campo6[80], campo7[80], campo8[80], campo9[80], campo10[80];

    // Instancia os dom�nios.

    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));

    cout<<texto13 <<" ";
    cin >> campo2;
    cout << texto3 << " ";
    cin >> campo3;                                                                             // L� valor do campo.
    cout << texto4 << " ";
    cin >> campo4;                                                                             // L� valor do campo.
    cout << texto6 << " ";
    cin >> campo6;                                                                             // L� valor do campo.

    cout << texto15 << " ";
    cin >> campo10;

    try{
        nome.setValor(string(campo1));
        sobrenome.setValor(string(campo2));
        email.setValor(string(campo3));
        telefone.setValor(string(campo4));
        senha.setValor(string(campo6));
        cargo.setValor(string(campo10));

    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Participante participante;

    participante.setNome(nome);
    participante.setNome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setMatricula(matricula);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    // //Cadastra usu�rio e conta.

    if(cntrServicoPessoal->editarParticipante1(participante)){
        cout << texto11 << endl;                                                                    // Informa sucesso.
        getch();
        return;
        }

    cout << texto12 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPessoal::excluirParticipante(Matricula matricula){

    CntrApresentacaoControle *cntrApresentacaoControle;

    char texto1[]="Tem certeza que deseja excluir seu perfil do sistema?";
    char texto2[]="1 - Sim, quero excluir.";
    char texto3[]="2 - Não, entrei nessa opção por engano.";
    char texto4[]="Excluido com sucesso. Parabéns você não faz mais parte desse sistema :(";

    int campo;

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        CLR_SCR;
        cout << texto1 << "\n" << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getch() - 48;

        switch (campo){
            case 1: cntrServicoPessoal->excluirParticipante1(matricula);
                    cout << texto4;
                    getch();
                    apresentar = false;
                    return;
            case 2: apresentar = false;
                    return;
        }
    }
}

//############################################################################################################################

void CntrApresentacaoPeca::executar(Codigo identificador){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="\t\tServiços de Peça";
    char texto2[] ="1 - Cadastrar Peça.";
    char texto3[] ="2 - Consultar Peças.";
    char texto4[] ="3 - Editar peça.";
    char texto5[] ="4 - Exluir Peça.";
    char texto8[] ="5 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
        // cout << texto6 << endl;                                                                 // Imprime nome do campo.
        // cout << texto7 << endl;                                                                 // Imprime nome do campo.
        cout << texto8 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.


        switch(campo){
            case 1: incluirPeca(); //troquei o 1 pelo 2 e vice e versa.
                break;
            case 2: mostrarPeca();  //troquei o 1 pelo 2 e vice e versa.
                break;
            case 3: editarPeca();  //manual
                break;
            case 4: excluirPeca();  //antigo 3
                break;
            case 5: apresentar = false;
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::incluirPeca(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tCadastrar Peça";
    char texto2[] ="Nome da peça    :";
    char texto3[] ="Tipo            :";
    char texto4[] ="Classificação   :";
    char texto5[] ="Dados em formato incorreto. Digite algo.";
    char texto6[] ="Sucesso no cadastramento. Digite algo.";
    char texto7[] ="Falha no cadastramento. Digite algo.";
    char texto8[] ="Codigo          :";


    char campo1[80], campo2[80], campo3[80], campo4[80];                                                  // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Codigo codigo;
    Tipo tipo;
    Classificacao classificacao;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));                                                                              // L� valor do campo composto.
    cout << texto3 << " ";
    cin >> campo2;
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo3;                                                                             // L� valor do campo.
    cout << texto8 <<" ";
    cin >> campo4;

    try{
        nome.setValor(string(campo1));
        tipo.setValor(string(campo2));
        classificacao.setValor(string(campo3));
        codigo.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Peca peca;

    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);
    peca.setCodigo(codigo);

    // //Cadastra usu�rio e conta.

    if(cntrServicoPeca->incluirPeca1(peca)){
            cout << texto6 << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << texto7 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::excluirPeca(){

    char texto1[]="Qual peça você deseja excluir?";
    char texto2[]="Digite o código da Peça:";
    char texto3[]="Sucesso! Peça excluida.";
    char texto4[]="Falha! Não encontramos essa peça.";
    char texto5[]="Falha! Esse Código está incorreto.";

    char campo1[80];

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << "  ";
    cin >> campo1;

    Codigo codigo;

    try{
        codigo.setValor(string(campo1));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    if(cntrServicoPeca->excluirPeca1(codigo)){
        cout << texto3 << endl;
        getch();
        return;
    }
    CLR_SCR;
    cout << texto4 << endl;
    getch();
    return;

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::editarPeca(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tEditar Peça";
    char texto2[] ="Nome da peça    :";
    char texto3[] ="Tipo            :";
    char texto4[] ="Classificação   :";
    char texto5[] ="Dados em formato incorreto. Digite algo.";
    char texto6[] ="Sucesso na Edição. Digite algo.";
    char texto7[] ="Falha na Edição. Digite algo.";
    char texto8[] ="Código          :";


    char campo1[80], campo2[80], campo3[80], campo4[80];                                                  // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Tipo tipo;
    Codigo codigo;
    Classificacao classificacao;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;
    cout << texto8 << " ";
    cin >> campo4;
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));                                                                              // L� valor do campo composto.
    cout << texto3 << " ";
    cin >> campo2;
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo3;                                                                             // L� valor do campo.

    try{
        nome.setValor(string(campo1));
        tipo.setValor(string(campo2));
        classificacao.setValor(string(campo3));
        codigo.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Peca peca;

    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);
    peca.setCodigo(codigo);

    // //Cadastra usu�rio e conta.

    if(cntrServicoPeca->editarPeca1(peca)){
            cout << texto6 << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << texto7 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::mostrarPeca(){

    Peca *peca;
    CLR_SCR;
    cntrServicoPeca->visualizarPeca1(peca);
    getch();
    return;
}

//######################################################################################################################

void CntrApresentacaoSessao::executarSessao(Codigo identificador){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="\t\t\tServiço de Sessão";
    char texto2[] ="1 - Cadastrar sessão.";
    char texto3[] ="2 - Consultar sessões.";
    char texto4[] ="3 - Editar sessão.";
    char texto5[] ="4 - Exluir sessão.";
    char texto8[] ="5 - Retornar.";  //antigo 7

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
        cout << texto8 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: incluirSessao(); //troquei o 1 pelo 2 e vice e versa.
                break;
            case 2: mostrarSessao();  //troquei o 1 pelo 2 e vice e versa.
                break;
            case 3: editarSessao();  //manual
                break;
            case 4: excluirSessao();  //antigo 3
                break;
            case 5: apresentar = false;
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::mostrarSessao(){

    Sessao *sessao;
    CLR_SCR;
    cntrServicoSessao->visualizarSessao1(sessao);
    getch();
    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::incluirSessao(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tCadastrar Sessão";
    char texto2[] ="Data               :";
    char texto3[] ="Horario            :";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";
    char texto8[] ="Codigo da sessão (peça-sessao) :";


    char campo1[80], campo2[80], campo3[80];

    // Instancia os dom�nios.

    Data data;
    Horario horario;
    Codigo codigo;

    // Apresenta tela de cadastramento.

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";
    cin >> campo1;
    cout << texto3 << " ";
    cin >> campo2;
    cout << texto8 << " ";
    cin >> campo3;

    try{
        data.setValor(string(campo1));
        horario.setValor(string(campo2));
        codigo.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;
        getch();
        return;
    }

    // Instancia e inicializa entidades.

    Sessao sessao;

    sessao.setData(data);
    sessao.setHorario(horario);
    sessao.setCodigo(codigo);

    // //Cadastra usu�rio e conta.
    if(cntrServicoSessao->incluirSessao1(sessao)){
            cout << texto6 << endl;
            getch();
            return;
        }

    cout << texto7 << endl;
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::excluirSessao(){

    char texto1[]="Qual sessão você deseja excluir?";
    char texto2[]="Digite o código da sessão (peça-sessao):";
    char texto3[]="Sucesso! sessão excluida.";
    char texto4[]="Falha! Não encontramos essa sessão.";

    char campo1[80];

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << "  ";
    cin >> campo1;

    Codigo codigo;

    codigo.setValor(campo1);

    if(cntrServicoSessao->excluirSessao1(codigo)){
        cout << texto3 << endl;
        getch();
        return;
    }
    CLR_SCR;
    cout << texto4 << endl;
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::editarSessao(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tEditar Sessão";
    char texto2[] ="Data              :";
    char texto3[] ="Horario           :";
    char texto5[]="Dados em formato incorreto. Digite algo.";
    char texto6[]="Sucesso no cadastramento. Digite algo.";
    char texto7[]="Falha no cadastramento. Digite algo.";
    char texto8[] ="Codigo da sessão (peça-sessao) :";


    char campo1[80], campo2[80], campo3[80];                                                 // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Data data;
    Horario horario;
    Codigo codigo;

    // Apresenta tela de cadastramento.

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto8 << " ";
    cin >> campo3;
    cout << texto2 << " ";
    cin >> campo1;
    cout << texto3 << " ";
    cin >> campo2;


    try{
        data.setValor(string(campo1));
        horario.setValor(string(campo2));
        codigo.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Sessao sessao;

    sessao.setData(data);
    sessao.setHorario(horario);
    sessao.setCodigo(codigo);

    // //Cadastra usu�rio e conta.

    if(cntrServicoSessao->editarSessao1(sessao)){
            cout << texto6 << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << texto7 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//#####################################################################################################

void CntrApresentacaoSala::executarSala(Codigo identificador){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="\t\tServiço de Sala";
    char texto2[] ="1 - Cadastrar sala.";
    char texto3[] ="2 - Consultar salas.";
    char texto4[] ="3 - Editar sala.";
    char texto5[] ="4 - Exluir sala.";
    char texto8[] ="5 - Retornar.";  //antigo 7

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de la�o.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
        cout << texto8 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.

        switch(campo){
            case 1: incluirSala(); //troquei o 1 pelo 2 e vice e versa.
                break;
            case 2: mostrarSala();  //troquei o 1 pelo 2 e vice e versa.
                break;
            case 3: editarSala();  //manual
                break;
            case 4: excluirSala();  //antigo 3
                break;
            case 5: apresentar = false;
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::mostrarSala(){

    Sala *sala;
    CLR_SCR;
    cntrServicoSala->visualizarSala1(sala);
    getch();
    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::incluirSala(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tCadastrar Sala";
    char texto2[] ="Nome da Sala    :";
    char texto3[] ="Capacidade      :";
    char texto5[] ="Dados em formato incorreto. Digite algo.";
    char texto6[] ="Sucesso no cadastramento. Digite algo.";
    char texto7[] ="Falha no cadastramento. Digite algo.";
    char texto8[] ="Codigo da sala (peça-sessao-sala) :";


    char campo1[80], campo2[80], campo3[80];                                                 // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Capacidade capacidade;
    Codigo codigo;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));                                                                              // L� valor do campo composto.
    cout << texto3 << " ";
    cin >> campo2;
    cout << texto8 << " ";
    cin >> campo3;

    try{
        nome.setValor(string(campo1));
        capacidade.setValor(campo2);
        codigo.setValor(campo3);

    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Sala sala;

    sala.setNome(nome);
    sala.setCapacidade(capacidade);
    sala.setCodigo(codigo);                                      // //Cadastra usu�rio e conta.

    if(cntrServicoSala->incluirSala1(sala)){
            cout << texto6 << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << texto7 << endl;                                                                            // Informa falha.
    getch();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::excluirSala(){

    char texto1[]="Qual sala você deseja excluir?";
    char texto2[]="Digite o código da sala (peça-sala-sessão):";
    char texto3[]="Sucesso! sala excluida.";
    char texto4[]="Falha! Não encontramos essa sala.";

    char campo1[80];

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << "  ";
    cin >> campo1;

    Codigo codigo;

    codigo.setValor(string(campo1));

    if(cntrServicoSala->excluirSala1(codigo)){
        cout << texto3 << endl;
        getch();
        return;
    }
    CLR_SCR;
    cout << texto4 << endl;
    getch();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSala::editarSala(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="\t\t\tEditar Sala";
    char texto2[] ="Nome da Sala    :";
    char texto3[] ="Capacidade      :";
    char texto5[] ="Dados em formato incorreto. Digite algo.";
    char texto6[] ="Sucesso no cadastramento. Digite algo.";
    char texto7[] ="Falha no cadastramento. Digite algo.";
    char texto8[] ="Codigo da sala (peça-sala-sessão):";


    char campo1[80], campo2[80], campo3[80];                                                 // Cria campos para entrada dos dados.

    // Instancia os dom�nios.

    Nome nome;
    Capacidade capacidade;
    Codigo codigo;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicita��o ao usu�rio.
    cout << texto8 << " ";
    cin >> campo3;
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.ignore();
    cin.getline(campo1,sizeof(campo1));                                                                              // L� valor do campo composto.
    cout << texto3 << " ";
    cin >> campo2;

    try{
        nome.setValor(string(campo1));
        capacidade.setValor(campo2);
        codigo.setValor(campo3);

    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    // Instancia e inicializa entidades.

    Sala sala;

    sala.setNome(nome);
    sala.setCapacidade(capacidade);
    sala.setCodigo(codigo);                                      // //Cadastra usu�rio e conta.

    if(cntrServicoSala->editarSala1(sala)){
            cout << texto6 << endl;                                                                    // Informa sucesso.
            getch();
            return;
        }

    cout << texto7 << endl;                                                                            // Informa falha.
    getch();

    return;
}
