#include "dominios.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes dom�nio.
//
// M�todos com implementa��es simplificadas com o intuito de facilitar a constru��o do exemplo.



//Inicio Participante

void Matricula::validar(string valor){

     int j, i;

     if(valor.length() == TAMANHO_MAXIMO){
         for(i=0 ; i<5 ; i++){
             for(j=0 ; j<5 ; j++){
                 if(valor[i] == valor[j] && i!=j){
                     throw invalid_argument("Argumento invalido.");
                 }
             }
         }
         return;

     }
     else{
         throw invalid_argument("Argumento invalido");
     }
}


void Nome::validar(string valor){
    int flag=0;

    if (valor.size()>=5 && valor.size()<=20){
        for(int i=0; i<valor.size(); i++){
            if (valor[i]>=65 && valor[i]<=90) flag++;
            else if (valor[i]>=97 && valor[i]<=122) flag++;
            else if (valor[i]==46 && valor[i-1]>=65 && valor[i-1]<=90 || valor[i]==46 && valor[i-1]>=97 && valor[i-1]<=122) flag++;
            else if (valor[i]==32 && valor[i+1]>=65 && valor[i+1]<=90) flag++;
            else break;
        }
        if (flag==valor.size()) return;
    }
    throw invalid_argument("Nome invalido. Ex: Joao Pereira.");
}

void Email::validar(string valor){
    int posicao_arb, tamanho, flag = 0;

    tamanho = valor.size();
    if (tamanho<320){
        posicao_arb = valor.find("@");
        if (tamanho-posicao_arb<=255 && posicao_arb<=64 && posicao_arb!= -1){
            for (int i=0;i<tamanho;i++){
                if (valor[i]==46 && i==0 || valor[i]==46 && i==tamanho-1) break;
                else if (valor[i]==46 && valor[i+1]==46) break;
                else if (valor[i]>=48 && valor[i]<=57) flag++;
                else if (valor[i]>=65 && valor[i]<=90) flag++;
                else if (valor[i]>=97 && valor[i]<=122) flag++;
                else if (valor[i]==33 || valor[i]>=35 && valor[i]<=39 || valor[i]==42 || valor[i]==43 || valor[i]==45 || valor[i]==46 || valor[i]==47 || valor[i]==61 || valor[i]==63 || valor[i]==64 || valor[i]>=94 && valor[i]<=96 || valor[i]>=123 && valor[i]<=126) flag++;       //caracteres especiais
                else break;
            }
            if (flag == tamanho) return;
        }
    }
    throw invalid_argument("Email invalido.");
}

void Telefone::validar(string valor){
        char dd_char[2];
    int dd, n_zeros=0, flag=0;
    if (valor.size()==14){
        if (valor[0]==40 && valor[3]==41 && valor[4]==45){
            if (valor[2]>=48 && valor[2]<=57){
                for (int i=0, j=1; i<3; i++, j++){
                    if (i <2) dd_char[i] = valor[j];
                    else dd_char[2] = '\0';
                }
                dd = atoi(dd_char);
                if (dd>=11 && dd<=19 || dd==21 || dd==22 || dd==24 || dd==27 || dd==28 || dd==32 || dd==33 || dd==34 || dd==35 || dd==37 || dd==38 || dd>=41 && dd<=49 || dd==51 || dd==53 || dd==54 || dd==55 || dd>=61 && dd<=69 || dd==71 || dd==73 || dd==74 || dd==75 || dd==77 || dd==79 || dd>=81 && dd<=89 || dd>=91 && dd<=99){
                    for (int i=5; i<14;i++){
                        if (valor[i]>=48 && valor[i]<=57){
                            if (valor[i] == 48) n_zeros++;
                            flag++;
                        }
                    }
                    if (n_zeros != 9 && flag == 9) return;
                }
            }
        }
    }
    throw invalid_argument("Numero invalido. Ex: (00)-000000000.");
}

void Senha::validar(string valor){
    int tamanho, i=0,j=0, letras=0, digito=0, especial=0;
    tamanho = valor.size();
    if(tamanho == 8){
        for(i=0; i <= tamanho; i++){
            if(valor[i] == 33 || (valor[i] >= 35 && valor[i] <= 38)){
                especial++;
            }
            else if (valor[i] >= 48 && valor[i] <= 57){
                digito++;
            }
            else if ((valor[i] >= 63 && valor[i] <= 90) || (valor[i] >= 97 && valor[i] <= 122)) letras++;
        }
        if(letras!=0 && digito!=0 && especial!=0 && letras+digito+especial==8){
            for(i=0; i < tamanho; i++){
                for (j=0; j<tamanho; j++) {
                    if (valor[i]==valor[j] && i!=j) throw invalid_argument("Senha inválida. Não pode ter caracteres repetidos. Ex: NOME123@");
                }
            }
            return;
        }
    }
    throw invalid_argument("Senha inválida. Informe uma senha válida. Ex: NOME123@");
}

void Cargo::validar(string valor){
    string cargos[6] = {"ator", "cenógrafo", "figurinista", "maquiador", "sonoplasta", "iluminador"};
    for(int i = 0; i <= 5; i++){
        if(cargos[i].compare(valor) == 0)
            return;
    }
    throw invalid_argument("Cargo inválido. Informe um cargo válido. Ex: ator");
}

// fim participante

//Inicio Peça

//Classe nome já foi chamada na linha 39.

void Codigo::validar(string valor){
    int flag = 0;

    if (valor.size()==6) {
        for (int i=0;i<6;i++){
            if (i<2 && valor[i]>=65 && valor[i]<=90)flag++;
            else if (i>=2 && valor[i]>=48 && valor[i]<=57)flag++;
            else break;
        }
        if (flag == valor.size()) return;
    }
    else if (valor.size()==13 && valor[6]==45){
        for (int i=0;i<14;i++){
            if (i<2 && valor[i]>=65 && valor[i]<=90 || i>=7 && i<=8 && valor[i]>=65 && valor[i]<=90)flag++;
            else if (i>=2 && valor[i]>=48 && valor[i]<=57)flag++;
            else if (i==6) continue;
            else break;
        }
        if (flag == 12) return;
    }
    else if (valor.size()==20 && valor[6]==45 && valor[13]==45){
        for (int i=0;i<6;i++){
            if (i<2 && valor[i]>=65 && valor[i]<=90 || i>=7 && i<=8 && valor[i]>=65 && valor[i]<=90 || i>=14 && i<=15 && valor[i]>=65 && valor[i]<=90)flag++;
            else if (i>=2 && valor[i]>=48 && valor[i]<=57)flag++;
            else if (i==6 || i==13) continue;
            else break;
        }
        if (flag == 18) return;
    }
    throw invalid_argument("Codigo invalido. Ex: AA0000.");
}

void Classificacao::validar(string valor){
    string classificacoes[6] = {"livre", "10", "12", "14", "16", "18"};
    for(int i=0; i <=5; i++){
        if(classificacoes[i].compare(valor) == 0)
            return;
    }
    throw invalid_argument("Classificacao inválida. Informe um cargo válido. Ex: livre, 10");
}

void Tipo::validar(string valor){
    if(valor == "auto" || valor == "comédia" || valor == "comedia" || valor == "drama" ||
    valor == "farsa" || valor == "melodrama" || valor == "monólogo" || valor == "monologo" ||
    valor == "musical" || valor == "ópera" || valor == "opera" || valor == "revista") {
        return;
    }
    throw invalid_argument("Argumento invalido.");
}

//Fim Peça.

//inicio Sessão.

//Classe Código já foi implementada na linha 143.

void Data::validar(string valor){
    char dia_char[3], mes_char[3], ano_char[5];
    int dia, mes, ano, flag_laco = 0;

    if (valor.size()==10){
        if (valor[2]==47 && valor[5]==47){
            if (48<=valor[1] && valor[1]<=57 && 48<=valor[4] && valor[4]<=57 && 48<=valor[7] && valor[7]<=57 && 48<=valor[8] && valor[8]<=57 && 48<=valor[9] && valor[9]<=57){
                for(int i=0;i<11;i++){
                    if (i <2){
                        dia_char[flag_laco] = valor[i];
                        flag_laco++;
                    }
                    else if (i == 2) {
                        dia_char[3] = '\0';
                        dia = atoi(dia_char);
                        flag_laco = 0;
                    }
                    else if (i<5){
                        mes_char[flag_laco]=valor[i];
                        flag_laco++;
                    }
                    else if (i ==5){
                        mes_char[3] = '\0';
                        mes = atoi(mes_char);
                        flag_laco = 0;
                    }
                    else if (i<10){
                        ano_char[flag_laco] = valor[i];
                        flag_laco++;
                    }
                    else {
                        ano_char[5] = '\0';
                        ano = atoi(ano_char);
                    }
                }
            if (valor[6] >= 50 && valor[6] <= 57){
                if (mes == 1) {
                    if (dia >= 1 && dia <=31) return;
                }
                else if (mes == 2) {
                    if (ano%4==0 && ano%100!=0 || ano%4==0 && ano%100==0 && ano%400==0){
                        if (dia>=1 && dia<=29) return;
                    }
                    else{
                        if (dia>=1 && dia<=28) return;
                    }
                }
                else if (mes == 3) {
                    if (dia >= 1 && dia <=31) return;
                }
                else if (mes == 4) {
                    if (dia >= 1 && dia <=30) return;
                }
                else if (mes == 5) {
                    if (dia >= 1 && dia <=31) return;
                }
                else if (mes == 6) {
                    if (dia >= 1 && dia <=30) return;
                }
                else if (mes == 7) {
                    if (dia >= 1 && dia <=31) return;
                    }
                else if (mes == 8) {
                    if (dia >= 1 && dia <=31) return;
                }
                else if (mes == 9) {
                    if (dia >= 1 && dia <=30) return;
                }
                else if (mes == 10) {
                    if (dia >= 1 && dia <=31) return;
                }
                else if (mes == 11) {
                    if (dia >= 1 && dia <=30) return;
                }
                else if (mes == 12) {
                    if (dia >= 1 && dia <=31) return;
                }
            }
        }
    }
    cout << "Data"<<endl;
    throw invalid_argument("Data invalida. Cuidado com o ano bissesto. Ex: DD/MM/AAAA");
    }
}

void Horario::validar(string valor){

    char hora_string[2], minuto_string[2];
    int hora_int, minuto_int;

    if(valor[1]>=48 && valor[1]<=57 && valor[4]>48 && valor[4]<=57){
        hora_string[0] = valor[0];
        hora_string[1] = valor[1];
        hora_string[2] = '\0';
        hora_int = atoi(hora_string);

        minuto_string[0] = valor[3];
        minuto_string[1] = valor[4];
        minuto_string[2] = '\0';
        minuto_int = atoi(minuto_string);

        if(hora_int >= 0 && hora_int <= 23)
        {
            if(minuto_int == 00 || minuto_int == 15 || minuto_int == 30 || minuto_int == 45) return;
        }
    }
    cout << "horario" << endl;
    throw invalid_argument("Argumento invalido.");
}

void Capacidade::validar(string capacidade) {
   if(capacidade == "100" || capacidade == "200" || capacidade == "300" || capacidade == "400" || capacidade == "500")
        return;
    throw invalid_argument("Capacidade inválida. Informe um valor válido. Ex: 100");
}

//Fim da classe Sessão.
