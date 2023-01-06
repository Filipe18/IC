#include <iostream>
#include <fstream>
#include <map>
#include "Fcm.h"

using namespace std;

int main(int argc, char* argv[]){

    int k = stoi(argv[2]);
    double alpha = atof(argv[3]);
    double distance = 0;
    
    if(argc < 5){
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }
   
    Fcm fcm(argv[1], k, alpha);

    fcm.processText();

    cout << fcm.calculateEntropy() << endl;

    map<string, map<char, int>> model = fcm.getModel();
    map<string, int> contexts = fcm.getContexts();
    vector<char> symbolAlphabet = fcm.getSymbolAlphabet();
    
    fcm.close();

    fstream target; 
    target.open(argv[4]);

    string context = "";

    int nLetters=0;
    char c;
    while(target.get(c)){
        if(c == '\n' or c == '\t') continue;

        context += c;

        if(context.length() == k + 1){
            
            string temp = context.substr(0,k);
            distance += -log2((double) (alpha + model[temp][c]) / (contexts[temp] + alpha * symbolAlphabet.size()));
            context = context.substr(1);

            nLetters++;
        }
    }
    cout << "Estimativa de bits para comprimir o ficheiro: " << distance << endl;
    cout << "Estimativa de bits por símbolo: " << distance/nLetters << endl;

    return 0;
}