#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

int main(int argc, char* argv[]){

    int k=stoi(argv[2]);
    double alpha = atof(argv[3]);
    double best_distance = 0;
    string lang;

    if(argc < 4){
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }

    string texts[] = {"textos/dutch.txt","textos/eng.txt","textos/esp.txt","textos/fin.txt","textos/fr.txt","textos/ger.txt","textos/ita.txt",
                        "textos/pol.txt","textos/pt.txt","textos/swe.txt"};

    for(int i = 0; i < 10; i++){

        Fcm fcm(texts[i], k, alpha);

        fcm.processText();

        double distance = fcm.calculateDistance(argv[1]);

        if(i == 0){
            lang = texts[0];
            best_distance = distance;
        }
        else if(distance < best_distance){
            lang = texts[i];
            best_distance = distance;
        }
    }

    cout << "Linguagem : " << lang << ", com estimativa de : " << best_distance << " bits por simbolo" << endl;

    return 0;

}