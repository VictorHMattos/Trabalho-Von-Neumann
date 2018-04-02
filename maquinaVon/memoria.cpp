#include "memoria.h"


Memoria::Memoria()
{
}

void Memoria::inicializa(){

    ifstream arquivo("/home/victor/Área de Trabalho/Trabalho-Von/Trabalho-Von-Neumann/maquinaVon/selection-sort-size-15.ias");

    try{
        if(!arquivo.is_open())
            throw "Erro: Não foi possível abrir o arquivo.";

        int index = 0;
        string str;

        while(!arquivo.eof() && index < 1000){
            getline(arquivo, str);

            if(str.size() == 6){
                memoria[index][0] = '+';
                memoria[index][1] = '\0';

                strncat(memoria[index], str.c_str(), 7);
            }
            else{
                strncpy(memoria[index], str.c_str(), 8);

              }

            index++;
        }

    }catch(const char* erro){
        imprimeErro(erro);

        exit(1);
    }
}


const char* Memoria::ler(int index){
   char *retorno = new char[8];
    try{

        if(index < 0 && index >= 1000)
            throw "Erro: index invalido";

        strncpy(retorno , memoria[index], 8);

    }catch(const char* erro){

        imprimeErro(erro);

    }

   return (const char*)retorno;
}



void Memoria::escrever(char *dado, int index){
    try{

        if(index < 0 && index >= 1000)
            throw "Erro: index invalido";

        if(strlen(dado) < 8)
            throw "Erro: O tamanho da palavra está incorreto";

        strncpy(memoria[index], dado, 8);

    }catch(const char* erro){

        imprimeErro(erro);

    }
}



void Memoria::imprimeErro(const char *erro){
    cerr << erro << endl;
}


void Memoria::finalizar(){

    ofstream outfile("saida.txt", ofstream::out | ofstream::app);

    for(short int index = 0; index < 1000; index++)
        outfile << memoria[index] << endl;

    outfile.close();

}
