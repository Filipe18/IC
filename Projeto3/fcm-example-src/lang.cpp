#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

using namespace std;

int main(int argc, char* argv[]){
        
    if(argc < 5){
        cerr << "Usage: " << argv[0] << " <file_r> <model_order> <alpha> <file_t>\n" ;
        exit(EXIT_FAILURE);
    }
    
    int k = stoi(argv[2]);
    double alpha = atof(argv[3]);
    
    Fcm fcm(argv[1], k, alpha);

    fcm.processText();

    double distance = fcm.calculateDistance(argv[4]);

    cout << "Estimativa de bits: " << distance << endl;

    fcm.close();
    return 0;
}