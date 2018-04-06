#ifndef UC_H
#define UC_H

#include <unistd.h>
#include "instrucoes.h"


class UnitControl: public Instrucoes{
    private:
        int PC;
        int IR;
        int MAR;

        void show();
        void buscaInstrucao();
        void decodificaInstruacao();
        
    public:
        void init(bool isShow = false, int timeT = 0);
        UnitControl(char *name);

};

#endif // UC_H
