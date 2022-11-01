#ifndef DATA_H_
#define DATA_H_

class Data{
    private:
        int dia,mes,ano;
    public:
        Data();
        ~Data();
        bool setData(int,int,int);
        void getData(int,int,int);
        bool validaData();
        string determinaDiaSemana();
        long long calculaDiasEntreDatas();
};

Data::Data(){
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::~Data(){
    dia = 0;
    mes = 0;
    ano = 0;
}

bool Data::setData(int d, int m, int a){
    if (d < 0 || d > 31 || m < 0 || m > 12 || a < 0){
        return false;
    }else{
        dia = d;
        mes = m;
        ano = a;
        return true;
    }
}

void Data::getData(int dia, int mes, int ano){
    cout << dia << "/" << mes << "/" << ano << "\n";
}

bool Data::validaData(){
    if (setData() == true){

    }else{
        return false;
    }
}

#endif