#include "instrucoes.h"

Instrucoes::Instrucoes()
{
   inicializa();
}


void Instrucoes::carregarMQ(int x){
   int aux = converteInt(ler(x), false);

   cout << aux << endl;

   MQ = atoi(ler(aux));

   cout << MQ << endl;
}

void Instrucoes::carregarAC(int x){
    int aux = converteInt(ler(x), false);

    AC = atoi(ler(aux));
}

void Instrucoes::escreverMQ(int x){

    escrever(converteChar(MQ), converteInt(ler(x), false));
}


void Instrucoes::escreverAC(int x){

    escrever(converteChar(AC), converteInt(ler(x), false));
}


void Instrucoes::copiarMQAC(){

    AC = MQ;

}


void Instrucoes::copiarACMQ(){

    MQ = AC;
}



void Instrucoes::add(int x){

    AC += atoi(ler(converteInt(ler(x),false)));
}


void Instrucoes::sub(int x){

    AC -=  atoi(ler(converteInt(ler(x),false)));
}


void Instrucoes::mul(int x){

    AC = (atoi(ler(converteInt(ler(x),false))) * MQ);
}


void Instrucoes::div(int x){

    MQ = (atoi(ler(converteInt(ler(x),false))) / AC);
    AC = (atoi(ler(converteInt(ler(x),false))) % MQ);
}


void Instrucoes::parar(){


    finalizar();

    exit(0);

}


void Instrucoes::carregarACenderecoMQ(){
    AC = atoi(ler(MQ));
}


void Instrucoes::escreverACenderecoMQ(){
    escrever(converteChar(AC), MQ);
}


int Instrucoes::converteInt(string aux, bool isOpcode){

    int ret;

    if(isOpcode){

        ret =  (aux[1] - '0')*100;
        ret += (aux[2] - '0')*10;
        ret += (aux[3] - '0');

    }else{

        ret =  (aux[4] - '0')*100;
        ret += (aux[5] - '0')*10;
        ret += (aux[6] - '0');

        if(aux[0]== '-')
        {
            ret *= -1;
        }

    }

    return ret;
}


char *Instrucoes::converteChar(int value){
    char *ret = new char[8];
    string aux = std::to_string(value);

    ret = (char*)"000\0";

    strncat(ret, aux.c_str(), 3);

   return ret;
}
