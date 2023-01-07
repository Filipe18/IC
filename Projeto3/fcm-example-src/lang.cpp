#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

using namespace std;

int main(int argc, char* argv[]){

    int k = stoi(argv[2]);
    double alpha = atof(argv[3]);
        
    if(argc < 5){
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }
   
    Fcm fcm(argv[1], k, alpha);

    fcm.processText();

    cout << fcm.calculateEntropy() << endl;

    double distance = fcm.calculateDistance(argv[4]);

    cout << "Estimativa de bits por símbolo: " << distance << endl;

    fcm.close();
    return 0;
}