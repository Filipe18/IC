#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Fcm
{
private:
    
    map<string, map<char, int>> model;
    map<string, int> contexts;

    vector<char> symbolAlphabet;

    int k;

    double alpha;

    int nLetters;

    string file;
      
    fstream f;

public:

    Fcm(){}

    // Constructor for the FCM class
    Fcm(string file, int k, double alpha)
    : file(file), k(k), alpha(alpha)
{
    this->k = k;
    this->alpha = alpha;
    this->file = file;
    this->nLetters = 0;
}

    void openfile(){

        if(not file.empty()){
            f.open(file);
        }
        else{
            cout << "Could not open input file!" << endl;
        }
    }
    void processText(){
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

            if(context.length() == k + 1){
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
                nLetters++;
            }
        }
    }

    double calculateEntropy(){

        double totalEntropy = 0;
    
        // Iterate through all contexts in the model
        for (auto it = contexts.begin(); it != contexts.end(); it++)
        {
            //cout << "CTX: "<< it->first << "\t" << "TOTAL: "<< it->second << "\t";
            string context = it->first;
            map<char, int> symbolCounts = model[context];
   
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
            totalEntropy += contextEntropy * symbolCounts.size() / nLetters;

        }

        return totalEntropy;
    }

    int getNumLetters(){
       
        return nLetters;
    }

    map<string, map<char, int>> getModel(){
   
        return model;
    }
    map<string, int> getContexts(){
       
        return contexts;
    }
    map<string, double> getSymbolAlphabet(){

        return symbolAlphabet;
    }

    void close(){

        if(f.is_open()){
            f.close();
        }
    }
};