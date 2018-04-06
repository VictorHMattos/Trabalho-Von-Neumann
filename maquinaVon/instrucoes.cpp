#include "instrucoes.h"

Instrucoes::Instrucoes()
{
   
}


void Instrucoes::carregarMQ(int x){
   int aux = converteInt(ler(x), false);

   MQ = converteInt(ler(aux), false);

}

void Instrucoes::carregarAC(int x){
    int aux = converteInt(ler(x), false);

    AC = converteInt(ler(aux), false);
}

void Instrucoes::escreverMQ(int x){
    int aux = converteInt(ler(x), false);

    escrever(converteChar(MQ, aux), aux);
}


void Instrucoes::escreverAC(int x){
    int aux = converteInt(ler(x), false);

    escrever(converteChar(AC, aux), aux);
}


void Instrucoes::copiarMQAC(){
    AC = MQ;
}


void Instrucoes::copiarACMQ(){
    MQ = AC;
}



void Instrucoes::add(int x){
    AC += converteInt(ler(converteInt(ler(x),false)), false);
}


void Instrucoes::sub(int x){
    AC -=  converteInt(ler(converteInt(ler(x),false)), false);
}


void Instrucoes::mul(int x){
    AC = (converteInt(ler(converteInt(ler(x),false)), false) * MQ);
}


void Instrucoes::div(int x){
    MQ = (converteInt(ler(converteInt(ler(x),false)), false) / AC);
    AC = (converteInt(ler(converteInt(ler(x),false)), false) % MQ);
}


void Instrucoes::parar(){
    finalizar();

    exit(0);

}


void Instrucoes::carregarACenderecoMQ(){
    AC = converteInt(ler(MQ), false);
}


void Instrucoes::escreverACenderecoMQ(){
    escrever(converteChar(AC, MQ), MQ);
}


int Instrucoes::converteInt(string aux, bool isOpcode){

    int ret;

    if(isOpcode){
        if(aux[0] == '-'){
            ret =  (aux[1] - '0')*100;
            ret += (aux[2] - '0')*10;
            ret += (aux[3] - '0');
        
        }else{
            ret =  (aux[0] - '0')*100;
            ret += (aux[1] - '0')*10;
            ret += (aux[2] - '0');
        }

    }else{
        if(aux[0] == '-'){
            ret =  (aux[4] - '0')*100;
            ret += (aux[5] - '0')*10;
            ret += (aux[6] - '0');
            ret *= -1;
        
        }else{
            ret =  (aux[3] - '0')*100;
            ret += (aux[4] - '0')*10;
            ret += (aux[5] - '0');
        }
        
    }

    return ret;
}


char *Instrucoes::converteChar(int valueData, int index){
    char *ret = new char[8];
    char aux[4];
    char *aux2 = ler(index);

    if(aux2[0] == '-'){
        ret[0] = aux2[0];
        ret[1] = aux2[1];
        ret[2] = aux2[2];
        ret[3] = aux2[3];
        ret[4] = '\0';
    
    }else{
        ret[0] = aux2[0];
        ret[1] = aux2[1];
        ret[2] = aux2[2];
        ret[3] = '\0';
    }

    aux[0] = valueData / 100 + '0';
    aux[1] = valueData % 100 / 10 + '0';
    aux[2] = valueData % 100 % 10 + '0';
    aux[3] = '\0';


    strncat(ret, aux, 4);

   return ret;
}
