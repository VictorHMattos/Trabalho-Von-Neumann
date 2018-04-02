#include "instrucoes.h"

Instrucoes::Instrucoes()
{
   inicializa();
}


void Instrucoes::carregarMQ(int x){
   int aux = converteInt(ler(x), false);
   MQ = atoi(ler(aux));

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
    char auxC[4];

    if(value < 0)
        ret[0] = '-';

    else
        ret[0] = '+';

    ret[1] = '0';
    ret[2] = '0';
    ret[3] = '0';
    ret[4] = '\0';

    auxC[0] = value / 100 + '0';
    auxC[1] = value % 100 / 10 + '0';
    auxC[2] = value % 100 % 10 + '0';
    auxC[3] = '\0';


    strncat(ret, auxC, 4);

   return ret;
}
