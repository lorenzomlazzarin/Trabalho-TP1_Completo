#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

//--------------------------------------------------------------------------------------------
// Declara��es de classes entidade e implementa��es de m�todos.



class Participante {
private:
    Matricula matricula; //antigo CPF
    Nome nome;
    Nome sobrenome; //manual
    Email email; //antigo Endereço
    Telefone telefone; //antigo CEP
    Senha senha;
    Cargo cargo; //manual
public:
    void setNome(Nome);
    Nome getNome();

    void setSobrenome(Nome); //manual
    Nome getSobrenome(); //manual

    void setEmail(Email);
    Email getEmail();

    void setTelefone(Telefone);
    Telefone getTelefone();

    void setMatricula(Matricula);
    Matricula getMatricula();

    void setSenha(Senha);
    Senha getSenha();

    void setCargo(Cargo); //manual
    Cargo getCargo(); //manual
};

inline void Participante::setNome(Nome nome){
    this->nome = nome;
}
inline Nome Participante::getNome(){
    return nome;
}

inline void Participante::setSobrenome(Nome sobrenome){
    this->sobrenome = sobrenome;
}
inline Nome Participante::getSobrenome(){
    return sobrenome;
}

inline void Participante::setEmail(Email email){
    this->email = email;
}
inline Email Participante::getEmail(){
    return email;
}

inline void Participante::setTelefone(Telefone telefone){
    this->telefone = telefone;
}
inline Telefone Participante::getTelefone(){
    return telefone;
}

inline void Participante::setMatricula(Matricula matricula){
    this->matricula = matricula;
}
inline Matricula Participante::getMatricula(){
    return matricula;
}

inline void Participante::setSenha(Senha senha){
    this->senha = senha;
}
inline Senha Participante::getSenha(){
    return senha;
}

inline void Participante::setCargo(Cargo cargo){
    this->cargo = cargo;
}
inline Cargo Participante::getCargo(){
    return cargo;
}

//#######################################################################

class Peca {  //Antiga Class Conta
    private:
        Codigo identificador;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;

    public:
        void setCodigo(Codigo);
        Codigo getCodigo();
        void setNome(Nome);
        Nome getNome();
        void setTipo(Tipo);
        Tipo getTipo();
        void setClassificacao(Classificacao);
        Classificacao getClassificacao();
};

inline void Peca::setCodigo(Codigo identificador){
   this->identificador = identificador;
}

inline Codigo Peca::getCodigo(){
   return identificador;
}

inline void Peca::setNome(Nome nome){
    this->nome = nome;
}

inline Nome Peca::getNome(){
    return nome;
}

inline void Peca::setTipo(Tipo tipo){
    this->tipo = tipo;
}

inline Tipo Peca::getTipo(){
    return tipo;
}

inline void Peca::setClassificacao(Classificacao classificacao){
    this->classificacao = classificacao;
}

inline Classificacao Peca::getClassificacao(){
    return classificacao;
}

//--------------------------------------------------------------------------------------------

class Sessao {
    private:
        Codigo identificador;
        Data data;
        Horario horario;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();
        void setData(Data);
        Data getData();
        void setHorario(Horario);
        Horario getHorario();
};

inline void Sessao::setCodigo(Codigo identificador){
    this->identificador = identificador;
}

inline Codigo Sessao::getCodigo(){
    return identificador;
}

inline void Sessao::setData(Data data){
    this->data = data;
}

inline Data Sessao::getData(){
    return data;
}

inline void Sessao::setHorario(Horario horario){
    this->horario = horario;
}

inline Horario Sessao::getHorario(){
    return horario;
}

//--------------------------------------------------------------------------------------------

class Sala {
    private:
        Codigo identificador;
        Nome nome;
        Capacidade capacidade;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();
        void setNome(Nome);
        Nome getNome();
        void setCapacidade(Capacidade);
        Capacidade getCapacidade();
};

inline void Sala::setCodigo(Codigo identificador){
    this->identificador = identificador;
}

inline Codigo Sala::getCodigo(){
    return identificador;
}

inline void Sala::setNome(Nome nome){
    this->nome = nome;
}

inline Nome Sala::getNome(){
    return nome;
}

inline void Sala::setCapacidade(Capacidade capacidade){
    this->capacidade = capacidade;
}

inline Capacidade Sala::getCapacidade(){
    return capacidade;
}

#endif // ENTIDADES_H_INCLUDED
