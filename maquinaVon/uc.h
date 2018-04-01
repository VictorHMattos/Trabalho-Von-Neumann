#ifndef UC_H
#define UC_H

#include "instrucoes.h"

class UnitControl: public Instrucoes{
    private:
        int PC, MAR,IR;

        void buscaInstrucao();
        void decodificaInstruacao();

    public:
           UnitControl();

};

#endif // UC_H
