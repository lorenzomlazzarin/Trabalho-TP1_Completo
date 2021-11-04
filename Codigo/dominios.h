#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include<stdexcept>

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes dom�nio e implementa��es de m�todos.

class Dominio {
    private:
        string valor;
    protected:
        virtual void validar(string) = 0;
    public:
        void setValor(string);
        string getValor() const;
};

inline void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

inline string Dominio::getValor() const {
    return valor;
}

//--------------------------------------------------------------------------------------------

class Matricula:public Dominio {
     private:
         static const long unsigned int TAMANHO_MAXIMO = 5;
     protected:
         void validar(string);
};

//--------------------------------------------------------------------------------------------

class Senha:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};


//--------------------------------------------------------------------------------------------

class Cargo:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Nome:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Email:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Telefone:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Codigo:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Tipo:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Classificacao:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//---------------------------------------------------------------------------------------------

class Data:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//---------------------------------------------------------------------------------------------

class Horario:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//---------------------------------------------------------------------------------------------

class Capacidade:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
