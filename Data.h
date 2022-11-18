#ifndef DATA_H_
#define DATA_H_
#include <time.h>

class Data{
    private:
        int dia,mes,ano;
    public:
        Data();
        ~Data();
        bool validaData();
        bool setData(int*,int*,int*);
        void getData(int*,int*,int*);
        string determinaDiaSemana();
        long long calculaDiasEntreDatas(Data);
};

// Construtor
Data::Data(){
    time_t dataAtt;
    dataAtt = time(NULL);
    struct tm tm = *localtime(&dataAtt);
    dia = tm.tm_mday;
    mes = tm.tm_mon + 1;
    ano = tm.tm_year + 1900;
}

// Destrutor
Data::~Data(){
    dia = 0;
    mes = 0;
    ano = 0;
}

// Valida a data
bool Data::validaData(){
    if (ano < 0){
        return false;
    }
    if (mes < 1 || mes > 12){
        return false;
    }
    if (dia < 1 || dia > 31){
        return false;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if (dia > 30){
            return false;
        }
    }
    if (mes == 2){
        if (dia > 29){
            return false;
        }
        if (ano % 4 == 0){
            if (dia > 29){
                return false;
            }
        }
        if (ano % 4 != 0){
            if (dia > 28){
                return false;
            }
        }
    }
    return true;
}

// Adicionar Data (dia, mes, ano)
bool Data::setData(int *d, int *m, int *a){
    dia = *d;
    mes = *m;
    ano = *a;
    if (validaData() == true){
        return true;
    }
    return false;
}

// Obter Data (dia, mes, ano)
void Data::getData(int *d, int *m, int *a){
    *d = dia;
    *m = mes;
    *a = ano;
}

// Determina os dias da semana
string Data::determinaDiaSemana(){
    int d = (14 - mes) / 12;
    int y = ano - d;
    int m = mes + 12 * d - 2;
    int s = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    switch (s){
        case 0:
            return "Domingo";
            break;
        case 1:
            return "Segunda-feira";
            break;
        case 2:
            return "Terca-feira";
            break;
        case 3:
            return "Quarta-feira";
            break;
        case 4:
            return "Quinta-feira";
            break;
        case 5:
            return "Sexta-feira";
            break;
        case 6:
            return "Sabado";
            break;
    }
}

long long Data::calculaDiasEntreDatas(Data data2){
    int dia2,mes2,ano2;
    data2.getData(&dia2, &mes2, &ano2);
    long long dias = 0;
    
    if (ano == ano2){
        if (mes == mes2){
            dias = dia2 - dia;
        }
        else{
            dias = (mes2 - mes) * 30;
            dias += dia2 - dia;
        }
    }
    else{
        dias = (ano2 - ano) * 365;
        dias += (mes2 - mes) * 30;
        dias += dia2 - dia;
    }

    if (dias < 0){
        dias *= -1;
    }

    return dias;
}

#endif