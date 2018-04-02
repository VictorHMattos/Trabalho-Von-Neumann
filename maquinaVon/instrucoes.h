#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ULA.h"
#include "memoria.h"


class Instrucoes: public ULA, public Memoria{
protected:
    int  converteInt(string aux, bool isOpcode = true);
    char *converteChar(int aux);
    void carregarMQ(int x);
    void carregarAC(int x);
    void escreverMQ(int x);
    void escreverAC(int x);
    void copiarMQAC();
    void copiarACMQ();
    void desviar(int x);
    void add(int x);
    void sub(int x);
    void mul(int x);
    void div(int x);
    void parar();
    void carregarACenderecoMQ();
    void escreverACenderecoMQ();

public:
    Instrucoes();
};

#endif // INTRUCOES_H
