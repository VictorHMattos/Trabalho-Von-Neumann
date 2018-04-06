#include <iostream>
#include "uc.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2 || argc > 5){
        cout << "Erro: Usange ./main <file_prog.ias> " << endl<< 
                "Or ./main <file_prog.ias> -w -t <milleseconds> to show executing details  and use a time to execute instructions." << endl;

        exit(1);
    }

    if((argc == 3) && (strcmp(argv[2], "-w") == 0)){
        UnitControl uc(argv[1]); 
        uc.init(true);
    
    }else{ 
        if((argc == 5) && (strcmp(argv[2], "-w") == 0) && (strcmp(argv[3], "-t") == 0)){
            UnitControl uc(argv[1]); 
            uc.init(true, atoi(argv[4]));
    
        }else{
            UnitControl uc(argv[1]);
        
            uc.init();
        }
    }
    



    return 0;
}
