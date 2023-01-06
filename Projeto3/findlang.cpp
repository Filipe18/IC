#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include "fcm.h"

int main(int argc, char* argv[]){

    int k=stoi(argv[2]);
    double alpha = stod(argv[3]);
    double best_nBits = 0;
    string lang;

    if(argc < 4){
        cout << "Wrong number of arguments!" << endl;
        exit(EXIT_FAILURE);
    }

    string texts[] = {"textos/dutch.txt","textos/eng.txt","textos/esp.txt","textos/fin.txt","textos/fr.txt","textos/ger.txt","textos/ita.txt","textos/pol.txt","textos/pt.txt","textos/swe.txt"};

    for(int i = 0; i < 10; i++){

        double distance=0;

        Fcm fcm(texts[i], k, alpha;

        fcm.openfile();

        fcm.processText();

        cout << fcm.calculateEntropy(); << endl;

        map<string, map<char, int>> model = fcm.getModel;
        map<string, int> contexts = fcm.getContexts;
        vector<char> symbolAlphabet = fcm.getSymbolAlphabet;
        
        fcm.close();

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

        double nBits = distance/nLetters;
        if(i == 0){
            lang = filelist[0];
            best_nBits = nBits;
        }
        else{
            lang = filelist[i];
            best_nBits = nBits;
        }
    }

    cout << "Linguagem : " << lang << ", com estimativa de : " << best_nBits << " bits por simbolo" << endl;

    return 0;

}