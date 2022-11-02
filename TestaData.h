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
}

// Menu de interação com o usuário
void TestaData::menu(){
    int *dia = new int, *mes = new int, *ano = new int;
    string cidade;

    do{
        cout << "Insira a data (dia, mes, ano):\n";
        cin >> *dia >> *mes >> *ano;
        data1.setData(dia,mes,ano);
    }while (data1.validaData() == false);
    cout << "Insira a cidade: ";
    cin.ignore();
    getline(cin,cidade);
    cout << "O dia da semana eh: " << data1.determinaDiaSemana() << endl;
    data1.getData(dia,mes,ano);
    cout << "A data eh: " << *dia << '/' << *mes << '/' << *ano << endl;
    
}

#endif