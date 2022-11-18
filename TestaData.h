#ifndef TESTADATA_H_
#define TESTADATA_H_
#include "Data.h"

class TestaData{
    private:
        Data data1, data2;
    public:
        TestaData();
        ~TestaData();
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

// Menu de interação com o usuário
void TestaData::menu(){
    // declaracao de variaveis
    int *dia = new int, *mes = new int, *ano = new int;
    string cidade[2];
    // ler a primeira data
    do{
        cout << "Insira a data 1 (dia, mes, ano):\n";
        cin >> *dia >> *mes >> *ano;
        data1.setData(dia,mes,ano);
    }while (data1.validaData() == false);
    // ler cidade 1
    cout << "Insira a cidade 1: ";
    cin.ignore();
    getline(cin,cidade[0]);
    // ler a segunda data
    do{
        cout << "Insira a data 2 (dia, mes, ano):\n";
        cin >> *dia >> *mes >> *ano;
        data2.setData(dia,mes,ano);
    }while (data2.validaData() == false);
    // ler cidade 2
    cout << "Insira a cidade 2: ";
    cin.ignore();
    getline(cin,cidade[1]);
    // imprimir resultados
    data1.getData(dia,mes,ano);
    cout << "A data 1 eh: " << cidade[0] << ", " << data1.determinaDiaSemana() << " " << *dia << '/' << *mes << '/' << *ano <<  endl;
    data2.getData(dia,mes,ano);
    cout << "A data 2 eh: " << cidade[1] << ", " << data2.determinaDiaSemana() << " " << *dia << '/' << *mes << '/' << *ano << endl;
    cout << "Se passaram " << data1.calculaDiasEntreDatas(data2) << " dias entre as datas." << endl;
}

#endif