#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>


using namespace std;


class Memoria{
    private:
        char memoria[1000][8];
        void imprimeErro(const char* erro);

    protected:
        void inicializa();
        void finalizar();
        const char* ler(int index);
        void escrever(char* dado,int index);


    public:
        Memoria();


};

#endif // MEMORIA_H
