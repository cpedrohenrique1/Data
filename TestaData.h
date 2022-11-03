#ifndef TESTADATA_H_
#define TESTADATA_H_
#include "Data.h"

class TestaData{
    private:
        Data data1, data2;
    public:
        TestaData();
        ~TestaData();
        long long calculaDiasEntreDatas();
        void menu();
};

// Construtor
TestaData::TestaData(){
    data1 = Data();
    data2 = Data();
}

// Destrutor
TestaData::~TestaData(){
    data1 = Data();
    data2 = Data();
}

// Calcula a diferença entre duas datas e retorna o valor em dias
long long TestaData::calculaDiasEntreDatas(){
    int dia1, mes1, ano1, dia2, mes2, ano2;
    data1.getData(&dia1, &mes1, &ano1);
    data2.getData(&dia2, &mes2, &ano2);
    long long dias = 0;
    
    if (ano1 == ano2){
        if (mes1 == mes2){
            dias = dia2 - dia1;
        }
        else{
            dias = (mes2 - mes1) * 30;
            dias += dia2 - dia1;
        }
    }
    else{
        dias = (ano2 - ano1) * 365;
        dias += (mes2 - mes1) * 30;
        dias += dia2 - dia1;
    }

    if (dias < 0){
        dias *= -1;
    }

    return dias;
}

// Menu de interação com o usuário
void TestaData::menu(){
    // declaracao de variaveis
    int *dia = new int, *mes = new int, *ano = new int;
    string cidade[2];
    // ler a primeira data
    do{
        cout << "Insira a data (dia, mes, ano):\n";
        cin >> *dia >> *mes >> *ano;
        data1.setData(dia,mes,ano);
    }while (data1.validaData() == false);
    // ler cidade 1
    cout << "Insira a cidade: ";
    cin.ignore();
    getline(cin,cidade[0]);
    // ler a segunda data
    do{
        cout << "Insira a data (dia, mes, ano):\n";
        cin >> *dia >> *mes >> *ano;
        data2.setData(dia,mes,ano);
    }while (data2.validaData() == false);
    // ler cidade 2
    cout << "Insira a cidade: ";
    cin.ignore();
    getline(cin,cidade[1]);
    // imprimir resultados
    data1.getData(dia,mes,ano);
    cout << "A data 1 eh: " << cidade[0] << ", " << data1.determinaDiaSemana() << " " << *dia << '/' << *mes << '/' << *ano <<  endl;
    data2.getData(dia,mes,ano);
    cout << "A data 2 eh: " << cidade[1] << ", " << data2.determinaDiaSemana() << " " << *dia << '/' << *mes << '/' << *ano << endl;
    cout << "Se passaram " << calculaDiasEntreDatas() << " dias entre as datas." << endl;
}

#endif