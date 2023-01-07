#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Fcm{
    private:

        map<string, map<char, int>> model;

        map<string, int> contexts;
        
        vector<char> symbolAlphabet;

        int k;

        double alpha;

        int total;;
        
        fstream f;

    public:
        Fcm();

        Fcm(string file, int k, double alpha);

        void processText();

        double calculateEntropy();

        double calculateDistance(string input_file);

        map<string, map<char, int>> getModel();
    
        map<string, int> getContexts();

        vector<char> getSymbolAlphabet();

        void close();
};

Fcm::Fcm(){}

Fcm::Fcm(string file, int k_value, double alpha_value){

     if(not file.empty()){
        f.open(file);
    }
    else{
        cout << "Could not open input file!" << endl;
    }

    k = k_value;
    alpha = alpha_value;
    total = 0;
}

void Fcm::processText(){

    // Clear the model and alphabet from any previous processing
    model.clear();
    contexts.clear();
    symbolAlphabet.clear();

    string context = "";
    // Read characters from the input file stream one by one until the end of the file is reached
    char c;
    while (f.get(c)){

        if(c == '\n' or c == '\n') continue;
        context += c;
        
        if (find(symbolAlphabet.begin(), symbolAlphabet.end(), c) == symbolAlphabet.end())
            symbolAlphabet.push_back(c);

        if(context.length() == (size_t)(k + 1)){
            string temp = context.substr(0, k);
            contexts[temp]++;
            // Update the context count
            if (model.count(temp) > 0){
                model[temp][c]++;
            }
            else{
                map<char, int> empty;
                model[temp] = empty;
                model[temp][c]++;
            }
            context = context.substr(1);
            // Increment the total number of letters
            total++;
        }
    }
}

double Fcm::calculateEntropy(){
    double totalEntropy = 0;
    cout << "k -> " << k << '\t' << "alpha -> " << alpha<< endl;
    // Iterate through all contexts in the model
    for (auto it = contexts.begin(); it != contexts.end(); it++)
    {
        //cout << "CTX: "<< it->first << "\t" << "TOTAL: "<< it->second << "\t";
        string context = it->first;
        map<char, int> symbolCounts = model[context];
        
        int totalEntrysCtx = 0;
        for (auto it1 = symbolCounts.begin(); it1 != symbolCounts.end(); it1++){
            totalEntrysCtx += it1->second;
        }

        double contextEntropy = 0;
        // Calculate the probability of each symbol in the alphabet given the context
        for (auto symbol : symbolAlphabet)
        {
            int count = symbolCounts[symbol];   
            double probability = (count + alpha) / (it->second + alpha * symbolAlphabet.size());
            contextEntropy += -probability * log2(probability);
            //cout << "'" << symbol << "': " << model[it->first][symbol] << "\t";   
        }
        //cout << '\n';
        totalEntropy += contextEntropy * totalEntrysCtx / total;

    }

    return totalEntropy;
}

double Fcm::calculateDistance(string input_file) {
    double distance = 0;

    map<string, map<char, int>> model = getModel();
    map<string, int> contexts = getContexts();
    vector<char> symbolAlphabet = getSymbolAlphabet();

    fstream target;
    target.open(input_file);

    string context = "";

    int total = 0;
    char c;
    while (target.get(c)) {

      if (c == '\n' or c == '\t') continue;

      context += c;

      if (context.length() == (size_t)(k + 1)) {
        string temp = context.substr(0, k);
        distance += -log2((double)(alpha + model[temp][c]) /
                         (contexts[temp] + alpha * symbolAlphabet.size()));
        context = context.substr(1);

        total++;
      }
    }

    return distance/total;
  }

map<string, map<char, int>> Fcm::getModel(){

    return model;
}

map<string, int> Fcm::getContexts(){

    return contexts;
}

vector<char> Fcm::getSymbolAlphabet(){

    return symbolAlphabet;
}

void Fcm::close(){

    if(f.is_open()){
        f.close();
    }
}


