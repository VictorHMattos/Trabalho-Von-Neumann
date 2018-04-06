#include "memoria.h"


Memoria::Memoria()
{

}

void Memoria::inicializa(char *name){
    try{
        if(name == NULL)
            throw "Erro: Nome do arquivo não pode ser null.";

        ifstream arquivo(name);

        if(!arquivo.is_open())
            throw "Erro: Não foi possível abrir o arquivo. \nArquivo não encontrado!";

        int index = 0;
        string str;

        while(!arquivo.eof() && index < 1000){
            getline(arquivo, str);

            if(str.size() == 6){
             
                strncpy(memoria[index], str.c_str(), 7);
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


char* Memoria::ler(int index){
   char *retorno = new char[8];
    try{

        if(index < 0 && index >= 1000)
            throw "Erro: index invalido";

        
        strncpy(retorno , memoria[index], 8);

    }catch(const char* erro){

        imprimeErro(erro);

    }
   return retorno;
}



void Memoria::escrever(char *dado, int index){
    try{

        if(index < 0 && index >= 1000)
            throw "Erro: index invalido.";

        int tam = strlen(dado);

        if(tam < 6 || tam > 7)
            throw "Erro: O tamanho da palavra está incorreto";

        if(tam == 6)
            strncpy(memoria[index], dado, 7);
        
        else
            strncpy(memoria[index], dado, 8);

    }catch(const char* erro){

        imprimeErro(erro);

    }
}



void Memoria::imprimeErro(const char *erro){
    cerr << erro << endl;
}


void Memoria::finalizar(){
    time_t agora = time(NULL);
    tm *localTm = localtime(&agora);

    string fileName = "saida.";
    
    string aux = to_string(localTm->tm_hour) + "." + to_string(localTm->tm_min) + "."  + to_string(localTm->tm_sec) + ".txt";
    fileName += aux;

    
    ofstream outfile(fileName, ofstream::out | ofstream::app);

    for(short int index = 0; index < 1000; index++)
        outfile << memoria[index] << endl;

    cout << "Output file name is: " << fileName << std::endl;
    outfile.close();
}
