#include "uc.h"


UnitControl::UnitControl(char *name){
    PC    = 0;
    IR    = 0;
    MAR   = 0;

    inicializa(name);
}


void UnitControl::init(bool isShow, int timeT){

    if(timeT && isShow)
        while(true){
            show();
            buscaInstrucao();
            usleep(timeT);
            decodificaInstruacao();
        }

    else 
        if(isShow)
            while(true){
                show();
                buscaInstrucao();                
                decodificaInstruacao();
            }

        else
            while(true){
                buscaInstrucao();
                decodificaInstruacao();
            }
}


void UnitControl ::buscaInstrucao(){

    IR =  converteInt(ler(PC));

    MAR = PC;

    PC++;    
}


void  UnitControl::decodificaInstruacao(){

    switch (IR) {
    case 100:
        carregarMQ(MAR);
        break;

    case 105:
        carregarAC(MAR);
        break;

    case 110:
        escreverMQ(MAR);
        break;

    case 115:
        escreverAC(MAR);
        break;

    case 120:
        copiarMQAC();
        break;

    case 125:
        copiarACMQ();
        break;

    case 200:
        PC  = converteInt(ler(MAR), false);

        break;

    case 205:
        if(AC < 0){
            PC  = converteInt(ler(MAR), false);
        }

        break;

    case 210:
        if(AC <= 0){
            PC  = converteInt(ler(MAR), false);
        }
        break;

    case 215:
        if(AC == 0){
            PC  = converteInt(ler(MAR), false);
        }
        break;

    case 220:
        if(AC > 0){
            PC  = converteInt(ler(MAR), false);
        }
        break;

    case 225:
        if(AC >= 0){
            PC  = converteInt(ler(MAR), false);
        }
        break;

    case 300:
        add(MAR);
        break;

    case 305:
        sub(MAR);
        break;

    case 310:
        mul(MAR);
        break;


    case 315:
        div(MAR);
        break;

    case 400:
        show();
        parar();
        break;

    case 500:
        carregarACenderecoMQ();
        break;

    case 505:
        escreverACenderecoMQ();
        break;

    default:
        break;
    }
}


void UnitControl::show(){
    cout << "\e[1;1H\e[2J" << endl;
    cout << "IR   " << IR << endl; 
    cout << "PC   " << PC << endl;
    cout << "MAR  " << MAR << endl;
    cout << "AC   " << AC << endl;
    cout << "MQ   " << MQ << endl;
    cout << "Dado " << ler(MAR) << endl;
}

