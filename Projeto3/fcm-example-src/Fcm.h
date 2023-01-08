#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define ALPHABETH_SIZE 27 

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

        /**
         * @brief Construct a new Fcm object
         * 
         * @param file 
         * @param k 
         * @param alpha 
         */
        Fcm(string file, int k, double alpha);

        /**
         * @brief Reads characters from an input file and builds the language model
         * 
         */
        void processText();

        /**
         * @brief calculates the entropy of the constructed language model
         * 
         * @return double
         */
        double calculateEntropy();

        /**
         * @brief calculates the distance between the constructed language model and an input text file
         * 
         * @param input_file 
         * @return double
         */
        double calculateDistance(string input_file);

        /**
         * @brief calculates the distance between the constructed language model and an input text segment
         * 
         * @param input 
         * @return double 
         */
        double calculateDistanceSegment(string input);

        /**
         * @brief closes open file stream to read text data
         * 
         */
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
    // Iterate through all contexts in the model
    for (auto it = contexts.begin(); it != contexts.end(); it++)
    {
        
        string context = it->first;
        map<char, int> symbolCounts = model[context];
        
        int totalEntrysCtx = 0;
        for (auto it1 = symbolCounts.begin(); it1 != symbolCounts.end(); it1++){
            totalEntrysCtx += it1->second;
        }

        double contextEntropy = 0;
        for (auto symbol : symbolAlphabet)
        {
            int count = symbolCounts[symbol];   
            double probability = (count + alpha) / (it->second + alpha * ALPHABETH_SIZE);
            contextEntropy += -probability * log2(probability);
           
        }
      
        totalEntropy += contextEntropy * totalEntrysCtx / total;

    }

    return totalEntropy;
}

double Fcm::calculateDistance(string input_file) {
    
    double distance = 0;

    fstream target;
    target.open(input_file);

    string context = "";

    char c;
    while (target.get(c)) {

        if (c == '\n' or c == '\t') continue;

        context += c;

        if (context.length() == (size_t)(k + 1)) {
            string temp = context.substr(0, k);
            distance += -log2((double)(alpha + model[temp][c]) /
                                (contexts[temp] + alpha * ALPHABETH_SIZE));
            context = context.substr(1);
        }
    }

    return distance;
}

double Fcm::calculateDistanceSegment(string input) {

    double distance = 0;
    
    string context = "";

    for (char c : input) {

        if (c == '\n' or c == '\t') continue;

        context += c;

        if (context.length() == (size_t)(k + 1)) {
        string temp = context.substr(0, k);
        distance += -log2((double)(alpha + model[temp][c]) /
                            (contexts[temp] + alpha * ALPHABETH_SIZE));
        context = context.substr(1);

        }
    }

    return distance;
}

void Fcm::close(){

    if(f.is_open()){
        f.close();
    }
}


