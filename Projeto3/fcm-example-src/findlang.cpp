#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

int main(int argc, char* argv[]){

    if(argc < 5){
        cerr << "Usage: " << argv[0] << " <file_t> <model_order> <alpha> [<file_r>, ...]\n" ;
        exit(EXIT_FAILURE);
    }

    int k=stoi(argv[2]);
    double alpha = atof(argv[3]);
    double best_distance = 0;
    string lang;

    for(int i = 4; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");  // tente abrir o arquivo em modo de leitura
        if(fp == NULL){  // se a abertura do arquivo falhar, imprima uma mensagem de erro e pule para a próxima iteração do loop
            printf("Erro ao abrir o arquivo %s. Pulando...\n", argv[i]);
            continue;
        }
        Fcm fcm(argv[i], k, alpha);
        fcm.processText();

        double distance = fcm.calculateDistance(argv[1]);
        cout << "Distance -> " << distance << endl;
        if(i == 4){
            lang = argv[i];
            best_distance = distance;
        }
        else if(distance < best_distance){
            lang = argv[i];
            best_distance = distance;
        }
        fclose(fp);  // não esqueça de fechar o arquivo depois de usá-lo
    }

    cout << "Linguagem : " << lang << ", com estimativa de : " << best_distance << " bits" << endl;

    return 0;

}